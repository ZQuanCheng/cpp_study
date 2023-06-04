#ifndef RECURSION_ALGORITHM_H
#define RECURSION_ALGORITHM_H


// 求x的n次方

// for循环. 时间复杂度 O(n)
int recursion_algorithm_function1(int x, int n);

// 递归算法1.  时间复杂度: 递归的次数 * 每次递归中的操作次数 = n * 1= O(n) 。时间复杂度没有减小
int recursion_algorithm_function2(int x, int n);

// 递归算法2.  时间复杂度: 递归的次数 * 每次递归中的操作次数 = ？ * 1 。仍然是O(n)
int recursion_algorithm_function3(int x, int n);

// 递归算法3.  时间复杂度: 递归的次数 * 每次递归中的操作次数 = ？ * 1.   O(logn)
int recursion_algorithm_function4(int x, int n);





#endif