#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Shape {
private:
	T t;
	int N;
public:
	Shape(T _t, int _N) :t(_t), N(_N) {};
	void draw();
	~Shape() {};
	Shape(const Shape&) =delete;
	Shape& operator=(const Shape&) = delete;
	void printNull(int);
};

void Shape<char>::printNull(int length) {
	for (int i = 0; i < length; ++i)
		cout << " ";
}

void Shape<char>::draw() {
	int rows = (N%2==1)?(N/2+1):(N/2);
	//1 row
	for (int i = 0; i < N; ++i) {
		cout << t;
	}
	cout << endl;
	//2--(N-1) row
	for (int i = 2; i < rows; ++i) {
		cout << t;
		printNull(N-2);
		cout << t<<endl;

	}

	//N row
	for (int i = 0; i < N; ++i) {
		cout << t;
	}
}