#ifndef TEMPLATE_CLASS_ARRAY_H    // 防止头文件的重复包含和编译
#define TEMPLATE_CLASS_ARRAY_H

//类模板基本形式如下:
/* 
template <模板参数表>
class 类名{...}
*/

// 类外实现成员函数基本形式如下:(只是加了一个<实际参数表>)
// 如果类模板的成员函数在类外实现，那么它们必须是模板函数，即该函数定义的前面必须带有“template <模板参数表>”。同时，在模板类名与作用域运算符：：直接加上“<模板参数表>”
/*
template <模板参数表>
类名<实际参数表>::函数名(形参表)
{
    ...
}
*/

// 类模板实例化建立对象的形式如下:(只是加了一个<实际参数表>)
/*
类名 <实际参数表> 对象名1,...,对象名n;
*/


// T可以是基本数据类型,也可以是自定义数据类型,例如struct, enum

template <class T>  // template <typename T> 也可,因为这里,关键字class和关键字typename无区别
class Template_Array
{
    public:
        // 带默认/缺省值的形参 尽量写在声明里写缺省值！便于在头文件里查找修改。
        // 定义和声明分开的，只能在声明中设置默认参数
        // 带默认/缺省值的形参必须放在形参的最后面，可以是多个，调用时只能从最后一个参数开始进行缺省，
        // 如果要缺省一个参数，必须缺省它后面所有的参数。
        Template_Array(int size=10);
        ~Template_Array();
        void SetELem(int i,T v);
        T GetELem(int i);
    private:
        T *Buffer;
        int n;
};

#include "template_class_array.tpp"

// 模板 的.h头文件中具体实现不能在.cpp文件中,g++编译器不支持.
// 只能是建立一个同名.tpp文件, 进行 模板函数 和 模板类 成员函数 的实现
// https://blog.csdn.net/gxuan/article/details/8279988
// https://blog.csdn.net/huanghxyz/article/details/85280144

#endif