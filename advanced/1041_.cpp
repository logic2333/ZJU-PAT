// 1041_.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> data(N);
    map<int, bool> unique;
    for (int i = 0; i < N; i++) {
		cin >> data[i];
		if (unique.count(data[i]))
			unique[data[i]] = false;
		else unique[data[i]] = true;
	}
	int j = 0;
	for (; j < N; j++)
		if (unique[data[j]]) {
			cout << data[j] << endl;
			break;
		}
	if (j == N) cout << "None" << endl;
	return 0;
}
