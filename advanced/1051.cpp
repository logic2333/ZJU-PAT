// 1051.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>
#include <set>
//#include <sstream>
using namespace std;

/*
const string ipt = "5 7 5 "
"1 2 3 4 5 6 7 "
"3 2 1 7 5 6 4 "
"7 6 5 4 3 2 1 "
"5 6 4 3 7 2 1 "
"1 7 6 5 4 3 2";

istringstream is(ipt);*/

unsigned M, N;
set<queue<unsigned>> fulls;

struct _node {
	stack<unsigned> now;
	queue<unsigned> seq;
	queue<unsigned> rms;
	_node *left, *right;
	_node(const _node& src) {
		now = src.now; seq = src.seq; rms = src.rms;
		left = right = NULL;
	}
	void edit(const bool is_left) {
		if (!rms.empty()) {
			if (is_left) {
				now.push(rms.front()); rms.pop();
			}
			else {
				seq.push(now.top()); now.pop();
			}
			if (now.size() < M && !rms.empty()) { 
				left = new _node(*this);
				left->edit(true);
			}
			if (!now.empty()) {
				right = new _node(*this);
				right->edit(false);
			}
		}
		else for (; !now.empty(); now.pop()) seq.push(now.top());	
		if (seq.size() == N) fulls.insert(seq);
	}
	_node() {
		now.push(1);
		for (unsigned i = 2; i <= N; i++) rms.push(i);
		left = new _node(*this); right = new _node(*this);
		left->edit(true); 
		right->edit(false);
	}
};

int main()
{
	cin >> M >> N;
	_node tree;
	unsigned qry_cnt; cin >> qry_cnt;
	for (unsigned i = 0; i < qry_cnt; i++) {
		queue<unsigned> qry;
		for (unsigned j = 0; j < N; j++) {
			unsigned ipt; cin >> ipt;
			qry.push(ipt);
		}
		if (fulls.find(qry) != fulls.end()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

