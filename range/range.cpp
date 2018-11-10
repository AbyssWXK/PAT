// range.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;
class Student {
private:
	string name;
	string num;
	int score;
public:
	Student(string name, string num, int score);
	void display();
	int getscore();
	Student() {

	};
};
int main()
{
	int k = 0;
	string name;
	string num;
	int score;
	int min=0;
	int max=0;
	int n;
	scanf("%d", &k);
	Student stds[101];
	for (n = 0; n < k; n++) {
		cin >> name >>  num >>  score;
		stds[n]=Student(name, num, score);
	}
	for (n = 0; n < k; n++) {
		if (stds[n].getscore() <= stds[min].getscore())
			min = n ;
	}
	for (n = 0; n < k; n++) {
		if (stds[n].getscore() >= stds[max].getscore())
			max = n;
	}
	stds[max].display();
	stds[min].display();
    return 0;
}
void Student::display() {
	cout<<this->name<<" "<<this->num<<endl;
}
int Student::getscore() {
	return this->score;
}
Student::Student(string name1, string num1, int score1) {
	name = name1;
	num = num1;
	score = score1;
}

