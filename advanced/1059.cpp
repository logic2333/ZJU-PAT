// 1059.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <sstream>
using namespace std;


int main()
{
	unsigned ipt; cin >> ipt;
	if (ipt == 1) cout << "1=1";
	else {
		unsigned ipt_cpy = ipt;
		map<unsigned, unsigned> factors;
		for (unsigned i = 2; i < ipt; i++)
			while (ipt % i == 0) {
				factors[i]++; ipt /= i;
			}
		if (ipt > 1) factors[ipt]++;
		ostringstream os;
		os << ipt_cpy << '=';
		for (auto i = factors.begin(); i != factors.end(); i++) {
			os << i->first;
			if (i->second > 1) os << '^' << i->second;
			os << '*';
		}
		string opt = os.str();
		opt.erase(opt.begin() + opt.length() - 1);
		cout << opt;
	}
	return 0;
}

