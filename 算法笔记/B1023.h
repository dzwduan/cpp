#pragma once

#include<iostream>
using namespace std;

void get_max() {

	int num[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		cin >> num[i];
	}
	int k;
	//���ҵ���Ϊ0����С�����ٶ�ʣ�µĴ�С������
	for (int i = 1; i < 10; ++i) {
		if (num[i] != 0) {
			k = i;
			cout << i;
			break;
		}
	}
	for (int i = 0; i < 10; ++i) {
		if(k!=i)
			for (int j = 0; j < num[i]; ++j) {
				cout << i;
		}
		else
			for (int j = 0; j < num[i]-1; ++j) {
				cout << i;
			}
	}
}