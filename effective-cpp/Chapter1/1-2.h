
//ʹ�ñ������滻Ԥ������

//ratio���ܲ��ᱻ���������������ǳ���һ������Ǻű�
#define ratio 1.653
const double new_ratio = 1.653;

//classר������
class GamePlayer {
private:
	static const int num = 5;
	int scores[num];
};

//ȡ��ַ����
int a = GamePlayer::num;

//define���ܴ���ר����������Ϊ��������������һ�����壬֮����Ч
//static�Ǿ���ȷ�����������ڵ�



//�����ĺ��÷�
#define call_with_max(a,b) (a)>(b)?(a):(B)


//ȡ���÷�
template<typename T>
inline void call_max(const T& a, const T& b) {
	return a > b ? a : b;
}

//�ŵ�����
//����Ҫ��������,Ҳ�����Ķ���ۼ�,��������������



//��������caffe������common.h����ٸ�����
//ԭ�ȵ�д������
#define DCHECK(val) (((val)==0)? false:true)
#define DCHECK_EQ(val1, val2) (((val1)==(val2))? true:false)



//�Ҹĳ�������
template<typename T>
inline bool DCHECK(const T& val) {
	return val == 0 ? false : true;
}

template<typename T>
inline bool DCHECK_EQ(const T& val1, const T& val2) {
	return  val1 == val2 ? false : true;
}

