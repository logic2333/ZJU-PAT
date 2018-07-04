// 1037.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
using namespace std;

int main()
{
	unsigned NC, NP; cin >> NC;
	set<unsigned> pos_coups; set<int> neg_coups;
	for (unsigned i = 0; i < NC; i++) {
		int ipt; cin >> ipt;
		if (ipt > 0) pos_coups.insert(ipt);
		else neg_coups.insert(ipt);
	}
	cin >> NP; 
	set<unsigned> pos_prods; set<int> neg_prods;
	for (unsigned i = 0; i < NP; i++) {
		int ipt; cin >> ipt;
		if (ipt > 0) pos_prods.insert(ipt);
		else neg_prods.insert(ipt);
	}
	long long res = 0;
	if (!pos_prods.empty()) {
		auto j = pos_prods.rbegin();
		for (auto i = pos_coups.rbegin(); i != pos_coups.rend(); i++) {
			res += *i * *j++;
			if (j == pos_prods.rend()) break;
		}
	}
	if (!neg_prods.empty()) {
		auto k = neg_prods.begin();
		for (auto i = neg_coups.begin(); i != neg_coups.end(); i++) {
			res += *i * *k++;
			if (k == neg_prods.end()) break;
		}
	}
	cout << res;	
	return 0;
}

