#pragma once
//Ä£Äâ
#include<iostream>
using namespace std;
class Callatz {
public:
	Callatz() = default;
	void get_value() ;
	void step_count() ;

private:
	int value;
	int step = 0;
};

void Callatz::get_value() {
	int i;
	cin >> i;
	value = i;
}

void Callatz::step_count() {
	while (this->value != 1) {
		if (this->value % 2 == 0) {
			this->value /= 2;
		}
		else {
			this->value = (int)(3.*this->value + 1.) / 2.;
		}
		++step;
	}
	cout << step;
}