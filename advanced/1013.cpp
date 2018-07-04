// 1013.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
typedef pair<unsigned, unsigned> edge_type;

struct zhi {
	set<unsigned> points;
	zhi() {}
	zhi(const unsigned point) {
		points.insert(point);
	}
	zhi(const edge_type& edge) {
		points.insert(edge.first); points.insert(edge.second);
	}
	unsigned _search(const edge_type& edge) const {
		unsigned res = 0;
		if (find(points.begin(), points.end(), edge.first) != points.end()) res++;
		if (find(points.begin(), points.end(), edge.second) != points.end()) res++;
		return res;
	}
	bool operator==(const zhi& another) const {
		return points == another.points;
	}
};

void _merge(zhi& one, zhi& another, deque<zhi>& g) {
	zhi new_zhi;
	set_union(one.points.begin(), one.points.end(), another.points.begin(), another.points.end(), inserter(new_zhi.points, new_zhi.points.begin()));
	for (auto i = g.begin(); i != g.end();)
		if (*i == one || *i == another) i = g.erase(i);
		else i++;
	g.push_back(new_zhi);
}

struct graph {
	deque<zhi> zhis;
	graph(const unsigned N) {
		for (unsigned i = 0; i < N; i++)
			zhis.emplace_back(i + 1);
	}
	void search(const edge_type& edge) {
		deque<unsigned> res;
		for (unsigned i = 0; i < zhis.size(); i++) 
			if (zhis[i]._search(edge) > 0) res.push_back(i);
		if (res.size() == 2)
			_merge(zhis[res[0]], zhis[res[1]], zhis); 
	}
	void delet(const unsigned t) {
		for (auto i = zhis.begin(); i != zhis.end();)
			if (*(i->points.begin()) == t) i = zhis.erase(i);
			else i++;
	}
};


int main()
{
	unsigned N, M, K; cin >> N >> M >> K;
	deque<edge_type> edges(M);
	for (unsigned i = 0; i < M; i++) {
		edge_type edge;
		cin >> edge.first >> edge.second;
		edges[i] = edge;
	}
	deque<unsigned> expoints(K);
	for (unsigned i = 0; i < K; i++) 
		cin >> expoints[i];
	graph ori_g(N);
	for (auto i = expoints.begin(); i != expoints.end(); i++) {
		graph g = ori_g; g.delet(*i);
		for (auto j = edges.begin(); j != edges.end(); j++)
			if (j->first != *i && j->second != *i) g.search(*j);
		cout << g.zhis.size() - 1 << endl;
	}
	return 0;
}