// 1024.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;


struct num {
	string str;
	bool is_palin() {
		for (unsigned i = 0; i < str.length() / 2; i++)
			if (str[i] != str[str.length() - i - 1]) return false;
		return true;
	}
	num() { str = ""; }
	num reverse() {
		num res;
		for (auto i = str.rbegin(); i != str.rend(); i++)
			res.str += *i;
		return res;
	}
};

istream& operator>>(istream& is, num& n) {
	is >> n.str;
	return is;
}

num operator+(const num& a, const num& b) {
	num res;
	bool jin = false;
	for (int i = a.str.length() - 1; i >= 0; i--) {
		unsigned wei = a.str[i] - '0' + b.str[i] - '0' + jin;
		if (wei > 9) { jin = true; wei -= 10; }
		else jin = false;
		res.str.insert(0, 1, wei + '0');
	}
	if (jin) res.str.insert(0, 1, '1');
	return res;
}

int main()
{
	num N; unsigned T; cin >> N >> T;
	unsigned t = 0;
	for (; t < T; t++)
		if (!N.is_palin()) N = N + N.reverse();
		else break;
	cout << N.str << endl << t;
	return 0;
}

