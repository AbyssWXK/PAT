// ad1017_bank_query.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<deque>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct user {
	int artime;
	int severtime;
};
int N, K;
bool cmp(user a, user b) {
	return a.artime < b.artime;
}
int checkz(vector<deque<user> > a) {
	for (int i = 0; i < K; ++i) {
		if (a[i].size() == 0) {
			return i;
		}
	}
	return -1;
}
int timea = 8 * 60 * 60;
double watime = 0.0;
int main()
{
	cin >> N >> K;
	vector<deque<user> > window(K);
	vector<user> all(N);
	for (int i = 0; i < N; ++i) {
		int h, m, s;
		scanf("%d:%d:%d %d", &h, &m, &s, &all[i].severtime);
		all[i].artime = h * 60 * 60 + m * 60 + s;
		if (all[i].severtime > 60) {
			all[i].severtime = 60 * 60;
		}
		else {
			all[i].severtime = all[i].severtime * 60;
		}
	}
	sort(all.begin(), all.end(), cmp);
	auto iter1 = all.begin();
	for (; iter1 !=all.end(); ++iter1) {
		if ((*iter1).artime > 17 * 60 * 60) {
			break;
		}
	}
	deque<user> allq(all.begin(), iter1);
	int num = allq.size(); 
	while (allq.size() != 0) {
		if (checkz(window) != -1) {
			if (timea - allq[0].artime > 0) {
				watime = watime + timea - allq[0].artime;
			} 
			window[checkz(window)].push_back(allq[0]);
			allq.pop_front();
		}
		else {
			int mini = 0;
			for (int i = 0; i < K; ++i) {
				if (window[i][0].severtime < window[mini][0].severtime) {
					mini = i;
				}
			}
			timea = timea + window[mini][0].severtime;
			int tpst = window[mini][0].severtime;
			for (int i = 0; i < K; ++i) {
				window[i][0].severtime = window[i][0].severtime - tpst;
			}
			window[mini].pop_front();
		}
	}
	if (num == 0) {
		printf("0.0\n");
	}
	else {
		printf("%.1lf\n", watime / (num * 60.0));
	}
    return 0;
}