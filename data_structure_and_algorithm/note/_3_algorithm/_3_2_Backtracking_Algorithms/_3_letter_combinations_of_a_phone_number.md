# cpp_algorithms

* 代码随想录 https://programmercarl.com/

* geeksforgeeks https://www.geeksforgeeks.org

--------------------------------------------------------------------------------
> **大家不必太在意leetcode上执行用时，打败多少多少用户，这个就是一个玩具，非常不准确。**
> 
> 做题的时候自己能分析出来时间复杂度就可以了，至于leetcode上执行用时，大概看一下就行，只要达到最优的时间复杂度就可以了，
> 
> 一样的代码多提交几次可能就击败百分之百了....
--------------------------------------------------------------------------------

# 回溯算法

https://www.geeksforgeeks.org/backtracking-algorithms/

--------------------------------------------------------------------------------

## 电话号码的字母组合

## _3_letter_combinations_of_a_phone_number.md

--------------------------------------------------------------------------------

### 17. 电话号码的字母组合

> 
> Leetcode链接: https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
>
> 给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。
> 
> 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
>
> 
> <div align=center>
> <img src="./images/_3_letter_combinations_of_a_phone_number_1.png" style="zoom:100%"/>
> </div>
>
> 
> **示例1：**
> 
> ```html
> 输入：digits = "23"
> 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
> ```
> 
> **示例2：**
> 
> ```html
> 输入：digits = ""
> 输出：[]
> ```
> 
> **示例3：**
> 
> ```html
> 输入：digits = "2"
> 输出：["a","b","c"]
> ```
>
> **提示：**
> * `0 <= digits.length <= 4`
> * `digits[i]` 是范围 `['2', '9']` 的一个数字。
>
> ```c++
> class Solution {
> public:
>     vector<string> letterCombinations(string digits) {
> 
>     }
> };
> ```
> 




#### 我的解法

