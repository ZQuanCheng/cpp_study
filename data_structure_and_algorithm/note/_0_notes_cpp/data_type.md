# data_type

--------------------------------------------------------------------------------


> 
> <font color="gree"> 
>
> 
> 注意：
> 
> https://blog.csdn.net/m0_56618741/article/details/121169946
> 
> 在`C++`中可以使用
> 
> `<limits.h>`中
> * `INT_MIN`,  `INT_MAX`分别表示`int`的最小/最大值。
> * `LONG_MIN`, `LONG_MAX`分别表示`long`的最小/最大值。
> 
> `<float.h>`中
> * `FLT_MIN`,  `FLT_MAX`分别表示`float`的最小/最大值，但是其均为正数。想要表示负数时，需要加负号`-`
> * `DBL_MIN`,  `DBL_MAX`分别表示`double`的最小/最大值，但是其均为正数。想要表示负数时，需要加负号`-`
>
> 
> 除此之外
> `<limits.h>`中还有一个通用方法
>
> * `numeric_limits<typename>::min()` 表示`typename`的最小值。
> * `numeric_limits<typename>::max()` 表示`typename`的最大值。
> 
> </font>
> 
> ```c++
> #include <iostream> 
> #include <climits>  // #include <limits.h>   INT_MIN, INT_MAX: 分别表示int的最小最大值    LONG_MIN, LONG_MAX: 分别表示long的最小最大值
> #include <cfloat>   // #include <float.h>    FLT_MIN, FLT_MAX: 分别表示float的最小最大值  DBL_MIN, DBL_MAX:   分别表示double的最小最大值
> using namespace std; 
> 
> int main()
> {
> 
>     cout << "INT_MIN = " << INT_MIN << endl;
>     cout << "INT_MAX = " << INT_MAX << endl;
>     cout << "int最小值： " << numeric_limits<int>::min() << endl;  
>     cout << "int最大值： " << numeric_limits<int>::max() << endl;  
>     cout << endl;
> 
>     cout << "LONG_MIN = " << LONG_MIN << endl;
>     cout << "LONG_MAX = " << LONG_MAX << endl;
>     cout << "long最小值： " << numeric_limits<long>::min() << endl;  
>     cout << "long最大值： " << numeric_limits<long>::max() << endl;  
>     cout << endl;
> 
>     cout << "FLT_MIN = " << FLT_MIN << endl;
>     cout << "FLT_MAX = " << FLT_MAX << endl;
>     cout << "float最小值： " << numeric_limits<float>::min() << endl;  
>     cout << "float最大值： " << numeric_limits<float>::max() << endl;  
>     cout << endl;
> 
>     cout << "DBL_MIN = " << DBL_MIN << endl;
>     cout << "DBL_MAX = " << DBL_MAX << endl;
>     cout << "double最小值： " << numeric_limits<double>::min() << endl;  
>     cout << "double最大值： " << numeric_limits<double>::max() << endl;  
>     cout << endl;
> 
>     cout << endl;
>     pause(); // system("pause"); 
> 
>     return 0;
> }
> 
> ```
>
> 运行结果如下： 
>
> ```c++
> INT_MIN = -2147483648
> INT_MAX = 2147483647
> int最小值： -2147483648
> int最大值： 2147483647
> 
> LONG_MIN = -9223372036854775808
> LONG_MAX = 9223372036854775807
> long最小值： -9223372036854775808
> long最大值： 9223372036854775807
> 
> FLT_MIN = 1.17549e-38
> FLT_MAX = 3.40282e+38
> float最小值： 1.17549e-38
> float最大值： 3.40282e+38
> 
> DBL_MIN = 2.22507e-308
> DBL_MAX = 1.79769e+308
> double最小值： 2.22507e-308
> double最大值： 1.79769e+308
> ```
> 
> 
> **查看`climits`和`cfloat`**
>
> ```c++
> /usr/include/c++/8/climits
> 
> #pragma GCC system_header
> 
> #include <bits/c++config.h>
> #include <limits.h>
> ```
> 
> ```c++
> /usr/include/c++/8/cfloat
> 
> #pragma GCC system_header
> 
> #include <bits/c++config.h>
> #include <float.h>
> ```
> 
> **查看`limits.h`和`float.h`**
>
> ```c++
> /usr/lib/gcc/x86_64-linux-gnu/8/include/limits.h
> 
> /* Minimum and maximum values a `signed int' can hold.  */
> #undef INT_MIN
> #define INT_MIN (-INT_MAX - 1)
> #undef INT_MAX
> #define INT_MAX __INT_MAX__
> 
> /* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */
> #undef UINT_MAX
> #define UINT_MAX (INT_MAX * 2U + 1U)
> 
> /* Minimum and maximum values a `signed long int' can hold.
>    (Same as `int').  */
> #undef LONG_MIN
> #define LONG_MIN (-LONG_MAX - 1L)
> #undef LONG_MAX
> #define LONG_MAX __LONG_MAX__
> 
> /* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */
> #undef ULONG_MAX
> #define ULONG_MAX (LONG_MAX * 2UL + 1UL)
> ```
>
> ```c++
> /usr/lib/gcc/x86_64-linux-gnu/8/include/float.h
> 
> /* Minimum normalized positive floating-point number, b**(emin - 1).  */
> #undef FLT_MIN
> #undef DBL_MIN
> #undef LDBL_MIN
> #define FLT_MIN		__FLT_MIN__
> #define DBL_MIN		__DBL_MIN__
> #define LDBL_MIN	__LDBL_MIN__
> 
> /* Maximum representable finite floating-point number,
> 
> 	(1 - b**-p) * b**emax
> */
> #undef FLT_MAX
> #undef DBL_MAX
> #undef LDBL_MAX
> #define FLT_MAX		__FLT_MAX__
> #define DBL_MAX		__DBL_MAX__
> #define LDBL_MAX	__LDBL_MAX__
> ```
>


















