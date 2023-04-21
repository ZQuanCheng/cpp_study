#ifndef COMPARE_TIME_CONPLEXITY_H    // 防止头文件的重复包含和编译
#define COMPARE_TIME_CONPLEXITY_H

/*
O(n)的算法，1s内大概计算机可以运行 5 * (10^8)次计算。
O(n^2)的算法，1s内大概计算机可以运行 22500次计算，即5 * (10^8)开根号。
O(nlog n)的算法，1s内大概计算机可以运行 2 * (10^7)次计算。比 O(n)少一个数量级。
*/


void compare_time_function1(long long n);

void compare_time_function2(long long n);

void compare_time_function3(long long n);




#endif