> <font color="yellow">
> 
> 为何会想到用到回溯法（递归）？
>
> 因为这是组合问题，常用回溯法？
> 
> </font>
> 
> <font color="gree">
> 
> 回溯法，一般可以解决如下几种问题：
>
> * 组合问题：`N`个数里面按一定规则找出`k`个数的集合
> * 切割问题：一个字符串按一定规则有几种切割方式
> * 子集问题：一个`N`个数的集合里有多少符合条件的子集
> * 排列问题：`N`个数按一定规则全排列，有几种排列方式
> * 棋盘问题：`N`皇后，解数独等等
>
> </font>
>
> 
> 
> **代码随想录的回溯法模板**
>
> ```c++ {.line-numbers}
> void backtracking(参数) {
>     if (终止条件) {
>         存放结果;
>         return;
>     }
> 
>     for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
>         处理节点;
>         backtracking(路径，选择列表); // 递归
>         回溯，撤销处理结果
>     }
> }
> ```
> 
> 
> 
> <font color="gree">我的代码如下</font>
> 
```c++
class Solution {
public:
    // 因为是组合问题，所以想到用回溯法，暴力枚举
    // 递归回溯三要素：参数和返回值、停止条件、遍历过程
    // 参数和返回值：结果集result、原始字符串digits、当前组合字符串string、待处理的digits的下标
    // 停止条件：当前str长度 == digits的长度
    // 遍历过程：想象出树形结构，当时全部为1叉树，横向遍历当前digits[index]对应的3或4种字符，然后深入递归到digits[index + 1]中
    void recursion(vector<string>& result, string& digits, string& str, int index) {
        // 停止条件
        if(str.size() == digits.size()) {
            result.push_back(str);
            return;
        }

        // 处理当前节点, 求digits[index]对应的具体int类型值
        int num = digits[index] - '0'; // digits[index]是char类型，例如'2'，使用'2' - '0'得到真正的int类型数字2
        // 如果需要将digits[index]（char类型）转换为具体数字（int类型），则通过减法实现`ch` - '0'
        // 如果需要需要将ASCII码（int类型），转换为具体字符（char类型）， 则直接赋值给char类型就可以，就可以实现ASCII码和对应字符之间的传唤

        // 如果需要将int类型转换为string类型，则通过内置函数to_string()实现
        // 如果需要将string类型转换为int类型，则通过<stdlib.h>的函数stoi()实现


        // 先搞清楚映射关系
        // 对于数字num (2 <= num <= 6), 能映射到的有3种字符，其对应的ASCII码为 'a' + (num-2)*3 + 0、'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2
        // 对于数字num=7, 能映射到的有4种字符，其对应的ASCII码为 'a' + (num-2)*3 + 0、'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2、'a' + (num-2)*3 + 3
        // 对于数字num=8, 能映射到的有3种字符，其对应的ASCII码为 'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2、'a' + (num-2)*3 + 3、
        // 对于数字num=9, 能映射到的有4种字符，其对应的ASCII码为 'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2、'a' + (num-2)*3 + 3、'a' + (num-2)*3 + 4
        if(num >= 2 && num <= 6) {
            for(int i=0; i <=2; i++) {
                int ascii = 'a' + (num-2)*3 + i; // 数字digits映射的数字
                str.push_back(static_cast<char>(ascii)); // str += static_cast<char>(ascii);
                recursion(result, digits, str, index+1); // 递归深入
                str.pop_back();         // 回溯， 但是string类型没有减法, 不能str -= static_cast<char>(ascii);
            }
        }
        else if(num == 7) {
            for(int i=0; i <=3; i++) {
                int ascii = 'a' + (num-2)*3 + i; // 数字digits映射的数字
                str.push_back(static_cast<char>(ascii)); // str += static_cast<char>(ascii);
                recursion(result, digits, str, index+1); // 递归深入
                str.pop_back();         // 回溯， 但是string类型没有减法, 不能str -= static_cast<char>(ascii);
            }
        }
        else if(num == 8) {
            for(int i=1; i <=3; i++) {
                int ascii = 'a' + (num-2)*3 + i; // 数字digits映射的数字
                str.push_back(static_cast<char>(ascii)); // str += static_cast<char>(ascii);
                recursion(result, digits, str, index+1); // 递归深入
                str.pop_back();         // 回溯， 但是string类型没有减法, 不能str -= static_cast<char>(ascii);
            }
        }  
        else if(num == 9) {
            for(int i=1; i <=4; i++) {
                int ascii = 'a' + (num-2)*3 + i; // 数字digits映射的数字
                str.push_back(static_cast<char>(ascii)); // str += static_cast<char>(ascii);
                recursion(result, digits, str, index+1); // 递归深入
                str.pop_back();         // 回溯， 但是string类型没有减法, 不能str -= static_cast<char>(ascii);
            }
        }        
        else {
            // 应该没有别的情况了
        }

    }


    vector<string> letterCombinations(string digits) {
        // 限定条件0 <= digits.length <= 4；  digits[i] 是范围 ['2', '9'] 的一个数字。
        // digits的长度 = 返回值中每个元素string的长度

        vector<string> result;
        if(digits.size() == 0) return result;
        string str;
        recursion(result, digits, str, 0);
        return result;
    }
};
```
> 
> <font color="gree">简化，不用那么多`for`循环代码</font>
> 
```c++
class Solution {
public:
    // 因为是组合问题，所以想到用回溯法，暴力枚举
    // 递归回溯三要素：参数和返回值、停止条件、遍历过程
    // 参数和返回值：结果集result、原始字符串digits、当前组合字符串string、待处理的digits的下标
    // 停止条件：当前str长度 == digits的长度
    // 遍历过程：想象出树形结构，当时全部为1叉树，横向遍历当前digits[index]对应的3或4种字符，然后深入递归到digits[index + 1]中
    void recursion(vector<string>& result, string& digits, string& str, int index) {
        // 停止条件
        if(str.size() == digits.size()) {
            result.push_back(str);
            return;
        }

        // 处理当前节点, 求digits[index]对应的具体int类型值
        int num = digits[index] - '0'; // digits[index]是char类型，例如'2'，使用'2' - '0'得到真正的int类型数字2
        // 如果需要将digits[index]（char类型）转换为具体数字（int类型），则通过减法实现`ch` - '0'
        // 如果需要需要将ASCII码（int类型），转换为具体字符（char类型）， 则直接赋值给char类型就可以，就可以实现ASCII码和对应字符之间的传唤

        // 如果需要将int类型转换为string类型，则通过内置函数to_string()实现
        // 如果需要将string类型转换为int类型，则通过<stdlib.h>的函数stoi()实现


        // 先搞清楚映射关系
        // 对于数字num (2 <= num <= 6), 能映射到的有3种字符，其对应的ASCII码为 'a' + (num-2)*3 + 0、'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2
        // 对于数字num=7, 能映射到的有4种字符，其对应的ASCII码为 'a' + (num-2)*3 + 0、'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2、'a' + (num-2)*3 + 3
        // 对于数字num=8, 能映射到的有3种字符，其对应的ASCII码为 'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2、'a' + (num-2)*3 + 3、
        // 对于数字num=9, 能映射到的有4种字符，其对应的ASCII码为 'a' + (num-2)*3 + 1、'a' + (num-2)*3 + 2、'a' + (num-2)*3 + 3、'a' + (num-2)*3 + 4
        int start = 0;
        int end = 0;
        if(num >= 2 && num <= 6) {
            start = (num-2)*3 + 0;
            end = (num-2)*3 + 2;
        }
        else if(num == 7) {
            start = (num-2)*3 + 0;
            end = (num-2)*3 + 3;
        }
        else if(num == 8) {
            start = (num-2)*3 + 1;
            end = (num-2)*3 + 3;
        }  
        else if(num == 9) {
            start = (num-2)*3 + 1;
            end = (num-2)*3 + 4;
        }        
        else {
            // 应该没有别的情况了
        }

        for(int i=start; i <=end; i++) {
            int ascii = 'a' + i; // 数字digits映射的数字
            str.push_back(static_cast<char>(ascii)); // str += static_cast<char>(ascii);
            recursion(result, digits, str, index+1); // 递归深入
            str.pop_back();         // 回溯， 但是string类型没有减法, 不能str -= static_cast<char>(ascii);
        }

    }


    vector<string> letterCombinations(string digits) {
        // 限定条件0 <= digits.length <= 4；  digits[i] 是范围 ['2', '9'] 的一个数字。
        // digits的长度 = 返回值中每个元素string的长度

        vector<string> result;
        if(digits.size() == 0) return result;
        string str;
        recursion(result, digits, str, 0);
        return result;
    }
};
```



