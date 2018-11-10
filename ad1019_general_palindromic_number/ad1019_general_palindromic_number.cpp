// 1019_general_palindromic_number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long N, b;
	cin >> N >> b;
	long long num = N;
	long long base = b;
	vector<long> numstr;
	long long tpch;
	while (num != 0) {
		tpch = num%base;
		numstr.push_back(tpch);
		num = num / base;
	}
	if (numstr.size() == 0) {
		cout << "Yes" << endl;
		cout << 0 << endl;
		return 0;
	}
	vector<long> restr(numstr.begin(), numstr.end());
	reverse(restr.begin(), restr.end());
	if (restr == numstr) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cout << restr[0];
	for (int i = 1; i < restr.size(); ++i) {
		cout << " " << restr[i];
	}
    return 0;
}

