// 1036.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct money {
	int g, s, k;
	bool operator<(const money& another) const {
		if (g < another.g) return true;
		else if (g == another.g)
			if (s < another.s) return true;
			else if (s == another.s)
				if (k < another.k) return true;
		return false;
	}
	void simplify() {
		if (k > 28) {
			s += k / 29;
			k %= 29;
		}
		if (s > 16) {
			g += s / 17;
			s %= 17;
		}
	}
};

istream& operator>>(istream& is, money& m) {
	char p;
	is >> m.g >> p >> m.s >> p >> m.k;
	return is;
}

ostream& operator<<(ostream& os, const money& m) {
	os << m.g << '.' << m.s << '.' << m.k;
	return os;
}

money operator-(const money& a, const money& b) {
	money res;
	res.k = a.k - b.k + 29;
	res.s = a.s - b.s + 16;
	res.g = a.g - b.g - 1;
	res.simplify();
	return res;
}


int main()
{
	money a, b; cin >> a >> b;
	if (a < b) cout << b - a;
	else cout << '-' << a - b;
	return 0;
}

