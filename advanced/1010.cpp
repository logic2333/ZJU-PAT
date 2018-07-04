// 1010.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


unsigned to_dec(const string& str, const unsigned r) {
	unsigned res = 0;
	for (unsigned i = 0; i < str.length(); i++)
		if (str[i] >= '0' && str[i] <= '9')
			res += (str[i] - '0') * pow(float(r), int(str.length() - i - 1));
		else res += (str[i] - 'a' + 10) * pow(float(r), int(str.length() - i - 1));
	return res;
}

unsigned get_lowest_radix(const string& str) {
	char max = str[0];
	for (unsigned i = 0; i < str.length(); i++)
		if (str[i] > max) max = str[i];
	unsigned res;
	if (max >= '1' && max <= '9') res = max - '0' + 1;
	else res = max - 'a' + 11;
	return res;
}

int main()
{
	unsigned tag, radix; string str_n1, str_n2;
	cin >> str_n1 >> str_n2 >> tag >> radix;
	unsigned known, unknown = 0;
	if (tag == 1) {
		known = to_dec(str_n1, radix);
		unsigned r = get_lowest_radix(str_n2);
		if (str_n2.length() == 1) 
			if (str_n2[0] >= '1' && str_n2[0] <= '9')
				if (str_n2[0] - '0' == known) cout << r;
				else cout << "Impossible";
			else if (str_n2[0] - 'a' + 10 == known) cout << r;
				else cout << "Impossible";
		else {
			for (; unknown < known; r++) unknown = to_dec(str_n2, r);
			if (unknown == known) cout << --r;
			else cout << "Impossible";
		}
	}
	else {
		known = to_dec(str_n2, radix);
		unsigned r = get_lowest_radix(str_n1);
		if (str_n1.length() == 1) 
			if (str_n1[0] >= '1' && str_n1[0] <= '9')
				if (str_n1[0] - '0' == known) cout << r;
				else cout << "Impossible";
			else if (str_n1[0] - 'a' + 10 == known) cout << r;
				else cout << "Impossible";
		else {
			for (; unknown < known; r++) unknown = to_dec(str_n1, r);
			if (unknown == known) cout << --r;
			else cout << "Impossible";
		}
	}
	return 0;
}


