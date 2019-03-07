#pragma once
//贪心算法
//优先将高价的卖掉

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


//一开始测试点3一直过不去，后来发现是0的问题，printf必须放在最后输出，在循环里面不行。