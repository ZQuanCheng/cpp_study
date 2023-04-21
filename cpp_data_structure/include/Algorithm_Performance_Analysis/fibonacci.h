#ifndef FIBONACCI_H
#define FIBONACII_H


#include <iostream>
using namespace std;

#include <chrono>
#include <thread>
using namespace chrono;


// 斐波那契数列：F(1)=1，F(2)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）


// 斐波那契数的非递归算法
// 时间复杂度O(n) 空间复杂度：O(1)
int fibonacci (int n); 

void time_consumption_fibonacci ();




// 斐波那契数的递归算法

// 版本一: 逆向运算, 类似于数学归纳法的证明
// 时间复杂度O(2^n) 空间复杂度：O(n)
// n = 40，耗时：837 ms
// n = 50，耗时：110306 ms
int fibonacci_1 (int n);     // 我们可以定义为：F(0)=0，F(1)=1，F(2)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）

void time_consumption_fibonacci_1 ();

// 版本二: 正向运算(加法)
// 时间复杂度O(n) 空间复杂度：O(n)
// n = 40，耗时：0 ms
// n = 50，耗时：0 ms
int fibonacci_2 (int first, int second, int n);

void time_consumption_fibonacci_2 ();








#endif