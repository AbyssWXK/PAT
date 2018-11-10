// 1017_chufa.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int num01 = 49;
	int num02 = 7;
	char bignum[1001];
	char val[1001];
	int cs;
	int shang;
	int temp=0;
	cin >> bignum >> cs;
	val[0] = 0;
	int i;
	for (i = 0; bignum[i] != '\0'; i++) {
		shang = bignum[i] - '0';
		temp = temp * 10 + shang;
		if (temp < cs) {
			val[i] = '0';
		}
		else {
			shang = temp;
			temp = temp%cs;
			shang = (shang - temp) / cs;
			val[i] = shang + '0';
		}
	}
	val[i] = '\0';
	if (bignum[0] == '0') {
		cout << "0";
	}
	else{
		if (val[0] != '0') {
			cout << val[0];
		}
		for (i = 1; val[i] != '\0'; i++) {
			cout << val[i];
		}
	}
	printf(" %d",temp);
    return 0;
}

