#pragma once
//ģ��
#include<iostream>
using namespace std;
void get_highest_scores() {
	int N;
	int idx[100001] = {0};
	int info, score;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> info >> score;
		idx[info] += score;
	}
	int max=-1;
	int result_idx=1;
	for (int i = 1; i <=N; ++i) {
		if (idx[i] > max) {
			max = idx[i];
			result_idx = i;
		}
	}
	cout << result_idx << " "<<max;
}

//ע��ѧУ��Ŵ�1��ʼ��