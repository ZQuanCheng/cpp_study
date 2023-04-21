#ifndef TEMPLATE_CLASS_STACK_TPP
#define TEMPLATE_CLASS_STACK_TPP

#include <iostream>
#include <iomanip>

using namespace std;

// .h头文件中具体实现不能在.cpp文件中,g++编译器不支持.
// 只能是建立一个同名.tpp文件, 进行函数和类成员函数的实现

// 如果类模板的成员函数在类外实现，那么它们必须是模板函数，即该函数定义的前面必须带有“template <模板参数表>”。同时，在模板类名与作用域运算符：：直接加上“<模板参数表>”
//类外定义成员函数的基本形式:(只是加了一个<实际参数表>)
/*
template <模板参数表>
类名<实际参数表>::函数名(形参表)
{
    ...
}
*/

template <class T>
void Stack<T>::push(T const &elem)   // 入栈
{
    // 追加传入元素的副本
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()                 // 出栈
{
    if(elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");  
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const               // 返回栈顶
{
    if(elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();   
}

template <class T>
bool Stack<T>::empty() const         // 如果为空,则返回真
{
    return elems.empty();
}


#endif
