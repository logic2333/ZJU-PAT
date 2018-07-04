// 1008.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned n; cin >> n;
	unsigned* fs = new unsigned[n];
	for (unsigned i = 0; i < n; i++) cin >> fs[i];
	unsigned time = 5 * n;
	for (unsigned i = 0; i < n; i++) {
		if (i == 0) time += 6 * fs[0];
		else 
			if (fs[i] > fs[i - 1]) time += 6 * (fs[i] - fs[i - 1]);
			else time += 4 * (fs[i - 1] - fs[i]);
	}
	cout << time;
	return 0;
}

