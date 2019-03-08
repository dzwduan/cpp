#include<iostream>
#include<string>
#include"pch.h"
using namespace std;


char greeting[] = "hello";
char* p = greeting;

const char* p0 = greeting;   //greeing 是 const
char* const p1 = greeting;   // p1是 const
const char* const p2 = greeting;//p1 greeting 都是const
//const出现在*左侧就是被指物是const,出现在右侧就是指针是const



//const_iterator,所指的东西不能改动
//返回const会避免错误赋值的情况
/*
const int a, b;
int c;
(a*b) = c;  //就会出错
if (a*b = c);//也会出错
*/


//const成员函数的优点
//可以知道哪个函数能改变，哪个不能改变
//可以调用const对象

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
	//mutable使得在const成员函数内也可以被改变
};


//const non-const避免重复，例如上面的两个operator
//只能用non-const调用const,反之const状态会改变出错
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
//先转const class,再转char&
//const_cast用于去除const！
