
https://www.geeksforgeeks.org/difference-between-constant-pointer-pointers-to-constant-and-constant-pointers-to-constants/


> 
> `指针常量constant pointer`：指向固定的内存位置，该位置的值可以更改
>
> ```c++
> int *const p; // const修饰*，把指针固定住
> ```
> 
> `（指向）常量（的）指针pointers to constant`：指向的数据不可变，但是指针可以改变来指向别的地方
>
>
> ```c++
> // 两种写法
> const int *p; // const修饰int，把值固定住 
> int const *p; 
> ```
> 
> 
> `指向常量的常量指针constant pointers_to_constants`：指针指向的数据是常量，不能更改。指针本身是恒定的，不能改变并指向其他地方。
>
> ```c++
> const int *const p // 第一个const修饰int，把值固定住；第二个const修饰*，把指针固定住
> ```
> 
> 
> * `const常量`取地址后，其地址只能赋值给常量指针，不能给指针常量，更不能给普通指针
>
>
> ```c++
> const int n = 20; // const常量必须在定义的时候初始化
> 
> // int *ptr = &n; // 错误，常量的地址不能赋给普通指针，要保证"指向的内容不可改变"
> // int *const ptr = &n; // 错误，常量的地址不能赋给指针常量，要保证"指向的内容不可改变"
> const int *ptr = &n; // 正确，常量地址只能赋值给常量指针，保证"指向的内容不可改变"
> ```
> 
> 
> 


>
> 
> <font color="yellow"> 一个很有意思的现象</font> 
>
> https://blog.csdn.net/bitcarmanlee/article/details/124166842
>
> `char *p = "hello";`本质上是`const char *p = "hello";`，`常量指针`
>
> `char a[] = "hello";`本质上是`char *const a = "hello";`，`指针常量`
> 
> 














