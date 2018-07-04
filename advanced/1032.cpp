// 1032.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
const string ipt = "00001 00002 4 "
"00001 a 10001 "
"10001 s -1 "
"00002 a 10002 "
"10002 t -1";

istringstream is(ipt);*/

struct node {
	string addr, next_addr;
	char c;
};

istream& operator>>(istream& is, node& n) {
	is >> n.addr >> n.c >> n.next_addr;
	return is;
}

int main()
{
	string a_begin, b_begin; unsigned N;
	cin >> a_begin >> b_begin >> N;
	vector<node> nodes(N);
	for (unsigned i = 0; i < N; i++) cin >> nodes[i];
	vector<node*> a, b; 
	for (auto i = nodes.begin(); i != nodes.end(); ) {
		if (i->addr == a_begin) { 
			a.push_back(&*i);
			a_begin = i->next_addr;
			i = nodes.begin();
		}
		else if (i->addr == b_begin) { 
			b.push_back(&*i);
			b_begin = i->next_addr;
			i = nodes.begin();
		}
		else i++;
	}
	unsigned i = 0; bool found = false;
	for (; i < a.size(); i++) {
		for (unsigned j = 0; j < b.size(); j++)
			if (a[i] == b[j]) {
				found = true; break;
			}
		if (found) break;
	}
	if (found) cout << a[i]->addr;
	else cout << "-1";
	return 0;
}

