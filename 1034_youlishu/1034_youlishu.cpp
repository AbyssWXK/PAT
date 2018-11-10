// 1034_youlishu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct yls{
	long long z;
	long long fz;
	long long fm;
	yls() {};
	yls(long long  fz1, long long fm1, long long z1 = 0) {
		z = z1;
		fz = fz1;
		fm = fm1;
	}
	void display() {
		if (fm == 0) {
			cout << "Inf";
			return ;
		}
		if (fz == 0 && z == 0) {
			cout << "0";
			return;
		}
		if (fz < 0 || z<0) {
			cout << "(";
		}
		if (z != 0) {
			cout << z ;
			if (fz != 0)
				cout << " ";
		}
		if (fz != 0) {
			cout << fz << "/" << fm;
		}
		if (fz < 0||z<0) {
			cout << ")";
		}
	}
};
yls add(yls, yls);
yls atad(yls, yls);
yls mul(yls, yls);
yls chu(yls, yls);
yls tran(yls);
int main()
{
	long long tfz, tfm;
	scanf("%lld/%lld",&tfz,&tfm);
	yls A(tfz, tfm);
	scanf("%lld/%lld", &tfz, &tfm);
	yls B(tfz, tfm);
	yls a = tran(A);
	yls b = tran(B);
	a = tran(a);
	b = tran(b);
	// +
	yls ru = add(A, B);
	ru = tran(ru);
	a.display();
	cout << " + ";
	b.display();
	cout << " = ";
	ru.display();
	cout << endl;
	// -
	ru = atad(A, B);
	ru = tran(ru);
	a.display();
	cout << " - ";
	b.display();
	cout << " = ";
	ru.display();
	cout << endl;
	// *
	ru = mul(A, B);
	ru = tran(ru);
	a.display();
	cout << " * ";
	b.display();
	cout << " = ";
	ru.display();
	cout << endl;
	// /
	ru = chu(A, B);
	if (ru.fm != 0) {
		ru = tran(ru);
	}
	a.display();
	cout << " / ";
	b.display();
	cout << " = ";
	ru.display();
	cout << endl;
    return 0;
}
yls add(yls a, yls b) {
	long long tfz, tfm;
	tfm = a.fm*b.fm;
	a.fz = a.fz*b.fm;
	b.fz = b.fz*a.fm;
	tfz = a.fz + b.fz;
	yls ru(tfz, tfm);
	return ru;
}
yls atad(yls a, yls b) {
	long long tfz, tfm;
	tfm = a.fm*b.fm;
	a.fz = a.fz*b.fm;
	b.fz = b.fz*a.fm;
	tfz = a.fz - b.fz;
	yls ru(tfz, tfm);
	return ru;
}
yls mul(yls a, yls b) {
	long long tfz, tfm;
	tfm = a.fm*b.fm;
	tfz = a.fz *b.fz;
	yls ru(tfz, tfm);
	return ru;
}
yls chu(yls a, yls b) {
	long long temp;
	temp = b.fm;
	b.fm = b.fz;
	b.fz = temp;
	if (b.fm < 0) {
		b.fm = -b.fm;
		b.fz = -b.fz;
	}
	yls ru = mul(a, b);
	return ru;
}
yls tran(yls a) {
	int falg = 0;
	if (a.fz < 0) {
		falg = 1;
		a.fz = -a.fz;
	}
	while (a.fz - a.fm >= 0) {
		a.fz = a.fz - a.fm;
		++a.z;
	}
	for (long i = 2; i*i <= a.fm; ++i) {
		if (a.fm%i == 0 && a.fz%i == 0) {
			a.fm = a.fm / i;
			a.fz = a.fz / i;
			i = 1;
		}
	}
	if (falg == 1) {
		if (a.z != 0) {
			a.z = -a.z;
		}
		else {
			a.fz = -a.fz;
		}
	}
	return a;
}
