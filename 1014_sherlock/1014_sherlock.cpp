// 1014_sherlock.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool ischar(char a) {
	if ((a <= 'z'&&a >= 'a')||(a <= 'Z'&&a >= 'A')) {
		return true;
	}
	else
		return false;

}
int main()
{
	char str1[61];
	char str2[61];
	char str3[61];
	char str4[61];
	int flag = 0;
	int hour = -1;
	int k = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%s", str3);
	scanf("%s", str4);
	for (int i = 0; str1[i] != '\0'; i++) {
		if (flag == 0 && str1[i] == str2[i] && str1[i] <= 'Z'&&str1[i] >= 'A') {
			if (str1[i] == 'A') {
				cout << "MON ";
			}
			if (str1[i] == 'B') {
				cout << "TUE ";
			}
			if (str1[i] == 'C') {
				cout << "WED ";
			}
			if (str1[i] == 'D') {
				cout << "THU ";
			}
			if (str1[i] == 'E') {
				cout << "FRI ";
			}
			if (str1[i] == 'F') {
				cout << "SAT ";
			}
			if (str1[i] == 'G') {
				cout << "SUN ";
			}
			flag = 1;
		}
		if (str1[i] == str2[i] && ischar(str1[i])) {
			k++;
			if (k == 2){
				hour = i;
			}
		}
		cout << k << endl;
		if (hour != -1 && flag == 1) {
			if (str1[hour] <= '9'&&str1[hour] >= '1') {
				cout << "0" << str1[hour] - '0';
			}
			else
				cout << str1[hour] - 'A' + 10;
			break;
		}
	}
	for (int i = 0; str3[i] != '\0'; i++) {
		if (str3[i] == str4[i]&& ischar(str3[i])){
			if (i < 10)
				cout << ":0" << i;
			else
				cout << ":" << i;
			break;
		}
	}

	return 0;
}

