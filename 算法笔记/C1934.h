//²éÕÒ
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int find_xx() {
	int n;
	cin >> n;
	vector<int> find_set;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		find_set.push_back(num);
	}
	int x;
	cin >> x;
	/*int idx = 0;
	vector<int>::const_iterator it;
	for (it = find_set.cbegin(); it != find_set.cend();++it) {
		cout << *it;
		if (*it == x) {
			return idx;
		}
		++idx;
	}
	return idx;*/
	vector<int>::const_iterator iter = find(find_set.cbegin(), find_set.cend(), x);
	if (iter == find_set.cend()) {
		return -1;
	}
	return iter-find_set.cbegin();
}