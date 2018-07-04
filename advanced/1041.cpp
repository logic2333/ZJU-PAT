// 1041.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;


int main()
{
	unsigned N; cin >> N;
	list<pair<unsigned, bool>> bets;
	for (unsigned i = 0; i < N; i++) {
		pair<unsigned, bool> ipt; 
		cin >> ipt.first; ipt.second = true;
		for (auto j = bets.begin(); j != bets.end(); j++)
			if (j->first == ipt.first) { 
				j->second = false;
				ipt.second = false;
				break;
			}
		if (ipt.second) bets.push_back(ipt);
	}
	for (auto i = bets.begin(); i != bets.end(); i++)
		if (i->second) { 
			cout << i->first; 
			return 0;
		}
	cout << "None"; 
	return 0;
}

