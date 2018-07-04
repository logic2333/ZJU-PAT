// 1005.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

const string read[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	string ipt; cin >> ipt;
	vector<unsigned> digits;
	for (auto i : ipt) digits.push_back(i - '0');
	unsigned sum = accumulate(digits.begin(), digits.end(), 0);
	ipt = to_string(sum);
	digits.clear();
	for (auto i : ipt) digits.push_back(i - '0');
	for (unsigned i = 0; i < digits.size(); i++)
		if (i == digits.size() - 1) cout << read[digits[i]];
		else cout << read[digits[i]] << ' ';
	return 0;
}

