// 1020_ma.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int kind;					// 种类
	int lot;					// 需求
	cin >> kind >> lot;	
	double  *klot;					// 各种月饼的量
	double *kval;					// 各种月饼的总价值
	double *evet;				// 各种月饼的每吨价格
	klot = new double [kind];
	kval = new double[kind];
	evet = new double[kind];
	// 分别输入各种月饼的信息并计算每吨的价格
	for (int index=0; index < kind; index++) {
		cin >> klot[index];
	}
	for (int index=0; index < kind; index++) {
		cin >> kval[index];
	}
	for (int index=0; index < kind; index++) {
		evet[index]=(double)kval[index]/klot[index];
	}
	/* for (int i = 0; i < kind; i++) {
		cout << evet[i]<<" ";
	}
	cout << endl; */
	int *rindex;				//按单价从大到小排序的索引
	rindex = new int[kind];
	for (int i = 0; i < kind; i++) {
		rindex[i] = i;
	}
	double temp = evet[0];
	for (int i = 0; i < kind; i++) {
		for (int j = 0; j < kind - 1; j++) {
			if (evet[rindex[j]] < evet[rindex[j + 1]]) {
				temp = rindex[j];
				rindex[j] = rindex[j + 1];
				rindex[j + 1] = temp;
			}
		}
	}
	/* for (int i = 0; i < kind; i++) {
		cout << rindex[i]<<" ";
	}
	cout << endl; */
	// 每种月饼的分配量
	double *dst;
	dst = new double[kind];
	for (int i=0; i < kind; i++) {
		dst[i] = 0;
	}
	for (int i = 0; lot != 0&&i<kind ; i++) {
		if (lot - klot[rindex[i]] >= 0) {
			lot = lot - klot[rindex[i]];
			dst[rindex[i]] = klot[rindex[i]];
		}
		else {
			for (int j = 0; lot > 0 && j < klot[rindex[i]];) {
				j++;
				lot--;
				dst[rindex[i]] = j;
			}
		}

	}
	/* for (int i = 0; i < kind; i++) {
		cout << dst[i]<<" ";
	}
	cout << endl; */
	// 计算总盈利
	double sum = 0;
	for (int i = 0; i < kind; i++) {
		sum = dst[rindex[i]] * evet[rindex[i]] + sum;
	}
	printf("%.2f", sum);
    return 0;
}

