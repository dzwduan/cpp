//
// Created by dzw on 19-2-21.
//

#ifndef CPP_STRING_H
#define CPP_STRING_H

#include <iostream>
using namespace std;

class String{
public:
    //构造函数
    String(const char* cstr=0);
    //拷贝构造函数
    String(const String &str);
    //拷贝赋值
    String& operator=(const String& str);
    //析构函数
    ~String();
    //获取字符串
    char* get_c_str() const;

private:
    //不知道大小，使用指针
    char* m_data;
};

#endif //CPP_STRING_H
