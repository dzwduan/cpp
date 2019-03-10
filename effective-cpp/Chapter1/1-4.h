#include<iostream>
using namespace std;



//���ж����Ա������ʼ�������й��캯��
// member initializer list�滻��ֵ����
//�����ڳ�ֵ�����г����еĳ�Ա��������ֹ��ȷ���ķ���

//local static �����ڵ�static����
//non-local static  ����

//c++���ڶ����ڲ�ͬ�ı��뵥Ԫ��non-local static�����ʼ��û����ȷ����
//�����Ƿ���

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
//�����޷�ȷ��tfs��tmp֮ǰ��ʼ��

///////////////////////////////////////////

//�����������local-static����ᵽ�Լ���ר��������
//���ģʽ��Singleton

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