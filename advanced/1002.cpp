// 1002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
	unsigned expo;
	double coef;
	friend istream& operator>>(istream& is, item& it);
	friend ostream& operator<<(ostream& os, const item& it);
	bool operator<(const item& another) const {
		return expo > another.expo;
	}
};

istream& operator>>(istream& is, item& it) {
	is >> it.expo >> it.coef;
	return is;
}

ostream& operator<<(ostream& os, const item& it) {
	os << ' ' << it.expo << ' ' << setprecision(2) << it.coef;
	return os;
}

int main()
{
	vector<item> items;
	for (unsigned i = 0; i < 2; i++) {
		unsigned k; 
		for (cin >> k; k > 0; k--) {
			item temp; cin >> temp;
			bool found = false;
			for (unsigned i = 0; !items.empty() && i < items.size(); i++) {
				if (items[i].expo == temp.expo) {
					items[i].coef += temp.coef;
					found = true;
					break;
				}
			}
			if (!found) items.push_back(temp);
		}
	}
	for (auto i = items.begin(); i < items.end();) {
		if (i->coef == 0) i = items.erase(i);
		else i++;
	}
	cout << items.size();
	sort(items.begin(), items.end());
	for (auto it : items) cout << it;
	return 0;
}

