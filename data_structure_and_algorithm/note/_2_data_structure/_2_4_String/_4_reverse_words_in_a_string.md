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

## 反转字符串中的单词  reverse words in a string

## _4_reverse_words_in_a_string.md

--------------------------------------------------------------------------------

### 151. 反转字符串中的单词

> Leetcode链接: https://leetcode.cn/problems/reverse-words-in-a-string/

> 给你一个字符串 `s` ，请你反转字符串中 **单词** 的顺序。
> 
> **单词** 是由非空格字符组成的字符串。`s` 中使用至少一个空格将字符串中的 **单词** 分隔开。
> 
> 返回 **单词** 顺序颠倒且 **单词** 之间用单个空格连接的结果字符串。
> 
> **注意**：输入字符串 `s`中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
>
> 
> 
> **示例1：**
> 
> ```html
> 输入：s = "the sky is blue"
> 输出："blue is sky the"
> ```
>
> **示例2：**
> 
> ```html
> 输入：s = "  hello world  "
> 输出："world hello"
> 解释：反转后的字符串中不能存在前导空格和尾随空格。
> ```
>
>
> **示例3：**
> 
> ```html
> 输入：s = "a good   example"
> 输出："example good a"
> 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
> ```
>
> **提示：**
> * `1 <= s.length <= 104`
> * `s` 包含英文大小写字母、数字和空格 `' '`
> * `s` 中 **至少存在一个** 单词
>
> ```c++
> class Solution {
> public:
>     string reverseWords(string s) {
> 
>     }
> };
> ```
> 




#### 我的解法

```c++
class Solution {
public:
    string reverseWords(string s) {
        // ----------------------------------先拆分单词-------------------------------------
        // 因为需要反转单词顺序，所以用stack栈
        stack<string> chaifen;

        // 跳过前导空格
        int delete_front_space = 0;
        for(int i=0; i < s.size(); i++) {
            if(s[i] != ' ') {
                delete_front_space = i;   // 排除前导空格后的首字符下标
                break;
            } 
        }
        
        int left = delete_front_space;  // left标识单词开头, 初始化为跳过前导空格的第一个单词开头
        int right = -1;                 // right标识单词末尾, 初始化为-1（-1代表未发现单词末尾）

        // 从下标delete_front_space开始遍历
        for(int i=delete_front_space; i < s.size(); i++) {
            // 检查是否为单词开头， 这里多了i > 0的条件，是因为i=0时，s[i-1]非法，
            if(i > 0 && s[i] != ' ' && s[i-1] == ' ') left = i;
            // 检查是否为单词末尾(两种情况，1.下一个字符为空格  2.字符串最后一个字母)
            if(s[i] != ' ' && s[i+1] == ' ') right = i;
            if(s[i] != ' ' && i == s.size() - 1) right = i;

            // 如果发现单词末尾（right != -1）
            if(right != -1) {
                // string s(s1,pos,len) 将s1从下标pos开始拷贝，拷贝len个字符
                string temp(s, left, right - left + 1) ;
                // 存入stack<string> chaifen;
                chaifen.push(temp);
                // 将末尾标识重置为-1
                right = -1;
            } 
        }

        // ----------------------------------反向组合-------------------------------------
        string result;
        while(!chaifen.empty()) {
            result += chaifen.top();
            chaifen.pop();

            // 如果出栈后，栈不为空，说明后续还有单词，则添加空格给result
            if(!chaifen.empty()) {
                result += " "; // 单词用单个空格分隔开
            }
        }

        return result;
    }
};
```





#### 代码随想录

