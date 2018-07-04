// 1039.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

/*
const string ipt = "11 5 "
"4 7 "
"BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1 "
"1 4 "
"ANN0 BOB5 JAY9 LOR6 "
"2 7 "
"ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6 "
"3 1 "
"BOB5 "
"5 9 "
"AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1 "
"ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9";

istringstream is(ipt);*/

int main()
{
	unsigned N, K; cin >> N >> K;
	vector<vector<string>> courses(K);
	for (unsigned j = 0; j < K; j++) {
		unsigned i, Ni; cin >> i >> Ni;
		courses[i - 1].resize(Ni);
		for (unsigned k = 0; k < Ni; k++)
			cin >> courses[i - 1][k];
	}
	for (unsigned i = 0; i < N; i++) {
		string name; cin >> name;
		vector<unsigned> query;
		for (unsigned j = 0; j < K; j++)
			if (find(courses[j].begin(), courses[j].end(), name) != courses[j].end())
				query.push_back(j + 1);
		cout << name << ' ' << query.size();
		for (auto j = query.begin(); j != query.end(); j++)
			cout << ' ' << *j;
		cout << endl;
	}
	return 0;
}

