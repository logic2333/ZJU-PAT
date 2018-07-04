// 1020.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


struct mc {
	float storage, tprice, sprice, amount;
	bool operator<(const mc& another) const {
		return sprice < another.sprice;
	}
	void get_sprice() {
		sprice = tprice / storage;
	}
	float profit() {
		return amount * sprice;
	}
};


int main()
{
	unsigned N, D; cin >> N >> D;
	vector<mc> mcs(N);
	for (unsigned i = 0; i < N; i++) cin >> mcs[i].storage;
	for (unsigned i = 0; i < N; i++) cin >> mcs[i].tprice;
	for (unsigned i = 0; i < N; i++) mcs[i].get_sprice();
	sort(mcs.begin(), mcs.end());
	for (unsigned i = N - 1; i > 0; i--) {
		if (mcs[i].storage >= D) mcs[i].amount = D; 
		else mcs[i].amount = mcs[i].storage; 
		mcs[i].storage -= mcs[i].amount; D -= mcs[i].amount;
	}
	float tprofit = 0.0;
	for (unsigned i = 0; i < N; i++)
		tprofit += mcs[i].profit();
	cout << fixed << setprecision(2) << tprofit;
	return 0;
}

