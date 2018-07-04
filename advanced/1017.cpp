// 1017.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <numeric>
#include <iterator>
#include <sstream>
using namespace std;


const string test = "2 3 "
"07:55:00 16 "
//"17:00:01 2 "
//"07:59:59 15 "
//"08:01:00 60 "
//"08:00:00 30 "
//"08:00:02 2 "
"08:03:00 10";


struct _time {
	unsigned h, m, s;
	_time() { h = m = s = 0; }
	_time(const unsigned _h, const unsigned _m, const unsigned _s) {
		h = _h; m = _m; s = _s;
	}
	void formalize() {
		if (s > 60) {
			m += s / 60;
			s %= 60;
		}
		if (m > 60) {
			h += m / 60;
			m %= 60;
		}
	}
	bool operator<(const _time& another) const {
		if (h < another.h) return true;
		else if (h == another.h)
			if (m < another.m) return true;
			else if (m == another.m)
				if (s < another.s) return true;
		return false;
	}
	float to_min() {
		return h * 60 + m + s / 60.0;
	}
	_time operator+(const unsigned min) {
		_time res = *this;
		res.m += min;
		res.formalize();
		return res;
	}
};

istream& operator>>(istream& is, _time& t) {
	char maohao;
	is >> t.h >> maohao >> t.m >> maohao >> t.s;
	return is;
}

float operator-(_time a, _time b) {
	_time res;
	if (a.h == b.h && a.m == b.m)
		res.s = a.s - b.s;
	else {
		res.s = 60 - b.s;
		b.s = 0; b.m++;
		if (a.h == b.h) res.m = a.m - b.m;
		else {
			res.m = 60 - b.m; 
			b.m = 0; b.h++;
			res.h = a.h - b.h; 
			res.m += a.m;
		}
		res.s += a.s;
	}
	return res.to_min();
} 

struct _person {
	_time arrive_time, finish_time;
	unsigned serve_time;
	float wait_time;
	bool valid() {
		if (arrive_time.h > 17) return false;
		else if (arrive_time.h == 17) 
			if (arrive_time.m > 0 || arrive_time.s > 0) return false;
		return true;
	}
	bool operator<(const _person& another) const {
		return arrive_time < another.arrive_time;
	}
};

istream& operator>>(istream& is, _person& p) {
	is >> p.arrive_time >> p.serve_time;
	if (p.serve_time > 60) p.serve_time = 60;
	if (p.arrive_time.h >= 8) p.wait_time = 0.0;
	else p.wait_time = _time(8, 0, 0) - p.arrive_time;
	return is;
}

void queue_up(set<_person>& q, vector<_person>& w) {
	for (unsigned i = 0; i < w.size(); i++) {
		if (q.empty()) return;
		w[i] = *q.begin();
		q.erase(q.begin());
		w[i].finish_time = _time(8, 0, 0) + w[i].serve_time;
	}
}

void runtime(_time& now, set<_person>& q, vector<_person>& w, vector<_person>& e) {
	unsigned earliest_window = 0;
	for (unsigned i = 0; i < w.size(); i++)
		if (w[i].finish_time < w[earliest_window].finish_time) earliest_window = i;
	now = w[earliest_window].finish_time;
	e.push_back(w[earliest_window]);
	if (q.empty() || now.h >= 17) return;
	w[earliest_window] = *q.begin();
	w[earliest_window].wait_time = now - w[earliest_window].arrive_time;
	w[earliest_window].finish_time = now + w[earliest_window].serve_time;
	q.erase(q.begin());
}

int main()
{
	istringstream is(test);
	unsigned N, K; is >> N >> K;
	set<_person> waiting_customers;
	for (unsigned i = 0; i < N; i++) {
		_person ipt; is >> ipt;
		if (ipt.valid()) waiting_customers.insert(ipt);
	}
	float res = 0.0;
	if (waiting_customers.size() <= K) {
		for (auto i = waiting_customers.begin(); i != waiting_customers.end(); i++)
			res += i->wait_time;
		cout << fixed << setprecision(1) << res / waiting_customers.size();
	}
	else {
		vector<_person> windows(K);
		queue_up(waiting_customers, windows);
		_time n(8, 0, 0); vector<_person> finished_customers;
		while (n.h < 17 && !waiting_customers.empty())
			runtime(n, waiting_customers, windows, finished_customers);
		copy(windows.begin(), windows.end(), back_inserter(finished_customers));
		for (auto i = finished_customers.begin(); i != finished_customers.end(); i++)
			res += i->wait_time;
		cout << fixed << setprecision(1) << res / finished_customers.size();
	}
	return 0;
}

