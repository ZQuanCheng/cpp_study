#ifndef PRINT_BY_BASE_POINTER_CLASS_H    // 防止头文件的重复包含和编译
#define PRINT_BY_BASE_POINTER_CLASS_H

#include "shape_class.h"

// 重载函数：函数名和返回值类型可以相同，但是参数列表不能相同
// （多态）虚函数：继承中的概念。函数名、返回值类型、参数列表都相同，需要在声明时加Virtual关键字
// 每个子类（派生类）都有一个相同声明的函数的独立实现。这就是多态的一般使用方式。
// 对于Virtual虚函数，只是通过基类（父类）指针或基类（父类）引用时才有多态性。
// 如果没有基类（父类）指针，有无Virtual关键字，对于我们来说没有区别。
void print_by_base_pointer_virtual(Shape *p);
void print_by_base_pointer(Shape *p);


#endif