// ad1009_Product of Polynomials.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
using namespace std;
void add(map<int, double> &a, int e, double  c) {
	if (!a.insert(make_pair(e, c)).second) {
		a[e] = a[e] + c;
	}
}
pair<int ,double> mul(int ae, double ac, int be, double bc) {
	return pair<int, double>(ae + be, ac*bc);
}
int main()
{
	map<int, double> p1,p2,result;
	int n1, e1;
	cin >> n1;
	double c1;
	for (int i = 0; i < n1; ++i) {
		cin >> e1 >> c1;
		add(p1, e1, c1);
	}
	cin >> n1;
	for (int i = 0; i < n1; ++i) {
		cin >> e1 >> c1;
		add(p2, e1, c1);
	}
	for (map<int, double>::iterator iter1 = p1.begin(); iter1 != p1.end(); ++iter1) {
		for (map<int, double>::iterator iter2 = p2.begin(); iter2 != p2.end(); ++iter2) {
			pair<int, double> temp = mul(iter1->first, iter1->second, iter2->first, iter2->second);
			add(result, temp.first, temp.second);
		}
	}
	int count = 0;
	for (map<int, double>::reverse_iterator iter = result.rbegin(); iter != result.rend(); ++iter) {
		if (iter->second != 0) {
			count++;
		}
	}
	cout << count;
	for (map<int, double>::reverse_iterator iter = result.rbegin(); iter != result.rend(); ++iter) {
		if (iter->second != 0) {
			printf(" %d %.1lf", iter->first, iter->second);
		}
	}
    return 0;
}

