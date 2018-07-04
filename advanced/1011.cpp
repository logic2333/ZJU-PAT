// 1011.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

const char hints[3] = { 'W', 'T', 'L' };


int main()
{
	float bets[3][3];
	for (unsigned i = 0; i < 3; i++)
		for (unsigned j = 0; j < 3; j++)
			cin >> bets[i][j];
	unsigned max_bet[3] = { 0 };
	for (unsigned i = 0; i < 3; i++)
		for (unsigned j = 1; j < 3; j++)
			if (bets[i][j] > bets[i][max_bet[i]])
				max_bet[i] = j;
	for (unsigned i = 0; i < 3; i++)
		cout << hints[max_bet[i]] << ' ';
	float res = (bets[0][max_bet[0]] * bets[1][max_bet[1]] * bets[2][max_bet[2]] * 0.65 - 1) * 2;
	cout << fixed << setprecision(2) << res;
	return 0;
}

