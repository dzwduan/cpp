
#include<iostream>
using namespace std;

int convert(int num, int size) {
	if (size == 0)
		return 0;
	long long result = 0;
	while (size > 0) {
		result += num;
		num *= 10;
		--size;
	}
	return result;
}

int get_num(long long num, int a) {
	int sum = 0;
	while (num > 0) {
		if (num % 10 == a)
			sum++;
		num /= 10;
	}
	return sum;
}

void sum_partial() {
	long long a, b;
	int aa, bb;
	cin >> a >> aa >> b >> bb;
	int num_a = get_num(a, aa);
	int num_b = get_num(b, bb);
	cout << convert(aa, num_a) + convert(bb, num_b);

}
