//
// Created by dzw on 19-2-21.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H
//预编译，防止多次引用
#include <iostream>
using namespace std;

class complex{
    //class里的默认inline
    //数据私有
private:
    double re,im;
    //友元
    friend complex& __doapl(complex*, const complex&);

public:
    //构造函数
    //需要考虑pass by value ,pass by reference
    //列表初始化
    complex(double r=0.,double i=0.) :re(r),im(i){}
    //操作符重载,作用于左边
    complex& operator+=(const complex&);
    //常量成员函数，不会改变private的数据
    double real() const {return re;}
    double imag() const {return im;}

};



#endif //COMPLEX_COMPLEX_H
