// 1022_Djin.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
unsigned int fang(unsigned int k,unsigned int a ) {				//����a��k�η�
	unsigned int val = 1;
	for (int i = 0; i < k; i++) {
		val = val * a;
	}
	return val;
}
int main()
{
	unsigned int A;				//����abd
	unsigned int B;
	unsigned int D;
	cin >> A >> B >> D;
	unsigned int sum = A + B;
	unsigned int maxk;
	unsigned int test=sum;
	int flag = 0;
	int chge;
	for (maxk = 1; flag == 0; maxk++) {
		test = sum;
		for (int i = 0; i < D; i++) {
			chge= (double)test - fang(maxk, D);
			test = test - fang(maxk, D);
			if (chge >= 0) {
				continue;
			}
			else {
				flag = 1;
				break;
			}
		}
	}
	string result(maxk,'0');
	for (int i = 0; i < result.size(); i++) {
		int k = 0;
		while (true) {
			if ((double) sum - fang(result.size()-1 - i, D) >= 0) {
				sum = sum - fang(result.size()-1 - i, D);
				k++;
			}
			else
				break;
		}
		result[i] = k + '0';
	}
	cout << result;
    return 0;
}

