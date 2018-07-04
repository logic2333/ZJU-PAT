// 1014.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <iterator>
using namespace std;


struct _time {
	unsigned h, m;
	_time() { h = 8; m = 0; }
	_time(const unsigned _h, const unsigned _m) {
		h = _h; m = _m;
	}
	void operator+=(unsigned min) {
		m += min;
		h += (m / 60);
		m %= 60;
	}
	void out() {
		printf("%02d:%02d\n", h, m);
	}
};

struct _customer {
	unsigned req_time, id;
	_time end_time;
	bool serving;
	_customer(const unsigned time, const unsigned _id) {
		req_time = time; id = _id; end_time = _time(7, 0); serving = false;
	}
};

typedef deque<_customer> list_type;

void queue_up(list_type& all_customers, deque<list_type>& all_windows, unsigned list_capacity, unsigned window_count) {
	while (all_windows[0].size() < list_capacity && !all_customers.empty())
		for (unsigned i = 0; i < window_count; i++) {
			if (all_customers.empty()) break;
			_customer temp = all_customers.front();
			all_customers.pop_front();
			all_windows[i].push_back(temp);
		}
}

bool time_end(const deque<list_type>& all_windows) {
	for (auto i = all_windows.begin(); i != all_windows.end(); i++)
		if (!i->empty()) return false;
	return true;
}

void runtime(list_type& all_customers, deque<list_type>& all_windows, list_type& finished, _time& now) {
	if (now.h >= 17) return;
	if (time_end(all_windows)) return;
	unsigned run_window = 0;
	for (; all_windows[run_window].empty(); run_window++);
	for (unsigned i = 0; i < all_windows.size(); i++)
		if (!all_windows[i].empty())
			if (all_windows[i][0].req_time < all_windows[run_window][0].req_time)
				run_window = i;
	unsigned time_passed = all_windows[run_window][0].req_time;
	now += time_passed;
	for (unsigned i = 0; i < all_windows.size(); i++)
		if (!all_windows[i].empty()) {
			all_windows[i][0].req_time -= time_passed;
			all_windows[i][0].serving = true;
			if (all_windows[i][0].req_time == 0) {
				if (!all_customers.empty()) {
					_customer temp = all_customers.front();
					all_customers.pop_front();
					all_windows[i].push_back(temp);
				}
				all_windows[i][0].end_time = now;
				_customer temp = all_windows[i].front();
				all_windows[i].pop_front(); 
				finished.push_back(temp);
			}
		}
	runtime(all_customers, all_windows, finished, now);
}


int main()
{
	unsigned N, M, K, Q; cin >> N >> M >> K >> Q;
	list_type customers; deque<list_type> all_windows(N);
	list_type finished;
	for (unsigned i = 0; i < K; i++) {
		unsigned ipt; cin >> ipt;
		customers.push_back(_customer(ipt, i + 1));
	}
	queue_up(customers, all_windows, M, N);
	_time n;
	runtime(customers, all_windows, finished, n);
	for (auto i = all_windows.begin(); i != all_windows.end(); i++)
		copy(i->begin(), i->end(), back_inserter(finished));
	for (auto i = finished.begin(); i != finished.end(); i++) 
		if (i->serving && i->end_time.h == 7) {
			_time t = n;
			t += i->req_time;
			i ->end_time = t;
		}
	deque<unsigned> q_customers;
	for (unsigned i = 0; i < Q; i++) {
		unsigned ipt; cin >> ipt;
		q_customers.push_back(ipt);
	}
	for (auto i = q_customers.begin(); i != q_customers.end(); i++) {
		for (auto j = finished.begin(); j != finished.end(); j++)
			if (*i == j->id) {
				if (j->serving) j->end_time.out(); 
				else cout << "Sorry" << endl;
				break;
			}
	}
	return 0;
}

