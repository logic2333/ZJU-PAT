// 1040.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int main()
{
	string str; cin >> str;
	map<char, vector<unsigned>> recs;
	for (unsigned i = 0; i < str.length(); i++)
		recs[str[i]].push_back(i);
	unsigned res = 0; 
	for (auto i = recs['P'].begin(); i != recs['P'].end(); i++) 
		for (auto j = recs['A'].begin(); j != recs['A'].end(); j++)
			if (*j > *i) 
				for (auto k = recs['T'].begin(); k != recs['T'].end(); k++)
					if (*k > *j) { 
						res += recs['T'].end() - k;
						if (res >= 1000000007) res -= 1000000007;
						break;
					}
	/*unsigned res = 0;
	for (auto i = str.begin(); i != str.end(); i++) 
		if (*i == 'P')
			for (auto j = i; j != str.end(); j++)
				if (*j == 'A')
					for (auto k = j; k != str.end(); k++)
						if (*k == 'T') {
							res++; 
							if (res >= 1000000007) res -= 1000000007;
						}*/
	cout << res;
	return 0;
}

