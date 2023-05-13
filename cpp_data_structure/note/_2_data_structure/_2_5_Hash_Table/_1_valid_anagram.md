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

## 有效的字母异位词 valid anagram

## _1_valid_anagram.md

--------------------------------------------------------------------------------

### 242.有效的字母异位词

> Leetcode链接: https://leetcode.cn/problems/valid-anagram/

> 给定两个字符串 `s` 和 `t` ，编写一个函数来判断 `t` 是否是 `s` 的字母异位词。
> 
> **注意**：若 `s` 和 `t` 中每个字符出现的次数都相同，则称 `s` 和 `t` 互为字母异位词。
> 
> **示例1：**
> 
> ```html
> 输入: s = "anagram", t = "nagaram"
> 输出: true
> ```
>
> **示例2：**
> 
> ```html
> 输入: s = "rat", t = "car"
> 输出: false
> ```
>
> **提示：**
> * `1 <= s.length, t.length <= 5 * 104`
> * `s` 和 `t` 仅包含小写字母
>
> ```c++
> class Solution {
> public:
>     bool isAnagram(string s, string t) {
> 
>     }
> };
> ```
> 




#### 我的解法 暴力解法，遍历，使用`std::unordered_map`记录

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 使用unordered_map<key, value> 计算每个字母出现的次数
        unordered_map<char, int> s_map;            // s_map[key]即value，字符key的出现次数为value       
        unordered_map<char, int> t_map;            // t_map[key]即value，字符key的出现次数为value    
        
        // 首先要保证字符串长度相同，如果不同，直接返回false
        if(s.size() != t.size()) return false;

        // 遍历字符串
        // 先把每个字母出现次数置0
        for(size_t i=0; i < s.size(); i++) {
            s_map[s[i]] = 0;                
        }
        for(size_t i=0; i < t.size(); i++) {
            t_map[t[i]] = 0;
        }        
        // 然后计算每个字母出现次数
        for(size_t i=0; i < s.size(); i++) {  
            s_map[s[i]] = s_map[s[i]] + 1;    // s_map[key]即value，这里是++value的意思，
        }
        for(size_t i=0; i < t.size(); i++) {
            t_map[t[i]] = t_map[t[i]] + 1; 
        }             

        // 比较对应字母的出现次数是否相同
        unordered_map<char, int>::iterator it;
        for(it = s_map.begin(); it != s_map.end(); it++) {
            char ch = it->first; 
            if(s_map[ch] != t_map[ch]) { // 如果有出现相同字母，不同次数，直接返回false
                return false;            
            }
        }
        
        // 如果所有相同字母的出现次数都相同，返回true
        return true;
    }
};
```


#### 代码随想录

> 
> **思路**
>
> 先看暴力的解法，两层`for`循环，同时还要记录字符是否重复出现，很明显时间复杂度是 `O(n^2)`。
> 
> 暴力的方法这里就不做介绍了，直接看一下有没有更优的方式。
> 
> **数组其实就是一个简单哈希表**，而且这道题目中字符串只有小写字符，那么就可以定义一个数组，来记录字符串s里字符出现的次数。
>
> 需要定义一个多大的数组呢，定一个数组叫做`record`，大小为`26` 就可以了，初始化为`0`，因为字符`a`到字符`z`的`ASCII`也是26个连续的数值。
>
> 为了方便举例，判断一下字符串`s= "aee"`,` t = "eae"`。
>
> 操作动画如下：
>
> 
> <div align=center>
> <img src="./images/valid_anagram_1.gif" style="zoom:100%;"/>
> </div>
>
> 定义一个数组叫做`record`用来上记录字符串`s`里字符出现的次数。
>
> 需要把字符映射到数组也就是哈希表的索引下标上，**因为字符`a`到字符`z`的`ASCII`是`26`个连续的数值，所以字符`a`映射为下标`0`，相应的字符`z`映射为下标`25`**。
>
> 再遍历 字符串`s`的时候，只需要将 `s[i] - 'a'` 所在的元素做`+1` 操作即可，并不需要记住字符`a`的`ASCII`，只要求出一个相对数值就可以了。 这样就将字符串`s`中字符出现的次数，统计出来了。
>
> 那看一下如何检查字符串`t`中是否出现了这些字符，同样在遍历字符串`t`的时候，对`t`中出现的字符映射哈希表索引上的数值再做`-1`的操作。
>
> 那么最后检查一下，**`record`数组如果有的元素不为零`0`，说明字符串`s`和`t`一定是谁多了字符或者谁少了字符，`return false`**。
> 
> 最后如果`record`数组所有元素都为零`0`，说明字符串`s`和`t`是字母异位词，`return true`。
>
> 时间复杂度为`O(n)`，空间上因为定义是的一个常量大小的辅助数组，所以空间复杂度为`O(1)`。
>
> C++ 代码如下：
>
> ```c++
> class Solution {
> public:
>     bool isAnagram(string s, string t) {
>         int record[26] = {0}; 
>         for (int i = 0; i < s.size(); i++) {
>             // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
>             record[s[i] - 'a']++;
>         }
>         for (int i = 0; i < t.size(); i++) {
>             record[t[i] - 'a']--;
>         }
>         for (int i = 0; i < 26; i++) {
>             if (record[i] != 0) {
>                 // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
>                 return false;
>             }
>         }
>         // record数组所有元素都为零0，说明字符串s和t是字母异位词
>         return true;
>     }
> };
> ```
> 
> 





--------------------------------------------------------------------------------

##### 为什么上面的`recode`数组初始化就写了一个`0`

> <font color="yellow">
> 
> 讲一讲，相对于传统的C风格数组，`std::vector`、`std::string`这种容器有什么优势？
>
> 为什么不用`int num[size] = {0,0,...,0};` 而用`vector<int> num(size, 0);`
>
> 为什么不用`char ch[size] = {'c','c',...,'c'};` 而用`string s(size,'c');`
> 
> </font>


> **对于C风格的数组，有一个经常要注意的**
>
> <font color="gree">在初始化时，`int`类型的数组在初始化时，必须赋值，不然会各种乱起八糟的值</font>
>
> <font color="gree">但是也不用给所有元素都赋值，只需要给第一个元素赋值，后面的元素会自动赋值为`0`</font>
>
> ```c++
> int size = 10;
> 
> int num1[size] = {0};
> for (int i = 0; i < size; i++) {
>    cout << num1[i] << ", ";
> }
> cout << endl;
> 
> int num2[size] = {1};
> for (int i = 0; i < size; i++) {
>    cout << num2[i] << ", ";
> }
> cout << endl;
> 
> int num3[size] = {1, 2, 3};
> for (int i = 0; i < size; i++) {
>    cout << num3[i] << ", ";
> }
> cout << endl;
> ```
>
> 编译并运行，结果如下
>
> ```c++
> 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
> 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
> 1, 2, 3, 0, 0, 0, 0, 0, 0, 0,
> ```
>
> <font color="gree">但是别的类型数组没有自动赋值的功能</font>
>
> <font color="gree">以字符数组为例</font>
>
> ```c++
> char size = 10;
> 
> char ch1[size] = {'a'};
> for (int i = 0; i < size; i++) {
>    cout << ch1[i] << ", ";
> }
> cout << endl;
> 
> char ch2[size] = {'b'};
> for (int i = 0; i < size; i++) {
>    cout << ch2[i] << ", ";
> }
> cout << endl;
> 
> char ch3[size] = {'a', 'b', 'c'};
> for (int i = 0; i < size; i++) {
>    cout << ch3[i] << ", ";
> }
> cout << endl;
> ```
>
> 编译并运行，结果如下
>
> ```c++
> a, , , , , , , , , , 
> b, , , , , , , , , , 
> a, b, c, , , , , , , , 
> ```
>
> <font color="yellow">所以，对于C风格的数组，没有统一的初始化的简单方式，总不能一个个赋初始值吧</font>
>
> <font color="yellow">如果我们用`std::vector`、`std::string`，都是有很方便的初始化函数</font>
>
> 例如
> 
> ```c++
> vector<T> v(n,val); //v中包含n个重复元素，每个元素的值都是val  
> 
> string s(n,'c'); // 将 s 初始化为字符 ‘c’ 的 n 个副本
> 
> ```
>
> <font color="yellow">当然容器还有更多的好操作，都是很方便我们使用的</font>
>
> 

--------------------------------------------------------------------------------



#### 相关题目

> 
> `383`.赎金信 `_6_ransom-note.md`
> 
> `49`.字母异位词分组
> 
> `438`.找到字符串中所有字母异位词
> 














