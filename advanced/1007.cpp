// 1007.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

unsigned k;
int *nums;

struct seq {
	int *low, *high;
	int sum;
	seq() {}
	seq(int* arr) {
		low = high = arr; sum = 0;
	}
	void reset() {
		low = high + 1; sum = 0;
	}
	bool operator>(const seq& another) const {
		return sum > another.sum;
	}
	void out() {
		if (sum == 0 && high == nums) high = low + k - 1;
		cout << sum << ' ' << *low << ' ' << *high;
	}
};

int main()
{
	cin >> k;
	nums = new int[k];
	for (unsigned i = 0; i < k; i++) cin >> nums[i];
	seq _lseq(nums);
	for (seq _seq(nums); _seq.high < nums + k; _seq.high++) {
		_seq.sum += *_seq.high;
		if (_seq > _lseq) _lseq = _seq;
		if (_seq.sum < 0) _seq.reset();
	}
	_lseq.out();
	return 0;
}

