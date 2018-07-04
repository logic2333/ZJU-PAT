// 1012.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const char tags[4] = { 'A', 'C', 'M', 'E' };


bool comp_pair(const pair<char, unsigned>& one, const pair<char, unsigned>& another) {
	if (one.second < another.second) return true;
	else 
		if (one.second == another.second) 
			if (one.first < another.first) return true;
	return false;
}

struct _stud {
	string ID;
	unsigned grade[3];
	pair<unsigned, unsigned> rank[4];
	float A;
	void set(const string& ipt) {
		istringstream is(ipt);
		is >> ID >> grade[0] >> grade[1] >> grade[2];
		A = (grade[0] + grade[1] + grade[2]) / 3.0;
		rank[0] = make_pair(0, 0);	//A
		rank[1] = make_pair(1, 0);	//C
		rank[2] = make_pair(2, 0);	//M	
		rank[3] = make_pair(3, 0);	//E	
	}
	void sort_pair() {
		sort(rank, rank + 4, comp_pair);
	}
};

bool comp_A(const _stud& one, const _stud& another) {
	return one.A > another.A;
}

bool comp_C(const _stud& one, const _stud& another) {
	return one.grade[0] > another.grade[0];
}

bool comp_M(const _stud& one, const _stud& another) {	
	return one.grade[1] > another.grade[1];
}

bool comp_E(const _stud& one, const _stud& another) {
	return one.grade[2] > another.grade[2];
}

bool (*comp[4])(const _stud& one, const _stud& another) = { comp_A, comp_C, comp_M, comp_E };

int main()
{
	unsigned N, M; cin >> N >> M;
	_stud* studs = new _stud[N];
	cin.sync(); cin.clear();
	for (unsigned i = 0; i < N; i++) {
		string ipt; getline(cin, ipt);
		studs[i].set(ipt);
	}
	for (unsigned i = 0; i < 4; i++) {
		sort(studs, studs + N, comp[i]);
		for (unsigned j = 1; j < N; j++) {
			studs[j].rank[i].second = studs[j - 1].rank[i].second;
			if (i == 0) {
				if (studs[j].A < studs[j - 1].A) studs[j].rank[i].second = j;
			}
			else if (studs[j].grade[i - 1] < studs[j - 1].grade[i - 1])
				studs[j].rank[i].second = j;
		}
	}
	for (unsigned i = 0; i < N; i++)
		studs[i].sort_pair();
	string* ids = new string[M];
	for (unsigned i = 0; i < M; i++)
		cin >> ids[i];
	for (unsigned i = 0; i < M; i++) {
		bool found = false;
		for (unsigned j = 0; j < N; j++)
			if (studs[j].ID == ids[i]) {
				found = true;
				cout << studs[j].rank[0].second + 1 << ' ' << tags[studs[j].rank[0].first] << endl;
			}
		if (!found) cout << "N/A" << endl;
	}
	return 0;
}

