// 1030_perfectlist.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N = 0;
	double p = 0;
	cin >> N >> p;
	double *list = new double[N]; // 
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	double tpmin=list[0];
	int count = 0;
	int tpc = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1-i ; ++j) {
			if (list[j] > list[j + 1]) {
				tpmin = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tpmin;
			}
		}
	}
	for(int j = 0; j < N; ++j){
		tpc = 0;
		tpmin = list[j];
		for (int i = j; i < N ; ++i) {
			if (tpmin*p >= list[i]) {
				++tpc;
			}
		}
		if (tpc > count) {
			count = tpc;
		}
	}
	cout << count;
    return 0;
}

