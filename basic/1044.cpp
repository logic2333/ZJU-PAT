// 1044.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

const string diwei[] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
const string gaowei[] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

unsigned mar_to_ear(const string& ipt) {
	istringstream is(ipt); unsigned res = 0;
	string t[2]; is >> t[0] >> t[1];
	for (unsigned i = 0; i < 2; i++) {
		unsigned c = find(diwei, diwei + 13, t[i]) - diwei;
		if (c != 13) res += c; 
		c = find(gaowei, gaowei + 13, t[i]) - gaowei;
		if (c != 13) res += c * 13;
	}
	return res;
}

int main()
{
	unsigned N; cin >> N;
	vector<string> ipts_mar; vector<unsigned> ipts_ear;
	cin.sync(); cin.clear();
	for (unsigned i = 0; i < N; i++) {
		string ipt; getline(cin, ipt);
		if ('0' <= ipt[0] && ipt[0] <= '9') {
			unsigned tmp; istringstream is(ipt);
			is >> tmp; ipts_ear.push_back(tmp);
		}
		else ipts_mar.push_back(ipt);
	}
		
	//for (unsigned i = 0; i < N; i++)
		//cout << mar_to_ear(ipts[i]) << endl;
	return 0;
}

