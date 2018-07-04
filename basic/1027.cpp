// 1027.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <string>
#include <iterator>
#include <numeric>
using namespace std;


int main()
{
	unsigned N; char c;
	cin >> N >> c;
	deque<unsigned> each_line_c; each_line_c.push_back(1);
	unsigned c_used = 1, c_used_2 = 7, left;
	for (unsigned i = 5; c_used_2 <= N; i += 2) {
		each_line_c.push_back(i - 2);
		c_used = c_used_2; c_used_2 += 2 * i; 
	}
	left = N - c_used; unsigned max_line_c = each_line_c.back();
	copy(each_line_c.begin() + 1, each_line_c.end(), front_inserter(each_line_c));
	for (auto i = each_line_c.begin(); i != each_line_c.end(); i++)
		cout << string((max_line_c - *i) / 2, ' ') << string(*i, c) << endl;
	cout << left;
	return 0;
}

