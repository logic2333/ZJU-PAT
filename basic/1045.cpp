// 1045.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	unsigned N; cin >> N;
	vector<unsigned> nums(N);
	for (unsigned i = 0; i < N; i++) cin >> nums[i];
	vector<unsigned> sorted = nums;
	sort(sorted.begin(), sorted.end());
	vector<unsigned> res;
	for (unsigned i = 0; i < N; i++)
		if (nums[i] == sorted[i]) {
			bool ok = true;
			for (unsigned j = 0; j < i; j++)
				if (nums[j] > nums[i]) {
					ok = false; break;
				}
			if (ok) 
				for (unsigned j = i + 1; j < N; j++)
					if (nums[j] < nums[i]) {
						ok = false; break;
					}
			if (ok) res.push_back(nums[i]);
		}
	cout << res.size() << endl;
	for (unsigned i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1) cout << ' ';
	}
	cout << endl;
	return 0;
}

