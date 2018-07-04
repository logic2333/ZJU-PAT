// 1047.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	unsigned N, K; cin >> N >> K;
	vector<set<string>> res(K);
	for (unsigned i = 0; i < N; i++) {
		string name; unsigned C;
		cin >> name >> C;
		for (unsigned j = 0; j < C; j++) {
			unsigned course_code; cin >> course_code;
			res[course_code - 1].insert(name);
		}
	}
	for (unsigned i = 0; i < K; i++) {
		cout << i + 1 << ' ' << res[i].size() << endl;
		copy(res[i].begin(), res[i].end(), ostream_iterator<string>(cout, "\n"));
	}
	return 0;
}

