#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
constexpr auto max_t = 10000;
//�ռ任ʱ�䣬ʱ�临�Ӷ�o(m+n)
//����N�����������ٸ���M������������M�е�ÿ�����ֱ��Ƿ���N�����г��ֹ�
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

//����N�����������ٸ���M������������M�е�ÿ�����ֱ���N�г��ֹ�����
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

//�ַ�����ϣ
//�����A~Z���ɣ����ַ���ӳ��Ϊ26���ƣ���תʮ����
int hash_func(string s, int len,int p) {
	int id = 0;//p�ǽ���
	for (int i = 0; i < len; ++i) {
		if(s[i]>='A'&&s[i]<='Z')
		id = id * p + (s[i] - 'A');
	}
	return id;
}

//�����A-Z,a-z��ɣ�Ϊ52����
int hash_func2(string s, int len, int p) {
	int id = 0;//p�ǽ���
	for (int i = 0; i < len; ++i) {
		if (s[i] >= 'A'&&s[i] <= 'Z')
			id = id * p + (s[i] - 'A');
		else
			id = id * p + (s[i] - 'a');
	}
	return id;
}

//���ĩλ����������Ϊ62����
int hash_func3(string s, int len, int p) {
	int id = 0;  //p�ǽ���
	for (int i = 0; i < len-1; ++i) {
		id = id * p + (s[i] - 'A');
	}
	id = id * 10 + (s[len-1] - '0');
	return id;
}


/***************************************************************************
�ۺ��⣬����n���ַ������ٸ���m����ѯ�ַ�������ÿ����ѯ�ַ�����n���ַ����г��ֵĴ���
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
