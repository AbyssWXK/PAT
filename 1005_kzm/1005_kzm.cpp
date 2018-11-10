// 1005_kzm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Kzm {
public:
	int x;
	int k[5000];
	int len;
	void compute();
	void display();
	bool exist(Kzm);
};
int numdel(int*,int,int);
int main()
{
	int k;
	int fori;
	int i=0;
	int *num;
	int j;
	int len;
	scanf("%d",&k);
	len = k;
	Kzm *kzms;
	kzms = new Kzm[k];
	num = new int[k];
	for (i = 0; i < k; i++) {
		scanf("%d", num + i);
	}
	for (i = 0; i < k; i++) {
		kzms[i].x = num[i];
	}
	for (i = 0; i < k; i++) {
		kzms[i].compute();
	}
	for (i = 0; i < k; i++) {
		num[i] = i;
	}
	for (i = 0; i < k; i++) {
		for (j = i + 1; j < k; j++) {
			if (kzms[i].exist(kzms[j])) {
				len = numdel(num, len, i);
			} 
			if (kzms[j].exist(kzms[i])) {
				len = numdel(num, len, j);
			}
		}
	}
	for (i = len-1; i >=0; i--) {
		if (i != 0) {
			cout << kzms[num[i]].x << " ";
		}
		else
			cout << kzms[num[i]].x;
	}
    return 0;
}
void Kzm::compute() {
	int val = x;
	int i;
	for (i = 0; val != 1; i++) {
		k[i] = val;
		if (val % 2 == 0) {
			val = val / 2;
		}
		else {
			val = val * 3 + 1;
			val = val / 2;
		}
	}
	k[i] = 1;
	len = i + 1;
	//display();
}
bool Kzm::exist(Kzm big) {
	int i;
	for (i = 1; i < big.len; i++) {
		if (k[0] == big.k[i])
			return true;
	}
	return false;
}
int numdel(int* num,int len,int i) {
	int j;
	for (j = 0; j < len; j++) {
		if (num[j] == i)
			break;
	}
	if (j == len)
		return len;
	for (; j < len; j++) {
		num[j] = num [ j + 1];
	}
	return len - 1;
}
void Kzm::display() {
	int i;
	for (i = 0; i < len; i++)
		cout << k[i]<<" " ;
	cout << endl;
}