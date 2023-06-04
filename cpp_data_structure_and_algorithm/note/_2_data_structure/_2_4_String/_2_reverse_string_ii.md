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

# 字符串

--------------------------------------------------------------------------------

## 反转字符串 II  reverse string ii

## _1_reverse_string_ii.md

--------------------------------------------------------------------------------

### 541. 反转字符串 II

> Leetcode链接: https://leetcode.cn/problems/reverse-string/

> 给定一个字符串 `s` 和一个整数 `k`，从字符串开头算起，每计数至 `2k` 个字符，就反转这 `2k` 字符中的前 `k` 个字符。
>
> * 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
> * 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。
>
> 
> 
> **示例1：**
> 
> ```html
> 输入：s = "abcdefg", k = 2
> 输出："bacdfeg"
> ```
>
> **示例2：**
> 
> ```html
> 输入：s = "abcd", k = 2
> 输出："bacd"
> ```
>
> **提示：**
> * `1 <= s.length <= 104`
> * `s` 仅由小写英文组成
> * `1 <= k <= 104`
>
> ```c++
> class Solution {
> public:
>     string reverseStr(string s, int k) {
> 
>     }
> };
> ```
> 
> 
> 



#### 我的解法
```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        // std::reverse 反转左闭右开区间内的元素顺序[left, right)

        // 其实就是每隔2k个字符进行一次循环
        string::iterator it = s.begin();
        while(it != s.end()) { // 剩余字符少于
            if(s.end() - it - 1 < k) {
                reverse(it, s.end());
                it = s.end();
            }
            else if((s.end() - it - 1 >= k) && (s.end() - it - 1 < 2*k)) {
                reverse(it, it + k);
                it = s.end();
            }
            else { // s.end() - it - 1 > 2k
                reverse(it, it + k);
                it = it + 2*k;                
            }
        }
        
        return s;
    }
};
```





#### 代码随想录

> 这道题目其实也是模拟，实现题目中规定的反转规则就可以了。
>
> 一些同学可能为了处理逻辑：每隔`2k`个字符的前k的字符，写了一堆逻辑代码或者再搞一个计数器，来统计`2k`，再统计前`k`个字符。
>
> 其实在遍历字符串的过程中，只要让 `i += (2 * k)`，`i` 每次移动 `2 * k` 就可以了，然后判断是否需要有反转的区间。
>
> 因为要找的也就是每`2 * k` 区间的起点，这样写，程序会高效很多。
>
> **所以当需要固定规律一段一段去处理字符串的时候，要想想在在for循环的表达式上做做文章。**
>
> 那么这里具体反转的逻辑我们要不要使用库函数呢，其实用不用都可以，使用`reverse`来实现反转也没毛病，毕竟不是解题关键部分。
>
> C++代码
>
> ```c++
> class Solution {
> public:
>     string reverseStr(string s, int k) {
>         for (int i = 0; i < s.size(); i += (2 * k)) {
>             // 1. 每隔 2k 个字符的前 k 个字符进行反转
>             // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
>             if (i + k <= s.size()) {
>                 reverse(s.begin() + i, s.begin() + i + k );
>             } else {
>                 // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
>                 reverse(s.begin() + i, s.end());
>             }
>         }
>         return s;
>     }
> };
> ```
>
> * 时间复杂度: `O(n)`
> * 空间复杂度: `O(1)`
> 
> 那么我们也可以实现自己的`reverse`函数，其实和题目344. 反转字符串 (`_1_reverse_string.md`)道理是一样的。
> 
> 下面我实现的`reverse`函数区间是左闭右闭区间，代码如下：
> 
> ```c++
> class Solution {
> public:
>     void reverse(string& s, int start, int end) {
>         for (int i = start, j = end; i < j; i++, j--) {
>             swap(s[i], s[j]);
>         }
>     }
>     string reverseStr(string s, int k) {
>         for (int i = 0; i < s.size(); i += (2 * k)) {
>             // 1. 每隔 2k 个字符的前 k 个字符进行反转
>             // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
>             if (i + k <= s.size()) {
>                 reverse(s, i, i + k - 1);
>                 continue;
>             }
>             // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
>             reverse(s, i, s.size() - 1);
>         }
>         return s;
>     }
> };
> ```
> 
> 时间复杂度: `O(n)`
> 空间复杂度: `O(1)`或`O(n)`, 取决于使用的语言中字符串是否可以修改.
>
> 另一种思路的解法
>
> ```c++
> class Solution {
> public:
>     string reverseStr(string s, int k) {
>         int n = s.size(),pos = 0;
>         while(pos < n){
>             //剩余字符串大于等于k的情况
>             if(pos + k < n) reverse(s.begin() + pos, s.begin() + pos + k);
>             //剩余字符串不足k的情况 
>             else reverse(s.begin() + pos,s.end());
>             pos += 2 * k;
>         }
>         return s;
>     }
> };
> ```
>
> * 时间复杂度: `O(n)`
> * 空间复杂度: `O(1)`
> 
> 
> 























