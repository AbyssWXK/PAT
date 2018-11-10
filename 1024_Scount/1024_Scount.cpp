// 1024_Scount.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;
bool left(string *a, int t) {
	t = t + 1;
	*a = '.' + *a;
	if (t >= 0) {
		for (int i = 0; i < t; i++) {
			if (i < a->size() - 1) {
				char temp = (*a)[i];
				(*a)[i] = (*a)[i + 1];
				(*a)[i + 1] = temp;
			}
			else {
				if (i == a->size() - 1)
					(*a)[i] = '0';
				else {
					*a = *a + "0";
				}
			}
		}
		if ((*a)[a->size() - 1] == '.') {
			(*a)[a->size() - 1] = '\0';
		}
		return true;
	}
	else {
		t = -t;
		for (int i = 0; i < t; i++) {
			(*a)[0] = '0';
			*a = '.' + *a;
		}
		*a = '0' + *a;
		return true;
	}
}

int main()
{
	string num;				// input
	cin >> num;
	if (num[0] == '-') {
		cout << '-';
	}
	string result;			// save result
	int n = 0;				// ci
	int i = 0;
	for (i = 1; num[i] != 'E';i++) {
		if (num[i] != '.'&&num[i]!='-')
			result = result + num[i];
	}
	int flag = 1;
	if (num[i + 1] == '-') {
		flag = -1;
	}
	for (i = i + 2; i < num.size(); i++) {
		n = n * 10 + num[i] - '0';
	}
	n = n*flag;
	left(&result, n);
	cout << result;
	return 0;
}

