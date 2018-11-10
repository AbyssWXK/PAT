// 1020_tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int posord[31];
int inord[31];
vector<int> levelord[31];
void level(int root,int ai,int bi,int dp) {
	if (ai > bi) {
		return;
	}
	// cout << posord[root] << " " << ai << " " << bi << " " << dp << endl;
	levelord[dp].push_back(posord[root]);
	int i = 0;
	for (i = ai; i < bi; ++i) {
		if (inord[i] == posord[root]) {
			break;
		}
	}
	// cout << i << endl;
	level(root - 1 - bi + i, ai, i - 1, dp + 1);
	level(root - 1, i + 1, bi, dp + 1);
}
int main()
{
	cin >> N;
	int temp;
	for (int i = 0; i < N; ++i) {
		cin >> posord[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> inord[i];
	}
	level(N - 1, 0, N - 1, 0);
	cout << levelord[0][0];
	for (int i = 1; i < 31; ++i) {
		for (auto it = levelord[i].begin(); it != levelord[i].end(); ++it) {
			cout << " " << (*it);
		}
	}
    return 0;
}

