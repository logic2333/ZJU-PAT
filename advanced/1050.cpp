// 1050.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;


int main()
{
	string s1, s2;
	getline(cin, s1); getline(cin, s2);
	set<char> chrs;
	for (auto i = s2.begin(); i != s2.end(); i++)
		chrs.insert(*i);
	for (auto i = s1.begin(); i != s1.end(); ) {
		if (chrs.find(*i) != chrs.end()) i = s1.erase(i);
		else i++;
	}
	cout << s1;
	return 0;
}

