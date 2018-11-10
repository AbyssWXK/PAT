// 1037_HP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct hpm{
	int G, S, K;
	int mk;
	hpm(){}
	hpm(int g, int s, int k) {
		G = g;
		S = s;
		K = k;
		mk = (g * 17 + s) * 29 + k;
	}
};

int main()
{
	int g, s, k;
	scanf("%d.%d.%d", &g, &s, &k);
	hpm P(g, s, k);
	scanf("%d.%d.%d", &g, &s, &k);
	hpm A(g, s, k);

	hpm out(0, 0, 0);
	out.mk = A.mk - P.mk; 
	int falg = 0;
	if (out.mk < 0) {
		falg = 1;
		out.mk = -out.mk;
	}
	out.K = out.mk;
	while (out.K - 29 >= 0) {
		out.K = out.K - 29;
		++out.S;
	}
	while (out.S - 17 >= 0) {
		out.S = out.S - 17;
		++out.G;
	}
	if (falg == 1) {
		cout << "-";
	}
	cout << out.G << "." << out.S << "." << out.K;
    return 0;
}

