// 1029_.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void upper(char& c) {
	if ('a' <= c && c <= 'z') c -= 'a' - 'A';
}

void out(const char& c) {
	cout << c;
}

int main()
{
	string ori, brk; cin >> ori >> brk;
	//ori = "lnglabglaebg3o30gb3bhlkbhglkwbhklwehgeghehrhw54u5j54j54j4";
	//brk = "ngabgabgo0gbbbgbgg";
	for_each(ori.begin(), ori.end(), upper);
	for_each(brk.begin(), brk.end(), upper);
	auto i = ori.begin(); auto j = brk.begin();
	vector<char> brk_keys;
	for (; j != brk.end(); j++, i++)
		for (; *i != *j; i++)
			if (find(brk_keys.begin(), brk_keys.end(), *i) == brk_keys.end())
				brk_keys.push_back(*i);
	for (; i != ori.end(); i++)
		if (find(brk_keys.begin(), brk_keys.end(), *i) == brk_keys.end())
				brk_keys.push_back(*i);
	for_each(brk_keys.begin(), brk_keys.end(), out);
	return 0;
}

