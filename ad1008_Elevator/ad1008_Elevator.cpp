// ad1008_Elevator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int N, up = 0, down = 0, now = 0,temp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		if (temp - now >= 0)
			up = up + temp - now;
		else 
			down = down + now - temp;
		now = temp;
	}
	// cout << up << " " << down << endl;
	cout << N * 5 + up * 6 + down * 4;
    return 0;
}

