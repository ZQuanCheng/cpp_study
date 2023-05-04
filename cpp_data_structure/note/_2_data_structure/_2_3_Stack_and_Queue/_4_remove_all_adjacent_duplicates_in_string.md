# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

--------------------------------------------------------------------------------

# 栈与队列

--------------------------------------------------------------------------------

## 栈与队列理论基础

## Stack_and_Queue.md
--------------------------------------------------------------------------------

## 删除字符串中的所有相邻重复项 remove all adjacent duplicates in strin

## _4_remove_all_adjacent_duplicates_in_string.md
--------------------------------------------------------------------------------

### 1047. 删除字符串中的所有相邻重复项

> Leetcode链接: https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/


> 给出由小写字母组成的字符串 `S`，**重复项删除操作**会选择两个相邻且相同的字母，并删除它们。
> 
> 在 `S` 上反复执行重复项删除操作，直到无法继续删除。
> 
> 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
> 
> **示例：**
> 
> ```html
> 输入：
> "abbaca"
> 
> 输出：
> "ca"
> 
> 解释：
> 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，
> 这是此时唯一可以执行删除操作的重复项。
> 之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，
> 所以最后的字符串为 "ca"。
> ```
> **提示：**
> * `1 <= S.length <= 20000`
> * `S` 仅由小写英文字母组成。
> 
> ```c++
> class Solution {
> public:
>     string removeDuplicates(string s) {
> 
>     }
> };
> ```
>


#### 我的解法 一个队列、一个栈、一个临时栈

> <font color="yellow"> 注意：不要对对空栈访问了栈顶元素`top()`，否则会报错`AddressSanitizer:DEADLYSIGNAL`, 或者`Segmentation fault (core dumped)` </font>

```c++
class Solution {
public:
    string removeDuplicates(string s) {
        // 用队列存储字符串s中的字符，保证顺序；用栈的话，顺序会反
        queue<char> que;  // 存储待处理的字符串
        for(decltype(s.size()) i=0; i < s.size(); i++) {
            que.push(s[i]);
        }

        // 使用标志位，当一次遍历中出现重复时，置true；否则保持false
        bool flag = true;
        stack<char> sta; // 栈
        stack<char> sta_temp; // 栈, 只用于改回顺序
     
        // 首先que保证不为空
        // 如果标志位为false，说明上一轮有重复项，还需要检查一遍, 直到flag为false 
        while ( (!que.empty()) && flag ) {   
            // 先置true, 后面发现相同就置false
            flag = false;

            // 先保证que不为空，若为空则说明处理完了
            while ( !que.empty() ) {
                // 如果sta为空，则把que的头部push进来
                if (sta.empty()) {   
                    sta.push(que.front());
                    que.pop();
                }
                // 当que和sta都不为空时，判断是否重复
                // 如果que的front和sta的top相同，则说明相邻且相同，将que的front弹出, sta的top也弹出（flag = true）
                else if ( que.front() == sta.top() ) { 
                    flag = true;
                    sta.pop();
                    que.pop();
                }
                // 如果que的front和temp的top不同，则说明相邻但不同，将que的front压入sta的top，然后弹出，
                else {
                    sta.push(que.front());
                    que.pop();
                }
            } 

            // 处理完后，倒腾回来，由于stack会改变顺序，需要先压入一个临时栈sta_temp，然后再压入que
            while ( !sta.empty() ) {
                sta_temp.push(sta.top());
                sta.pop();                
            }
            while ( !sta_temp.empty() ) {
                que.push(sta_temp.top());
                sta_temp.pop();                
            }
        }

        // 从que弹出来，创建string no_same_s;
        int n = que.size(); 
        string no_same_s(n, '0'); // 将 no_same_s 初始化为字符 ‘0’ 的 n 个副本
        for(int i=0; i < n; i++) {
            no_same_s[i] = que.front();
            que.pop();
        }

        s = no_same_s;

        return s;
    }
};
```
> <font color="yellow"> 用于实机测试并检查问题的程序 </font>
```c++
#include <iostream>   // #include <iostream.h>  已过时，现在反对把.h符号继续用在标准的头文件中
using namespace std;  
#include <string>   // string类
#include <queue>       // C++ queue 容器适配器
#include <stack>       // C++ stack 容器适配器
// #include <deque>       // C++ deque 容器
#include <cstdlib>    // 注： itoa()：将整型值转换为字符串。
                      // 注： atoi()：将字符串转换为整型值。
                      // 在windows系统下，用如下语句,控制台不会输出后马上消失。system("pause"); 
int main()
{
    string s = "abbaca";
    
    cout << "打印string s" << endl;
    cout << s << endl;

    // 用队列存储字符串s中的字符，保证顺序；用栈的话，顺序会反
    queue<char> que;  // 存储待处理的字符串
    for(decltype(s.size()) i=0; i < s.size(); i++) {
        que.push(s[i]);
    }
          
    char ch;
    cout << "打印初始que" << endl;
    for(decltype(que.size()) i=0; i < que.size(); i++) {
        ch = que.front();
        cout << ch << ", ";
        que.push(ch);
        que.pop();
    }
    cout << endl << endl;


    // 使用标志位，当一次遍历中出现重复时，置true；否则保持false
    bool flag = true;
    stack<char> sta; // 栈
    stack<char> sta_temp; // 栈, 只用于改回顺序
        
    
    cout << "打印每轮while循环处理后的que" << endl;

    // 首先que保证不为空
    // 如果标志位为false，说明上一轮有重复项，还需要检查一遍, 直到flag为false 
    while ( (!que.empty()) && flag ) {   
        // 先置true, 后面发现相同就置false
        flag = false;

        // 先保证que不为空，若为空则说明处理完了
        while ( !que.empty() ) {
            // 如果sta为空，则先把que的头部push进来
            if (sta.empty()) {   
                sta.push(que.front());
                que.pop();
            }
            // 当que和sta都不为空时，判断是否重复
            // 如果que的front和sta的top相同，则说明相邻且相同，将que的front弹出, sta的top也弹出（flag = true）
            else if ( que.front() == sta.top() ) { 
                flag = true;
                sta.pop();
                que.pop();
            }
            // 如果que的front和temp的top不同，则说明相邻但不同，将que的front压入sta的top，然后弹出，
            else {
                sta.push(que.front());
                que.pop();
            }
        } 

        // 处理完后，倒腾回来，由于stack会改变顺序，需要先压入一个临时栈sta_temp，然后再压入que
        while ( !sta.empty() ) {
            sta_temp.push(sta.top());
            sta.pop();                
        }
        while ( !sta_temp.empty() ) {
            que.push(sta_temp.top());
            sta_temp.pop();                
        }


        for(decltype(que.size()) i=0; i < que.size(); i++) {
            ch = que.front();
            cout << ch << ", ";
            que.push(ch);
            que.pop();
        }
        cout << endl;

    }
    cout << endl;

    // 从que弹出来，创建string no_same_s;
    int n = que.size(); 
    string no_same_s(n, '0'); // 将 no_same_s 初始化为字符 ‘0’ 的 n 个副本
    for(int i=0; i < n; i++) {
        no_same_s[i] = que.front();
        que.pop();
    }

    
    cout << "打印处理完成的string" << endl;
    cout << no_same_s << endl;

    
    cout << endl;
    pause(); 

    return 0;
}

```

