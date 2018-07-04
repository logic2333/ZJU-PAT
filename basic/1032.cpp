// 1032.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;


int main()
{
	unsigned N; cin >> N;
	map<unsigned, unsigned> scores;
	for (unsigned i = 0; i < N; i++) {
		pair<unsigned, unsigned> ipt;
		cin >> ipt.first >> ipt.second;
		scores[ipt.first] += ipt.second;
	}
	pair<unsigned, unsigned> highest(0, 0);
	for (auto i = scores.begin(); i != scores.end(); i++)
		if (i->second > highest.second) highest = *i;
	cout << highest.first << ' ' << highest.second;
	return 0;
}

