#ifndef TEMPLATE_CLASS_ARRAY_TPP    
#define TEMPLATE_CLASS_ARRAY_TPP

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
Template_Array<T>::Template_Array(int size)
{
    n = size >1 ? size :10;
    Buffer = new T[n];
    for(int k=0; k<n; k++)
    {
        Buffer[k]=0;
    }
}

template <class T>
Template_Array<T>::~Template_Array()
{
    delete []Buffer;
}

template <class T>
void Template_Array<T>::SetELem(int i, T v)
{
    if(i >= 0 && i < n)
    {
        Buffer[i] = v;
    }
    else 
    {
        cout << "设置数组元素值时下标(" << i << ")太大或太小." << endl;
    }
}

template <class T>
T Template_Array<T>::GetELem(int i)
{
    char c = 0;
    if (i >= 0 && i < n)
    {
        return Buffer[i];
    }
    else
    {
        cout << "取出数组元素值时下标(" << i << ")太大或太小,设为0." << endl;
        return c;
    }
}







#endif