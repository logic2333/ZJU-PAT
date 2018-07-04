// 1052.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

/*
const string ipt = "5 00001 "
"11111 100 -1 "
"00001 0 22222 "
"33333 100000 11111 "
"12345 -1 33333 "
"22222 1000 12345";

istringstream is(ipt);*/

struct node {
	string addr, next;
	int key;
	bool operator<(const node& another) const {
		return key < another.key;
	}
};

istream& operator>>(istream& is, node& n) {
	is >> n.addr >> n.key >> n.next;
	return is;
}

ostream& operator<<(ostream& os, const node& n) {
	os << n.addr << ' ' << n.key << ' ' << n.next;
	return os;
}

int main()
{
	unsigned N; string head; cin >> N >> head;
	vector<node> ipt(N);
	for (auto i = ipt.begin(); i != ipt.end(); i++) cin >> *i;
	vector<node> nodes;
	for (auto i = ipt.begin(); i != ipt.end(); )
		if (head == "-1") break;
		else if (i->addr == head) { 
			nodes.push_back(*i); 
			head = i->next; 
			i = ipt.begin();
		}
		else i++;
	if (nodes.empty()) cout << "0 -1";
	else {
		sort(nodes.begin(), nodes.end());
		for (unsigned i = 0; i < nodes.size() - 1; i++)
			nodes[i].next = nodes[i + 1].addr;
		nodes.back().next = "-1";	
		cout << nodes.size() << ' ' << nodes[0].addr << endl;
		copy(nodes.begin(), nodes.end(), ostream_iterator<node>(cout, "\n"));
	}
	return 0;
}