> <font color="yellow"> 可优化的点：  </font>
> 
> 从队列出来，压入栈，还需要经过一个临时栈才能恢复队列顺序
>
> `std:queue`没法随机访问，我们把`string`转成`std:queue`处理，<font color="yellow"> 完全丢弃了`string`能够随机访问d 优点  </font>
> 
> <font color="yellow"> 省去队列，字符串直接一个个压入栈 </font>，同步处理
>
> <font color="yellow"> 不用`while`来回循环，不用`flags` </font>
>
> <font color="red"> 见如下代码 </font>


##### 我的解法优化 参考_3_valid_parentheses.md，只用一个栈

>
> 
```c++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sta;  
        for(decltype(s.size()) i=0; i < s.size(); i++) {
            if (sta.empty() || s[i] != sta.top()) {
                sta.push(s[i]);
            }
            else { // !sta.empty() && s[i] == sta.top()
                sta.pop();
            }
        }

        // 翻转顺序
        stack<char> sta_reverse; // 栈, 只用于改回顺序
        while ( !sta.empty() ) {
            sta_reverse.push(sta.top());
            sta.pop();                
        }

        // 从sta_sta_reverse弹出来，创建string no_same_s;
        int n = sta_reverse.size(); 
        string no_same_s(n, '0'); // 将 no_same_s 初始化为字符 ‘0’ 的 n 个副本
        for(int i=0; i < n; i++) {
            no_same_s[i] = sta_reverse.top();
            sta_reverse.pop();
        }
        
        s = no_same_s;

        return s;
    }
};
```
> <font color="yellow"> 可优化的点：  </font>
> 
> <font color="yellow"> 直接使用`reverse()`函数，不用自己手动恢复顺序 </font>
> 
> <font color="red"> 见如下代码 </font>
>

#####  我的解法优化 直接使用`reverse()`函数翻转字符串

