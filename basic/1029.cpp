// 1029.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;


int main()
{
	string str, broken;
	cin >> str >> broken;
	transform(str.begin(), str.end(), str.begin(), toupper);
	transform(broken.begin(), broken.end(), broken.begin(), toupper);
	set<char> str_chars, broken_chars;
	for (auto i = str.begin(); i != str.end(); i++) str_chars.insert(*i);
	for (auto i = broken.begin(); i != broken.end(); i++) broken_chars.insert(*i);
	set_difference(str_chars.begin(), str_chars.end(), broken_chars.begin(), broken_chars.end(), ostream_iterator<char>(cout));
	return 0;
}

