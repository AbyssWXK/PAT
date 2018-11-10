// 1028_research.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct birth {
	string name;
	int birthday;
	birth(string, int n,int y,int r);
	birth() {};
	void display() {
		cout << name << " " << birthday << endl;
	}
	bool legal();
};
int main()
{
	int num;			//input number
	cin >> num;
	vector<birth>allb(num);
	for (vector<birth>::iterator iter = allb.begin(); iter != allb.end(); ++iter) {
		string name;
		int n, y, r;
		cin >> name;
		scanf("%d/%d/%d", &n, &y, &r);
		birth temp(name, n, y, r);
		*iter = temp;
	}
	int count = 0;
	vector<birth> aft;
	for (vector<birth>::iterator iter = allb.begin(); iter != allb.end();++iter) {
		if ((*iter).legal()) {
			aft.push_back((*iter));
			++count;
		}
	}
	for (vector<birth>::iterator iter = aft.begin(); iter != aft.end(); ++iter) {
		(*iter).display();
	}
	if (aft.begin() == aft.end()) {
		cout << count;
	}
	birth max = aft[0];
	birth min = aft[0];
	for (vector<birth>::iterator iter = aft.begin(); iter != aft.end(); ++iter) {
		if ((*iter).birthday > max.birthday) {
			max = *iter;
		}
		if ((*iter).birthday <= min.birthday) {
			min = *iter;
		}
	}
	cout << count << " " << min.name << " " << max.name;
    return 0;
}
birth::birth(string na, int n,int y,int r) {
	this->name = na;
	this->birthday = n * 10000 + y * 100 + r;
}
bool birth::legal() {
	if (birthday > 20140906 || birthday < 18140906) {
		return false;
	}
	else
		return true;
}

