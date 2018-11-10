// ad1010_Radix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<char, int> repr = { { '0',0 },{ '1',1 },{ '2',2 },{ '3',3 },{ '4',4 },{ '5',6 },{ '6',6 },{ '7',7 },{ '8',8 },{ '9',9 },{ 'a',10 },{ 'b',11 },{ 'c',12 },{ 'd',13 },{ 'e',14 },{ 'f',15 },{ 'g',16 },{ 'h',17 },{ 'i',18 },{ 'j',19 },{ 'k',20 },{ 'l',21 },{ 'm',22 },{ 'n',23 },{ 'o',24 },{ 'p',25 },{ 'q',26 },{ 'r',27 },{ 's',28 },{ 't',29 },{ 'u',30 },{ 'v',31 },{ 'w',32 },{ 'x',33 },{ 'y',34 },{ 'z',35 } };
// map<char, int> rrepr = { { '0',0 },{ '1',1 },{ '2',2 },{ '3',3 },{ '4',4 },{ '5',6 },{ '6',6 },{ '7',7 },{ '8',8 },{ '9',9 },{ 'a',10 },{ 'b',11 },{ 'c',12 },{ 'd',13 },{ 'e',14 },{ 'f',15 },{ 'g',16 },{ 'h',17 },{ 'i',18 },{ 'j',19 },{ 'k',20 },{ 'l',21 },{ 'm',22 },{ 'n',23 },{ 'o',24 },{ 'p',25 },{ 'q',26 },{ 'r',27 },{ 's',28 },{ 't',29 },{ 'u',30 },{ 'v',31 },{ 'w',32 },{ 'x',33 },{ 'y',34 },{ 'z',35 } };

unsigned long long fang(unsigned long long a, int k) {
	unsigned long long result = 1;
	for (int i = 0; i < k; ++i) {
		result = result*a;
		// cout << a << " " << k << " fang:" << result << endl;
	}
	// cout <<"fang:  "<< result << endl;
	return result;
}
unsigned long long stn(string a, unsigned long long rad) {
	long long val = 0;
	for (int i = 0; i < a.size(); ++i) {
		val = repr[a[i]] * fang(rad, a.size() - i - 1) + val;
		// cout << "stn:" << repr[ a[i] ] << " "<< repr[a[i]] * fang(rad, a.size() - i - 1) <<" " <<val << endl;
	}
	return val;
}
int main()
{
	int tag;
	unsigned long long rad;
	string N1, N2;
	cin >> N1 >> N2 >> tag >> rad;
	unsigned long long val = 0;
	if (tag == 2) {
		string temp;
		temp = N1;
		N1 = N2;
		N2 = temp;
	}
	// cout << N1 << " " << N2 << endl;
	val = stn(N1, rad);
	// cout << val<<endl;
	unsigned long long down = '2';
	unsigned long long up = val;
	for (int i = 0; i < N2.size(); ++i) {
		if (N2[i] > down) {
			down = N2[i];
		}
	}
	down = repr[down];
	// cout << down << " " << up << endl;
	unsigned long long tval = 0;
	int falg = 0;
	unsigned long long tprad = -2;
	unsigned long long ltp = -1;
	while(ltp != tprad ) {
		ltp = tprad;
		tprad = (up + down) / 2;
		tval = stn(N2, tprad);
		// cout << val << " " << tval << " " << tprad << endl;
		if (tval == val) {
			falg = 1;
			break;
		}
		if (tval > val) {
			up = tprad;
		}
		else {
			down = tprad;
		}
	}
	if (falg == 0) {
		cout << "Impossible";
	}
	else {
		if (val == 0) {
			cout << 2;
		}
		else {
			cout << tprad;
		}
	}
    return 0;
}

