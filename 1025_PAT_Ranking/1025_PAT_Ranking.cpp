// 1025_PAT_Ranking.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int num = 0;
	vector < map<int, vector<string> > > lists(N);
	map<int, vector<string> > totl;
	map<string, vector<int> > student;
	for (int n = 0; n < N; ++n) {
		int K;
		cin >> K;
		num = num + K;
		for (int k = 0; k < K; ++k) {
			string id;
			int score;
			cin >> id >> score;
			lists[n][score].push_back(id);
			totl[score].push_back(id);
			student[id].push_back(n + 1);
		}
	}
	for (int n = 0; n < N; ++n) {
		int rank = 1;
		for (auto it1 = lists[n].rbegin(); it1 != lists[n].rend(); it1++) {
			for (auto it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
				student[(*it2)].push_back(rank);
			}
			rank = rank + (*it1).second.size();
		}
	}
	cout << num << endl;
	int rank = 1;
	for (auto it1 = totl.rbegin(); it1 != totl.rend(); it1++){
		sort((*it1).second.begin(), (*it1).second.end());
		for (auto it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
			cout << (*it2) << " " << rank << " " << student[(*it2)][0] << " " << student[(*it2)][1] << endl;
		}
		rank = rank + (*it1).second.size();
	}
    return 0;
}