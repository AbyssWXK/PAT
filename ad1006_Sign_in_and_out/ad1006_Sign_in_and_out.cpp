// ad1006_Sign_in_and_out.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string unlock, lock;
	int min=100000, max=-1;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int ih, im, is,oh,om,os;
		string temp;
		cin >> temp;
		scanf("%d:%d:%d %d:%d:%d", &ih, &im, &is, &oh, &om, &os);
		int itime = ih * 10000 + im * 100 + is;
		int otime = oh * 10000 + om * 100 + os;
		if (itime < min) {
			min = itime;
			unlock = temp;
		}
		if (otime > max) {
			max = otime;
			lock = temp;
		}
	}
	cout << unlock << " " << lock;
    return 0;
}

