// 1001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int a, b, resnum;
	cin >> a >> b;
	resnum = a + b;
	string res = to_string(resnum);
	unsigned len = res.length();
	for (int i = len - 3; i > 0; i -= 3)
		if (res[i - 1] != '-') res.insert(i, ",");
	cout << res;
	return 0;
}

