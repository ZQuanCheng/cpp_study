/* cpp_learn */

// 编译预处理
// 预处理命令以"#"开头，预处理不是程序语句，最后没有";",必须独占一行

#include <iostream>   // #include <iostream.h>  已过时，现在反对把.h符号继续用在标准的头文件中
using namespace std;  // C++标准库定义的标准命名空间. 
// #include <iostream> 这个库中定义了命名空间td
// using namespace std; 是将命名空间std中的所有内容展开到全局中，这样很多关键词前面就不用加std::了

// #include <iostream> 一般都跟using namespace std;  不跟using xxx的话，直接用cout、endl会报错，需要用std::cout、std::endl。
// 如果是#include <iostream.h>则不需要跟using namespace std;


#include <cstdio>     // gets()、puts()、getchar()、putchar()
#include <cstring>    // C语言  strlen()、strcat()、strcpy()、strcmp()、strstr()、strchr()、isupper()、islower()、toupper()、tolower()
#include <cstdlib>    // 在windows系统下，用如下语句,控制台不会输出后马上消失。system("pause"); 
#include <unistd.h>   // 在Linux系统下，用如下语句,控制台不会输出后马上消失。pause(); 
#include <stdexcept>  // 异常处理exception try throw catch

#include <typeinfo>   // 查看变量类型 typeid(变量名).name()

#include <string>   // string类
#include <cctype>   // string对象的各种字符处理函数，如toupper、isupper、

// STL（标准模板库） 
#include <array>       // C++ array 容器
#include <vector>      // C++ vector 容器
#include <list>        // C++ list 容器
#include <stack>       // C++ stack 容器适配器
#include <queue>       // C++ queue 容器适配器  priority_queue 容器适配器
#include <deque>       // C++ deque 容器
#include <string>      // C++ string 容器
#include <map>         // C++ map 容器
#include <set>         // C++ set 容器


// 与STL 容器有关的头文件
// <algorithm>是标准模版库（STL）中最重要的头文件之一，提供了大量基于迭代器的非成员模板函数。
#include <algorithm>   // remove()、remove_if()、find_if()、sort、...
// https://blog.csdn.net/szplzx1314/article/details/120644640

#include <functional> // function包装器 例如std::function


// https://programmercarl.com/ 算法为什么会超时
#include <chrono>
#include <thread>
using namespace chrono;

#include "compare_time_complexity.h"
#include "recursion_algorithm.h"
#include "fibonacci.h"

#include "swap.h"



// 已经不让用void main()了  // ‘::main’ must return ‘int’
int main()
{


    // ---------------------------------------------------------代码随想录-------------算法性能分析 ---------------------------------------------------------
    
    // ----------------------------------2.算法为什么会超时------------------------------
    /*
    
    // O(n)的算法，1s内大概计算机可以运行 5 * (10^8)次计算。
    // O(n^2)的算法，1s内大概计算机可以运行 22500次计算，即5 * (10^8)开根号。
    // O(nlog n)的算法，1s内大概计算机可以运行 2 * (10^7)次计算。比 O(n)少一个数量级。

    long long n; // 数据规模
    while (1) {
        // cout << "O(n)算法 ";
        // cout << "O(n^2)算法 ";
        cout << "O(nlogn)算法 ";

        cout << "输入n：";
        cin >> n;

        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        // compare_time_function1(n);
        // compare_time_function2(n);
        compare_time_function3(n);

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        cout << "耗时:" << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
    }

    */
    // ------------------------------------------------------------------------------------

    // ----------------------------------3.递归算法的时间复杂度------------------------------
    /*
    
    int x, n; // 求x的n次方
    while (1) {
        // cout << "for循环 ";
        // cout << "递归算法1 ";
        // cout << "递归算法2 ";
        cout << "递归算法3 ";

        cout << "输入x, n：";
        cin >> x >> n;

        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        
        int result;
        // result = recursion_algorithm_function1(x, n);
        // result = recursion_algorithm_function2(x, n);
        // result = recursion_algorithm_function3(x, n);
        // result = recursion_algorithm_function4(x, n);

        cout << "x的n次方：" << result << endl;

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        cout << "耗时:" << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
    }    
 
    */
    // ------------------------------------------------------------------------------------
 
    // -----------------------------6.递归算法的性能分析（时间与空间复杂度）------------------
    /*

    // 通过求斐波那契数列深入分析一波递归算法的时间和空间复杂度
    
    // ---------------斐波那契数列----------------
    
    // 非递归写法
    // 时间复杂度O(n) 空间复杂度：O(1)
    time_consumption_fibonacci();


    // 斐波那契数的递归写法

    // 版本一: 逆向运算, 类似于数学归纳法的证明
    // 时间复杂度O(2^n) 空间复杂度：O(n)
    // n = 40，耗时：837 ms
    // n = 50，耗时：110306 ms
    // time_consumption_fibonacci_1 ();

    // 版本二: 正向运算(加法)
    // 时间复杂度O(n) 空间复杂度：O(n)
    // n = 40，耗时：0 ms
    // n = 50，耗时：0 ms
    // time_consumption_fibonacci_2 ();

    */
    // --------------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------------------------------------------------------------------



    // ---------------------------------------------------------代码随想录-------------数组---------------------------------------------------------









    
    cout << endl;
    pause(); // system("pause"); 
    /*
    * 在windows系统下，用如下语句,控制台不会输出后马上消失。 
    * 在windows平台就是执行DOS命令
    #include <cstdlib>    
    system("pause"); 

    * 在Linux系统下，用如下语句,控制台不会输出后马上消失,需要按下Ctrl+C才可以(pause可能会输出"press any key to continue. . .")。 
    * 在linux平台就是执行shell命令
    #include <unistd.h>   
    pause(); 

    * 在C语言中一般通过添加getchar();
    * 在C++中一般在main函数中的return之前添加system("pause")或pause();这样就可以看清楚输出的结果
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