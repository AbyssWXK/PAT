// ad1007_Max_subsquence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int *sq;
	sq = new int(N);
	for (int i = 0; i < N; ++i) {
		cin >> sq[i];
	}
	int falg = 0;
	for (int i = 0; i < N; ++i) {
		if (sq[i] >= 0) {
			falg = 1;
		}
	}
	if (falg == 0) {
		cout << "0 " << sq[0] <<" "<< sq[N - 1];
		return 0;
	}
	int maxsum = -1;
	int sum ,itf,ite,iter1,iter2;
	sum = itf = ite = iter1 = iter2 = 0;
	for (iter2 = iter1 ; iter2 < N; ++iter2) {
		sum = sum + sq[iter2];
		if (sum < 0) {
			iter1 = iter2 + 1;
			sum = 0;
		}
		else {
			if (sum > maxsum) {
				itf = iter1;
				ite = iter2;
				maxsum = sum;
			}
		}
	}
	cout << maxsum << " " << sq[itf] << " " << sq[ite];
    return 0;
}

