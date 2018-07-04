// 1004.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <set>
using namespace std;


struct node {
	unsigned id;
	node *brother, *son;
	bool operator<(const node& another) {
		return id < another.id;
	}
	node() {
		brother = son = NULL;
	}
	node(const string& _ipt) {
		istringstream is(_ipt); is >> id;
		brother = son = NULL;
	}
	void get_non_leaf(set<node*>& res) {
		node* temp = this;
		if (temp->son) res.insert(temp);
		for (; temp->brother; temp = temp->brother)
			if (temp->son) res.insert(temp);
		if (temp->son) res.insert(temp);
	}
	node* search(const unsigned _id) {
		if (id == _id) return this; 
		node* res = this;
		for (; res->brother; res = res->brother)
			if (res->id == _id) return res;
		if (res->id == _id) return res;
		set<node*> non_leaf; get_non_leaf(non_leaf);
		for (auto i : non_leaf) return i->son->search(_id);
		return NULL;
	}
	unsigned grow(const string& _ipt) {
		istringstream is(_ipt); 
		unsigned temp_id; is >> temp_id;
		unsigned son_num; is >> son_num;
		node* before = search(temp_id);
		for (unsigned i = 0; i < son_num; i++) {
			node* new_node = new node();
			is >> new_node->id;
			if (i == 0) before = before->son = new_node;
			else before = before->brother = new_node; 
		}
		return son_num;
	}
	bool is_leaf() const {
		return son == NULL;
	}
	unsigned count_leaf() {
		unsigned res = 0; node* temp = son;
		for (; temp->brother; temp = temp->brother)
			if (temp->is_leaf()) res++;
		if (temp->is_leaf()) res++;
		return res;
	}	
};

void out(set<node*>& _non_leaf_by_level) {
	if (_non_leaf_by_level.empty()) return;
	unsigned opt = 0;
	for (auto i : _non_leaf_by_level)
		opt += i->count_leaf();
	cout << ' ' << opt;
	set<node*> non_leaf_by_level;
	for (auto i : _non_leaf_by_level)
		i->son->get_non_leaf(non_leaf_by_level);
	out(non_leaf_by_level);
}

int main()
{
	string ipt; getline(cin, ipt);
	istringstream is(ipt);
	unsigned nodes_num, non_leaf_num;
	is >> nodes_num >> non_leaf_num;
	if (nodes_num == 1) cout << '1';
	else {
		getline(cin, ipt);
		node* root; root = new node(ipt);
		unsigned nodes_cnt = 0;
		while (true) {
			nodes_cnt += root->grow(ipt);
			if (nodes_cnt == nodes_num - 1) break;
			getline(cin, ipt);
		}
		cout << '0';
		set<node*> t; t.insert(root);
		out(t);
	}
	return 0;
}

