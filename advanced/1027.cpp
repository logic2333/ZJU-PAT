// 1027.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;


map<unsigned, char> c;

void init() {
	for (unsigned i = 0; i < 10; i++)
		c[i] = i + '0';
	c[10] = 'A'; c[11] = 'B'; c[12] = 'C';
}

int main()
{
	init();
	unsigned col[3]; cin >> col[0] >> col[1] >> col[2];
	string opt = "#";
	for (unsigned i = 0; i < 3; i++) {
		opt += c[col[i] / 13];
		opt += c[col[i] % 13];
	}
	cout << opt;
	return 0;
}

