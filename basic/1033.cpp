// 1033.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string brk_keys, ori; 
	getline(cin, brk_keys);
	getline(cin, ori);
	int findp = brk_keys.find('+');
	if (findp != -1) {
		for (auto i = ori.begin(); i != ori.end();)
			if ('A' <= *i && *i <= 'Z') i = ori.erase(i);
			else i++;
		brk_keys.erase(findp, 1);
	}
	for (auto i = brk_keys.begin(); i != brk_keys.end(); i++)
		if ('A' <= *i && *i <= 'Z') brk_keys.push_back(*i + 'a' - 'A');
	for (auto i = brk_keys.begin(); i != brk_keys.end(); i++)
		for (auto j = ori.begin(); j != ori.end();)
			if (*j == *i) j = ori.erase(j);
			else j++;
	cout << ori << endl;
	return 0;
}

