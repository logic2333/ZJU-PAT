// 1044.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <list>
//#include <sstream>
using namespace std;
/*
const string ipt = "5 13 "
"2 4 5 7 9";

istringstream is(ipt);*/

typedef pair<unsigned, unsigned> res_type;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	unsigned N, M; cin >> N >> M;
	vector<unsigned> ipt(N);
	for (auto i = ipt.begin(); i != ipt.end(); i++) cin >> *i;
	unsigned nearest = 100000001;
	map<unsigned, list<res_type>> res;
	unsigned sum = 0; int j = -1;
	for (unsigned i = 0; i < N; i++) {
		if (i > 0) sum -= ipt[i - 1];
		if (sum <= nearest)
			if (sum >= M) { 
				nearest = sum;
				res[nearest].push_back(make_pair(i + 1, j < N ? j + 1 : j));
			}
			else for (j++; j < N; j++) {
				sum += ipt[j];
				if (sum > nearest) break;
				else if (sum >= M) {
					nearest = sum;
					res[nearest].push_back(make_pair(i + 1, j + 1));
					break;
				}
			}
	}
	for (auto i = res.begin()->second.begin(); i != res.begin()->second.end(); i++)
		cout << i->first << '-' << i->second << endl;
	return 0;
}

