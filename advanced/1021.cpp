// 1021.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;


void opt_largest(const vector<vector<int>>& con) {
	set<unsigned> res;
	int tmp = con[0][0];
	for (unsigned i = 0; i < con.size(); i++)
		for (unsigned j = 0; j < con[i].size(); j++)
			if (con[i][j] > tmp)
				tmp = con[i][j];
	for (unsigned i = 0; i < con.size(); i++)
		for (unsigned j = 0; j < con[i].size(); j++)
			if (con[i][j] == tmp) {
				res.insert(i + 1); res.insert(j + 1);
			}
	copy(res.begin(), res.end(), ostream_iterator<unsigned>(cout, "\n"));
}

typedef pair<unsigned, unsigned> edge_type;

int main()
{
	unsigned N; cin >> N;
	vector<vector<int>> dist;
	for (unsigned i = 0; i < N; i++)
		dist.push_back(vector<int>(N));
	for (unsigned i = 0; i < N; i++)
		for (unsigned j = 0; j < N; j++)
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = -1;
	vector<edge_type> edges(N - 1);
	for (unsigned i = 0; i < N - 1; i++) {
		cin >> edges[i].first >> edges[i].second;
		edges[i].first--; edges[i].second--;
	}
	vector<set<unsigned>> zhis(N);
	for (unsigned i = 0; i < N; i++)
		zhis[i].insert(i);
	for (auto j = edges.begin(); j != edges.end(); j++) {
		unsigned first_zhi, second_zhi;
		for (unsigned i = 0; i < zhis.size(); i++) {
			if (find(zhis[i].begin(), zhis[i].end(), j->first) != zhis[i].end())
				first_zhi = i;
			if (find(zhis[i].begin(), zhis[i].end(), j->second) != zhis[i].end())
				second_zhi = i;
		}
		if (first_zhi != second_zhi) {
			dist[j->first][j->second] = dist[j->second][j->first] = 1;
			for (auto i = zhis[first_zhi].begin(); i != zhis[first_zhi].end(); i++)
				for (auto t = zhis[second_zhi].begin(); t != zhis[second_zhi].end(); t++)
					if (dist[*i][*t] < 0 || dist[*i][*t] > dist[j->first][*i] + 1 + dist[j->second][*t])
						dist[*t][*i] = dist[*i][*t] = dist[j->first][*i] + 1 + dist[j->second][*t];
			set<unsigned> res;
			set_union(zhis[first_zhi].begin(), zhis[first_zhi].end(), zhis[second_zhi].begin(), zhis[second_zhi].end(), inserter(res, res.begin()));
			if (second_zhi < first_zhi) {
				zhis.erase(zhis.begin() + first_zhi); zhis.erase(zhis.begin() + second_zhi);
			}
			else {
				zhis.erase(zhis.begin() + second_zhi); zhis.erase(zhis.begin() + first_zhi);
			}
			zhis.push_back(res);
		}
	}
	if (zhis.size() > 1) cout << "Error: " << zhis.size() << " components";
	else opt_largest(dist);
	return 0;
}
