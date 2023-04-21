#ifndef TEMPLATE_FUNC_MAX_TPP    
#define TEMPLATE_FUNC_MAX_TPP

#include <iostream>
#include <iomanip>

using namespace std;

// .h头文件中具体实现不能在.cpp文件中,g++编译器不支持.
// 只能是建立一个同名.tpp文件, 进行函数和类成员函数的实现

template <typename T>
T template_max(T x, T y)
{
    T ret = (x>y)?x:y;
    return ret;
}


template <typename T1, typename T2>
void template_addarray(T1 a[], T2 b[], int size)
{

    for(int i=0; i<size; i++)
    {
        a[i] = a[i] + b[i];
    }
}

template <typename T3>
void template_print_array(T3 arr[], int size)
{
    cout << " arr[" << size << "] = { " ;
    for(int i=0; i<size-1; i++)
    {
        cout << arr[i] <<", ";
    }

    if(arr[size-1] != '\0')
    {
        cout << arr[size-1] << "}";   // 非字符数组,正常打印最后一个元素. 
                                      // 也有可能字符数组最后不存储'\0',但是那样使用cout << arr;会乱码,因为是cout检测到'\0'才停止
    }
    else 
    {
        cout << "\'\\0\' }";  // 如果字符数组是最后存储'\0',无法直接显示. \' 打印单引号 \\打印斜线
    }
    cout << endl;
}


#endif