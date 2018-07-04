// 1028.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;


struct stu {
	string id, name;
	unsigned grade;
};

istream& operator>>(istream& is, stu& s) {
	is >> s.id >> s.name >> s.grade;
	return is;
}

ostream& operator<<(ostream& os, const stu& s) {
	os << s.id << ' ' << s.name << ' ' << s.grade;
	return os;
}

bool cmp_1(const stu& a, const stu& b) {
	return a.id < b.id;
}

bool cmp_2(const stu& a, const stu& b) {
	if (a.name == b.name) return cmp_1(a, b);
	else return a.name < b.name;
}

bool cmp_3(const stu& a, const stu& b) {
	if (a.grade == b.grade) return cmp_1(a, b);
	else return a.grade < b.grade;
}

int main()
{
	unsigned N, C; cin >> N >> C;
	vector<stu> stus(N);
	for (unsigned i = 0; i < N; i++) cin >> stus[i];
	switch (C) {
	case 1: sort(stus.begin(), stus.end(), cmp_1); break;
	case 2: sort(stus.begin(), stus.end(), cmp_2); break;
	case 3: sort(stus.begin(), stus.end(), cmp_3); break;
	}
	copy(stus.begin(), stus.end(), ostream_iterator<stu>(cout, "\n"));
	return 0;
}

