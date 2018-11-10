// 1016_a+b.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
long fang(int k) {
	long val = 1;
	if (k == 0) {
		return 1;
	}
	for (int i = 0; i < k; i++) {
		val = val * 10;
	}
	return val;
}
long fun(char *str, int num) {
	int k=0;
	long val=0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == (num + '0')) {
			k++;
		}
	}
	for (int i = 0; i < k; i++) {
		val = num*fang(i) + val;
	}
	return val;
}

int main()
{
	char str1[11];
	char str2[11];
	int num1;
	int num2;
	int val1;
	int val2;
	scanf("%s %d %s %d", str1, &num1, str2, &num2);
	val1 = fun(str1, num1);
	val2 = fun(str2, num2);
	cout << val1 + val2;
    return 0;
}

