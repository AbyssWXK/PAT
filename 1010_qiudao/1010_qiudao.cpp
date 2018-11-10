// 1010_qiudao.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	int dxs[1000][2];
	int i;
	int len;
	for (i = 0; dxs[i-1][1] != 0; i++) {
		scanf("%d %d", &dxs[i][0], &dxs[i][1]);
	}
	len = i + 1;
	for (i = 0; i <len; i++) {
		dxs[i][0] = dxs[i][0] * dxs[i][1];
		dxs[i][1]--;
	}
	printf("%d %d", dxs[0][0], dxs[0][1]);
	for (i = 1; i<len; i++) {
		if (dxs[i][1] >= 0) {
			printf(" %d %d", dxs[i][0], dxs[i][1]);
		}
		if (dxs[i][1] ==-1 ) {
			if (dxs[i - 1][1] == 0) {
				break;
			}
			else
				printf(" 0 0");
		}
	}
    return 0;
}
