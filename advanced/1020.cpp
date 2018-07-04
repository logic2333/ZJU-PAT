// 1020.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;

ostringstream os;

struct tree {
	unsigned elem;
	tree *left, *right;
	tree(const vector<unsigned>::iterator& post_start, const vector<unsigned>::iterator& post_end, 
		const vector<unsigned>::iterator& in_start, const vector<unsigned>::iterator& in_end) {
		//post_start, post_end�򶨵�ǰ�����ĺ���������У�in_start, in_end������������У�endָ�����һ��Ԫ�صĺ�һ��λ��
		if (post_end - post_start == 1) { elem = *post_start; left = right = NULL; }	//�������ֻ��һ��Ԫ��
		else {
			elem = *(post_end - 1);
			auto i = in_start;
			while (*i != elem) i++;
			auto j = post_start;
			while (find(in_start, i, *j) != i) j++;
			//���ϻ���������������
			if (post_start == j) left = NULL;	//�������Ϊ��
			else left = new tree(post_start, j, in_start, i);
			if (j == post_end - 1) right = NULL;
			else right = new tree(j, post_end - 1, i + 1, in_end);
		}
	}
	void levelorder() {
		os << elem << ' ';		
		static queue<tree*> con;
		if (left) con.push(left);
		if (right) con.push(right);
		while (!con.empty()) {
			tree* node = con.front();
			con.pop();
			node->levelorder();
		}
	}
};


int main()
{
	unsigned N; cin >> N;
	vector<unsigned> postorder(N), inorder(N);
	for (unsigned i = 0; i < N; i++) cin >> postorder[i];
	for (unsigned i = 0; i < N; i++) cin >> inorder[i];
	tree T(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
	T.levelorder();
	string opt = os.str();
	opt.erase(opt.end() - 1);
	cout << opt;
	return 0;
}

