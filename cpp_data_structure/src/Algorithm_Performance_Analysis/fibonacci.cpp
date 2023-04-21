#include "fibonacci.h"

// 斐波那契数列：F(1)=1，F(2)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 3，n ∈ N*）

// 非递归写法

// 时间复杂度O(n) 空间复杂度：O(1)
int fibonacci (int n) {
    int first = 1;
	int second = 1;
	int third = 1;   //n如果为1或者为2，直接返回Third=1.
	while (n > 2){
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}


// 斐波那契数的递归写法

// 版本一: 逆向运算, 类似于数学归纳法的证明
// 时间复杂度O(2^n) 空间复杂度：O(n)
// n = 40，耗时：837 ms
// n = 50，耗时：110306 ms
int fibonacci_1(int n) {     // 我们可以定义为：F(0)=0，F(1)=1，F(2)=1, F(i)=F(i - 1)+F(i - 2)（i ≥ 2，n ∈ N*）
    if (n <= 0) return 0;                     // F(0)=0
    if (n == 1) return 1;                     // F(1)=1
    return fibonacci_1(n-1) + fibonacci_1(n-2);   // F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）
}



// 版本二: 正向运算(加法)
// 时间复杂度O(n) 空间复杂度：O(n)
// n = 40，耗时：0 ms
// n = 50，耗时：0 ms
int fibonacci_2(int first, int second, int n) {     // 用first和second来记录当前相加的两个数值， n递减, 用于控制加法的次数. 
    if (n <= 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    else if (n == 3) {
        return first + second;
    }
    else {
        return fibonacci_2(second, first + second, n - 1);    
    }
}



void time_consumption_fibonacci() {
    int n;
    cout << "斐波那契数的非递归算法" << endl << "输入n：";
    while (cin >> n) {
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        int result;
        result = fibonacci(n);
        // result = fibonacci_1(n);
        // result = fibonacci_2(1, 1, n);

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        
        cout << "fibonacci数列的第 " << n << " 个数为: " << result << endl;

        cout << "耗时:" ;
        cout << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
        
        cout << "输入n：";
    }    
}


void time_consumption_fibonacci_1() {
    int n;
    cout << "斐波那契数的递归算法 版本1" << endl << "输入n：";
    while (cin >> n) {
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        int result;
        // result = fibonacci(n);
        result = fibonacci_1(n);
        // result = fibonacci_2(1, 1, n);

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        
        cout << "fibonacci数列的第 " << n << " 个数为: " << result << endl;

        cout << "耗时:" ;
        cout << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
        
        cout << "输入n：";
    }    
}




void time_consumption_fibonacci_2() {
    int n;
    cout << "斐波那契数的递归算法 版本2" << endl << "输入n：";
    while (cin >> n) {
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        
        int result;
        // result = fibonacci(n);
        // result = fibonacci_1(n);
        result = fibonacci_2(1, 1, n);
    

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        
        cout << "fibonacci数列的第 " << n << " 个数为: " << result << endl;

        cout << "耗时:" ;
        cout << milliseconds(end_time).count() - milliseconds(start_time).count()
            <<" ms"<< endl;
       
        cout << "输入n：";
    }    
}


