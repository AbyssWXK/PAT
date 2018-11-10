// 1026_time.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int c1, c2;
	cin >> c1 >> c2;
	int time = c2 - c1;
	int h = 0, m = 0, s = 0;
	double second = (double)time / 100;
	while (second - 3600 >= 0) {
		second = second - 3600;
		h++;
	}
	while (second - 60 >= 0) {
		second = second - 60;
		m++;
	}
	while (second - 1 >= 0) {
		second = second - 1;
		s++;
	}
	if (second >= 0.5) {
		s++;
	}
	if (h > 9) {
		cout << h << ":";
	}
	else
		cout << "0" << h << ":";
	if (m > 9) {
		cout << m << ":";
	}
	else
		cout << "0" << m << ":";
	if (s > 9) {
		cout << s;
	}
	else
		cout << "0" << s;
    return 0;
}

