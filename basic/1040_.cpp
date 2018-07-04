// 1040-分治.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


unsigned count_one(const string::iterator& start, const string::iterator& termi, const char c) {
	unsigned res = 0;
	for (auto i = start; i != termi; i++)
		if (*i == c) res++;
	return res;
}

unsigned count_two(const string::iterator& start, const string::iterator& termi, const char a, const char b) {
	switch (termi - start) {
	case 1: return 0;
	case 2: if (*start == a && *(start + 1) == b) return 1;
			else return 0;
	default: {
		unsigned left_res = count_two(start, (termi - start) / 2 + start, a, b);
		unsigned right_res = count_two((termi - start) / 2 + start, termi, a, b);
		unsigned left_a = count_one(start, (termi - start) / 2 + start, a);
		unsigned right_b = count_one((termi - start) / 2 + start, termi, b);
		return left_res + right_res + left_a * right_b;
			 }
	}
}

unsigned count_three(const string::iterator& start, const string::iterator& termi, const char a, const char b, const char c) {
	switch (termi - start) {
	case 1: return 0;
	case 2: return 0;
	case 3: if (*start == a && *(start + 1) == b && *(start + 2) == c) return 1;
			else return 0;
	default: {
		unsigned left_res = count_three(start, (termi - start) / 2 + start, a, b, c);
		unsigned right_res = count_three((termi - start) / 2 + start, termi, a, b, c);
		unsigned left_ab = count_two(start, (termi - start) / 2 + start, a, b);
		unsigned right_c = count_one((termi - start) / 2 + start, termi, c);
		unsigned left_a = count_one(start, (termi - start) / 2 + start, a);
		unsigned right_bc = count_two((termi - start) / 2 + start, termi, b, c);
		unsigned res = (left_res + right_res + left_ab * right_c + left_a * right_bc) % 1000000007;
		return res;
			 }
	}
}


int main()
{
	string str; cin >> str;
	cout << count_three(str.begin(), str.end(), 'P', 'A', 'T');
	return 0;
}

