#pragma once
#include <iostream>
using namespace std;

//p����ת10����
int p2ten(int x,int p) {
	int y = 0, product = 1;
	while (x != 0) {
		y = y + (x % 10)*product;
		x /= 10;
		product *= p;
	}
	return y;
}

//10����תp���ƣ�շת�����
void ten2p(int x, int p) {
	int z[40], num = 0;
	do {
		z[num++] = x % p;
		x /= p;
	} while (x != 0);
	for (int i = num - 1; i >= 0; --i) {
		cout << z[i];
	}
}

void sum2p() {
	int a, b,d;
	cin >> a >> b>>d;
	int sum = a + b;
	ten2p(sum, d);
}
