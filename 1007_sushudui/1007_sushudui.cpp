// 1007_sushudui.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool isprime(int n) {
	int chu;
	if (n <= 1)
		return false;
	for (chu = 2; chu*chu <= n; chu++) {
		if (n % chu == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	int i;
	int numnow=2;
	int numbefor=2;
	int count=0;
	cin >> num;
	for (i = 1; i < num; i++) {
		if (isprime(i)) {
			numbefor = numnow;
			numnow = i;
			if (numnow - numbefor == 2)
				count++;
		}
	}
	cout << count;
    return 0;
}

