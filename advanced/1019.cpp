// 1019.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <deque>
using namespace std;


int main()
{
	unsigned N, b; cin >> N >> b;
	deque<unsigned> res;
	for (; N >= b ; N /= b)
		res.push_front(N % b);
	res.push_front(N);
	bool is_palin = true;
	auto i = res.begin(); auto j = res.end() - 1;
	for (; i < j; i++, j--)
		if (*i != *j) { 
			is_palin = false; break;
		}
	if (is_palin) cout << "Yes";
	else cout << "No";
	cout << endl;
	for (unsigned i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i < res.size() - 1) cout << ' ';
	}
	return 0;
}

