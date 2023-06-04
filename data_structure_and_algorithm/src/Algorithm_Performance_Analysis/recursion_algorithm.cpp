#include "recursion_algorithm.h"

// 求x的n次方

// for循环. 时间复杂度 O(n)
int recursion_algorithm_function1(int x, int n) {
    int result = 1;  // 注意 任何数的0次方等于1
    for (int i = 0; i < n; i++) {
        result = result * x;
    }
    return result;
}



// 递归算法1.  时间复杂度: 递归的次数 * 每次递归中的操作次数 = n * 1= O(n) 。时间复杂度没有减小
/*
int recursion_algorithm_function2(int x, int n) {
    int result;
    
    //设函数f(x，n) = x^n
    //    当 n = 0 时, f(x，0) = 1;  
    //    当 n > 0 时, f(x，n) = f(x，n-1) * x;

    if (n == 0) {
        result = 1;   // 递归调用必须设置终止条件， 当n = 0时，不再递归调用，直接给result赋值1.
    }
    else if(n > 0) {
        result = recursion_algorithm_function2(x, n - 1) * x;        
    } 
    else {
        result = -1; //n为负数，则返回-1
    }
    return result;
}
*/
// 直接return，比上面的省事，不用声明局部变量来存储，也不用if else，只用if就行
int recursion_algorithm_function2(int x, int n) {

    //设函数f(x，n) = x^n
    //    当 n = 0 时, f(x，0) = 1;  
    //    当 n > 0 时, f(x，n) = f(x，n-1) * x;

    if (n == 0) {
        return 1;   // 递归调用必须设置终止条件， 当n = 0时，不再递归调用，直接给result赋值1.
    }
    if(n > 0) {
        return recursion_algorithm_function2(x, n - 1) * x;        
    } 
    return -1; //n为负数，则返回-1
}



// 递归算法2.  时间复杂度: 递归的次数 * 每次递归中的操作次数 = ？ * 1 。仍然是O(n)
/*
int recursion_algorithm_function3(int x, int n) {
    int result;
    
    //设函数f(x，n) = x^n
    //    当 n = 0 时 f(x，0) = 1;  
    //    当 n 为非0 奇数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2) * x;
    //    当 n 为非0 偶数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2);        
    
    if (n == 0) {
        result = 1;   // 递归调用必须设置终止条件， 当n = 0时，不再调用本函数，给result赋值1.
    }
    else if (n % 2 == 1) {
        result = recursion_algorithm_function3(x, n / 2) * recursion_algorithm_function3(x, n / 2) * x; 
    }
    else if(n % 2 == 0){
        result = recursion_algorithm_function3(x, n / 2) * recursion_algorithm_function3(x, n / 2);
    }
    else {
        result = -1; //n为负数，则返回-1
    }
    return result;
}
*/
// 直接return，比上面的省事，不用声明局部变量来存储，也不用if else，只用if就行
int recursion_algorithm_function3(int x, int n) {

    //设函数f(x，n) = x^n
    //    当 n = 0 时 f(x，0) = 1;  
    //    当 n 为非0 奇数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2) * x;
    //    当 n 为非0 偶数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2);        
    
    if (n == 0) {
        return 1;   // 递归调用必须设置终止条件， 当n = 0时，不再调用本函数，给result赋值1.
    }
    if (n % 2 == 1) {
        return recursion_algorithm_function3(x, n / 2) * recursion_algorithm_function3(x, n / 2) * x; 
    }
    if(n % 2 == 0){
        return recursion_algorithm_function3(x, n / 2) * recursion_algorithm_function3(x, n / 2);
    }
    return -1; //n为负数，则返回-1
}









// 递归算法3.  时间复杂度: 递归的次数 * 每次递归中的操作次数 = ？ * 1.   O(logn)
/*
int recursion_algorithm_function4(int x, int n) {
    int result;
    
    //设函数f(x，n) = x^n
    //    当 n = 0 时 f(x，0) = 1;  
    //    当 n 为非0 奇数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2) * x;
    //    当 n 为非0 偶数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2);        
    
    if (n == 0) {
        result = 1;   // 递归调用必须设置终止条件， 当n = 0时，不再调用本函数，给result赋值1.
    }
    else if (n % 2 == 1) {
        int t = recursion_algorithm_function4(x, n / 2);
        result = t * t * x; 
    }
    else if(n % 2 == 0){
        int t = recursion_algorithm_function4(x, n / 2);
        result = t * t; 
    }
    else {
        result = -1; //n为负数，则返回-1
    }
    return result;
}
*/
// 直接return，比上面的省事，不用声明局部变量来存储
int recursion_algorithm_function4(int x, int n) {

    //设函数f(x，n) = x^n
    //    当 n = 0 时 f(x，0) = 1;  
    //    当 n 为非0 奇数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2) * x;
    //    当 n 为非0 偶数 时, f(x，n)= x^n = f(x，n / 2) * f(x，n / 2);        
    
    if (n == 0) {
        return 1;   // 递归调用必须设置终止条件， 当n = 0时，不再调用本函数，给result赋值1.
    }
    int t = recursion_algorithm_function4(x, n / 2);
    if (n % 2 == 1) {
        return t * t * x; 
    }
    if(n % 2 == 0){
        return t * t; 
    }
    return -1; //n为负数，则返回-1
}