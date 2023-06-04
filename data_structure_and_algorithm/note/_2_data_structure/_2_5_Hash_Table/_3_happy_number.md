# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

* 一个有非常简明例子的cpp网站：https://en.cppreference.com/w/

--------------------------------------------------------------------------------
> **大家不必太在意leetcode上执行用时，打败多少多少用户，这个就是一个玩具，非常不准确。**
> 
> 做题的时候自己能分析出来时间复杂度就可以了，至于leetcode上执行用时，大概看一下就行，只要达到最优的时间复杂度就可以了，
> 
> 一样的代码多提交几次可能就击败百分之百了....
--------------------------------------------------------------------------------

# 哈希表

--------------------------------------------------------------------------------

## 快乐数 ihappy number

## _3_happy_number.md

--------------------------------------------------------------------------------

### 202. 快乐数

> Leetcode链接: https://leetcode.cn/problems/happy-number/

> 编写一个算法来判断一个数 `n` 是不是快乐数。
>
> 「快乐数」 定义为：
> 
> * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
> 
> * 然后重复这个过程直到这个数变为 `1`，也可能是 **无限循环** 但始终变不到 1。
> 
> * 如果这个过程 **结果为 `1`**，那么这个数就是快乐数。
>
> 如果 `n` 是 快乐数 就返回 `true` ；不是，则返回 `false` 。
>
> 
> 
> **示例1：**
> 
> ```html
> 输入：n = 19
> 输出：true
> 解释：
> 1^2 + 9^2 = 82
> 8^2 + 2^2 = 68
> 6^2 + 8^2 = 100
> 1^2 + 0^2 + 0^2 = 1
> ```
>
> **示例2：**
> 
> ```html
> 输入：n = 2
> 输出：false
> ```
>
> **提示：**
> * `1 <= n <= 2^31 - 1`
>
> ```c++
> class Solution {
> public:
>     bool isHappy(int n) {
> 
>     }
> };
> ```
> 
> 



#### 我的解法 注意读题，意思就是要么变为1，要么重复回到之前的某次求和结果，陷入死循环

```c++
class Solution {
public:
    bool isHappy(int n) {
        // 注意读题，要么变为1，要么重复回到之前的某次求和结果，陷入死循环

        int num = n;                // 暂存数字
        queue<int> que;             // 存储拆分的每位数字
        int sum = 10;               // 暂存循环中的平方和
        unordered_set<int> sum_set; // 存储每次运算的平方和

        // 拆分每个位置的数字, 然后求平方和，直到sum为个位数
        while(1) {
            // 拆分每个位置的数字，存入queue
            while(num / 10 != 0) { // 被除数小于10时（即只剩最高位），停止取余,
                int shang = num % 10; // 取出临时最低位的数字，即除余
                que.push(shang); 
                num = num / 10; // 去掉最低位
            }
            que.push(num); // 最高位
            
            // 一个个从队列中取出，求和
            sum = 0;
            while(!que.empty()) {
                int temp = que.front();
                sum = sum + temp * temp;
                que.pop();
            } 

            // 检查是否为1，若为1，则直接返回
            if(sum == 1) return true;
            
            // 检查是否出现重复的sum
            if(sum_set.find(sum) != sum_set.end()) { // 发现之前出现过的总和，则直接返回false，因为循环了
                return false;
            }   
            else {                     // 之前没出现过这个sum值，加入set
                sum_set.insert(sum);
            }

            num = sum;
        }
    }
};
```


#### 修改`拆分每个位置的数字`的循环进入条件，可以不用最后加一句`que.push(num); `


```c++
class Solution {
public:
    bool isHappy(int n) {
        // 注意读题，要么变为1，要么重复回到之前的某次求和结果，陷入死循环

        int num = n;                // 暂存数字
        queue<int> que;             // 存储拆分的每位数字
        int sum = 10;               // 暂存循环中的平方和
        unordered_set<int> sum_set; // 存储每次运算的平方和

        // 拆分每个位置的数字, 然后求平方和，直到sum为个位数
        while(1) {
            // 拆分每个位置的数字，存入queue
            while(num != 0) { // 被除数小于10时（即只剩最高位），停止取余,
                int shang = num % 10; // 取出临时最低位的数字，即除余
                que.push(shang); 
                num = num / 10; // 去掉最低位
            }
            
            // 一个个从队列中取出，求和
            sum = 0;
            while(!que.empty()) {
                int temp = que.front();
                sum = sum + temp * temp;
                que.pop();
            } 

            // 检查是否为1，若为1，则直接返回
            if(sum == 1) return true;
            
            // 检查是否出现重复的sum
            if(sum_set.find(sum) != sum_set.end()) { // 发现之前出现过的总和，则直接返回false，因为循环了
                return false;
            }   
            else {                     // 之前没出现过这个sum值，加入set
                sum_set.insert(sum);
            }

            num = sum;
        }
    }
};
```



#### 如果把拆分求和的过程更加简化，就成了代码随想录的那样

```c++
class Solution {
public:
    bool isHappy(int n) {
        // 注意读题，要么变为1，要么重复回到之前的某次求和结果，陷入死循环

        int num = n;                // 暂存数字
        int sum = 10;               // 暂存循环中的平方和
        unordered_set<int> sum_set; // 存储每次运算的平方和

        while(1) {
            // 拆分每个位置的数字, 然后求平方和，直到sum为个位数
            sum = 0;
            while (num != 0) {
                sum = sum +  (num % 10) * (num % 10);
                num = num/10;
            }

            // 检查是否为1，若为1，则直接返回
            if(sum == 1) return true;
            
            // 检查是否出现重复的sum
            if(sum_set.find(sum) != sum_set.end()) { // 发现之前出现过的总和，则直接返回false，因为循环了
                return false;
            }   
            else {                     // 之前没出现过这个sum值，加入set
                sum_set.insert(sum);
            }

            num = sum;
        }
    }
};
```









#### 代码随想录

> 这道题目看上去貌似一道数学问题，其实并不是！
>
>题目中说了会 **无限循环**，那么也就是说**求和的过程中，`sum`会重复出现，这对解题很重要！**
>
> 正如`Hash_Table.md`中所说，**当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法了**。
>
> 所以这道题目使用哈希法，来判断这个`sum`是否重复出现，如果重复了就是`return false`， 否则一直找到`sum`为`1`为止。
>
> 判断`sum`是否重复出现就可以使用`unordered_set`。
> 
> **还有一个难点就是求和的过程，如果对取数值各个位上的单数操作不熟悉的话，做这道题也会比较艰难**
>
> C++代码如下：
>
> ```c++
> class Solution {
> public:
>     // 取数值各个位上的单数之和
>     int getSum(int n) {
>         int sum = 0;
>         while (n) {
>             sum += (n % 10) * (n % 10);
>             n /= 10;
>         }
>         return sum;
>     }
>     bool isHappy(int n) {
>         unordered_set<int> set;
>         while(1) {
>             int sum = getSum(n);
>             if (sum == 1) {
>                 return true;
>             }
>             // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
>             if (set.find(sum) != set.end()) {
>                 return false;
>             } else {
>                 set.insert(sum);
>             }
>             n = sum;
>         }
>     }
> };
> ```
> 
> 
> 













