// ad1013_Battle_over_cities.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M, K;
int cmap[1000][1000] = { 0 };
void dfs(int index,vector<int> &v, vector<int> &ved) {
	for (int i = 0; i < N; ++i) {
		// cout << v[0] << v[1] << v[2]<<endl;
		if (cmap[index][i] == 1) {
			if (v[i] == 1) {
				v[i] = 0;
				// cout << "i:" << i << endl;
				dfs(i, v, ved);
			}
		}
	}
}
int main()
{
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		int tps, tpt;
		cin >> tps >> tpt;
		cmap[tps - 1][tpt - 1] = cmap[tpt - 1][tps - 1] = 1;
	}
	for (int i = 0; i < K; ++i) {
		int cnm;
		cin >> cnm;
		vector<int> visit(N, 1);
		vector<int> vsted(N, 0);
		visit[cnm - 1] = 0;
		vsted[cnm - 1] = 1;
		int count = -1;
		while (find(visit.begin(), visit.end(), 1) != visit.end()) {
			// cout <<"count:"<< count << endl;
			int tp = find(visit.begin(), visit.end(), 1) - visit.begin();
			visit[tp] = 0;
			dfs(tp, visit, vsted);
			count++;
		}
		cout << count << endl;
	}
    return 0;
}

