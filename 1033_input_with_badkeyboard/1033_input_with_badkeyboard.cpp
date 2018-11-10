// 1033_input_with_badkeyboard.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
bool findk(string a,char x) {
	x = toupper(x);
	// cout << x << endl;
	for (int i = 0; i < a.size(); ++i) {
		if (x == a[i]) {
			return true;
		}
	}
	return false;
}
int main()
{
	string badkey;
	cin >> badkey;
	string input;
	cin >> input;
	int upf = 0;
	if (findk(badkey, '+')) {
		upf = 1;
	}
	for (int i = 0; i < input.size(); ++i) {
		if (findk(badkey, input[i])) {
			continue;
		}
		if (upf == 1 && input[i] <= 'Z'&&input[i] >= 'A') {
			continue;
		}
		cout << input[i];
	}
	cout << endl;
    return 0;
}