>
> <font color="gree">或者我们直接列出来映射关系</font>
> 


```c++
class Solution {
public:
    // 因为是组合问题，所以想到用回溯法，暴力枚举
    // 递归回溯三要素：参数和返回值、停止条件、遍历过程
    // 参数和返回值：结果集result、原始字符串digits、当前组合字符串string、待处理的digits的下标, 映射关系表mapping
    // 停止条件：当前str长度 == digits的长度
    // 遍历过程：想象出树形结构，当时全部为1叉树，横向遍历当前digits[index]对应的三种字符，然后深入递归到digits[index + 1]中
    void recursion(vector<string>& result, string& digits, string& str, int index, vector<vector<char>>& mapping) {
        // 停止条件
        if(str.size() == digits.size()) {
            result.push_back(str);
            return;
        }

        // 处理当前节点, 求digits[index]对应的具体int类型值
        int num = digits[index] - '0'; // digits[index]是char类型，例如'2'，使用'2' - '0'得到真正的int类型数字2
        // 如果需要将digits[index]（char类型）转换为具体数字（int类型），则通过减法实现`ch` - '0'
        // 如果需要需要将ASCII码（int类型），转换为具体字符（char类型）， 则直接赋值给char类型就可以，就可以实现ASCII码和对应字符之间的传唤

        // 如果需要将int类型转换为string类型，则通过内置函数to_string()实现
        // 如果需要将string类型转换为int类型，则通过<stdlib.h>的函数stoi()实现

        // 横向遍历当前digits[index]对应的三种字符
        for(int i=0; i < mapping[num].size(); i++) {
            str.push_back(mapping[num][i]); // str += mapping[num][i]
            recursion(result, digits, str, index+1, mapping); // 递归深入, 到下一层digits[index + 1]中去，检测下一个数字对应的几种字符
            str.pop_back();         // 回溯， 但是string类型没有减法, 不能str -= mapping[num][i]
        }

    }

    vector<string> letterCombinations(string digits) {
        // 限定条件0 <= digits.length <= 4；  digits[i] 是范围 ['2', '9'] 的一个数字。

        // 先搞清楚映射关系
        // 对于数字num (2 <= num <= 9), 能映射到的有3种字符， 8也是映射3种
        // 但是7和9分别能映射4种字母？这怎么处理？
        // 还是我们直接列出来吧
        vector<vector<char>> mapping = {
            {},   
            {},   
            {'a', 'b', 'c'},  // mapping[2] = vector<char>{'a', 'b', 'c'}
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}                                            
        };

        vector<string> result;
        if(digits.size() == 0) return result;
        string str;
        recursion(result, digits, str, 0, mapping);
        return result;
    }
```


