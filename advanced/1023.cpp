// 1023.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include <deque>
using namespace std;

map<char, char> multitable;

void init() {
	multitable['0'] = '0';
	multitable['1'] = '2';
	multitable['2'] = '4';
	multitable['3'] = '6';
	multitable['4'] = '8';
	multitable['5'] = '0';
	multitable['6'] = '2';
	multitable['7'] = '4';
	multitable['8'] = '6';
	multitable['9'] = '8';
}

string _double(const string& ipt) {
	deque<char> res; bool jin = false;
	for (auto i = ipt.rbegin(); i != ipt.rend(); i++) {
		res.push_front(multitable[*i] + jin);
		if (*i > '4') jin = true;
		else jin = false;
	}
	if (jin) res.push_front('1');
	return string(res.begin(), res.end());
}

int main()
{
	init();
	string ipt_str; cin >> ipt_str;
	string opt_str = _double(ipt_str);
	map<char, unsigned> ipt_map, opt_map;
	for (auto i = ipt_str.begin(); i != ipt_str.end(); i++)
		ipt_map[*i]++;
	for (auto i = opt_str.begin(); i != opt_str.end(); i++)
		opt_map[*i]++;
	bool res = true;
	for (char i = '0'; i <= '9'; i++)
		if (ipt_map[i] != opt_map[i]) {
			res = false; break;
		}
	if (res) cout << "Yes";
	else cout << "No";
	cout << endl << opt_str;
	return 0;
}

