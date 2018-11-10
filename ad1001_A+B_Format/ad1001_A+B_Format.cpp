// ad1001_A+B_Format.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int fang(int k) {
	int a = 1;
	for (int i = 0; i < k; ++i) {
		a = a * 10;
	}
	return a;
}
int main()
{
	int A, B;
	cin >> A >> B;
	int ru = A + B;
	string str;
	int falg = 0;
	for (int i = 7; i >= 0; --i) {
		if (ru < 0) {
			ru = -ru;
			cout << "-";
		}
		int num = 0;
		if (falg == 0)
		{
			if (ru - fang(i) >= 0) {
				falg = 1;
			}
		}
		if (falg == 1) {
			num = ru / fang(i);
			ru = ru - num*fang(i);
			char a = '0' + num;
			str = str + a;
		}
	}
	int count = 3;
	string b;
	for (int i = str.size() - 1; i >= 0; --i) {
		count--;
		b = b + str[i];
		if (count == 0 && i != 0) {
			count = 3;
			b = b + ',';
		}
	}
	if (b.empty()) {
		cout << "0";
	}
	else {
		for (int i = b.size() - 1; i >= 0; --i) {
			cout << b[i];
		}
	}
    return 0;
}

