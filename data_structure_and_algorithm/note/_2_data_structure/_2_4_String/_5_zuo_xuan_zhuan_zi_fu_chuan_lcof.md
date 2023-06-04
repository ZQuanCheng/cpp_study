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

## 左旋转字符串  zuo xuan zhuan zi fu chuan lcof

## _5_zuo_xuan_zhuan_zi_fu_chuan_lcof.md

--------------------------------------------------------------------------------

### 剑指 Offer 58 - II. 左旋转字符串

> Leetcode链接: https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

> 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"`abcdefg`"和数字`2`，该函数将返回左旋转两位得到的结果"`cdefgab`"。
>
> 
> 
> **示例1：**
> 
> ```html
> 输入: s = "abcdefg", k = 2
> 输出: "cdefgab"
> ```
>
> **示例2：**
> 
> ```html
> 输入: s = "lrloseumgh", k = 6
> 输出: "umghlrlose"
> ```
>
> **限制：**
> * `1 <= k < s.length <= 10000`
>
> ```c++
> class Solution {
> public:
>     string reverseLeftWords(string s, int n) {
> 
>     }
> };
> ```
> 
> 
> 



 
#### 我的解法

> * 取出前`n`个字符
> * 将后面的`s.size() - n`个字符前移
> * 将n个字符添加到最后

```c++
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // 先存储前n个字符
        // string s(s1,pos,len) 将s1从下标pos开始拷贝，拷贝len个字符
        string str(s, 0, n); 

        // 使用双指针移动后面的字符串到前面
        int left = 0;
        int right = n; // 第n + !个字符位置
        while(right < s.size()) {
            s[left] = s[right];
            left++;
            right++;
        }
        // 此时left移动到s.size() - n位置
        s.resize(left); // 将s的长度缩短到s.size() - n

        // 将前n个字符添加到后面
        s += str; 

        return s;
    }
};
```



#### 代码随想录

> 为了让本题更有意义，提升一下本题难度：**不能申请额外空间，只能在本串上操作**。
>
> 不能使用额外空间的话，模拟在本串操作要实现左旋转字符串的功能还是有点困难的。
>
> 那么我们可以想一下上一题目字符串：花式反转还不够！ (`_4_reverse_words_in_a_string.md`)中讲过，**使用整体反转+局部反转就可以实现反转单词顺序的目的**。
>
> 这道题目也非常类似，依然可以通过局部反转+整体反转 达到左旋转的目的。
>
> 具体步骤为：
> * 反转区间为前`n`的子串
> * 反转区间为`n`到末尾的子串
> * 反转整个字符串
>
> 最后就可以达到左旋`n`的目的，而不用定义新的字符串，完全在本串上操作。
>
> 例如 ：示例1中 输入：字符串`abcdefg`，`n=2`
>
> 如图：
>
> <div align=center>
> <img src="./images/zuo_xuan_zhuan_zi_fu_chuan_lcof_1.png" style="zoom:100%;"/>
> </div>
>
> 最终得到左旋2个单元的字符串：`cdefgab`
> 
> 思路明确之后，那么代码实现就很简单了
>
> C++代码如下：
> 
> ```c++
> class Solution {
> public:
>     string reverseLeftWords(string s, int n) {
>         reverse(s.begin(), s.begin() + n);
>         reverse(s.begin() + n, s.end());
>         reverse(s.begin(), s.end());
>         return s;
>     }
> };
> ```
> 
> * 时间复杂度: `O(n)`
> * 空间复杂度：`O(1)`
>
> 是不是发现这代码也太简单了，哈哈。
>
> 

#### 总结

> <font color="yellow"> 
> 
> 此时我们已经反转好多次字符串了，来一起回顾一下吧。
>
> 在这篇文章344.反转字符串 (`_1_reverse_string.md`)，第一次讲到反转一个字符串应该怎么做，使用了双指针法。
>
> 然后发现541. 反转字符串II (`_2_reverse_string_ii.md`)，这里开始给反转加上了一些条件，当需要固定规律一段一段去处理字符串的时候，要想想在for循环的表达式上做做文章。
>
> 后来在151.翻转字符串里的单词 (`_4_reverse_words_in_a_string.md`)中，要对一句话里的单词顺序进行反转，发现先整体反转再局部反转 是一个很妙的思路。
>
> 最后再讲到本题，本题则是先局部反转再 整体反转，与151.翻转字符串里的单词 (`_4_reverse_words_in_a_string.md`)类似，但是也是一种新的思路。
> 
> 好了，反转字符串一共就介绍到这里，相信大家此时对反转字符串的常见操作已经很了解了。
>
> </font>
>
> 


#### 题外话

> 
> 一些同学热衷于使用`substr`，来做这道题。 其实使用`substr` 和 反转 时间复杂度是一样的 ，都是`O(n)`，但是使用`substr`申请了额外空间，所以空间复杂度是`O(n)`，而反转方法的空间复杂度是`O(1)`。
>
> **如果想让这套题目有意义，就不要申请额外空间**
>
> 







































