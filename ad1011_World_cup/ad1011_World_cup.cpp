// ad1011_World_cup.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<int, char> ch = { {0,'W'},{1,'T'},{2,'L'} };
int main()
{
	vector<double> list[3];
	vector<int> maxl(3,0);
	for (int i = 0; i < 3; ++i) {
		double a, b, c;
		cin >> a >> b >> c;
		list[i].push_back(a);
		list[i].push_back(b);
		list[i].push_back(c);
		for (int j = 0; j < 3; ++j) {
			// cout << "11" << endl;
			if (list[i] [maxl[i] ] < list[i][j]) {
				maxl[i] = j;
			}
		}
	}

	double sum = 1;
	for (int i = 0; i < 3; ++i) {
		sum = sum * list[i][maxl[i]];
		cout << ch[maxl[i]] << " ";
	}
	printf("%.2lf",(sum*0.65 - 1) * 2);
    return 0;
}

