// 1037.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;


int main()
{
	unsigned N, K; cin >> N;
	map<unsigned, unsigned> recs;
	for (; N > 0; N--) {
		unsigned tmp; cin >> tmp;
		recs[tmp]++;
	}
	cin >> K; unsigned* q = new unsigned[K];
	for (unsigned i = 0; i < K; i++) cin >> q[i];
	for (unsigned i = 0; i < K; i++) {
		cout << recs[q[i]];
		if (i < K - 1) cout << ' ';
	}
	return 0;
}

