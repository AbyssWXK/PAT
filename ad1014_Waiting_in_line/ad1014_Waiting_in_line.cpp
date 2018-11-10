// ad1014_Waiting_in_line.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<deque>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map> 
using namespace std;

int time1 = 0;
int N, M, K, Q;
int falg = 0;
deque<pair<int, int> > yellow;

void display(int a) {
	if (a > 540) {
		cout << "Sorry" << endl;
	}
	else {
		int h = 0, m = 0;
		while (a - 60 >= 0) {
			++h;
			a = a - 60;
		}
		if (h + 8 > 9) {
			if (a > 9) {
				cout << h + 8 << ":" << a << endl;
			}
			else {
				cout << h + 8 << ":0" << a << endl;
			}
		}
		else {
			if (a > 9) {
				cout << "0" << h + 8 << ":" << a << endl;
			}
			else {
				cout << "0" << h + 8 << ":0" << a << endl;
			}
		}
	}
}

void checkmin(vector<deque<pair<int, int> > > &que) {
	int min = 10000000;
	for (int i = 0; i < N; ++i) {
		if (que[i].size() != 0) {
			if (que[i][0].second < min) {
				min = que[i][0].second;
			}
		}
	}
	// cout << "min:" << min << endl;
	for (int i = 0; i < N; ++i) {
		if (que[i].size() != 0) {
			que[i][0].second = que[i][0].second - min;
		}
	}
	time1 = time1 + min;
	if (time1 > 540) {
		falg = 1;
	}
}
int checkz(vector<deque<pair<int,int> > > &que) {
	for (int i = 0; i < N; ++i) {
		if (que[i].size() != 0) {
			if (que[i][0].second == 0) {
				int customer = que[i][0].first;
				que[i].pop_front();
				if (yellow.size() != 0) {
					// if (falg = 0) {
						que[i].push_back(yellow[0]);
						yellow.pop_front();
					// }
					// else {
					// 	yellow[0].second = yellow[0].second + 540;
					// 	que[i].push_back(yellow[0]);
					// 	yellow.pop_front();
					// }
				}
				return customer;
			}
		}
	}
	return -1;
}
int main()
{
	cin >> N >> M >> K >> Q;
	vector<int> servedtime1(K, 0);
	vector<deque<pair<int,int> > > query(N);
	int k = 0;
	for (k = 0; k < M * N; ) {
		for (int i = 0; i < N; ++i) {
			int tptm;
			cin >> tptm;
			// cout << "f:" << k << " s:" << tptm << endl;
			query[i].push_back(make_pair(k, tptm));
			++k;
		}
	}
	for (; k < K ; ++k) {
		int tptm;
		cin >> tptm;
		yellow.push_back(make_pair(k, tptm));
	} 
	/*for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout<<query[i][j].first<<" ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < K; ) {
		// cout << "time1:" << time1 << endl;

		/*for (int ix = 0; ix < N; ++ix) {
			for (int jx = 0; jx < query[ix].size(); ++jx) {
				cout << query[ix][jx].second << " ";
			}
			cout << endl;
		}*/

		int check = checkz(query);
		if (check!=-1) {
			// cout << "checkz:" << check <<endl;
			servedtime1[check] = time1;
			++i;
		}
		else {
			checkmin(query);
		}
	}
	for (int i = 0; i < K; ++i) {
		cout << servedtime1 << " ";
		cout << endl;
	}
	int tpc;
	cin >> tpc;
	display( servedtime1[tpc - 1]);
	for (int i = 1; i < Q; ++i) {
		cin >> tpc;
		display( servedtime1[tpc-1]);
	}
    return 0;
}

