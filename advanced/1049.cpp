// 1049.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
  unsigned ipt; cin >> ipt;
  long long res = 0;
  for (unsigned i = 1; i <= ipt; i++) {
    string tmp = to_string(i);
    for (auto j = tmp.begin(); j != tmp.end(); j++)
      if (*j == '1') res++;
  }
  cout << res;
  return 0;
}

