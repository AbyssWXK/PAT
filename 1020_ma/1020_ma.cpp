// 1020_ma.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int kind;					// ����
	int lot;					// ����
	cin >> kind >> lot;	
	double  *klot;					// �����±�����
	double *kval;					// �����±����ܼ�ֵ
	double *evet;				// �����±���ÿ�ּ۸�
	klot = new double [kind];
	kval = new double[kind];
	evet = new double[kind];
	// �ֱ���������±�����Ϣ������ÿ�ֵļ۸�
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
	int *rindex;				//�����۴Ӵ�С���������
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
	// ÿ���±��ķ�����
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
	// ������ӯ��
	double sum = 0;
	for (int i = 0; i < kind; i++) {
		sum = dst[rindex[i]] * evet[rindex[i]] + sum;
	}
	printf("%.2f", sum);
    return 0;
}

