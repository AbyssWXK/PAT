// 1019_find.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int fang(int a) {
	int val = 1;
	for (int i = 0; i < a; i++) {
		val = val * 10;
	}
	return val;
}
int ctn(char*a) {		//四位字符串转数字
	int sum = 0;
	for (int i = 3; i >= 0; i--) {
		sum = (a[i] - '0') * fang(i) + sum;
	}
	return sum;
}
bool ntc(char *a, int x) {
	for (int i = 0; i < 4; i++) {
		int k = 0;
		while (true) {
			if (x - fang(3 - i) >= 0) {
				x = x - fang(3 - i);
				k++;
			}
			else
				break;
		}
		a[i] = k + '0';
	}
	return true;
}

bool range(char *a, int k) {
	int temp;
	if (k == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[j] < a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[j] > a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
	return true;
}
void show(int a, int b, int c) {
	char outval[4];
	int i;
	ntc(outval, a);
	for (i = 0; i < 4; i++) {
		cout << outval[i];
	}
	cout << " - ";
	ntc(outval, b);
	for (i = 0; i < 4; i++) {
		cout << outval[i];
	}
	cout << " = ";
	ntc(outval, c);
	for (i = 0; i < 4; i++) {
		cout << outval[i];
	}
	cout << endl;
}
int main()
{
	char inval[4];
	for(int alnum=0;alnum<10000;alnum++)
	{
		ntc(inval, alnum);
		int val1 = 0;
		int val2 = 0;
		int val3 = 0;
		while (val3 != 6174) {
			range(inval, 0);
			val1 = ctn(inval);
			range(inval, 1);
			val2 = ctn(inval);
			val3 = val2 - val1;
			ntc(inval, val3);
			show(val2, val1, val3);
			if (val3 == 0) {
				break;
			}
		}
		cout << endl;
	}
	return 0;
}
