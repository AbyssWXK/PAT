// ad1015_prime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct conum {
	int num;
	int rad;
	int val;
	int tval;
	conum(int, int);
	conum() {};
};
int fang(int, int);
bool isprime(int);
string trans(string);
string nts(int ,int);
int main()
{
	vector<conum> list;
	while (true) {
		int temps;
		int tempt;
		cin >> temps;
		if (temps<0)
			break;
		cin>> tempt;
		conum temp(temps, tempt);
		list.push_back(temp);
	}
	for (vector<conum>::iterator iter = list.begin(); iter != list.end(); iter++) {
		if (isprime((*iter).val) && isprime((*iter).tval)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
    return 0;
}
conum::conum(int nu, int a) {
	num = nu;
	rad = a;
	tval = 0;
	val = 0;
	string s = nts(nu, a);
	for (int i = 0; i < s.size(); i++) {
		int x = s[s.size() - i - 1] - '0';
		val = val + fang(a, i)*x;
	};
	for (int i = 0; i < s.size(); i++) {
		int x = s[s.size() - i - 1] - '0';
		tval = tval + fang(a, s.size() - i - 1)*x;
	}
	// cout << val << " " << tval << endl;
}
int fang(int a, int n) {
	int val = 1;
	for (int k = 0; k < n; k++) {
		val = val*a;
	}
	return val;
}
bool isprime(int a) {
	if (a <= 1) {
		return false;
	}
	for (int i = 2; i*i <= a; ++i) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}
string nts(int a,int d) {
	int k;
	for (k = 0; fang(d, k) < a; ++k) {
	}
	--k;
	string s;
	char x;
	int count = 0;
	for (int i=k; i >=0; --i) {
		while (a - fang(d, i) >= 0) {
			a = a - fang(d, i);
			count++;
		}
		x = count + '0';
		s = s + x;
		count = 0;
	}
	// cout << s << endl;
	return s;
}