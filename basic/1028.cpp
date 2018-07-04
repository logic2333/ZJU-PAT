// 1028.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;


struct _date {
	unsigned y, m, d;
	_date() {}
	_date(const unsigned _y, const unsigned _m, const unsigned _d) {
		y = _y; m = _m; d = _d;
	}
	bool operator<(const _date& another) const {
		if (y < another.y) return true;
		else if (y == another.y) 
			if (m < another.m) return true;
			else if (m == another.m)
				if (d < another.d) return true;
		return false;
	}
	bool valid() const {
		if (*this < _date(1814, 9, 6)) return false;
		return *this < _date(2014, 9, 7);
	}
};

istream& operator>>(istream& is, _date& d) {
	char gang;
	is >> d.y >> gang >> d.m >> gang >> d.d;
	return is;
}

struct _person {
	string name;
	_date birth;
	_person() {}
	bool operator<(const _person& another) const {
		return birth < another.birth;
	}
	bool valid() { return birth.valid(); }
};

istream& operator>>(istream& is, _person& p) {
	is >> p.name >> p.birth;
	return is;
}


int main()
{
	unsigned N; cin >> N;
	set<_person> people;
	for (; N > 0; N--) {
		_person ipt; cin >> ipt;
		if (ipt.valid()) people.insert(ipt);
	}
	if (people.empty()) cout << '0';
	else cout << people.size() << ' ' << people.begin()->name << ' ' << people.rbegin()->name;
	return 0;
}

