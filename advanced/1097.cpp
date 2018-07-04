// 1097.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
//#include <sstream>
#include <set>
#include <map>
#include <deque>
using namespace std;
/*
const string ipt = "00100 5 "
"99999 -7 87654 "
"23854 -15 00000 "
"87654 15 -1 "
"00000 -15 99999 "
"00100 21 23854";
istringstream is(ipt);
*/

struct _node {
	int next; int val; bool to_delete;
};

istream& operator>>(istream& is, _node& n) {
	is >> n.val >> n.next;
	n.to_delete = false;
	return is;
}

ostream& operator<<(ostream& os, const _node& n) {
	os << n.val << ' ';
	if (n.next != -1) os << setw(5) << setfill('0') << n.next;
	else os << n.next;
	return os;
}

void out_link(const deque<pair<int, _node>>& l) {
	for (auto i = l.begin(); i != l.end(); i++) {
		if (i->first != -1) cout << setw(5) << setfill('0') << i->first;
		else cout << i->first;
		cout << ' ' << i->second << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	unsigned start; unsigned N;
	cin >> start >> N;
	map<int, _node> ori_ipt;
	for (unsigned i = 0; i < N; i++) {
		int addr; _node ipt; 
		cin >> addr >> ipt;
		ori_ipt[addr] = ipt;
	}
	deque<pair<int, _node>> link, relink;
	set<unsigned> exist_val;
	while (start != -1) {
		_node& tmp = ori_ipt[start];
		if (exist_val.count(abs(tmp.val))) {
			if (!relink.empty()) relink.back().second.next = start;
			relink.push_back(make_pair(start, tmp));
		}
		else {
			exist_val.insert(abs(tmp.val));
			if (!link.empty()) link.back().second.next = start;
			link.push_back(make_pair(start, tmp));
		}
		start = tmp.next;
	}
	link.back().second.next = -1;
	if (!relink.empty()) relink.back().second.next = -1;
	out_link(link); out_link(relink);
	return 0;
}

