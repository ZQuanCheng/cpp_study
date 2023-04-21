#ifndef SWAP_H    // 防止头文件的重复包含和编译
#define SWAP_H

/*
  调用函数时，有三种传递参数的方式：
  值传递：把实参赋值给形参，修改形参不影响修改实参  void swap_value(int a, int b)
  引用传递：形参相当于实参，修改形参相当于修改实参  void swap_reference(int &a, int &b)
  指针传递：直接对指针操作，修改形参相当于修改实参  void swap_pointer(int *a, int *b)
*/

void swap_value(int a, int b);       // 引用方法 swap_value(a, b);
void swap_reference(int &a, int &b); // 引用方法 swap_reference(a, b);
void swap_pointer(int *a, int *b);   // 引用方法 swap_pointer(&a, &b);

#endif