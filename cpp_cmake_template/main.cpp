/* cpp_cmake_template */

// 编译预处理
// 预处理命令以"#"开头，预处理不是程序语句，最后没有";",必须独占一行
#include <iostream>   // #include <iostream.h>  已过时，现在反对把.h符号继续用在标准的头文件中
#include "swap.h"    
 
using namespace std;  // C++标准库定义的标准命名空间. 没有这个，直接用cout、endl会报错，需要用std::cout、std::endl。
// #include <iostream> 必须跟using namespace std; 如果是#include <iostream.h>则不需要跟using namespace std;

// 已经不让用void main()了  // ‘::main’ must return ‘int’
int main(){
    int a1 = 1, b1 = 2;
    int a2 = 10, b2 = 20;
    int a3 = 100, b3 = 200;

    // 若没有using namespace std; 则需要cout改成std::cout，end改成std::endl
    cout << "Before Swap: " << endl;
    cout << "a1 = " << a1 << ", b1 = " << b1 << endl;
    swap_value(a1, b1);
    cout << "After swap_value(a1, b1): " << endl;
    cout << "a1 = " << a1 << ", b1 = " << b1 << endl;
    cout << endl;

    cout << "Before Swap: " << endl;
    cout << "a2 = " << a2 << ", b2 = " << b2 << endl;
    swap_reference(a2, b2);
    cout << "After swap_reference(a2, b2): " << endl;
    cout << "a2 = " << a2 << ", b2 = " << b2 << endl;
    cout << endl;

    cout << "Before Swap: " << endl;
    cout << "a3 = " << a3 << ", b3 = " << b3 << endl;
    swap_pointer(&a3, &b3);
    cout << "After swap_pointer(&a3, &b3): " << endl;
    cout << "a3 = " << a3 << ", b3 = " << b3 << endl;
    cout << endl;

    return 0;
}

/*
补充：
1、旧的C++头文件是官方明确反对使用的，但旧的C头文件则没有（以保持对C的兼容性） 
2、iostream.h是包含输入/输出流处理的头文件,iostream就什么都不是了 但用iostream要加名词空间namespace
4、标准化委员会在简化非C标准头文件时用<iostream> 取代了它。但又没有完全取消 <iostream.h> 的使用，并且很多编译器都同时支持<iostream > 和< iostream.h > ，
   造成现在的局面，标准化委员会确实有不得已的苦衷。
4、 C++中新定义的方法都是有名字空间的 比如cout就属于std名字空间 
5、如果include头文件的时候加上.h，默认会using namespace 否则需要自己加上 using namespace XXX 
6、对于C中已经定义的方法如printf，没有影响的。#include <stdio.h> 不会报错
*/