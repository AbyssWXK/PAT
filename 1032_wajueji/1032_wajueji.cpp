// 1032_wajueji.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
struct gc {
	int gp;
	int score;
};
int main()
{
	int num;
	cin >> num;
	gc temp;
	temp.gp = 0;
	temp.score = 0;
	gc max = temp;
	vector<gc> list(num, temp);
	vector<gc>::iterator iterc=list.begin();
	for (int i = 0; i < num; ++i) {
		int falg = 0;
		cin >> temp.gp >> temp.score;
		for (vector<gc>::iterator iter = list.begin(); iter != iterc; ++iter) {
			if ((*iter).gp == temp.gp) {
				(*iter).score = (*iter).score + temp.score;
				falg = 1;
				if ((*iter).score >= max.score) {
					max = *iter;
				}
				break;
			}
		}
		if (falg == 0) {
			*iterc=temp ;
			++iterc;
		}
	}
	cout << max.gp << " " << max.score;
	return 0;
}

