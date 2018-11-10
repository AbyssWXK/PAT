// 1004_Counting_Leaves.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector <int> tree[100];
int book[100] = { 0 };
int maxdepth = -1;
void dfs(int index,int depth) {
	if (tree[index].size() == 0) {
		book[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}
	for (int i = 0; i < tree[index].size(); ++i) {
		dfs(tree[index][i], depth + 1);
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int fa, nos;
		cin >> fa >> nos;
		for(int j = 0; j < nos; ++j ) {
			int temp;
			cin >> temp;
			tree[fa].push_back(temp);
		}
	}
	dfs(1, 0);
	cout << book[0];
	for (int i = 1; i <= maxdepth; ++i) {
		cout << " " << book[i];
	}
    return 0;
}

