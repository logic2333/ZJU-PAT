// 1042.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
	string ipt; getline(cin, ipt);
	for (auto i = ipt.begin(); i != ipt.end(); i++)
		if ('A' <= *i && *i <= 'Z') *i += 'a' - 'A';
	map<char, unsigned> recs;
	for (auto i = ipt.begin(); i != ipt.end(); i++)
		if ('a' <= *i && *i <= 'z') recs[*i]++;
	char largest = recs.begin()->first;
	for (auto i = recs.begin(); i != recs.end(); i++)
		if (i->second > recs[largest]) largest = i->first;
	cout << largest << ' ' << recs[largest];
	return 0;
}

