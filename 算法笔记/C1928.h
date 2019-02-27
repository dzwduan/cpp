#pragma once
#include <iostream>
using namespace std;

auto func = [](int x) {
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) {
		return 1;
	}
	return 0;
};

template<typename T> 
void max_chage(T& a, T& b) {
	if (a > b) {
		return;
	}
	else {
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
}

void get_ymd(long long data, int &y, int &m, int &d) {
	y = data / 10000;
	m = data % 10000 / 100;
	d = data % 100;
}

//1闰年，0平年
void get_data_diff() {
	int month[13][2] = { {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31}, {30,30},{31,31},{30,30},{31,31} };
	long long data1, data2;
	cin >> data1 >> data2;
	max_chage(data1, data2);
	int y1, y2, m1, m2, d1, d2;
	get_ymd(data1, y1, m1, d1);
	get_ymd(data2, y2, m2, d2);
	int sum = 1;
	while (y1 > y2 || m1 > m2 || d1 > d2) {
		d2++;
		if (d2 == month[y2][func(m2)] + 1) {
			m2++;
			d2 = 1;
		}
		if (m2 == 13) {
			y2++;
			m2 = 1;
		}
		sum++;
	}
	cout << sum << endl;
}

//注意点是设置0的地方为0