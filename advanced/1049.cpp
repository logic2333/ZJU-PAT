// 1049.cpp : �������̨Ӧ�ó������ڵ㡣
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

