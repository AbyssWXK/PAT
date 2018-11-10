// ad1024_Palindromic_Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string add(string a, string b) {
	int r=0;
	for (int i = 0; i < a.size(); ++i) {
		a[i] = a[i] - '0' + b[i] - '0' + r + '0';
		if (a[i] > '9') {
			r = 1;
			a[i] = a[i] - 10;
		}
		else {
			r = 0;
		}
	}
	if (r == 1) {
		a = a + "1";
	}
	reverse(a.begin(), a.end());
	return a;
}
int main()
{
	string str1;
	cin >> str1;
	int K;
	cin >> K;
	int i = 1;
	int falg = 0;
	string str2(str1);
	for (i = 0; i <= K;) {
		reverse(str2.begin(), str2.end());
		if (str1 == str2|| i==K ) {
			if (i != K)
				falg = 1;
			break;
		}
		str1 = add(str1, str2);
		i++;
		str2 = str1;
	}
	if (falg == 0) {
		cout << str1 << endl;
		cout << i;
	}
	else {
		cout << str1 << endl;
		cout << i;
	}
    return 0;
}

