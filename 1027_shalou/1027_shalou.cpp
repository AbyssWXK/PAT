// 1027_shalou.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void display(int k, char c) {
	for (int i = 0; i < k; i++) {
		cout << c;
	}
}
int main()
{
	int num;
	cin >> num;
	char c;
	cin >> c;
	int k;
	for (k = 0; k*k * 2-1 <= num; ++k) {
		;
	}
	if (num == 0) {
		cout << 0;
		return 0;
	}
	--k;
	int left = num - k*k * 2 + 1;
	for (int i = 0; i < k; ++i) {
		display(i, ' ');
		display((k - i) * 2 - 1, c);
		cout << endl;
	}
	for (int i = k-2; i >=0; --i) {
		display(i, ' ');
		display((k - i) * 2 - 1, c);
		cout << endl;
	}
	cout << left;
    return 0;
}

