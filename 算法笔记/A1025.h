#pragma once
#include <iostream>
using namespace std;
//ѡ������
//ÿ�˴Ӵ����������ѡȡ��С����������еĵ�һ������
void select_sort(int A[],int size) {
	int min;
	int tmp;
	int k;
	for (int i = 0; i < size; ++i) {
		k = i;
		min = 100; //ÿһ��min��Ҫȡ�ıȽϴ����
		//�ڴ�����Ķ���������С�ĺ�index
		for (int j = i; j < size; ++j) {
			if (min > A[j]) {
				min = A[j];
				k = j;
			}
		}
		cout << "time " << i << " min value: " << min << endl;
		//�ҵ��˽���
		tmp = A[i];
		A[i] = min;
		A[k] = tmp;
	}

	for (int i = 0; i < 5; ++i) {
		cout << A[i] << " ";
	}
	cout << "end!";
}

//ֱ�Ӳ�������
//��δ����Ķ�����Ԫ�����β��뵽�����������
void insert_sort(int A[], int size) {
	int tmp,j;
	for (int i = 1; i < size; ++i) {
		tmp = A[i];
		j = i;
		while (tmp >= 0 && tmp < A[j - 1]) {
			A[j] = A[j - 1];
			--j;
		}
		A[j] = tmp;
	}
	for (int i = 0; i < 5; ++i) {
		cout << A[i] << " ";
	}
	cout << "end!";
}








