// ad1015_test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n) {
	int sqr = int(sqrt(n));
	if (n <= 1) return false;
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0) return false;

	}
	return true;
}
int main() {
	int n=2, d;
	int sum = 0;
	int r = 1;
	int num = 2;
	while (num < 100000) {
		n = num;
		if (n <= 0)  break;//��ĿҪ��Ϊ��������ֹ����ѭ��
		// scanf("%d", &d);
		d = 10;
		if (isPrime(n) == false) {
			printf("No\n");
			++num;
			continue;//��ǰ�����˴�ѭ��
		}

		int arr[100];
		int len = 0;
		while (n != 0) {
			arr[len++] = n%d;
			n /= d;
		}

		for (int i = len - 1; i >= 0; i--) {

			sum += arr[i] * r;
			r *= d;

		}
		cout << num << " ";
		if (isPrime(sum)) printf("Yes\n");
		else printf("No\n");
		++num;
	}
	return 0;
}
