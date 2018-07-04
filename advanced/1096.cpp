// 1096.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;


int main()
{
	unsigned ipt; cin >> ipt;
	unsigned i = 2;
	for (; i < ipt; i++)
		if (ipt % i == 0) break;
	unsigned tmp = ipt / i;
	list<unsigned> ares; ares.push_back(i);
	list<unsigned> res = ares;
	unsigned max_size = res.size();
	for (unsigned j = i + 1; j <= ipt; j++)
		if (tmp % j == 0) {
			ares.push_back(j);
			tmp /= j;
		}
		else { 
			tmp = ipt;
			if (!ares.empty()) {
				if (ares.size() > max_size) { 
					max_size = ares.size();
					res = ares;
				}
				ares.clear();
			}
		}
	cout << res.size() << endl;
	ostringstream os;
	copy(res.begin(), res.end(), ostream_iterator<unsigned>(os, "*"));
	string opt = os.str();
	opt.erase(opt.begin() + opt.length() - 1);
	cout << opt;
	return 0;
}

