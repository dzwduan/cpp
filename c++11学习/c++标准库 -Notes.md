# c++标准库 -Notes



## 1.Variadic templates

>  关键字...
>
>  能够接受任意参数，每个参数类型也是任意的
>
> ```c++
> template<typename T,typename... Types>
> void print(const T& firstArg, const Types&... args){
> 	cout<<firstArg<<endl;
> 	print（args...);//产生了递归
> 	
> }
> 
> void print(){}  //递归终止函数
> 
> print(7.5,"hello",16,'c');//后三个就是args...
> 
> //注意...位置
> 
> //sizeof...(args)看长度
> ```



## 2.Spaces in template expressions

> 1.vector<list<int> > 可以写成vector<list>>d
>
> 2.
>
> ```c++
> //nullptr取代 0 NULL
> 
> typedef decltype(nullptr) nullptr_t; 
> //实际上std::nullptr_t nullptr二者等价
> 
> ```
>
> 3.自动类型推导auto 



