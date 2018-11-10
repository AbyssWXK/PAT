// 1036_abm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int a;
	char x;
	cin >> a >> x;
	for (int i = 0; i < a; ++i) {
		cout << x;
	}
	cout << endl;
	int temp = 10 * a;
	temp = temp / 2;
	int falg = 0;
	while(temp-10>=0){
		temp = temp - 10;
	}
	if (temp >= 5) {
		falg = 1;
	}
	temp = a;
	temp = temp / 2 + falg - 2;
	for (int i = 0; i < temp; ++i) {
		cout << x;
		for (int j = 0; j < a - 2; ++j) {
			cout << " ";
		}
		cout << x << endl;
	}
	for (int i = 0; i < a; ++i) {
		cout << x;
	}
    return 0;
}

