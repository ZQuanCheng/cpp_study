/* cpp_enum */

// 编译预处理
// 预处理命令以"#"开头，预处理不是程序语句，最后没有";",必须独占一行
#include <iostream>   // #include <iostream.h>  已过时，现在反对把.h符号继续用在标准的头文件中

using namespace std;  // C++标准库定义的标准命名空间. 没有这个，直接用cout、endl会报错，需要用std::cout、std::endl。
// #include <iostream> 必须跟using namespace std; 如果是#include <iostream.h>则不需要跟using namespace std;

// 已经不让用void main()了  // ‘::main’ must return ‘int’
int main()
{
    // 若没有using namespace std; 则需要cout改成std::cout，end改成std::endl

    // enum <类型名> {<枚举常量表>};
    enum gender {man, women};                                // 枚举常量man=0, women=1,
    enum fruit_set {apple, orange, banana=1, peach, grape}; // 枚举常量apple=0, orange=1, banana=1, peach=2, grape=3
    enum week {Sun=7, Mon=1, Tue, Wed, Thu, Fri, Sat};      // 枚举常量Sun,Mon,Tue,Wed,Thu,Fri,Sat的值分别为7、1、2、3、4、5、6。

    enum direction {east, west, south=10, north}x, y;        // 枚举常量east=0, west=1, south=10, north=11
    enum color {red, yellow, blue, white, black}c1, c2;      // 枚举常量red=0, yellow=1, blue=2, white=3, black=4
    enum color m1, m2;
    
    x = west; y = north;
    c1 = red; c2 = white; m1 = blue; m2 = black;
    
    // 枚举变量可以直接输出，输出的是变量的整数值。例如：
    cout << "x:" << x << endl;     // x的值为1
    cout << "y:" << y << endl;     // y的值为11
    cout << "c1:" << c1 << endl;   // c1的值为0
    cout << "c2:" << c2 << endl;   // c1的值为3
    cout << "m1:" << m1 << endl;   // m1的值为2
    cout << "m2:" << m2 << endl;   // m1的值为4
    cout << endl;


    c1 = yellow;        //将枚举常量值赋给枚举变量
    c2 = c1;            //相同类型的枚举变量赋值，c2的值为yellow
    int i = c1;          //将枚举变量赋给整型变量，i的值为1
    int j = red;         //将枚举常量赋给整型变量，j的值为0
    cout << "c1:" << c1 << endl;  // c1的值为1 yellow
    cout << "c2:" << c2 << endl;  // c2的值为1 yellow
    cout << "i:" << i << endl;    // i的值为1 yellow
    cout << "j:" << j << endl;    // j的值为0 red    
    cout << endl;    

    m1 = (enum color)3; 
    m2 = (enum color)4;
    cout << "m1:" << m1 << endl;  // m1的值为3 white
    cout << "m2:" << m2 << endl;  // m2的值为4 black
    cout << endl;

    // 允许的关系运算有：==、<、>、<=、>=、!=等，例如：
    // 比较同类型枚举变量c1，c2是否相等
    if (c1 == c2) cout<< "相等" << endl;
    //输出的是变量color3与WHITE的比较结果，结果为1
    cout << (c1 < white) ;
    cout << endl;


    // 枚举变量可以直接输出，但不能直接输入。如：cout >> color3;   //非法
    // 不能直接将常量赋给枚举变量。如：  color1=1; //非法
    // 不同类型的枚举变量之间不能相互赋值。如： color1=color3;  //非法

    // 枚举变量的输入输出一般都采用switch语句将其转换为字符或字符串；枚举类型数据的其他处理也往往应用switch语句，以保证程序的合法性和可读性。

    /*
    c1 = c1 + 1; // 报错
    c2 = c2 - 1; // 报错
    c1 ++; // 报错
    c2 --; // 报错    
    cout << "c1:" << c1 << endl;  // c1的值为1 yellow
    cout << "c2:" << c2 << endl;  // c2的值为1 yellow
    cout << endl;
    */


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