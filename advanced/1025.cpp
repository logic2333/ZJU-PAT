// 1025.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/*
const string ipts = "2 "
"5 "
"1234567890001 95 "
"1234567890005 100 "
"1234567890003 95 "
"1234567890002 77 "
"1234567890004 85 "
"4 "
"1234567890013 65 "
"1234567890011 25 "
"1234567890014 100 "
"1234567890012 85";*/

struct testee {
	unsigned rnk[2], loca, mark; //rnk[0] - local_rnk, rnk[1] - final_rnk
	string id;
	bool operator<(const testee& another) {
		if (mark > another.mark) return true;
		else if (mark == another.mark) 
			if (id < another.id) return true;
		return false;
	}
};

istream& operator>>(istream& is, testee& t) {
	is >> t.id >> t.mark;
	return is;
}

ostream& operator<<(ostream& os, const testee& t) {
	os << t.id << ' ' << t.rnk[1] << ' ' << t.loca << ' ' << t.rnk[0];
	return os;
}

typedef vector<testee> _loca;

void get_rank(_loca& loc, bool is_all) {
	loc[0].rnk[is_all] = 1;
	for (unsigned i = 1; i < loc.size(); i++)
		if (loc[i].mark == loc[i - 1].mark) loc[i].rnk[is_all] = loc[i - 1].rnk[is_all];
		else loc[i].rnk[is_all] = i + 1;
}

int main()
{
	//istringstream is(ipts);
	unsigned N; cin >> N;//is >> N;
	vector<_loca> locas;
	for (unsigned i = 1; i <= N; i++) {
		unsigned K; cin >> K;//is >> K;
		_loca loc;
		for (unsigned j = 0; j < K; j++) {
			testee ipt; cin >> ipt;//is >> ipt;
			ipt.loca = i;
			loc.push_back(ipt);
		}
		sort(loc.begin(), loc.end());
		get_rank(loc, false);
		locas.push_back(loc);
	}
	_loca all;
	for (auto i = locas.begin(); i != locas.end(); i++)
		copy(i->begin(), i->end(), back_inserter(all));
	sort(all.begin(), all.end());
	get_rank(all, true);
	cout << all.size() << endl;
	copy(all.begin(), all.end(), ostream_iterator<testee>(cout, "\n"));
	return 0;
}

