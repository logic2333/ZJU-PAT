// 1015.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> case_type;


bool is_prime(const unsigned t) {
	if (t == 1) return false;
	for (unsigned i = 2; i * i <= t; i++) 
		if (t % i == 0) return false;
	return true;
}

unsigned radix_change(case_type& c) {
	string t;
	while (c.first >= c.second) {
		t.push_back(c.first % c.second + '0');
		c.first /= c.second;
	}
	t.push_back(c.first + '0');
	unsigned res = 0;
	for (unsigned i = 0; i < t.length(); i++)
		res += (t[i] - '0') * pow(float(c.second), int(t.length() - i - 1));
	return res;
}

int main()
{
	vector<case_type> cases;
	while (true) {
		case_type ipt;
		cin >> ipt.first;
		if (ipt.first < 0) break;
		cin >> ipt.second;
		cases.push_back(ipt);
	}
	for (auto i = cases.begin(); i != cases.end(); i++) {
		if (!is_prime(i->first)) cout << "No" << endl;
		else {
			unsigned t = radix_change(*i);
			if (is_prime(t)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}

