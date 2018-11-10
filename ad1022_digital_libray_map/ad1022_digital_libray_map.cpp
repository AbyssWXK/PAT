// 1022_digital_libray_map.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;
int main() {
	int N;
	cin >> N;
	map<string, set<int> > search;
	for (int i = 0; i < N; ++i) {
		string temp;
		int id;
		cin >> id;
		getchar();
		getline(cin, temp);
		//cout << temp << endl;
		search[temp].insert(id);
		getline(cin, temp);
		//cout << temp << endl;
		search[temp].insert(id);
		string tpstr;
		while (cin >> tpstr) {
			search[tpstr].insert(id);
			//cout << tpstr << endl;
			char tpch = getchar();
			if (tpch == '\n')break;
		}
		//cout << endl;
		getline(cin, temp);
		//cout << temp << endl;
		search[temp].insert(id);
		cin >> temp;
		//cout << temp << endl;
		search[temp].insert(id);
	}
	int K;
	cin >> K;
	getchar();
	for (int i = 0; i < K; ++i) {
		string input;
		getline(cin, input);
		auto it1 = find(input.begin(), input.end(), ' ');
		string key(it1 + 1, input.end());
		cout << input << endl;
		if (search[key].size() == 0) {
			cout << "Not Found" << endl;
		}
		else {
			for (auto it2 = search[key].begin(); it2 != search[key].end(); ++it2) {
				printf("%07d\n", *it2);
			}
		}
	}
	return 0;
}

