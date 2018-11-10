// ad1012_Best_rank.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
vector<int> Score[4];
map<string, vector<int> > student;
map<int, char> repr = { {0,'A'},{1,'C'},{2,'M'},{3,'E'} };
int main()
{
	vector<int> zero(101, 0);
	for (int i = 0; i < 4; ++i) {
		Score[i] = zero;
	}
	int N, M;
	cin >> N >> M;
	string id;
	for (int i = 0; i < N; ++i) {
		int cs, ms, es,as;
		vector<int> temp;
		cin >> id >> cs >> ms >> es;
		as = (cs + ms + es) / 3;
		temp.push_back(cs);
		temp.push_back(ms);
		temp.push_back(es);
		temp.push_back(as);
		// cout << cs << " " << ms << " " << es << " " << as << endl;
		++Score[0][cs];
		++Score[1][ms];
		++Score[2][es];
		++Score[3][as];
		student.insert({ id,temp });
	}
	for (int i = 0; i < M; ++i) {
		cin >> id;
		if (student.find(id) != student.end() ) {
			// cout << i << endl;
			vector<int> arank(4, N);
			int rank = 1;
			for (int j = 0; j < 4; ++j) {
				// cout << "1" << endl;
				rank = 1;
				for (int k = 100; k != student[id][j]; --k) {
					// cout << "2" << endl;
					rank = rank + Score[j][k];
				}
				arank[j] = rank;
				// cout << "3" << endl;
			}
			int tprk = arank[3];
			arank[3] = arank[2];
			arank[2] = arank[1];
			arank[1] = arank[0];
			arank[0] = tprk;
			// cout << arank[0] << arank[1] << arank[2] << arank[3] << endl;
			int bestindex = min_element(arank.begin(), arank.end()) - arank.begin();
			// cout << bestindex << endl;
			cout << arank[bestindex] << " " << repr[bestindex] << endl;
		}
		else {
			cout << "N/A" << endl;
		}
	}
    return 0;
}

