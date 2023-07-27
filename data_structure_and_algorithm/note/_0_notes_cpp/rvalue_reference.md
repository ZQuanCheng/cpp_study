# `右值引用rvalue reference`、`左值引用lvalue reference`、、`左值lvalue`、`右值rvalue`

>
> https://blog.csdn.net/caojianfa969/article/details/118927852
>
> https://blog.csdn.net/xujianjun229/article/details/120026260
>




>
> `左值lvalue`和`右值rvalue`这些术语来自C语言
> 
> `左值lvalue`： 出现在等号左边的必须是`lvalue`；可以长时间保存; 可以取地址；
> 
> 
> `右值rvalue`： `rvalue`只能出现在等号的右边；临时值; 不可以取地址; 
>
> 有了`const`以后，也不是所有的`lvalue`都能出现在等号左边
> 
>
> 
> `左值引用lvalue reference`：传统C++时代的引用`int& a = b;`; 
> 
> 
> 顾名思义，对左值的引用即为左值引用
> 
>
> 
> `右值引用rvalue reference`：Morden C++，也就是C++11, 带来了`rvalue reference`
> 
> 顾名思义，对右值的引用即为右值引用
>
> ```c++
> int &t = a;         // a为左值，所以可以赋给左值引用
> // int &t1 = 3;     // 错误 3为一个临时值，为右值，不能赋给左值引用
> // int &&t = a;     // 错误 a为左值，不能赋给右值引用
> int &&t = 3;        // 可以
> int &&t = -a;       // 可以
> // int &t = -a;     // 不可以
> // int &&t1 = t;    // 不可以，t本身是左值
> ```
> 
> `右值引用，使得 函数返回 和 函数调用 时创建的 临时对象 能够存在更久，避免了频繁构造和频繁析构，提高效率`。
> 
> 
> 


















