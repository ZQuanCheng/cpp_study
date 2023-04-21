#ifndef TEMPLATE_FUNC_MAX_H    // 防止头文件的重复包含和编译
#define TEMPLATE_FUNC_MAX_H

//函数模板基本形式如下:
/* 
template <模板参数表>
类型 函数名(形参表)
    函数体
*/

// T可以是基本数据类型,也可以是自定义数据类型,例如struct, enum
template <typename T>  // template <class T> 也可,因为这里,关键字class和关键字typename无区别
T template_max(T x, T y);


template <typename T1, typename T2>
void template_addarray(T1 a[], T2 b[], int size);

template <typename T3>
void template_print_array(T3 arr[], int size);




#include "template_func_max.tpp"




// 模板 的.h头文件中具体实现不能在.cpp文件中,g++编译器不支持.
// 只能是建立一个同名.tpp文件, 进行 模板函数 和 模板类 成员函数 的实现
// https://blog.csdn.net/gxuan/article/details/8279988
// https://blog.csdn.net/huanghxyz/article/details/85280144



#endif