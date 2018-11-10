// 1025_link.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class link {			// 链表节点类
private:
	string ads;
	int data;
	string next;
public:
	void display();
	string getads();
	string getnext();
	void upnext(string);
	link(string, int, string);	// 初始构造函数
	link() {};					// 默认构造函数
	link(const link &);			// 深拷贝构造函数
};
vector<link>::iterator findads(vector<link> &, string);
void show(vector<link>,string);
int main()
{
	string first;		// 第一个节点
	cin >> first;
	int num;			// 节点个数
	cin >> num;
	int antigp;
	cin >> antigp;
	vector<link> links(num);		// input
	for (int i = 0; i < num; i++) {
		string tempad;
		string tempnext;
		int tempda;
		cin >> tempad >> tempda >> tempnext;
		link temp(tempad, tempda, tempnext);
		links[i] = temp;
	}
	show(links, first);


	link f(0, 0, first);
	link *head = &f;
	// stack<link> stk;
	// 
	link temp = *head;
	for (int i = 0; i < antigp; ++i) {
		temp = *findads(links, temp.getnext());
	}
	first = temp.getads();
	string end = "-1";
	int flag = 1;
	while (true) {
		for (int i = 0; i < antigp; ++i) {
			if (temp.getnext() == end) {
				flag = 0;
			}
			else
				temp = *findads(links, temp.getnext());
		}
		if (flag == 1) {
			for (int k = 0; k < antigp - 1; ++k) {
				link temp1(*findads(links, (*head).getnext()));
				link temp2 ( *findads(links, temp1.getnext()));
				(*findads(links, temp1.getnext())).upnext((*findads(links, (*head).getnext())).getads());
				(*findads(links, (*head).getnext())).upnext(temp2.getnext());
				(*head).upnext(temp2.getads());
				head = &(*findads(links, temp1.getnext()));
			}
		}
		else 
			break;
	}
	show(links, first);
	return 0;
}
void link::display() {
	cout << ads << " " << data << " " << next << endl;
}
link::link(string ads, int data, string next) {
	this->ads = ads;
	this->data = data;
	this->next = next;
}
link::link(const link &a) {
	this->ads = a.ads;
	this->data = a.data;
	this->next = a.next;
}
string link::getads() {
	return ads;
}
string link::getnext() {
	return next;
}
vector<link>::iterator findads(vector<link> &a, string ad) {
	for (vector<link>::iterator iter = a.begin(); iter != a.end(); ++iter) {
		if (ad == iter->getads()) {
			return iter;
		}
	}
}
void link::upnext(string a) {
	this->next = a;
}
void show(vector<link> a,string fads) {
	link temp(0, 0, fads);
	string end = "-1";
	for (int i = 0;temp.getads()!=end ; ++i) {
		 temp= *findads(a, temp.getnext());
		 temp.display();
	}
}