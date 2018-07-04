// 1034.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct fenshu {
	int fenzi, fenmu;
	void yuefen() {
		fenzi = abs(fenzi);
		unsigned max = (fenzi > fenmu ? fenzi : fenmu);
		for (unsigned i = 2; i <= max; i++) 
			while (fenzi % i == 0 && fenmu % i == 0) {
				fenzi /= i; fenmu /= i;
			}
	}
};

istream& operator>>(istream& is, fenshu& fs) {
	char gang;
	is >> fs.fenzi >> gang >> fs.fenmu;
	return is;
}

fenshu operator+(const fenshu& a, const fenshu& b) {
	fenshu res;
	if (a.fenmu == b.fenmu) {
		res.fenmu = a.fenmu;
		res.fenzi = a.fenzi + b.fenzi;
	}
	else {
		res.fenmu = a.fenmu * b.fenmu;
		res.fenzi = a.fenmu * b.fenzi + a.fenzi * b.fenmu;
	}
	return res;
}

fenshu operator-(const fenshu& a, const fenshu& b) {
	fenshu res;
	if (a.fenmu == b.fenmu) {
		res.fenmu = a.fenmu;
		res.fenzi = a.fenzi - b.fenzi;
	}
	else {
		res.fenmu = a.fenmu * b.fenmu;
		res.fenzi = - b.fenzi * a.fenmu + a.fenzi * b.fenmu;
	}
	return res;
}

fenshu operator*(const fenshu& a, const fenshu& b) {
	fenshu res;
	res.fenmu = a.fenmu * b.fenmu;
	res.fenzi = a.fenzi * b.fenzi;
	return res;
}

fenshu operator/(const fenshu& a, const fenshu& b) {
	fenshu res;
	res.fenmu = a.fenmu * abs(b.fenzi);
	res.fenzi = a.fenzi * b.fenmu;
	if (b.fenzi < 0) res.fenzi *= -1;
	return res;
}

ostream& operator<<(ostream& os, const fenshu& fs) {
	unsigned zheng = 0; int fenzi = fs.fenzi;
	if (abs(fs.fenzi) >= fs.fenmu) {
		zheng = abs(fs.fenzi) / fs.fenmu;
		fenzi = fs.fenzi % fs.fenmu;
	}
	if (fs.fenzi < 0) os << "(-";
	if (zheng != 0 || fenzi == 0) os << zheng;
	if (zheng != 0 && fenzi != 0) os << ' ';
	fenshu after_yue; after_yue.fenzi = fenzi; after_yue.fenmu = fs.fenmu;
	after_yue.yuefen();
	if (after_yue.fenzi != 0)
		os << after_yue.fenzi << '/' << after_yue.fenmu;
	if (fs.fenzi < 0) os << ')';
	return os;
}


int main()
{
	fenshu a, b; cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = ";
	if (b.fenzi == 0) cout << "Inf";
	else cout << a / b;
	return 0;
}

