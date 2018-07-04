// 1026.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;


const string ipt = "9 "
"20:52:00 10 0 "
"08:00:00 20 0 "
"08:02:00 30 0 "
"20:51:00 10 0 "
"08:10:00 5 0 "
"08:12:00 10 1 "
"20:50:00 10 0 "
"08:01:30 15 1 "
"20:53:00 10 1 "
"3 1 "
"2";

istringstream is(ipt);


struct _time {
	unsigned h, m, s;
	bool operator<(const _time& another) const {
		if (h < another.h) return true;
		else if (h == another.h) 
			if (m < another.m) return true;
			else if (m == another.m) return s < another.s;
		return false;
	}
	unsigned to_sec() const {
		return h * 3600 + m * 60 + s;
	}
	int operator-(const _time& another) const {
		return int((to_sec() - another.to_sec()) / 60.0 + 0.5);
	}
	_time operator+(const unsigned _min) const {
		_time res = *this;
		res.m += _min;
		if (res.m >= 60) {
			res.h += res.m / 60; res.m %= 60;
		}
	}
};

istream& operator>>(istream& is, _time& t) {
	char maohao;
	is >> t.h >> maohao >> t.m >> maohao >> t.s;
	return is;
}

ostream& operator<<(ostream& os, const _time& t) {
	os << t.h << ':' << t.m << ':' << t.s;
	return os;
}

_time now = { 8, 0, 0 };

struct _player {
	_time serve; unsigned playtime, waittime; bool is_VIP;
};

istream& operator>>(istream& is, _player& p) {
	is >> p.playtime >> p.is_VIP;
	return is;
}

ostream& operator<<(ostream& os, const _player& p) {
	os << p.serve << ' ' << p.waittime;
	return os;
}

struct _table {
	bool is_VIP;
	unsigned served;
	_time release;
	_table() {
		is_VIP = false; 
		served = 0; release = now;
	}
	void occupy(_player& p, const _time& arrive) {
		p.serve = now;
		p.waittime = now - arrive;
		release = now + p.playtime;
		served++;
	}
};


map<_time, _player> players;
vector<_table> tables;

void runtime() {
	auto i = tables.begin(); 
	for (; i != tables.end() && now < i->release; i++) ;
	if (i->is_VIP) {
		auto k = players.begin();
		for (; k != players.end() && !k->second.is_VIP; k++) ;
		if (k != players.end() && k->first < now) i->occupy(k->second, k->first);
	}
	else 
}

int main()
{
	unsigned player_cnt; is >> player_cnt;
	for (unsigned i = 0; i < player_cnt; i++) {
		_time ipt1; _player ipt2; is >> ipt1 >> ipt2;
		players[ipt1] = ipt2;
	}
	unsigned table_cnt; is >> table_cnt;
	tables.resize(table_cnt);
	unsigned VIP_table_cnt; is >> VIP_table_cnt;
	for (unsigned i = 0; i < VIP_table_cnt; i++) {
		unsigned ipt; is >> ipt;
		tables[ipt - 1].is_VIP = true;
	}
	
	return 0;
}

