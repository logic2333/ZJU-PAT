// 1054.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
//#include <sstream>
using namespace std;
/*
const string ipt = "5 3 "
"0 0 255 16777215 24 "
"24 24 0 0 24 "
"24 0 24 24 24";

istringstream is(ipt);*/

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	unsigned M, N; cin >> M >> N;
	map<unsigned, unsigned> colors;
	for (unsigned i = 0; i < M * N; i++) {
		unsigned ipt; cin >> ipt;
		colors[ipt]++;
	}
	unsigned dom = colors.begin()->first;
	for (auto i = colors.begin(); i != colors.end(); i++)
		if (i->second > colors[dom]) dom = i->first;
	cout << dom;
	return 0;
}

