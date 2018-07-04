// 1040.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	unsigned res = 1;
	string ipt; getline(cin, ipt);
	for (auto i = ipt.begin() + 1; i != ipt.end(); ) {
		unsigned t, temp_res;
		if (*i == *(i - 1)) {
			t = 1;
			do {
				t += 2; i++;
			} while (i - ipt.begin() >= t && i != ipt.end() && *i == *(i - t));
			temp_res = t - 1;
			if (temp_res > res) res = temp_res;
		}
		else if (i - ipt.begin() >= 2 && *i == *(i - 2)) {
			t = 2;
			do {
				t += 2; i++;
			} while (i - ipt.begin() >= t && i != ipt.end() && *i == *(i - t));
			temp_res = t - 1;
			if (temp_res > res) res = temp_res;
		}
		else i++;
	}
	cout << res;
	return 0;
}

