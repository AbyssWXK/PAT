// ad1003_Emergency.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
using namespace std;
int main()
{
	const int MAX = 200000000;		// MAX
	int N, P, F, T;
	cin >> N >> P >> F >> T;
	vector<int> weight(N, 0);
	for (vector<int>::iterator iter = weight.begin(); iter != weight.end(); ++iter) {
		cin >> (*iter);
	}
	vector<vector<int> > gp(N);			// Graph init with MAX
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			(gp[i]).push_back(MAX);
		}
	}
	for (int i = 0; i < P; ++i) {	// input graph
		int l, r, val;
		cin >> l >> r >> val;
		gp[l][r] = val;
		gp[r][l] = val;
	}
	// record number of shortest path
	vector<int> num(N);
	// record length of shortest path
	vector<int> dis(N);
	// record weight of shorterst path
	vector<int> w(N);
	// record if a potint reach shorterst
	vector<bool> visit(N);
	/*for (int i = 0; i < N; ++i) {
		cout << num[i] << " " << dis[i] << " " << visit[i] << " " << endl;
	}*/
	// init dis[]
	for (int i = 0; i < N; ++i) {
		dis[i] = MAX;
	}
	dis[F] = 0;
	w[F] = weight[F];
	num[F] = 1;
	for (int i = 0; i < N ; i++) {
		int u = -1, minn = MAX;
		for (int j = 0; j < N; j++) {
			if (visit[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 0; v < N; v++) {
			if (visit[v] == false && gp[u][v] != MAX) {
				if (dis[u] + gp[u][v] < dis[v]) {
					dis[v] = dis[u] + gp[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				else if (dis[u] + gp[u][v] == dis[v]) {
					num[v] = num[v] + num[u];
					if (w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
				}
			}
		}
	}

	printf("%d %d\n", num[T], w[T]);




	// output graph
	for (int i = 0; i < N; ++i) {	// input graph
		for (int j = 0; j < N; ++j) {
			cout << gp[i][j] << "\t";
		}
		cout << endl;
	}

    return 0;
}

