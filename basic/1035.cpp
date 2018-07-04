// 1035.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
	unsigned N; cin >> N;
	vector<unsigned> nums(N), part_sorted(N);
	for (unsigned i = 0; i < N; i++) cin >> nums[i];
	for (unsigned i = 0; i < N; i++) cin >> part_sorted[i];
	bool is_insert = true; unsigned chkp = 1;
	for (; chkp < N; chkp++) 
		if (part_sorted[chkp] < part_sorted[chkp - 1]) break;
	for (unsigned i = chkp; i < N; i++)
		if (part_sorted[i] != nums[i]) {
			is_insert = false; break;
		}
	cout << (is_insert ? "Insertion Sort" : "Merge Sort") << endl;
	if (is_insert) {
		set<unsigned> sorted_part;
		copy(part_sorted.begin(), part_sorted.begin() + chkp + 1, inserter(sorted_part, sorted_part.begin()));
		copy(sorted_part.begin(), sorted_part.end(), ostream_iterator<unsigned>(cout, " "));
		for (unsigned i = chkp + 1; i < N; i++) {
			cout << nums[i];
			if (i != N - 1) cout << ' ';
		}
	}
	else {
		vector<unsigned> res; auto i = part_sorted.begin();
		for (; part_sorted.end() - i >= chkp * 2; i += chkp * 2)
			merge(i, i + chkp, i + chkp, i + chkp * 2, back_inserter(res));
		copy(i, part_sorted.end(), back_inserter(res));
		for (unsigned i = 0; i < N; i++) {
			cout << res[i];
			if (i != N - 1) cout << ' ';
		}
	}
	return 0;
}

