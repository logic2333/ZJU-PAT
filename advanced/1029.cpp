// 1029.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	unsigned n1; cin >> n1;
	vector<long long> a(n1);
	for (unsigned i = 0; i < n1; i++) cin >> a[i];
	unsigned n2; cin >> n2;
	vector<long long> b(n2);
	for (unsigned i = 0; i < n2; i++) cin >> b[i];
	vector<long long> c(n1 + n2);
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	cout << c[(n1 + n2 - 1) / 2];
	return 0;
}

