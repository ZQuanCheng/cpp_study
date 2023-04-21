#ifndef TEMPLATE_CLASS_STACK_H
#define TEMPLATE_CLASS_STACK_H

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

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


// T可以是基本数据类型,也可以是自定义数据类型,例如struct, enum

template <class T>
class Stack
{
    public:
        void push(T const&);   // 入栈
        void pop();            // 出栈
        T top() const;         // 返回栈顶
        bool empty() const;    // 如果为空,则返回真.
  

    private:
        vector<T> elems;     //元素
};




#include "template_class_stack.tpp"


#endif