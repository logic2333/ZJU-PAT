// 1055.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
const string ipt = "12 4 "
"Zoe_Bill 35 2333 "
"Bob_Volk 24 5888 "
"Anny_Cin 95 999999 "
"Williams 30 -22 "
"Cindy 76 76000 "
"Alice 18 88888 "
"Joe_Mike 32 3222 "
"Michael 5 300000 "
"Rosemary 40 5888 "
"Dobby 24 5888 "
"Billy 24 5888 "
"Nobody 5 0 "
"4 15 45 "
"4 30 35 "
"4 5 95 "
"1 45 50";

istringstream is(ipt);*/

struct person {
	string name; unsigned age; 
	int nwt;	//资产
	bool operator<(const person& another) const {
		return age < another.age;
	}
};

bool cmp1(const person& a, const person& b) { //用于输出
	if (a.nwt > b.nwt) return false;
		else if (a.nwt == b.nwt) 
			if (a.age < b.age) return false;
			else if (a.age == b.age) return a.name > b.name;
	return true;
}

bool cmp2(const person& a, const unsigned _age) {
	return a.age < _age;
}

bool cmp3(const unsigned _age, const person& a) {
	return a.age > _age;
}

istream& operator>>(istream& is, person& p) {
	is >> p.name >> p.age >> p.nwt;
	return is;
}

ostream& operator<<(ostream& os, const person& p) {
	os << p.name << ' ' << p.age << ' ' << p.nwt;
	return os;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);	//据说这两句可以加快cin、cout的速度
	unsigned N, K; cin >> N >> K;
	vector<person> people(N);
	for (auto i = people.begin(); i != people.end(); i++) cin >> *i;
	sort(people.begin(), people.end());	//先按年龄排序
	for (unsigned i = 1; i <= K; i++) {	//不需要将所有的queries预先储存，读入一条处理一条也可以
		unsigned n, age_upper, age_lower;
		cin >> n >> age_lower >> age_upper;
		vector<person> exps;	//符合年龄条件的人，由t1、t2框定
		auto t1 = lower_bound(people.begin(), people.end(), age_lower, cmp2);
		auto t2 = upper_bound(people.begin(), people.end(), age_upper, cmp3);
		copy(t1, t2, back_inserter(exps));
		cout << "Case #" << i << ':' << endl;
		if (exps.empty()) cout << "None" << endl;
		else {
			make_heap(exps.begin(), exps.end(), cmp1);
			for (unsigned i = 0; i < n; i++) {
				cout << exps[0] << endl;
				pop_heap(exps.begin(), exps.end(), cmp1);
				exps.pop_back();
				if (exps.empty()) break;
			}
		}
	}
	return 0;
}

