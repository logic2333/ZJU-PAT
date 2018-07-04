// 1035.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


map<char, char> modi;

void init() {
	modi['1'] = '@'; modi['0'] = '%';
	modi['l'] = 'L'; modi['O'] = 'o';
}

struct account {
	string id, pswd;
	bool modified;
	void modify() {
		for (auto i = pswd.begin(); i != pswd.end(); i++)
			for (auto j = modi.begin(); j != modi.end(); j++)
				if (*i == j->first) {
					modified = true; *i = j->second;
				}
	}
};

istream& operator>>(istream& is, account& a) {
	is >> a.id >> a.pswd;
	a.modified = false;
	return is;
}

ostream& operator<<(ostream& os, const account& a) {
	os << a.id << ' ' << a.pswd;
	return os;
}

int main()
{
	init();
	unsigned N; cin >> N;
	vector<account> accounts(N);
	unsigned modi_cnt = 0;
	for (unsigned i = 0; i < N; i++) { 
		cin >> accounts[i];
		accounts[i].modify();
		if (accounts[i].modified) modi_cnt++;
	}
	if (modi_cnt > 0) {
		cout << modi_cnt << endl;
		for (auto i = accounts.begin(); i != accounts.end(); i++)
			if (i->modified) cout << *i << endl;
	}
	else if (N == 1) cout << "There is 1 account and no account is modified";
	else cout << "There are " << N << " accounts and no account is modified";
	return 0;
}

