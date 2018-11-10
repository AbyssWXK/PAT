// 1022_digital_library.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

struct book{
	string id;
	string  name, auth,publish,year;
	vector<string> keyword;
	void display() {
		cout << id << endl;
		cout << name << endl;
		cout << auth << endl;
		for (int i = 0; i < keyword.size(); i++) {
			cout << keyword[i] << " ";
		}
		cout << endl;
		cout << publish << endl;
		cout << year << endl;
	}
};
vector<book> books;
vector<book> result;
void findkey(string key) {
	for (int i = 0; i < books.size(); ++i) {
		if (books[i].id == key) {
			result.push_back(books[i]);
			break;
		}
		if (books[i].name == key) {
			result.push_back(books[i]);
			break;
		}
		if (books[i].auth == key) {
			result.push_back(books[i]);
			break;
		}
		if (books[i].publish == key) {
			result.push_back(books[i]);
			break;
		}
		if (books[i].year == key) {
			result.push_back(books[i]);
			break;
		}
		for (int j = 0; j < books[i].keyword.size(); j++) {
			if (books[i].keyword[j] == key) {
				result.push_back(books[i]);
				break;
			}
		}
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		book tpbook;
		string temp;
		cin >> temp;;
		getchar();
		//cout << tpid << endl;
		tpbook.id = temp;
		getline(cin, temp);
		//cout << temp << endl;
		tpbook.name = temp;
		getline(cin, temp);
		//cout << temp << endl;
		tpbook.auth = temp;
		char tpch;
		string tpstr;
		while ((tpch = getchar()) != '\n') {
			//cout << tpch << endl;
			if (tpch == ' ') {
				tpbook.keyword.push_back(tpstr);
				//cout << tpstr << endl;
				tpstr = "";
			}
			else {
				tpstr = tpstr + tpch;
			}
		}
		//cout << endl;
		getline(cin, temp);
		//cout << temp << endl;
		tpbook.publish = temp;
		cin >> temp;
		//cout << temp << endl;
		tpbook.year = temp;
		books.push_back(tpbook);
	}
	for (int i = 0; i < N; ++i) {
		// books[i].display();
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		string search;
		getline(cin, search);
		auto it1 = find(search.begin(), search.end(), ' ');
		string key(it1 + 1, search.end());
		findkey(key);
		for (int j = 0; j < result.size(); ++j) {
			result[j].display();
		}
	}
    return 0;
}

