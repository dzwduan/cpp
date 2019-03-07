
#include<iostream>
using namespace std;


void compare() {
	int n;
	cin >> n;
	long long a, b,c;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b >>c;
		if (a + b>c)
			cout << "Case #" << i << ": true"<<endl;
		else
			cout << "Case #" << i << ": false"<<endl;
	}
}

// long longÔËÓÃ