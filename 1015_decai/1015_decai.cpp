// 1015_decai.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool init(int* a,int len) {
	for (int i = 0; i < len; i++) {
		a[i] = -1;
	}
	return true;
}
bool append(int*a, int num,int k) {
	for (int i = 0;i<k; i++) {
		if (a[i] == -1) {
			a[i] = num;
			return true;
		}
	}
	return false;
}
bool range(int *a,int **list) {
	int i, j;
	int temp;
	for (i = 0; a[i] != -1; i++) {
		for (j = 0; a[j + 1] != -1; j++) {
			if (list[a[j]][1] + list[a[j]][2] < list[a[j + 1]][1] + list[a[j + 1]][2]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; a[i] != -1; i++) {
		for (j = 0; a[j + 1] != -1; j++) {
			if (list[a[j]][1] + list[a[j]][2] == list[a[j + 1]][1] + list[a[j + 1]][2]) {
				if(list[a[j]][1]<list[a[j+1]][1]){
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
				else
					if (list[a[j]][1] == list[a[j + 1]][1]) {
						if (list[a[j]][0] > list[a[j + 1]][0]) {
							temp = a[j];
							a[j] = a[j + 1];
							a[j + 1] = temp;
						}
					}
			}
		}
	}
	return true;
}
bool show(int*a, int **list) {
	for (int i = 0; a[i] != -1; i++) {
		cout << list[a[i]][0] << " " << list[a[i]][1] << " " << list[a[i]][2] << endl;
	}
	return true;
}

int main()
{
	int N;
	int L;
	int H;
	int k=0;
	cin >> N >> L >> H;
	int**list;
	int *list1;
	int *list2;
	int *list3;
	int *list4;
	list1 = new int[N+1];
	list2 = new int[N+1];
	list3 = new int[N+1];
	list4 = new int[N+1];
	init(list1, N + 1);
	init(list2, N + 1); 
	init(list3, N + 1);
	init(list4, N + 1);
	list = new int*[N+1];
	for (int i = 0; i < N+1; i++) {
		list[i] = new int[3];
		cin >> list[i][0] >> list[i][1] >> list[i][2];
	}
	for (int i = 0; i < N+1; i++) {
		if (list[i][1] >= L&&list[i][2] >= L) {
			k++;
			if (list[i][1] >= H&&list[i][2] >= H) {
				append(list1, i,N+1);
			}
			else {
				if (list[i][1] >= H) {
					append(list2, i,N+1);
				}
				else {
					if (list[i][1] < H&&list[i][2] < H&&list[i][1] >= list[i][2]) {
						append(list3, i,N+1);
					}
					else
						append(list4, i,N+1);
				}
			}
		}
	}
	cout << k << endl;
	range(list1, list);
	range(list2, list);
	range(list3, list);
	range(list4, list);
	show(list1, list);
	show(list2, list);
	show(list3, list);
	show(list4, list);
	return 0;
}

