#include<iostream>
#include<string>
#include"pch.h"
using namespace std;


char greeting[] = "hello";
char* p = greeting;

const char* p0 = greeting;   //greeing �� const
char* const p1 = greeting;   // p1�� const
const char* const p2 = greeting;//p1 greeting ����const
//const������*�����Ǳ�ָ����const,�������Ҳ����ָ����const



//const_iterator,��ָ�Ķ������ܸĶ�
//����const��������ֵ�����
/*
const int a, b;
int c;
(a*b) = c;  //�ͻ����
if (a*b = c);//Ҳ�����
*/


//const��Ա�������ŵ�
//����֪���ĸ������ܸı䣬�ĸ����ܸı�
//���Ե���const����

class TextBlock {
public:
	TextBlock(string s) :text(s) {}
	const char& operator[](size_t position) const {
		return text[position];
	}
	char& operator[](size_t position) {
		return text[position];
	}

	size_t length() const {
		if (!lengthIsValid) {
			textLength = text.length();
			lengthIsValid = true;
		}
		return textLength;
	}

private:
	string text;
	mutable size_t textLength;
	mutable bool lengthIsValid;
	//mutableʹ����const��Ա������Ҳ���Ա��ı�
};


//const non-const�����ظ����������������operator
//ֻ����non-const����const,��֮const״̬��ı����
class TextBlock2 {
private:
	string text;
public:
	TextBlock2(string s) :text(s) {}
	const char& operator[](size_t position) const {
		return text[position];
	}

	char& operator[](size_t position) {
		return
			const_cast<char&>(   
				static_cast<const TextBlock2>(*this)[position]
				);
	}

};
//��תconst class,��תchar&
//const_cast����ȥ��const��
