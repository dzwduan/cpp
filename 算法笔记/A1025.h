#pragma once
#include <iostream>
using namespace std;
//选择排序
//每趟从待排序队列中选取最小项，与待排序队列的第一个交换
void select_sort(int A[],int size) {
	int min;
	int tmp;
	int k;
	for (int i = 0; i < size; ++i) {
		k = i;
		min = 100; //每一轮min都要取的比较大才行
		//在待排序的队列里找最小的和index
		for (int j = i; j < size; ++j) {
			if (min > A[j]) {
				min = A[j];
				k = j;
			}
		}
		cout << "time " << i << " min value: " << min << endl;
		//找到了交换
		tmp = A[i];
		A[i] = min;
		A[k] = tmp;
	}

	for (int i = 0; i < 5; ++i) {
		cout << A[i] << " ";
	}
	cout << "end!";
}

//直接插入排序
//将未有序的队列中元素依次插入到已有序队列中
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








