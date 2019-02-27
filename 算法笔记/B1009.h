#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverse_str() {
	string str;
	getline(cin,str);  //注意用法
	vector<string> ss;
	string tmp="";
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '\n') {
			return;
		}
		else if (str[i] != ' ') {
			tmp += str[i];
		}
		else {
			ss.push_back(tmp);
			tmp = "";
		}
	}
	//最后一个string轮不到else条件了
	ss.push_back(tmp);
	//逆序输出
	for (int i = ss.size(); i > 0; --i) {
		cout << ss[i] << " ";
	}
	cout << ss[0];
}