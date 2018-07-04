// 1033.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


struct Stat {
	float pr, dist;
	bool operator<(const Stat& another) const {
		return dist < another.dist;
	}
};

const Stat far = { 0.0, 30001.0 };

istream& operator>>(istream& is, Stat& s) {
	is >> s.pr >> s.dist;
	return is;
}

int main()
{
	float cmax, d, davg; unsigned n;
	cin >> cmax >> d >> davg >> n;
	vector<Stat> stats(n);
	for (unsigned i = 0; i < n; i++) cin >> stats[i];
	sort(stats.begin(), stats.end());
	stats.push_back(far);
	if (stats[0].dist != 0.0) {
		cout << "The maximum travel distance = 0.00";
		return 0;
	}
	float longest_run = cmax * davg;
	float now_oil = 0.0, fare = 0.0;
	auto now_stat = stats.begin();
	while (now_stat->dist + now_oil * davg < d) {
		auto next_stat = now_stat + 1;
		if (now_stat->dist + longest_run < next_stat->dist) {
			if (now_stat->dist + longest_run >= d) {
				fare += ((d - now_stat->dist) / davg - now_oil) * now_stat->pr;
				now_oil = (d - now_stat->dist) / davg;
			}
			else now_oil = cmax;
			break;
		}
		for (; next_stat->dist <= now_stat->dist + longest_run; next_stat++)
			if (next_stat->pr < now_stat->pr) break;
		if (next_stat->dist > now_stat->dist + longest_run) {
			if (now_stat->dist + longest_run >= d) {
				fare += ((d - now_stat->dist) / davg - now_oil) * now_stat->pr;
				now_oil = (d - now_stat->dist) / davg;
			}
			else {
				next_stat = now_stat + 1;
				for (auto cheap_stat = now_stat + 1; cheap_stat->dist <= now_stat->dist + longest_run; cheap_stat++)
					if (cheap_stat->pr < next_stat->pr) next_stat = cheap_stat;
				fare += (cmax - now_oil) * now_stat->pr;
				now_oil = cmax - (next_stat->dist - now_stat->dist) / davg;
				now_stat = next_stat;
			}
		}
		else {
			fare += ((next_stat->dist - now_stat->dist) / davg - now_oil) * now_stat->pr;
			now_stat = next_stat;
			now_oil = 0.0;
		}
	}
	if (int(now_stat->dist + now_oil * davg + 0.5) == d) cout << fixed << setprecision(2) << fare;
	else cout << "The maximum travel distance = " << fixed << setprecision(2) << now_stat->dist + now_oil * davg;
	return 0;
}

