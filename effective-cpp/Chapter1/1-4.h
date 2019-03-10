#include<iostream>
using namespace std;



//先有对象成员变量初始化，再有构造函数
// member initializer list替换赋值操作
//总是在初值列中列出所有的成员变量，防止不确定的风险

//local static 函数内的static对象
//non-local static  其他

//c++对于定义于不同的编译单元的non-local static对象初始化没有明确定义
//以下是反例

class FileSystem_1 {
public:
	size_t Disk() const {};
};
extern FileSystem_1 tfs_1;

class Directory_1 {
	int params;
public:
	Directory_1(int);
};

Directory_1::Directory_1(int param) {
	size_t disk = tfs_1.Disk();
}
int params = 0;
Directory_1 tmp_1(params);
//这里无法确定tfs在tmp之前初始化

///////////////////////////////////////////

//解决方案：将local-static对象搬到自己的专属函数内
//设计模式：Singleton

class FileSystem_2{
public:
	size_t Disk() const {};
};
FileSystem_2& tfs_2() {
	static FileSystem_2 tfs2;
	return tfs2;
}

class Directory_2{
	Directory_2();
};
Directory_2::Directory_2() {
	size_t disk = tfs_2().Disk();
}