>
> <font color="gree">或者我们直接用`std::unordered_map`</font>
>

```c++
class Solution {
public:
    // 因为是组合问题，所以想到用回溯法，暴力枚举
    // 递归回溯三要素：参数和返回值、停止条件、遍历过程
    // 参数和返回值：结果集result、原始字符串digits、当前组合字符串string、待处理的digits的下标, 映射关系表mapping
    // 停止条件：当前str长度 == digits的长度
    // 遍历过程：想象出树形结构，当时全部为1叉树，横向遍历当前digits[index]对应的三种字符，然后深入递归到digits[index + 1]中
    void recursion(vector<string>& result, string& digits, string& str, int index, unordered_map<int, string>& mapping) {
        // 停止条件
        if(str.size() == digits.size()) {
            result.push_back(str);
            return;
        }

        // 处理当前节点, 求digits[index]对应的具体int类型值
        int num = digits[index] - '0'; // digits[index]是char类型，例如'2'，使用'2' - '0'得到真正的int类型数字2
        // 如果需要将digits[index]（char类型）转换为具体数字（int类型），则通过减法实现`ch` - '0'
        // 如果需要需要将ASCII码（int类型），转换为具体字符（char类型）， 则直接赋值给char类型就可以，就可以实现ASCII码和对应字符之间的传唤

        // 如果需要将int类型转换为string类型，则通过内置函数to_string()实现
        // 如果需要将string类型转换为int类型，则通过<stdlib.h>的函数stoi()实现

        // 横向遍历当前digits[index]对应的三种字符
        for(int i=0; i < mapping[num].size(); i++) {
            str.push_back(mapping[num][i]); // str += mapping[num][i]
            recursion(result, digits, str, index+1, mapping); // 递归深入, 到下一层digits[index + 1]中去，检测下一个数字对应的几种字符
            str.pop_back();         // 回溯， 但是string类型没有减法, 不能str -= mapping[num][i]
        }

    }

    vector<string> letterCombinations(string digits) {
        // 限定条件0 <= digits.length <= 4；  digits[i] 是范围 ['2', '9'] 的一个数字。

        // 先搞清楚映射关系
        // 对于数字num (2 <= num <= 9), 能映射到的有3种字符， 8也是映射3种
        // 但是7和9分别能映射4种字母？这怎么处理？
        // 还是我们直接列出来吧
        unordered_map<int, string> mapping = {
            {0, ""},
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        vector<string> result;
        if(digits.size() == 0) return result;
        string str;
        recursion(result, digits, str, 0, mapping);
        return result;
    }
};
```




#### 代码随想录

##### 思路

