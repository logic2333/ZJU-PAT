// 1003.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct road {
	unsigned start, end, len;
};

struct route {
	unsigned depart, dest, len;
	deque<unsigned> vias;
	route() {}
	route(const unsigned _depart, const unsigned _dest) {
		depart = _depart; dest = _dest; len = 0;
		vias.push_back(depart);
	}
	bool operator<(const route& another) const {
		return len < another.len;
	}
	void grow(const road* _roads, const unsigned _m, const unsigned _n, deque<route>& _routes) {
		while (vias.back() != dest && vias.back() != _n + 1) {
			bool is_first = true; bool found = false;
			route temp_route = *this;
			for (unsigned i = 0; i < _m; i++) {
				if (_roads[i].start == temp_route.vias.back() && 
					find(temp_route.vias.begin(), temp_route.vias.end(), _roads[i].end) == temp_route.vias.end()) {
					found = true;
					if (is_first) {
						vias.push_back(_roads[i].end); len += _roads[i].len;
						is_first = false;
					}
					else {
						route new_route = temp_route; 
						new_route.vias.push_back(_roads[i].end); new_route.len += _roads[i].len;
						_routes.push_back(new_route);
					}
				}
				else if (_roads[i].end == temp_route.vias.back() &&
					find(temp_route.vias.begin(), temp_route.vias.end(), _roads[i].start) == temp_route.vias.end()) {
					found = true;
					if (is_first) {
						vias.push_back(_roads[i].start); len += _roads[i].len;
						is_first = false;
					}
					else {
						route new_route = temp_route;
						new_route.vias.push_back(_roads[i].start); new_route.len += _roads[i].len;
						_routes.push_back(new_route);
					}
				}
			}
			if (!found) vias.push_back(_n + 1);
		}
	}
};

int main()
{
	unsigned n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	unsigned* team = new unsigned[n];
	for (unsigned i = 0; i < n; i++) cin >> team[i];
	road* roads = new road[m];
	for (unsigned i = 0; i < m; i++)
		cin >> roads[i].start >> roads[i].end >> roads[i].len;
	deque<route> routes;
	routes.emplace_back(c1, c2);
	unsigned i = 0;
	for (; i < routes.size(); i++) routes[i].grow(roads, m, n, routes);
	sort(routes.begin(), routes.end());
	i = 1;
	for (; i < routes.size(); i++) {
		if (routes[i].len > routes[i - 1].len) break;
	}
	unsigned* teams = new unsigned[i];
	memset(teams, 0, i * sizeof(unsigned));
	for (unsigned j = 0; j < i; j++)
		for (unsigned k = 0; k < routes[j].vias.size(); k++)
			teams[j] += team[routes[j].vias[k]];
	sort(teams, teams + i);
	cout << i << ' ' << teams[i - 1];
	return 0;
}

