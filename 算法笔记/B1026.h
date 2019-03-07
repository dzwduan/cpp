#include<iostream>
using namespace std;

void get_time() {
	long long t1, t2;
	cin >> t1 >> t2;
	long long ans = t2 - t1;
	if (ans % 100 >= 50) {  //四舍五入注意有等号！！
		ans = ans / 100 + 1;
	}
	else {
		ans = ans / 100;
	}
	printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
}