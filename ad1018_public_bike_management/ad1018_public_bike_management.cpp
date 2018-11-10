// 1018_public_bike_management.cpp : 定义控制台应用程序的入口点。
//
// sent 和back 不满足“最优子结构”，不能只使用迪杰斯特拉算法。

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


const int MAX = 10000000;
int group[501][501];
int C, N, S, M;
int main()
{
	cin >> C >> N >> S >> M;
	N++;
	for (int i = 0; i < 500; ++i) {
		for (int j = 0; j < 500; ++j) {
			group[i][j] = MAX;
		}
	}
	vector<int> bikenum(N,0);
	for (int i = 1; i < N; ++i) {
		cin >> bikenum[i];
	}
	bikenum[0] = C / 2;
	for (int i = 0; i < M; ++i) {
		int tpi, tpj, tpl;
		cin >> tpi >> tpj >> tpl;
		group[tpi][tpj] = group[tpj][tpi] = tpl;
	}
	vector<bool> down(N, false);
	vector<int> dis(N,MAX);
	dis[0] = 0;
	vector<int> sent(N);
	vector<int> back(N);
	vector<string> path(N);
	path[0] = "0";
	for (int k = 0; k < N; ++k) {
		int min = MAX;
		int index = -1;
		for (int i = 0; i < N; ++i) {
			if (min > dis[i] && !down[i]) {
				index = i;
				min = dis[i];
			}
		}
		if (index == -1)
			break;
		down[index] = true;
		for (int i = 0; i < N; ++i) {
			if (!down[i] && group[index][i] != MAX) {
				if (dis[index] + group[index][i] < dis[i]) {
					dis[i] = dis[index] + group[index][i];
					path[i] = path[index] + "->" + to_string(i);
					int need = 0;
					if (bikenum[i] >= C / 2) {
						back[i] = back[index] + bikenum[i] - C / 2;
					}
					else {
						back[i] = back[index];
						need = C / 2 - bikenum[i];
						while (back[i] - 1 >= 0 && need > 0) {
							--need;
							--back[i];
						}
					}
					sent[i] = sent[index] + need;
				}
				else {
					if (dis[index] + group[index][i] == dis[i]) {
						int tpst ;
						int need = 0;
						int tpbk = back[index];
						if (bikenum[i] < C / 2) {
							need = C / 2 - bikenum[i];
							while (tpbk - 1 >= 0 && need > 0) {
								--need;
								--tpbk;
							}
						}
						else {
							tpbk = tpbk + bikenum[i] - C / 2;
						}
						tpst = sent[index] + need;
						if (tpst < sent[i]) {
							path[i] = path[index] + "->" + to_string(i);
							back[i] = tpbk;
							sent[i] = tpst;
						}
						else{
							if (tpst==sent[i]) {
								if (tpbk > back[i]) {
									back[i] = tpbk;
									path[i] = path[index] + "->" + to_string(i);
								}
							}
						}
					}
				}
			}
		}
	}
	//for (int i = 0; i < N; ++i) {
	//	cout << (path[i]) << " sent:" << sent[i] << " back:" << back[i] << endl;
	//}
	cout << sent[S] << " " << path[S] << " " << back[S] << endl;
    return 0;
}