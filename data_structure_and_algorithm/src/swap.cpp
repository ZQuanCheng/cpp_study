#include "swap.h"

/*
  调用函数时，有三种传递参数的方式：
  值传递(pass by value)：把实参赋值给形参，修改形参不影响修改实参  void swap(int a, int b)    引用方法 swap(a, b);
  引用传递(pass by reference)：形参相当于实参，修改形参相当于修改实参  void swap(int &a, int &b)  引用方法 swap(a, b);
  指针传递(pass by pointer)：直接对指针操作，修改形参相当于修改实参  void swap(int *a, int *b)  引用方法 swap(&a, &b);
*/
void swap_value(int a, int b)   // 引用方法 swap_value(a, b);
{ 
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 值传递和引用传递用法一样，
void swap_reference(int &a, int &b)  // 引用方法 swap_reference(a, b);
{ 
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// 指针传递要着重注意，以下为实例：
void swap_pointer(int *a, int *b)   // 引用方法 swap_pointer(&a, &b);
{ 
    int temp;
    temp = *a;   // *取指针所指内容， &取变量地址
    *a = *b;
    *b = temp;
}
