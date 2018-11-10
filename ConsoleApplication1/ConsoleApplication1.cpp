// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
int test(char*);
int main() {
	char str[10][101];
	int yn = 0;
	int k = 0;
	int i = 0;
	int j = 0;
	scanf("%d", &k);
	for (i = 0; i<k; i++)
		scanf("%s", &(str[i][0]));
	for (j = 0; j < k; j++) {
		yn = test(&(str[j][0]));
		if (yn == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
int test(char*str) {
	int i = 0;
	int al = 0;
	int ar = 0;
	int am = 0;
	int result;
	while (1) {
		if (str[i] == 'P') {
			i++;
			while (1) {
				if (str[i] == 'A') {
					i++;
					am++;
					while (1) {
						if (str[i] == 'T') {
							i++;
							while (1) {
								if (str[i] == 'A') {
									i++;
									ar++;
									continue;
								}
								if (str[i] == NULL) {
									break;
								}
							}
							break;
						}
						if (str[i] == 'A') {
							i++;
							am++;
							continue;
						}
						return 0;
					}
					break;
				}
				return 0;
			}
			break;
		}
		if (str[i] == 'A') {
			i++;
			al++;
			continue;
		}

		return 0;
	}
	if (am == 1)
		return 1;
	if (ar - am*al >= 0)
		return 1;
	return 0;
}