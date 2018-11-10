// ad1016_phone_bills.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct record {
	string name;
	int status, month, time, day, hour, minute;
};
bool cmp(record a, record b) {
	if (a.name == b.name) {
		return a.time < b.time;
	}
	else {
		return a.name < b.name;
	}
}
double billFromZero(record call, int *rate) {
	double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
	for (int i = 0; i < call.hour; ++i) {
		total += rate[i] * 60;
	}
	return total / 100.0;
}
const string off = "off-line";
const string on = "on-line";
int pcost[25] = { 0 };

int main()
{
	for (int i = 0; i < 24; ++i) {
		cin >> pcost[i];
		pcost[24] += pcost[i];
	}
	int N;
	scanf("%d", &N);
	vector<record> data(N);
	for (int i = 0; i < N; ++i) {
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
		string tpstr;
		cin >> tpstr;
		if (tpstr == off) {
			data[i].status = 0;
		}
		else {
			data[i].status = 1;
		}
		data[i].time = (data[i].day * 24 + data[i].hour) * 60 + data[i].minute;
	}
	sort(data.begin(), data.end(), cmp);
	map<string, vector<record> > custom;
	/*for (auto it : data) {
		cout << it.name << " " << it.time <<" "<<it.status<<endl;
	}*/
	for (int i = 1; i < N; ++i) {
		if (data[i].name == data[i - 1].name&&data[i - 1].status == 1 && data[i].status == 0) {
			custom[data[i - 1].name].push_back(data[i - 1]);
			custom[data[i].name].push_back(data[i]);
		}
	}
	for (auto it : custom) {
		
		vector<record> temp = it.second;
		cout << it.first;
		printf(" %02d\n", temp[0].month);
		double total = 0.0;
		for (int i = 1; i < temp.size(); i += 2) {
			double t = billFromZero(temp[i], pcost) - billFromZero(temp[i - 1], pcost);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}

    return 0;
}

