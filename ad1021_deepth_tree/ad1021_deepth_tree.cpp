// 1021_deepth_tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector< vector<int> > graph;
vector<int> depth;
vector<bool> book;
vector<bool> visit;

void dfs(int root,int tpi, int hight) {
	if (depth[root] < hight) {
		depth[root] = hight;
	}
	visit[tpi] = true;
	book[tpi] = true;
	for (int i = 0; i < graph[tpi].size(); i++) {
		if (visit[graph[tpi][i]]==false) {
			dfs(root, graph[tpi][i], hight + 1);
		}
	}
}
int main()
{
	cin >> N;
	graph.resize(N);
	depth.resize(N);
	book.resize(N);
	visit.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	int k = 0;
	int falsenum = N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; j++) {
			visit[j] = false;
		}
		dfs(i,i, 1);
		int temp = 0;
		for(int j=0;j<N;++j){
			if (book[j] == false) {
				temp++;
			}
		}
		if (temp != falsenum) {
			k++;
			falsenum = temp;
		}
	}
	if (k > 1) {
		cout << "Error: " << k << " components";
		return 0;
	}
	else {
		int max = 0;
		for (int i = 0; i < N; i++) {
			if (depth[i] > max) {
				max = depth[i];
			}
		}
		for (int i = 0; i < N; ++i) {
			if (depth[i] == max) {
				cout << i+1 << endl;
			}
		}
	}
    return 0;
}