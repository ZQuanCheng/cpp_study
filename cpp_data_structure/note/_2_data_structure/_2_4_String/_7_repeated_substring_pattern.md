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

## 重复的子字符串  repeated substring pattern

## _7_repeated_substring_pattern.md

--------------------------------------------------------------------------------

### 459. 重复的子字符串

> Leetcode链接: https://leetcode.cn/problems/repeated-substring-pattern/

>
> 给定一个非空的字符串 `s` ，检查是否可以通过由它的一个子串重复多次构成。
>
> 
> **示例1：**
> 
> ```html
> 输入: s = "abab"
> 输出: true
> 解释: 可由子串 "ab" 重复两次构成。
> ```
>
> **示例2：**
> 
> ```html
> 输入: s = "aba"
> 输出: false
> ```
>
> **示例3：**
> 
> ```html
> 输入: s = "abcabcabcabc"
> 输出: true
> 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
> ```
>
> **提示：**
> * `1 <= s.length <= 104`
> * `s` 由小写英文字母组成
>
> ```c++
> class Solution {
> public:
>     bool repeatedSubstringPattern(string s) {
> 
>     }
> };
> ```
>  






#### 我的解法 暴力解法 时间复杂度`O(n^2)`

```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 首先必须保证s.size() / str.size() 能够整除子串长度
        // 且子串长度不大于 k = str.size() <= s.size() / 2
        
        // 遍历各种可能的子串长度
        // 一级循环
        for(int str_len=1; str_len <= s.size() / 2; str_len++) { // 从1开始，子串长度不为0
            // 保证子串长度合理
            // 如果不能够整除子串长度（余数！= 0），当前子串长度不合理
            if(s.size() % str_len != 0) continue; 

            bool flags = false;  // 标志位

            // 二级循环
            int cycles = s.size() / str_len; // 子串可能的最多重复次数
            for(int i=1; i < cycles; i++) {  // 第i次循环. i = 1,2, ..., n-1

                // 从s[str_len]开始，与s[0]进行比较；s[str_len + 1]与s[1]进行比较; ...
                // 从s[str_len * 2]开始，与s[0]进行比较；s[str_len * 2 + 1]与s[1]进行比较; ...
                // ...
                int start = str_len * i; // 第i次循环中，进行比较的第一个下标

                // 三级循环
                for(int j=0; j < str_len; j++) {
                    if(s[start + j] != s[j]) { // 只要有一个比较结果不对
                        flags = false; // 标志位false
                        break;         // 停止三级循环
                    } 
                    else {   
                        flags = true;
                    }
                } 

                // 每次三级循环结束后，检查flags
                if(!flags) {
                    break; // 只要有一组子串比对错误，当前str_len就不合理，停止二级循环，
                }
            }       
            
            // 每次二级循环结束后，检查flags
            if(flags) { // 如果为true，说明重复子串的长度str_len正确
                return true;
            }
        }

        // str_len从1 ~ s.size() / 2都不对，说明不能由重复子串构成
        return false; 
    }
};
```



#### 代码随想录

#### 思路

> 
> 暴力的解法， 就是一个`for`循环获取 子串的终止位置， 然后判断子串是否能重复构成字符串，又嵌套一个`for`循环，所以是`O(n^2)`的时间复杂度。
> 
> 有的同学可以想，怎么一个`for`循环就可以获取子串吗？ 至少得一个`for`获取子串起始位置，一个`for`获取子串结束位置吧。
> 
> 其实我们只需要判断，以第一个字母为开始的子串就可以，所以一个`for`循环获取子串的终止位置就行了。 而且遍历的时候 都不用遍历结束，只需要遍历到中间位置，因为子串结束位置大于中间位置的话，一定不能重复组成字符串。
> 
> 暴力的解法，这里就不详细讲解了。
> 
> 
> 主要讲一讲 **移动匹配** 和 `KMP` 两种方法。
>
> 
> 


#### 移动匹配

> 
> 当一个字符串`s：abcabc`，内部由重复的子串组成，那么这个字符串的结构一定是这样的：
>
> 
















