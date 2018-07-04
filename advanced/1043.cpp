// 1043.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string opt = "";

struct _tree {
	int elem;
	_tree *left, *right;
	void postorder() {
		if (left) left->postorder();
		if (right) right->postorder();
		opt += to_string(_Longlong(elem)); opt += ' ';
	}
};

template<typename T>
T myfind(const T beg, const T en, const int& elem, const bool _reversed) {
	if (!_reversed) return find(beg, en, elem);
	else {
		T res_1 = find(beg, en, elem);
		if (res_1 != en)
			for (T res_2 = find(res_1 + 1, en, elem); res_2 != en; res_2 = find(res_1 + 1, en, elem)) 
				res_1 = res_2;
		return res_1;
	}
}

template<typename T>
bool construct(_tree* dest, const vector<int>::iterator& pre_begin, const vector<int>::iterator& pre_end, 
	const T in_begin, const T in_end, const bool reversed) {
	dest->elem = *pre_begin; 
	if (pre_end - pre_begin == 1)
		if (*in_begin == dest->elem)
			dest->left = dest->right = NULL;
		else return false;
	else {	
		T root_posit = myfind(in_begin, in_end, dest->elem, reversed);
		if (root_posit == in_end) return false;
		bool left_construct = true, right_construct = true;
		if (in_begin == root_posit) dest->left = NULL;
		else {
			dest->left = new _tree; 
			left_construct = construct(dest->left, pre_begin + 1, pre_begin + 1 + (root_posit - in_begin), in_begin, root_posit, reversed);
		}
		if (root_posit + 1 == in_end) dest->right = NULL; 
		else {
			dest->right = new _tree;
			right_construct = construct(dest->right, pre_begin + 1 + (root_posit - in_begin), pre_end, root_posit + 1, in_end, reversed);
		}
		return left_construct && right_construct;
	}
	return true;
}

int main()
{
	unsigned N; cin >> N;
	vector<int> ipt(N);
	for (auto i = ipt.begin(); i != ipt.end(); i++) cin >> *i;
	vector<int> sorted = ipt;
	sort(sorted.begin(), sorted.end());
	_tree* tree = new _tree;
	if (construct(tree, ipt.begin(), ipt.end(), sorted.begin(), sorted.end(), false)) tree->postorder();
	else if (construct(tree, ipt.begin(), ipt.end(), sorted.rbegin(), sorted.rend(), true)) tree->postorder();
	if (opt == "") cout << "NO";
	else {
		opt.erase(opt.end() - 1); 
		cout << "YES" << endl << opt;
	}
	return 0;
}