```c++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sta;  
        for(decltype(s.size()) i=0; i < s.size(); i++) {
            if (sta.empty() || s[i] != sta.top()) {
                sta.push(s[i]);
            }
            else { // !sta.empty() && s[i] == sta.top()
                sta.pop();
            }
        }

        // 从sta弹出来，创建string no_same_s;
        int n = sta.size(); 
        string no_same_s(n, '0'); // 将 no_same_s 初始化为字符 ‘0’ 的 n 个副本
        for(int i=0; i < n; i++) {
            no_same_s[i] = sta.top();
            sta.pop();
        }
        
        // 翻转回来
        reverse (no_same_s.begin(), no_same_s.end());

        s = no_same_s;

        return s;
    }
};
```







#### 代码随想录 

> 本题要删除相邻相同元素，相对于20. 有效的括号 (opens new window)来说其实也是匹配问题，20. 有效的括号 是匹配左右括号，本题是匹配相邻元素，最后都是做消除的操作。
> 
> 本题也是用栈来解决的经典题目。
> 
> 那么栈里应该放的是什么元素呢？
> 
> 我们在删除相邻重复项的时候，其实就是要知道当前遍历的这个元素，我们在前一位是不是遍历过一样数值的元素，那么如何记录前面遍历过的元素呢？
> 
> 所以就是用栈来存放，那么栈的目的，就是存放遍历过的元素，当遍历当前的这个元素的时候，去栈里看一下我们是不是遍历过相同数值的相邻元素。
> 
> 然后再去做对应的消除操作。 如动画所示：
>
> <div align=center>
> <img src="./images/remove_all_adjacent_duplicates_in_string_1.gif" style="zoom:100%;"/>
> </div>
>
> 从栈中弹出剩余元素，此时是字符串ac，因为从栈里弹出的元素是倒序的，所以再对字符串进行反转一下，就得到了最终的结果。
>
> C++代码 :
>
> ```c++
> class Solution {
> public:
>     string removeDuplicates(string S) {
>         stack<char> st;
>         for (char s : S) {
>             if (st.empty() || s != st.top()) {
>                 st.push(s);
>             } else {
>                 st.pop(); // s 与 st.top()相等的情况
>             }
>         }
>         string result = "";
>         while (!st.empty()) { // 将栈中元素放到result字符串汇总
>             result += st.top();
>             st.pop();
>         }
>         reverse (result.begin(), result.end()); // 此时字符串需要反转一下
>         return result;
> 
>     }
> };
> ```
>
> 当然可以拿字符串直接作为栈，这样省去了栈还要转为字符串的操作。
> 
> 代码如下：
> 
> ```c++
> class Solution {
> public:
>     string removeDuplicates(string S) {
>         string result;
>         for(char s : S) {
>             if(result.empty() || result.back() != s) {
>                 result.push_back(s);
>             }
>             else {
>                 result.pop_back();
>             }
>         }
>         return result;
>     }
> };
> ```
> 



#### 如上面所示，字符串类型`string` 也有类似栈的操作

> `string::empty()`
> `string::back()`
> `string::push_back()`
> `string::pop_back()`
> 
> 等等有很多，可以看看这些用法
> 





#### 代码随想录 题外话

> 这道题目就像是我们玩过的游戏对对碰，如果相同的元素挨在一起就要消除。
> 
> 可能我们在玩游戏的时候感觉理所当然应该消除，但程序又怎么知道该如何消除呢，特别是消除之后又有新的元素可能挨在一起。
> 
> 此时游戏的后端逻辑就可以用一个栈来实现（我没有实际考察对对碰或者爱消除游戏的代码实现，仅从原理上进行推断）。
> 
> 游戏开发可能使用栈结构，编程语言的一些功能实现也会使用栈结构，实现函数递归调用就需要栈，但不是每种编程语言都支持递归，例如：
>
> **递归的实现就是：每一次递归调用都会把函数的局部变量、参数值和返回地址等压入调用栈中，然后递归返回的时候，从栈顶弹出上一次递归的各项参数，所以这就是递归为什么可以返回上一层位置的原因**。
>
> 相信大家应该遇到过一种错误就是栈溢出，系统输出的异常是`Segmentation fault`（当然不是所有的`Segmentation fault` 都是栈溢出导致的） ，如果你使用了递归，就要想一想是不是无限递归了，那么系统调用栈就会溢出。
>
> 而且**在企业项目开发中，尽量不要使用递归**！在项目比较大的时候，由于参数多，全局变量等等，使用递归很容易判断不充分`return`的条件，非常容易无限递归（或者递归层级过深），**造成栈溢出错误（这种问题还不好排查！）**
>
> 






