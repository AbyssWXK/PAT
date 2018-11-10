// ad1005_spell_it_right.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
string result = "0";
void add(char a) {
	int carry = 0;
	for (long long i = result.size() - 1; i >= 0; --i) {
		if (i == result.size() - 1) {
			result[i] = result[i] + a - '0';
		}
		result[i] = result[i] + carry;
		carry = 0;
		if (result[i] > '9') {
			carry = 1;
			result[i] = result[i] - 10;
		}
		else {
			break;
		}
	}
	if (carry == 1) {
		result = '1' + result;
	}
}
int main()
{
	string eng[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	string num;
	cin >> num;
	for (long long i = 0; i < num.size(); ++i) {
		add(num[i]);
	}
	cout << eng[(result[0] - '0')];
	for (long long i = 1; i < result.size(); ++i) {
		cout<<" "<< eng[(result[i] - '0')];
	}
    return 0;
}

