// 1038.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
	string prov, want; cin >> prov >> want;
	map<char, unsigned> m_prov, m_want;
	for (auto i = prov.begin(); i != prov.end(); i++)
		m_prov[*i]++;
	for (auto i = want.begin(); i != want.end(); i++)
		m_want[*i]++;
	bool ok = true;
	for (auto i = m_want.begin(); i != m_want.end(); i++)
		if (m_prov[i->first] < i->second) {
			ok = false; break;
		}
	unsigned cnt = 0;
	if (ok) {
		for (auto i = m_prov.begin(); i != m_prov.end(); i++)
			cnt += i->second - m_want[i->first];
		cout << "Yes ";
	}
	else {
		for (auto i = m_want.begin(); i != m_want.end(); i++)
			if (m_prov[i->first] < i->second)
				cnt += i->second - m_prov[i->first];
		cout << "No ";
	}
	cout << cnt;
	return 0;
}

