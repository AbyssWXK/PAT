// 1023_ have_fun_with_number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	vector<int> num1;
	char tpc;
	while ((tpc = getchar()) != '\n') {
		num1.push_back(tpc - '0');
	}
	vector<int> num2(num1);
	int r = 0;
	for (auto rit = num1.rbegin(); rit != num1.rend(); rit++) {
		(*rit) = (*rit) * 2 + r;
		r = 0;
		if ((*rit) >= 10) {
			(*rit) = (*rit) - 10;
			r++;
		}
	}
	vector<int> num(num1);
	if (r == 1) {
		cout << "No" << endl;
		cout << 1;
		for (int i = 0; i < num.size(); ++i) {
			cout << num[i];
		}
	}
	else {
		sort(num1.begin(), num1.end());
		sort(num2.begin(), num2.end());
		if (num1 == num2) {
			cout << "Yes" << endl;
			for (int i = 0; i < num.size(); ++i) {
				cout << num[i] ;
			}
		}
		else {
			cout << "No" << endl;
			for (int i = 0; i < num.size(); ++i) {
				cout << num[i];
			}
		}
	}
    return 0;
}