> 
> **这道题目可以说是综合考察了字符串的多种操作。**
>
> 一些同学会使用`split`库函数，分隔单词，然后定义一个新的`string`字符串，最后再把单词倒序相加，那么这道题题目就是一道水题了，失去了它的意义。
>
> 所以这里我还是提高一下本题的难度：**不要使用辅助空间，空间复杂度要求为`O(1)`**。
>
> 不能使用辅助空间之后，那么只能在原字符串上下功夫了。
>
> 想一下，我们将整个字符串都反转过来，那么单词的顺序指定是倒序了，只不过单词本身也倒序了，那么再把单词反转一下，单词不就正过来了。
>
> 所以解题思路如下：
> 
> * 移除多余空格
> * 将整个字符串反转
> * 将每个单词反转
>
> 举个例子，源字符串为：`"the sky is blue "`
>
> * 移除多余空格 : `"the sky is blue"`
> * 字符串反转：`"eulb si yks eht"`
> * 单词反转：`"blue is sky the"`
>
> 
> 这样我们就完成了翻转字符串里的单词。
> 
> 思路很明确了，我们说一说代码的实现细节，就拿移除多余空格来说，一些同学会上来写如下代码：
> 
> 
> ```c++
> void removeExtraSpaces(string& s) {
>     for (int i = s.size() - 1; i > 0; i--) {
>         if (s[i] == s[i - 1] && s[i] == ' ') {
>             s.erase(s.begin() + i);
>         }
>     }
>     // 删除字符串最后面的空格
>     if (s.size() > 0 && s[s.size() - 1] == ' ') {
>         s.erase(s.begin() + s.size() - 1);
>     }
>     // 删除字符串最前面的空格
>     if (s.size() > 0 && s[0] == ' ') {
>         s.erase(s.begin());
>     }
> }
> ```
> 
> 逻辑很简单，从前向后遍历，遇到空格了就`erase`。
> 
> 如果不仔细琢磨一下`erase`的时间复杂度，还以为以上的代码是`O(n)`的时间复杂度呢。
>
> 想一下真正的时间复杂度是多少，一个`erase`本来就是`O(n)`的操作。
> 
> `erase`操作上面还套了一个`for`循环，那么以上代码移除冗余空格的代码时间复杂度为`O(n^2)`。
> 
> 那么使用双指针法来去移除空格，最后`resize`（重新设置）一下字符串的大小，就可以做到`O(n)`的时间复杂度。
>
> ```c++
> //版本一 
> void removeExtraSpaces(string& s) {
>     int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
>     // 去掉字符串前面的空格
>     while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
>         fastIndex++;
>     }
>     for (; fastIndex < s.size(); fastIndex++) {
>         // 去掉字符串中间部分的冗余空格
>         if (fastIndex - 1 > 0
>                 && s[fastIndex - 1] == s[fastIndex]
>                 && s[fastIndex] == ' ') {
>             continue;
>         } else {
>             s[slowIndex++] = s[fastIndex];
>         }
>     }
>     // 前面已经去掉冗余空格，末尾最多剩一个空格, 且slowIndex已经是新字符串末尾的下一个位置
>     if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
>         s.resize(slowIndex - 1);
>     } else {
>         s.resize(slowIndex); // 重新设置字符串大小
>     }
> }
> ```
> 
> 有的同学可能发现用`erase`来移除空格，在`leetcode`上性能也还行。主要是以下几点；：
>
> 1. `leetcode`上的测试集里，字符串的长度不够长，如果足够长，性能差距会非常明显。
> 2. `leetcode`的测程序耗时不是很准确的。
>
> 版本一的代码是一般的思考过程，就是 先移除字符串前的空格，再移除中间的，再移除后面部分
>
> 不过其实还可以优化，这部分和27.移除元素 (`../_2_1_Array/_2_remove_element.md`)的逻辑是一样一样的，本题是移除空格，而 27.移除元素 就是移除元素。
> 
> 所以代码可以写的很精简，大家可以看 如下 代码 `removeExtraSpaces` 函数的实现：
>
> ```c++
> // 版本二 
> void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
>     int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
>     for (int i = 0; i < s.size(); ++i) { //
>         if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
>             if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
>             while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
>                 s[slow++] = s[i++];
>             }
>         }
>     }
>     s.resize(slow); //slow的大小即为去除多余空格后的大小。
> }
> ```
>
> 如果以上代码看不懂，建议先把 27.移除元素(`../_2_1_Array/_2_remove_element.md`)这道题目做了。
>
> 
> 此时我们已经实现了`removeExtraSpaces`函数来移除冗余空格。
>
> 还要实现反转字符串的功能，支持反转字符串子区间，这个实现我们分别在344.反转字符串 (`_1_reverse_string.md`)和541.反转字符串II (`_2_reverse_string_ii.md`)里已经讲过了。
>
> 代码如下：
>
> ```c++
> // 反转字符串s中左闭右闭的区间[start, end]
> void reverse(string& s, int start, int end) {
>     for (int i = start, j = end; i < j; i++, j--) {
>         swap(s[i], s[j]);
>     }
> }
> ```
> 
> 整体代码如下：
> 
> ```c++
> class Solution {
> public:
>     void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
>         for (int i = start, j = end; i < j; i++, j--) {
>             swap(s[i], s[j]);
>         }
>     }
> 
>     void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
>         int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
>         for (int i = 0; i < s.size(); ++i) { //
>             if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
>                 if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
>                 while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
>                     s[slow++] = s[i++];
>                 }
>             }
>         }
>         s.resize(slow); //slow的大小即为去除多余空格后的大小。
>     }
> 
>     string reverseWords(string s) {
>         removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
>         reverse(s, 0, s.size() - 1);
>         int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
>         for (int i = 0; i <= s.size(); ++i) {
>             if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
>                 reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
>                 start = i + 1; //更新下一个单词的开始下标start
>             }
>         }
>         return s;
>     }
> };
> ```
> 
> * 时间复杂度: `O(n)`
> * 空间复杂度: `O(1)` 或 `O(n)`，取决于语言中字符串是否可变
> 
> 
> 
> 















