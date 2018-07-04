// 1006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


struct time {
	unsigned h, m, s;
	bool operator<(const time& another) const {
		if (h < another.h) return true;
		else if (h > another.h) return false;
		else
			if (m < another.m) return true;
			else if (m > another.m) return false;
			else
				if (s < another.s) return true;
				else return false;
	}
};

istream& operator>>(istream& is, time& t) {
	is >> t.h;
	char maohao; is >> maohao;
	is >> t.m; is >> maohao;
	is >> t.s;
	return is;
}

struct record {
	string ID;
	time in, out;
};

istream& operator>>(istream& is, record& r) {
	is >> r.ID >> r.in >> r.out;
	return is;
}

bool comp_in(const record& a, const record& b) {
	return a.in < b.in;
}

bool comp_out(const record& a, const record& b) {
	return a.out < b.out;
}

int main()
{
	unsigned rec_num; cin >> rec_num;
	record* recs = new record[rec_num];
	for (unsigned i = 0; i < rec_num; i++)
		cin >> recs[i];
	sort(recs, recs + rec_num, comp_in);
	cout << recs->ID << ' ';
	sort(recs, recs + rec_num, comp_out);
	cout << recs[rec_num - 1].ID;
	return 0;
}

