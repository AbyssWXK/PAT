// ad1002_poly.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<map>			// use map to save poly
#include<iostream>
using namespace std;
int main()
{
	map<int, double> poly;
	int i;
	cin >> i;
	for (int j = 0; j < i; ++j) {
		int exp;
		double coe;
		cin >> exp >> coe;
		if ( !poly.insert(make_pair(exp, coe)).second) {
			poly[exp] = poly[exp] + coe;
		}
	}
	cin >> i;
	for (int j = 0; j < i; ++j) {
		int exp;
		double coe;
		cin >> exp >> coe;
		if (!poly.insert(make_pair(exp, coe)).second) {
			poly[exp] = poly[exp] + coe;
		}
	}
	int count = 0;
	for (map<int, double>::reverse_iterator iter = poly.rbegin(); iter != poly.rend(); ++iter) {
		if ((*iter).second != 0) {
			++count;
		}
	}
	cout << count;
	for (map<int, double>::reverse_iterator iter = poly.rbegin(); iter != poly.rend(); ++iter) {
		if ((*iter).second!=0) {
			printf(" %d %.1lf", (*iter).first, (*iter).second);
		}
	}
    return 0;
}

