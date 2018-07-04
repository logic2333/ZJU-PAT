// 1046.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

typedef pair<unsigned, unsigned> _ipt;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	unsigned N, M; cin >> N;
	vector<unsigned> dist(N);
	for (auto i = dist.begin(); i != dist.end(); i++) cin >> *i;
	cin >> M;
	vector<_ipt> ipts(M);
	for (auto i = ipts.begin(); i != ipts.end(); i++) {
		cin >> i->first >> i->second;
		if (i->first > i->second) swap(i->first, i->second);
	}
	unsigned total = accumulate(dist.begin(), dist.end(), 0);
	vector<unsigned> res(M);
	for (unsigned i = 0; i < M; i++) {
		unsigned temp_res_1 = accumulate(dist.begin() + ipts[i].first - 1, dist.begin() + ipts[i].second - 1, 0);
		unsigned temp_res_2 = total - temp_res_1;
		res[i] = (temp_res_1 > temp_res_2 ? temp_res_2 : temp_res_1);
	}
	copy(res.begin(), res.end(), ostream_iterator<unsigned>(cout, "\n"));
	return 0;
}

