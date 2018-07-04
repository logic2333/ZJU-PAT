// 1057.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

ostringstream os;
const string INV = "Invalid";

vector<unsigned> _stack;
vector<unsigned> _copy;

unsigned _pop() {
	int res = 0;
	if (!_stack.empty()) {
		res = _stack.back();
		_stack.pop_back();
		_copy.pop_back();
	}
	return res;
}

unsigned _peekmedian() {
	if (!_copy.empty()) {
		nth_element(_copy.begin(), _copy.begin() + (_copy.size() - 1) / 2, _copy.end());
		return _copy[(_copy.size() - 1) / 2];
	} 
	return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	unsigned N; cin >> N;
	cin.sync(); cin.clear();
	for (unsigned i = 0; i < N; i++) {
		string ipt; getline(cin, ipt);
		switch (ipt[1]) {
		case 'o': {
			unsigned res = _pop();
			if (res) os << res << endl;
			else os << INV << endl;
			break;
				  }
		case 'e': {
			unsigned res = _peekmedian();
			if (res) os << res << endl;
			else os << INV << endl;
			break;
				  }
		case 'u': {
			istringstream iss(ipt);
			string tmp; unsigned p;
			iss >> tmp >> p;
			_stack.push_back(p);
			_copy.push_back(p);
			break;
				  }
		}
	}
	cout << os.str();
	return 0;
}

