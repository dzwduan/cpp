#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
constexpr auto max_t = 10000;
//空间换时间，时间复杂度o(m+n)
//给出N个正整数，再给出M个正整数，问M中的每个数分别是否在N个数中出现过
void n_get_m() {
	bool hashtable[max_t] = { false };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> i;
		hashtable[i] = true;
	}
	for (int j = 0; j < m; ++j) {
		cin >> j;
		if (hashtable[j] == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

//给出N个正整数，再给出M个正整数，问M中的每个数分别在N中出现过几次
void get_times() {
	int hashtable[max_t] = { 0 };
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> i;
		hashtable[i]++;
	}
	for (int j = 0; j < m; ++j) {
		cin >> j;
		cout <<hashtable[j] << endl;
	}
}

//字符串哈希
//如果由A~Z构成，将字符串映射为26进制，再转十进制
int hash_func(string s, int len,int p) {
	int id = 0;//p是进制
	for (int i = 0; i < len; ++i) {
		if(s[i]>='A'&&s[i]<='Z')
		id = id * p + (s[i] - 'A');
	}
	return id;
}

//如果由A-Z,a-z组成，为52进制
int hash_func2(string s, int len, int p) {
	int id = 0;//p是进制
	for (int i = 0; i < len; ++i) {
		if (s[i] >= 'A'&&s[i] <= 'Z')
			id = id * p + (s[i] - 'A');
		else
			id = id * p + (s[i] - 'a');
	}
	return id;
}

//如果末位出现数字则为62进制
int hash_func3(string s, int len, int p) {
	int id = 0;  //p是进制
	for (int i = 0; i < len-1; ++i) {
		id = id * p + (s[i] - 'A');
	}
	id = id * 10 + (s[len-1] - '0');
	return id;
}


/***************************************************************************
综合题，给定n个字符串，再给定m个查询字符串，问每个查询字符串在n个字符串中出现的次数
***************************************************************************/
void get_times_in_n() {
	int n, m;
	cin >> n >> m;
	string ss;
	int hashtab[max_t] = { 0 };
	for (int i = 0; i < n; ++i) {
		cout << "enter string to save" << endl;
		cin >> ss;
		int num = hash_func(ss,ss.length(),26);
		hashtab[num] ++;
	}
	for (int i = 0; i < m; ++i) {
		cout << "enter string for search" << endl;
		cin >> ss;
		int num = hash_func(ss,ss.length(),26);
		cout << hashtab[num]<<endl;
	}
}