>
> <font color="yellow">
> 
> 从示例上来说，输入"`23`"，最直接的想法就是两层`for`循环遍历了吧，正好把组合的情况都输出了。
>
> 如果输入"`233`"呢，那么就三层`for`循环，如果"`2333`"呢，就四层`for`循环.......
> 
> 大家应该感觉出和77.组合 (`_1_combinations.md`)遇到的一样的问题，就是这`for`循环的层数如何写出来，此时又是回溯法登场的时候了。
>
> 理解本题后，要解决如下三个问题：
>
> 1. 数字和字母如何映射
> 2. 两个字母就两个for循环，三个字符我就三个for循环，以此类推，然后发现代码根本写不出来
> 2. 输入`1` `*` `#`按键等等异常情况
>
> </font>
> 


##### 数字和字母如何映射

>
> 可以使用`map`或者定义一个二维数组，例如：`string letterMap[10]`，来做映射，我这里定义一个二维数组，代码如下：
>
> ```c++
> const string letterMap[10] = {
>     "",     // 0
>     "",     // 1
>     "abc",  // 2
>     "def",  // 3
>     "ghi",  // 4
>     "jkl",  // 5
>     "mno",  // 6
>     "pqrs", // 7
>     "tuv",  // 8
>     "wxyz"  // 9
> };
> ```
> 
> ```c++
> unordered_map<int, string> letterMap = {
>     {0, ""},
>     {1, ""},
>     {2, "abc"},
>     {3, "def"},
>     {4, "ghi"},
>     {5, "jkl"},
>     {6, "mno"},
>     {7, "pqrs"},
>     {8, "tuv"},
>     {9, "wxyz"}
> };
> ```




##### 回溯法来解决n个for循环的问题

>
> 对于回溯法还不了解的同学看这篇：关于回溯算法，你该了解这些！(`backtracking_algorithms.md`)
>
> 例如：输入："`23`"，抽象为树形结构，如图所示：
> 
> <div align=center>
> <img src="./images/_3_letter_combinations_of_a_phone_number_2.png" style="zoom:100%"/>
> </div>
>
> 图中可以看出遍历的深度，就是输入"`23`"的长度，而叶子节点就是我们要收集的结果，输出`["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`。
>
> 
> 回溯三部曲：
> 
> * 确定回溯函数参数
>
> 首先需要一个字符串`s`来收集叶子节点的结果，然后用一个字符串数组`result`保存起来，这两个变量我依然定义为全局。
>
> 再来看参数，参数指定是有题目中给的`string digits`，然后还要有一个参数就是`int`型的`index`。
>
> 注意这个`index`可不是 77.组合 (`_1_combinations.md`)和216.组合总和III (`_2_combination_sum_iii.md`)中的`startIndex`了。
>
> 这个`index`是记录遍历第几个数字了，就是用来遍历`digits`的（题目中给出数字字符串），同时`index`也表示树的深度。
>
> 代码如下：
>
> ```c++
> vector<string> result;
> string s;
> void backtracking(const string& digits, int index)
> ```
> 
> * 确定终止条件
>
> 例如输入用例"`23`"，两个数字，那么根节点往下递归两层就可以了，叶子节点就是要收集的结果集。
>
> 那么终止条件就是如果`index` 等于 输入的数字个数（`digits.size`）了（本来`index`就是用来遍历`digits`的）。
>
> 然后收集结果，结束本层递归。
> 
> 代码如下：
>
> ```c++
> if (index == digits.size()) {
>     result.push_back(s);
>     return;
> }
> ```
> 
> * 确定单层遍历逻辑
> 
> 首先要取`index`指向的数字，并找到对应的字符集（手机键盘的字符集）。
> 
> 然后`for`循环来处理这个字符集，代码如下：
>
> ```c++
> int digit = digits[index] - '0';        // 将index指向的数字转为int
> string letters = letterMap[digit];      // 取数字对应的字符集
> for (int i = 0; i < letters.size(); i++) {
>     s.push_back(letters[i]);            // 处理
>     backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
>     s.pop_back();                       // 回溯
> }
> ```
>
> <font color="gree">
> 
> 注意这里`for`循环，可不像是在回溯算法：求组合问题！ (`_1_combinations.md`)和回溯算法：求组合总和！ (`_2_combination_sum_iii.md`)中从`startIndex`开始遍历的。
> 
> 因为本题每一个数字代表的是不同集合，也就是**求不同集合之间的组合**，而77. 组合 (`_1_combinations.md`)和216.组合总和III (`_2_combination_sum_iii.md`)都是**求同一个集合中的组合！**
>
> </font>
> 
> 注意：输入`1 * #`按键等等异常情况
> 
> 代码中最好考虑这些异常情况，但题目的测试数据中应该没有异常情况的数据，所以我就没有加了。
>
> **但是要知道会有这些异常，如果是现场面试中，一定要考虑到！**
>
> 
> 


