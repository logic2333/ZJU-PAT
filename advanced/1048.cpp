// 1048.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
using namespace std;


int main()
{
	unsigned N, M; cin >> N >> M;
	multiset<unsigned> coins;
	for (unsigned i = 0; i < N; i++) {
		unsigned ipt; cin >> ipt;
		coins.insert(ipt);
	}
	int res = -1;
	if (M > 2 * *coins.begin() && M < 2 * *coins.rbegin())
		for (auto i = coins.begin(); i != coins.end(); i++) {
			auto j = coins.find(M - *i);
			if (j != coins.end() && j != i) {
				res = *i; break;
			}
		}
	if (res == -1) cout << "No Solution";
	else cout << res << ' ' << M - res;
	return 0;
}

