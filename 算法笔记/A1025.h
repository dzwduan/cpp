#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
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


//A1025 below
//输出格式 准考证号 排名 考场号 考场排名
struct Student
{
	char id[15];
	int score;
	int location_number;
	int local_rank;

}stu[30010];

bool cmp(Student a, Student b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.id,b.id)<0;  //一开始直接用的<两个报错
}

void stu_sort() {
	int num=0; //考生数
	int k;//考场数
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int location; //考场人数
		cin >> location;
		for (int j = 0; j < location; ++j) {
			cin >> stu[num].id >> stu[num].score;
			stu[num].location_number = i + 1;
			num++;
		}
		sort(stu + num - location, stu + num, cmp); //考场内排名
		stu[num - location].local_rank = 1;
		for (int a = num - location + 1; a < num; ++a) {
			if (stu[a].score == stu[a - 1].score) {
				stu[a].local_rank = stu[a - 1].local_rank;
			}
			else {
				stu[a].local_rank = a + 1 - (num - location);
			}
		}
	}
	//再求总排名
	sort(stu, stu + num, cmp);
	int rank = 1;
	cout << num << endl;
	for (int a = 0; a < num; ++a) {
		if (a > 0 && stu[a].score != stu[a - 1].score) {
			rank =a + 1;
		}
		
		cout << stu[a].id << " "<<rank<<" "<<stu[a].location_number<<" "<<stu[a].local_rank<<endl;
	}

}






