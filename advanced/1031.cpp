// 1031.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
	string ipt; cin >> ipt;
	unsigned vert = (ipt.length() + 2) / 3;
	unsigned hori = ipt.length() + 2 - 2 * vert;
	string blank(hori - 2, ' ');
	auto i = ipt.begin(); auto j = ipt.rbegin();
	for (unsigned t = 0; t < vert - 1; t++)
		cout << *i++ << blank << *j++ << endl;		
	for (unsigned t = 0; t < hori; t++)
		cout << *i++;
	return 0;
}

