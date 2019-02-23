
#ifndef Virtual_H
#define Virtual_H
#include<iostream>

class Shape {
public:
	//纯虚函数，希望子类一定要重新定义
	virtual void draw() const = 0; 
	//虚函数，希望子类重新定义，且基类已有默认定义
	virtual void error(const std::string &msg);
	//非虚函数
	int objectID() const;
};

class Rectangle :public Shape {};
class Ellipse: public Shape{};

#endif 
