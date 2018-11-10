// 1023_zuhe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> allnum(10, 0);			// 输入数字个数数组
	int i = 0;
	for (vector<int>::iterator iter1 = allnum.begin(); iter1 != allnum.end(); iter1++) {
		cin >> *iter1;
	}
	// 找到首位
	for (vector<int>::iterator iter1 = allnum.begin()+1; iter1 != allnum.end(); iter1++) {
		if (*iter1 != 0) {
			cout << iter1 - allnum.begin();
			(*iter1)--;
			break;
		}
	}
	for (vector<int>::iterator iter1 = allnum.begin() ; iter1 != allnum.end(); iter1++) {
		for (int k = 0; k < *iter1; k++) {
			cout << (iter1 - allnum.begin());
		}
	}
    return 0;
}

