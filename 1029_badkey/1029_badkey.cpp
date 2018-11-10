// 1029_badkey.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<cctype>
using namespace std;
bool ins(string&, char);
int main()
{
	string ori ;
	string af;
	string bad;
	cin >> ori;
	cin >> af;
	for (int i = 0, j = 0; i < ori.size(); ++i) {
		if (ori[i] == af[j]) {
			++j;
		}
		else {
			char temp = toupper(ori[i]);
			if (!(ins(bad,temp))) {
				bad = bad + temp;
			}
		}
	}
	cout << bad;
	return 0;
}
bool ins(string &s, char c) {
	for (string::size_type i = 0; i < s.size(); ++i) {
		if (s[i] == c) {
			return true;
		}
	}
	return false;
}
