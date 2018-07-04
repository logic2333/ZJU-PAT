// 1016.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

unsigned toll[24], rec_cnt, month;

const string ipt = "10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10 "
"5 "
"aaa 01:01:01:03 on-line "
"aaa 01:02:00:01 on-line "
"CYLL 01:28:15:41 on-line "
"aaa 01:05:02:24 on-line "
"aaa 01:02:00:02 off-line";

struct _time {
	unsigned d, h, m;
	bool operator<(const _time& another) const {
		if (d < another.d) return true;
		else if (d == another.d)
			if (h < another.h) return true;
			else if (h == another.h)
				if (m < another.m) return true;
		return false;	
	}
};

bool within_hour(const _time& a, const _time& b) {
	return (a.d == b.d && a.h == b.h);
}

istream& operator>>(istream& is, _time& t) {
	char maohao; 
	is >> month >> maohao >> t.d >> maohao >> t.h >> maohao >> t.m;
	return is;
}

ostream& operator<<(ostream& os, const _time& t) {
	os << setw(2) << setfill('0') << t.d;
	os << ':';
	os << setw(2) << setfill('0') << t.h;
	os << ':';
	os << setw(2) << setfill('0') << t.m;
	return os;
}

void _hash(_time a, _time b, unsigned dest[24]) {
	if (within_hour(a, b)) dest[a.h] += b.m - a.m;
	else {
		dest[a.h] += 60 - a.m; a.h++;
		for (; a.d < b.d; a.d++) {
			for (; a.h < 24; a.h++) dest[a.h] += 60;
			a.h = 0;
		}
		for (; a.h < b.h; a.h++) dest[a.h] += 60;
		dest[b.h] += b.m;
	}
}

struct _rec {
	string name; _time t; bool online;
	bool operator<(const _rec& another) const {
		return t < another.t;
	}
};

istream& operator>>(istream& is, _rec& r) {
	is >> r.name >> r.t;
	string temp; is >> temp;
	r.online = (temp == "on-line");
	return is;
} 

struct phone {
	_time start, termi; unsigned by_hour[24];
	float fare; unsigned length;
	phone() {}
	phone(const _rec& a, const _rec& b) {
		memset(by_hour, 0, 24 * sizeof(unsigned));
		start = a.t; termi = b.t;
		_hash(start, termi, by_hour);
		fare = inner_product(by_hour, by_hour + 24, toll, 0) / 100.0;
		length = accumulate(by_hour, by_hour + 24, 0);
	}
	bool operator<(const phone& another) const {
		return start < another.start;
	}
};

ostream& operator<<(ostream& os, const phone& p) {
	os << p.start << ' ' << p.termi << ' ' << p.length << " $" << fixed << setprecision(2) << p.fare; 
	return os;
}

struct _person {
	set<phone> phones;
	float total() const {
		float res = 0.0;
		for (auto i = phones.begin(); i != phones.end(); i++)
			res += i->fare;
		return res;
	};
	void add_rec(const _rec& a, const _rec& b) {
		phones.insert(phone(a, b));
	}
};

ostream& operator<<(ostream& os, const _person& p) {
	for (auto i = p.phones.begin(); i != p.phones.end(); i++)
		os << *i << endl;
	os << "Total amount: $" << fixed << setprecision(2) << p.total();
	return os;
}

int main()
{
	istringstream is(ipt);
	for (unsigned i = 0; i < 24; i++) is >> toll[i];
	is >> rec_cnt;
	map<string, set<_rec>> recs;
	for (unsigned i = 0; i < rec_cnt; i++) {
		_rec temp_rec; is >> temp_rec;
		recs[temp_rec.name].insert(temp_rec);
	}
	map<string, _person> people;
	for (auto i = recs.begin(); i != recs.end(); i++) {	
		auto j = i->second.begin(); 
		for (; !j->online; j++);
		auto k = j; k++;
		for (; k != i->second.end(); j++, k++)
			if (j->online && !k->online)
				people[i->first].add_rec(*j, *k);	
	}
	for (auto i = people.begin(); i != people.end(); i++)
		cout << i->first << ' ' << setw(2) << setfill('0') << month << endl << i->second << endl;
	return 0;
}

