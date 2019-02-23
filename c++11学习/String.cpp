//
// Created by dzw on 19-2-21.
//
#include <cstring>
#include "String.h"

String::String(const char *cstr) {
     if(cstr){
         //最后一位\0
         m_data = new char[strlen(cstr)+1];
         strcpy(m_data,cstr);
     }
     else{
         m_data = new char[1];
         *m_data = '\0';
     }
}

String::~String() {
    delete [] m_data;
}

inline
String::String(const String& str) {
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
}

inline
String& String::operator=(const String &str) {
    //关注是否自我赋值
    if(this==&str){
        return *this;
    }

    delete[] m_data;
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
    return *this; //传出去不必知道返回的是by value,by reference.
}

char* String::get_c_str() const {
    return m_data;
}
