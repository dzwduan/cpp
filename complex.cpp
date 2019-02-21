//
// Created by dzw on 19-2-21.
//

#include "complex.h"

//return 不是local object可以返回引用
//class外要加inline

inline complex&
__doapl(complex* ths, const complex& r){
    ths->re+=r.re;
    ths->im+=r.im;
    return *ths;
}

//this是隐式存在的对象指针
inline complex&
complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

//全局函数 操作符重载（一定作用在左边）
//complex+complex
inline complex
operator+ (const complex& x, const complex& y){
    //使用的是local object,不能返回reference
    return complex(x.real()+y.real(),
                   x.imag()+y.imag());
}

//complex + double
inline complex
operator+ (const complex& x, double y){
    //使用的是local object,不能返回reference
    return complex(x.real()+y,
                   x.imag());
}

//double + complex
inline complex
operator + (double x, const complex& y){
    //使用的是local object,不能返回reference
    return complex(x+y.real(),
                  y.imag());
}

//不能返回void,多次<< <<会报错
ostream&
operator <<(ostream& os,const complex& x){
    return os<<'('<<x.real()<<','<<x.imag()<<')';
}