##### C++代码

>
> ```c++
> // 版本一
> class Solution {
> private:
>     const string letterMap[10] = {
>         "", // 0
>         "", // 1
>         "abc", // 2
>         "def", // 3
>         "ghi", // 4
>         "jkl", // 5
>         "mno", // 6
>         "pqrs", // 7
>         "tuv", // 8
>         "wxyz", // 9
>     };
> public:
>     vector<string> result;
>     string s;
>     void backtracking(const string& digits, int index) {
>         if (index == digits.size()) {
>             result.push_back(s);
>             return;
>         }
>         int digit = digits[index] - '0';        // 将index指向的数字转为int
>         string letters = letterMap[digit];      // 取数字对应的字符集
>         for (int i = 0; i < letters.size(); i++) {
>             s.push_back(letters[i]);            // 处理
>             backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
>             s.pop_back();                       // 回溯
>         }
>     }
>     vector<string> letterCombinations(string digits) {
>         s.clear();
>         result.clear();
>         if (digits.size() == 0) {
>             return result;
>         }
>         backtracking(digits, 0);
>         return result;
>     }
> };
> ```
> 
> * 时间复杂度: `O(3^m * 4^n)`，其中 `m` 是对应四个字母的数字个数，`n` 是对应三个字母的数字个数
> * 空间复杂度: `O(3^m * 4^n)`
>
> 一些写法，是把回溯的过程放在递归函数里了，例如如下代码，我可以写成这样：（注意注释中不一样的地方）
>
> ```c++
> // 版本二
> class Solution {
> private:
>         const string letterMap[10] = {
>             "", // 0
>             "", // 1
>             "abc", // 2
>             "def", // 3
>             "ghi", // 4
>             "jkl", // 5
>             "mno", // 6
>             "pqrs", // 7
>             "tuv", // 8
>             "wxyz", // 9
>         };
> public:
>     vector<string> result;
>     void getCombinations(const string& digits, int index, const string& s) { // 注意参数的不同
>         if (index == digits.size()) {
>             result.push_back(s);
>             return;
>         }
>         int digit = digits[index] - '0';
>         string letters = letterMap[digit];
>         for (int i = 0; i < letters.size(); i++) {
>             getCombinations(digits, index + 1, s + letters[i]);  // 注意这里的不同
>         }
>     }
>     vector<string> letterCombinations(string digits) {
>         result.clear();
>         if (digits.size() == 0) {
>             return result;
>         }
>         getCombinations(digits, 0, "");
>         return result;
> 
>     }
> };
> ```
>
> <font color="gree">
> 
> 我不建议把回溯藏在递归的参数里这种写法，很不直观，我在二叉树：以为使用了递归，其实还隐藏着回溯 (https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E9%80%92%E5%BD%92%E5%B8%A6%E7%9D%80%E5%9B%9E%E6%BA%AF.html)这篇文章中也深度分析了，回溯隐藏在了哪里。
>
> 所以大家可以按照版本一来写就可以了。
> 
> </font>
> 
> 




##### 总结

>
> 本篇将题目的三个要点一一列出，并重点强调了和前面讲解过的77. 组合 (`_1_combinations.md`)和216.组合总和III (`_2_combination_sum_iii.md`)的区别，本题是多个集合求组合，所以在回溯的搜索过程中，都有一些细节需要注意的。
>
> 






















