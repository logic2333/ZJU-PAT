// 1043.cpp : 定义控制台程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const char recs[] = { 'P', 'A', 'T', 'e', 's', 't' };

bool all_empty(const map<char, unsigned>& s) {
	for (auto i = s.begin(); i != s.end(); i++)
		if (i->second > 0) return false;
	return true;
}

int main()
{
	string ipt; ipt = "redlesPayBestPATTopTeePHPereatitAPPT";//cin >> ipt;
	map<char, unsigned> cnt;
	for (auto i = ipt.begin(); i != ipt.end(); i++)
		if (find(recs, recs + 6, *i) != recs + 6) cnt[*i]++;
	while (!all_empty(cnt)) {
		for (unsigned i = 0; i < 6; i++)
			if (cnt[recs[i]] > 0) {
				cout << recs[i]; cnt[recs[i]]--;
			}
	}
	return 0;
}


