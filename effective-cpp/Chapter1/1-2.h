
//使用编译器替换预处理器

//ratio可能不会被编译器看见，但是常量一定进入记号表
#define ratio 1.653
const double new_ratio = 1.653;

//class专属常量
class GamePlayer {
private:
	static const int num = 5;
	int scores[num];
};

//取地址操作
int a = GamePlayer::num;

//define不能创建专属常量，因为他不重视作用域，一旦定义，之后都生效
//static是具有确定的生命周期的



//常见的宏用法
#define call_with_max(a,b) (a)>(b)?(a):(B)


//取代用法
template<typename T>
inline void call_max(const T& a, const T& b) {
	return a > b ? a : b;
}

//优点如下
//不需要加上括号,也不担心多次累加,并且遵守作用域



//这里我拿caffe框架里的common.h代码举个例子
//原先的写法如下
#define DCHECK(val) (((val)==0)? false:true)
#define DCHECK_EQ(val1, val2) (((val1)==(val2))? true:false)



//我改成了如下
template<typename T>
inline bool DCHECK(const T& val) {
	return val == 0 ? false : true;
}

template<typename T>
inline bool DCHECK_EQ(const T& val1, const T& val2) {
	return  val1 == val2 ? false : true;
}

