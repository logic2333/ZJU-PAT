// 1098.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	unsigned N; cin >> N;
	vector<int> ori_nums(N), sorted_nums(N);
	for (auto i = ori_nums.begin(); i != ori_nums.end(); i++) cin >> *i;
	for (auto i = sorted_nums.begin(); i != sorted_nums.end(); i++) cin >> *i;
	bool is_insert = (sorted_nums[0] < sorted_nums[1]);
	if (is_insert) {
		cout << "Insertion Sort" << endl;
		unsigned chk_pnt = 1;
		for (; chk_pnt < N; chk_pnt++)
			if (sorted_nums[chk_pnt] < sorted_nums[chk_pnt - 1]) break;
		int chk_num = sorted_nums[chk_pnt];
		unsigned ist_pnt = lower_bound(sorted_nums.begin(), sorted_nums.begin() + chk_pnt, sorted_nums[chk_pnt]) - sorted_nums.begin();
		for (unsigned i = chk_pnt; i > ist_pnt; i--) sorted_nums[i] = sorted_nums[i - 1];
		sorted_nums[ist_pnt] = chk_num;
		for (unsigned i = 0; i < N; i++) {
			cout << sorted_nums[i];
			if (i < N - 1) cout << ' ';
		}
	}
	else {
		cout << "Heap Sort" << endl;
		auto heap_end = sorted_nums.begin();
		for (; heap_end != sorted_nums.end() && *heap_end <= sorted_nums.front(); heap_end++) ;
		pop_heap(sorted_nums.begin(), heap_end);
		for (unsigned i = 0; i < N; i++) {
			cout << sorted_nums[i];
			if (i < N - 1) cout << ' ';
		}
	}
	return 0;
}

