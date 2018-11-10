// 1018_cjb.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
enum resolution {win,equ,lose};
enum resolution match(char a, char b) {
	if (a == b) {
		return equ;
	}
	else {
		if (a == 'C'&&b == 'J' || a == 'J'&&b == 'B' || a == 'B'&&b == 'C') {
			return win;
		}
		else
			return lose;
	}
}
int ctn(char a) {		//记录常胜手势符号到索引的转换
	if (a == 'B')
		return 0;
	else {
		if (a == 'C')
			return 1;
		else
			return 2;
	}
}
char ntc(int a) {		// 记录常胜手势索引到符号的转换
	if (a == 0)
		return 'B';
	else {
		if (a == 1)
			return 'C';
		else
			return 'J';
	}
}
// 从三种手势中找到最多的
int maxi(int *a) {
	int max = 0;
	for (int i = 0; i < 3; i++) {  
		if (a[max] < a[i]) {
			max = i;
		}
	}
	return max;
}
int main()
{
	int inum;			// 交锋次数
	cin >> inum;
	char **mainfo;		// 交锋二维数组,并初始化
	mainfo = new char*[inum];
	for (int i = 0; i < inum; i++) {
		mainfo[i] = new char[2];
		cin >> mainfo[i][0] >> mainfo[i][1];
	}
	int awin = 0;
	int equ = 0;
	int alose = 0;
	int awin_c[3] = { 0,0,0 };
	int bwin_c[3] = { 0,0,0 };
	for (int i = 0; i < inum; i++) {				//计算比赛结果并统计
		if (match(mainfo[i][0], mainfo[i][1]) == win) {
			awin_c[ctn(mainfo[i][0])]++;
			awin++;
			
		}
		else {
			if (match(mainfo[i][0], mainfo[i][1]) == lose) {
				alose++;
				bwin_c[ctn(mainfo[i][1])]++;
			}
			else {
				equ++;
			}
		}
	}
	cout << awin << " " << equ << " " << alose << endl;
	cout << alose << " " << equ << " " << awin << endl;
	cout << ntc(maxi(awin_c)) << " " << ntc(maxi(bwin_c));
    return 0;
}

