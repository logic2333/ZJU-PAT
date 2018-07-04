// 1036.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;


struct stu {
	string name, id; int grade;
	stu(const string& _name, const string& _id, const int& _grade) {
		name = _name; id = _id; grade = _grade;
	}
	bool operator<(const stu& another) const {
		return grade < another.grade;
	}
};

ostream& operator<<(ostream& os, const stu& s) {
	os << s.name << ' ' << s.id;
	return os;
}

int main()
{
	unsigned N; cin >> N;
	set<stu> M_stu, F_stu;
	for (unsigned i = 0; i < N; i++) {
		string _name, _id; char _sex; int _grade;
		cin >> _name >> _sex >> _id >> _grade;
		if (_sex == 'M') M_stu.insert(stu(_name, _id, _grade));
		else F_stu.insert(stu(_name, _id, _grade));
	}
	bool NA = false;
	if (F_stu.empty()) { 
		cout << "Absent" << endl; NA = true;
	}
	else cout << *F_stu.rbegin() << endl;
	if (M_stu.empty()) {
		cout << "Absent" << endl; NA = true;
	}
	else cout << *M_stu.begin() << endl;
	if (NA) cout << "NA";
	else cout << F_stu.rbegin()->grade - M_stu.begin()->grade;
	return 0;
}

