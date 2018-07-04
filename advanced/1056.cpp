// 1056.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
//#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

/*
const string ipt = "11 3 "
"25 18 0 46 37 3 19 22 57 56 10 "
"6 0 8 7 10 5 9 1 4 2 3";

istringstream is(ipt);*/

struct rival {
	unsigned id, weight, score, rank;
	bool operator<(const rival& another) const {
		return weight < another.weight;
	}
};

bool score_cmp(const rival& a, const rival& b) {
	return a.score > b.score;
}

bool id_cmp(const rival& a, const rival& b) {
	return a.id < b.id;
}

int main()
{
	unsigned np, ng; cin >> np >> ng;
	vector<rival> rvs(np);
	for (unsigned i = 0; i < np; i++) {
		rvs[i].id = i; rvs[i].score = 0; 
		cin >> rvs[i].weight;
	}
	bool integ = (np % ng == 0);
	vector<set<rival>> groups(integ ? np / ng : np / ng + 1);
	for (unsigned i = 0; i < groups.size(); i++) {
		unsigned upper = ng;
		if (!integ && i == groups.size() - 1) upper = np % ng;
		for (unsigned j = 0; j < upper; j++) {
			unsigned _id; cin >> _id;
			groups[i].insert(rvs[_id]);
		}
	}
	while (groups.size() > 1) {
		vector<rival> temp_rvs;
		for (auto i = groups.begin(); i != groups.end(); i++) {
			temp_rvs.push_back(*i->rbegin());
			rvs[i->rbegin()->id].score++;
		}
		groups.clear();
		bool integ = (temp_rvs.size() % ng == 0);
		groups.resize(integ ? temp_rvs.size() / ng : temp_rvs.size() / ng + 1);
		auto start_posit = temp_rvs.begin();
		for (unsigned i = 0; i < groups.size(); i++) {
			copy(start_posit, temp_rvs.end() - start_posit < ng ? temp_rvs.end() : start_posit + ng, inserter(groups[i], groups[i].begin()));
			if (temp_rvs.end() - start_posit >= ng) start_posit += ng;
		}
	}
	rvs[groups[0].rbegin()->id].score++;
	sort(rvs.begin(), rvs.end(), score_cmp);
	rvs[0].rank = 1;
	for (unsigned i = 1; i < np; i++) {
		if (rvs[i].score < rvs[i - 1].score) rvs[i].rank = i + 1;
		else rvs[i].rank = rvs[i - 1].rank;
	}
	sort(rvs.begin(), rvs.end(), id_cmp);
	for (unsigned i = 0; i < np; i++) {
		cout << rvs[i].rank;
		if (i < np - 1) cout << ' ';
	}
	return 0;
}

