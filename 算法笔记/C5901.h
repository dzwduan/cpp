#pragma once
#include <iostream>
#include <string>
using namespace std;

//回文字符判断
void judge() {
	string ss;
	cin >> ss;
	for (auto i = 0; i < ss.length() / 2; ++i) {
		if (ss[i] != ss[ss.length() - 1 - i]) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}

//注意只要比较 i 和 len-i-1位置是否相等