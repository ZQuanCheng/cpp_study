# floor_ceil_round

--------------------------------------------------------------------------------

>
> https://blog.csdn.net/qq_43331089/article/details/124301689
>
> `#include <cmath>`
>
> `floor()` 向下取整
>
> `ceil()` 向上取整
>
> `round()` 四舍五入
>
> <font color="gree"> 注意，3个函数返回值都是`double`类型， 并不是`int`类型 </font>

>
> ```c++
> 功能：把一个小数向下取整
>       即就是如果数是2.2 ，那向下取整的结果就为2.000000
>             如果数是-2.2 ，那向上取整的结果就为-3.000000
> 
> 原型：double floor(doube x);
>     参数解释：
>         x:是需要计算的数
> 返回值：
>     成功：返回一个double类型的数，此数默认有6位小数
>     无失败的返回值
> 
> 头文件：#include<math.h>
> ```
> 



>
> ```c++
> 功能：把一个小数向上取整
>       即就是如果数是2.2 ，那向上取整的结果就为3.000000
>            如果数是-2.2 ，那向上取整的结果就为-2.000000
> 
> 原型：double ceil(doube x);
>     参数解释：
>         x:是需要计算的数
> 
> 返回值：
>     成功：返回一个double类型的数，此数默认有6位小数
>     无失败的返回值
> 
> 头文件：#include<math.h>
> ```
> 



>
> ```c++
> 功能：把一个小数四舍五入
>       即就是如果数是2.2 ，那四舍五入的结果就为2.000000
>            如果数是-2.2 ，那向上取整的结果就为-2.000000
>            如果数是2.7 ，那向上取整的结果就为3.000000
>            如果数是-2.7 ，那向上取整的结果就为-3.000000
>  
> 原型：double round(doube x);
>     参数解释：
>         x:是需要计算的数
> 
> 头文件：#include<math.h>
> ```
> 

















