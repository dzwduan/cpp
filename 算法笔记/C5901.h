#pragma once
#include <iostream>
#include <string>
using namespace std;

//�����ַ��ж�
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

//ע��ֻҪ�Ƚ� i �� len-i-1λ���Ƿ����