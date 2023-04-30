# cpp_learn 

https://www.runoob.com/cplusplus/cpp-polymorphism.html

Linux---C++  学习

## 功能介绍


## 编译、运行

```sh
# 赋予脚本所有者执行权限，允许该用户执行该脚本
# r、w、x 分别表示读、写、执行权限 
$ chmod +x build.sh 
# 执行脚本
$ ./build
``` 


## 注意
如果你在改变了文件结构, 例如添加了一个新的.c文件，makefile构建系统是不能感知这个文件的，所以必须手动重新生成cmake工程.先 $ cmake .. 后 $ make 才能生成可执行文件

如果不改变文件结构,即不新增或删减文件,只是修改内容,文件结构不变,则只需要重复 $ make 命令 即可生成可执行文件


## main.cpp包含内容

* 字符串函数: #include <cstring>  strlen()、strcpy()、strncpy()、strstr()、islower()、isupper()、tolower()、toupper()

* 指针: NULL空指针、指针的算术运算、指针数组、指向指针的指针（多级间接寻址）、、、、、、、
* 数组: 数组名a、数组名取地址&a、数组首地址&a[0]、数组指针*p
* 讨论: cout 显示char * 指针的讨论
* 指针常量、常量指针

* 结构体 struct

* 类与对象
* 构造函数 & 析构函数 &  拷贝构造函数
* this 指针  指向类的指针（ ->访问符 ）
* 友元函数、友元类
* 重载运算符、重载函数

* 继承
* 简单对象掉用
* （多态）虚函数--通过基类指针或基类对象引用

* 模板:函数模板  类模板



## 文件结构

* ./include文件夹（存放.h头文件）；
* ./src文件夹（存放.cpp源文件）
* ./bulid文件夹（存放Cmake产生的中间文件）
* ./out文件夹，（存放输出的可执行文件）
* ./main.cpp 
* ./CMakeLists.txt
* ./README.md


* ./include/
  * book_struct.h   结构体类型Books,  函数形参:结构体指针
  * box_class.h     类和对象、构造函数、带部分缺省参数值的构造函数、拷贝构造函数、析构函数、静态成员函数、友元函数、友元类
  * class_inherit.h _Shape类、_PaintCost类、_AB类、_Rectangle类、_Triangle类、_print_by_base_pointer_virtual函数(通过基类指针或基类对象引用,Virtual虚函数才有多态性, 才能实现动态链接)
  * overload.h      重载成员函数、重载运算符operator+() 
  * swap.h    调用函数时，有三种传递参数的方式：值传递、 引用传递、 指针传递      

* ./src/
  * book_struct.cpp  
  * box_class.cpp
  * class_inherit.cpp
  * overload.cpp
  * swap.cpp


* ./include/
  * class_inherit_depart: 将class_inherit.h拆分成6个.h文件  
                          Shape类       父类1   虚析构函数(在类继承的场合,防止内存泄漏) ； 注释掉了纯虚函数getArea(), 不然Shape类为抽象类, 无法创建对象
                          PaintCost类   父类2   只有一个成员函数
                          AB类          提供子对象给Rectangle类
                          Rectangle类   public继承(Shape类、PaintCost类);  成员变量: AB类子对象成员、指针变量(分配动态内存 单个)、指针变量(分配动态内存 数组)
                          Triangle类    与Rectangle类相似
                          print_by_base_pointer_virtual函数(通过基类指针或基类对象引用,Virtual虚函数才有多态性, 才能实现动态链接)
* ./src/
  * class_inherit_depart: 将class_inherit.cpp拆分成6个.h文件  


* ./include/
  * template: .h头文件中具体实现不能在.cpp文件中,g++编译器不支持. 只能是建立一个同名.tpp文件, 进行函数和类成员函数的实现
                           

* ./src/
  * template: .cpp文件只需要包含同名.h文件就行.我感觉这个.src不需要