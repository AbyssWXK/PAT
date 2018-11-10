// 1031_idhash.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<iostream>
#include<cctype>
using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<string> list;
	vector<string> bad;
	int power[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char hash[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	for (int i = 0; i < num; ++i) {
		string temp;
		cin >> temp;
		if (temp.size() != 18) {
			bad.push_back(temp);
			continue;
		}
		int falg = 0;
		for (int j = 0; j < 17; ++j) {
			if (!isdigit(temp[j])) {
				bad.push_back(temp);
				falg = 1;
				break;
			}
		}
		if ( falg == 0) {
			int sum = 0;
			char jug = 0;
			int ijug = 0;
			for (int j = 0; j < 17; ++j) {
				sum = (temp[j] - '0')*power[j] + sum;
			}
			ijug = sum % 11;
			jug = hash[ijug];
			if (temp[17] != jug) {
				bad.push_back(temp);
			}
		}
	}
	/*for (int i = 0; i < num; ++i) {
		cout << list[i];
	}*/
	/*for (vector<string>::iterator iter = list.begin(); iter != list.end(); ++iter) {

		int sum=0;
		char jug=0;
		int ijug = 0;
		for (int j = 0; j < 17; ++j) {
			sum = ((*iter)[j] - '0')*power[j] + sum;
		}
		ijug = sum % 11;
		jug = hash[ijug];
		if ((*iter)[17] != jug) {
			bad.push_back((*iter));
		}
	}*/

	if ( bad.begin() == bad.end()) {
		cout << "All passed";
	}
	else {
		for (vector<string>::iterator iter=bad.begin();iter!=bad.end(); ++iter) {
			cout << *iter<<endl;
		}
	}
    return 0;
}

