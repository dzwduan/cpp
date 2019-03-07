#pragma once
//̰���㷨
//���Ƚ��߼۵�����

#include<iostream>
#include<algorithm>

template <typename T>
class cake {
public:
	T store;
	T sell;
	T price;
public:
	T get_price() {
		return sell / store;
	}

};


bool cmp(cake<double> c1, cake<double> c2) {
	return c1.price > c2.price;
}

void max_value() {
	int category;
	double needs;
	std::cin >> category >> needs;
	cake<double> all[1010];
	for (int i = 0; i < category; ++i) {
		std::cin >> all[i].store;
	}
	for (int i = 0; i < category; ++i) {
		std::cin >> all[i].sell;
		all[i].price = all[i].get_price();
	}
	std::sort(all, all + category, cmp);
	double result = 0.0;
	for (int i = 0; i < category; ++i) {
		if (all[i].store <= needs) {
			result += all[i].sell;
			needs -= all[i].store;
		}
		else {
			result += all[i].price*needs;
			needs = 0;
			break;
		}
	}
	printf("%.2f\n", result);
}


//һ��ʼ���Ե�3һֱ����ȥ������������0�����⣬printf�����������������ѭ�����治�С