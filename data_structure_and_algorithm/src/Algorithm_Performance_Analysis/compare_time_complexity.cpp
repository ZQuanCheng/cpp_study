#include "compare_time_complexity.h"

/*
O(n)的算法，1s内大概计算机可以运行 5 * (10^8)次计算。
O(n^2)的算法，1s内大概计算机可以运行 22500次计算，即5 * (10^8)开根号。
O(nlog n)的算法，1s内大概计算机可以运行 2 * (10^7)次计算。比 O(n)少一个数量级。
*/

// O(n)
void compare_time_function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}

// O(n^2)
void compare_time_function2(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            k++;
        }
    }
}

// O(nlogn)
void compare_time_function3(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j < n; j = j*2) { // 注意这里j=1
            k++;
        }
    }
}
/*
为什么第三个是O(nlogn)？
第一层：1，2，3，…，n运行n次，时间复杂度是n
第二层：1，2，4，8，…，n。运行次数设为x，即1*2x=n时停止，得x=log2n，忽略底数，运行x=logn次，时间复杂度是logn
所以第三个算法的时间复杂度是nlogn。
*/