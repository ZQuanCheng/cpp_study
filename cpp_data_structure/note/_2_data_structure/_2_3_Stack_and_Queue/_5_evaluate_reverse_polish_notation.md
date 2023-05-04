# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

--------------------------------------------------------------------------------

# 栈与队列

--------------------------------------------------------------------------------

## 栈与队列理论基础

## Stack_and_Queue.md
--------------------------------------------------------------------------------

## 逆波兰表达式求值 evaluate reverse polish notation

## _5_evaluate_reverse_polish_notation.md
--------------------------------------------------------------------------------

### 150. 逆波兰表达式求值

> Leetcode链接: https://leetcode.cn/problems/evaluate-reverse-polish-notation/

>
> 给你一个字符串数组 `tokens` ，表示一个根据 逆波兰表示法 表示的算术表达式。
> 
> 请你计算该表达式。返回一个表示表达式值的整数。
> 
> **注意：**
> 
> * 有效的算符为 `'+'`、`'-'`、`'*'` 和 `'/'` 。
> * 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
> * 两个整数之间的除法总是 **向零截断** 。
> * 表达式中不含除零运算。
> * 输入是一个根据逆波兰表示法表示的算术表达式。
> * 答案及所有中间计算结果可以用 `32` 位 整数表示。
> 
> 
> **示例1：**
> 
> ```html
> 输入：tokens = ["2","1","+","3","*"]
> 输出：9
> 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
> ```
>
> **示例2：**
> 
> ```html
> 输入：tokens = ["4","13","5","/","+"]
> 输出：6
> 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
> ```
>
> **示例3：**
> 
> ```html
> 输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
> 输出：22
> 解释：该算式转化为常见的中缀算术表达式为：
>   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
> = ((10 * (6 / (12 * -11))) + 17) + 5
> = ((10 * (6 / -132)) + 17) + 5
> = ((10 * 0) + 17) + 5
> = (0 + 17) + 5
> = 17 + 5
> = 22
> ```
>
> **提示：**
> * `1 <= tokens.length <= 104`
> * `tokens[i]` 是一个算符（`"+"`、`"-"`、`"*"` 或 `"/"`），或是在范围 `[-200, 200]` 内的一个整数
>
> 
> **逆波兰表达式：**
> 
> 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
>
> * 平常使用的算式则是一种中缀表达式，如 `( 1 + 2 ) * ( 3 + 4 )` 。
> * 该算式的逆波兰表达式写法为 `( ( 1 2 + ) ( 3 4 + ) * )` 。
> 
> 逆波兰表达式主要有以下两个优点：
> 
> * 去掉括号后表达式无歧义，上式即便写成 `1 2 + 3 4 + *` 也可以依据次序计算出正确结果。
> * 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
>
> ```c++
> class Solution {
> public:
>     int evalRPN(vector<string>& tokens) {
> 
>     }
> };
> ```
>




#### 我的解法 

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string>::iterator it;
        int num1;
        int num2;
        int temp;
        stack<int> sta; 
        for (it = tokens.begin(); it !=tokens.end(); it++) {
            // 如果是运算符
            if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
                // 取出顶部两个数字
                num1 = sta.top();
                sta.pop();
                num2 = sta.top();
                sta.pop();    
                // 运算
                if (*it == "+") {                
                    temp = num2 + num1;
                }
                else if (*it == "-") {
                    temp = num2 - num1;    // 不能是 num1 - num2    
                }
                else if (*it == "*") {
                    temp = num2 * num1;                    
                }
                else {
                    temp = num2 / num1;    // 不能是 num1 / num2          
                }      
                // 结果压入栈
                sta.push(temp);          
            }
            // 如果是数字
            else { 
                // 先将string 转为 const char* 类型，即(*it).c_str()
                // 再使用atoi() 函数 将 const char* 类型 转换为 int类型
                temp = atoi((*it).c_str()); 
                // 压入栈
                sta.push(temp);
            }
        }
        temp = sta.top();
        sta.pop();
        return temp;
    }
};
```

> 实机测试

```c++
#include <iostream>   // #include <iostream.h>  已过时，现在反对把.h符号继续用在标准的头文件中
using namespace std;  
#include <string>     // string类
#include <vector>     // C++ vector 容器
#include <stack>      // C++ stack 容器适配器
// #include <deque>       // C++ deque 容器
#include <typeinfo>   // 查看变量类型 typeid(变量名).name()
#include <cstdlib>    // 注： itoa()：将整型值转换为字符串。
                      // 注： atoi()：将字符串转换为整型值。
                      // 在windows系统下，用如下语句,控制台不会输出后马上消失。system("pause"); 
int main()
{
    vector<string> tokens = {"4","13","5","/","+"};
        
    vector<string>::iterator it;
    int num1;
    int num2;
    int temp;
    stack<int> sta; 

    for (it = tokens.begin(); it !=tokens.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl << endl;

    for (it = tokens.begin(); it !=tokens.end(); it++) {
        // 如果是运算符
        if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
            // 取出顶部两个数字
            num1 = sta.top();
            sta.pop();
            num2 = sta.top();
            sta.pop();    
            // 运算
            if (*it == "+") {                
                temp = num2 + num1;
            }
            else if (*it == "-") {
                temp = num2 - num1;
            }
            else if (*it == "*") {
                temp = num2 * num1;                    
            }
            else {
                temp = num2 / num1;                    
            }      
            // 结果压入栈
            sta.push(temp);     
            cout << "遇到运算符: " << "num1 = " << num1 << ", num2 = " << num2 << ", result = " << temp << endl;     
        }
        // 如果是数字
        else { 
            // 先将string 转为 const char* 类型，即(*it).c_str()
            // 再使用atoi() 函数 将 const char* 类型 转换为 int类型
            // 注： itoa()：将整型值转换为字符串。
            // 注： atoi()：将字符串转换为整型值。
            temp = atoi((*it).c_str()); 
            // 压入栈
            sta.push(temp);
            cout << "新数字入栈: " << "temp =" << temp << ", typeid(temp).name()为" << typeid(temp).name() << ", 表示:int" << endl;
        }
    }
    cout << endl;

    temp = sta.top();
    sta.pop();

    cout << "result = " << temp << endl;   

    cout << endl;
    pause();
    return 0;
}
```

#### 简化，如果for、if、while等循环体、判断体中只有一句，就不用加{}，这样更简洁

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string>::iterator it;
        int num1, num2, temp;
        stack<int> sta; 
        for (it = tokens.begin(); it !=tokens.end(); it++) {
            // 如果是运算符
            if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
                // 取出顶部两个数字
                num1 = sta.top();
                sta.pop();
                num2 = sta.top();
                sta.pop();    
                // 运算, 结果压入栈
                if (*it == "+") sta.push(num2 + num1);
                else if (*it == "-") sta.push(num2 - num1); 
                else if (*it == "*") sta.push(num2 * num1); 
                else sta.push(num2 / num1); 
            }
            // 如果是数字
            else { 
                // 先将string 转为 const char* 类型，即(*it).c_str()
                // 再使用atoi() 函数 将 const char* 类型 转换为 int类型
                temp = atoi((*it).c_str()); 
                // 压入栈
                sta.push(temp);
            }
        }
        temp = sta.top();
        sta.pop();
        return temp;
    }
};
```


#### 代码随想录 


> 在上一篇文章中`1047.删除字符串中的所有相邻重复项` 提到了 递归就是用栈来实现的。
> 
> 所以**栈与递归之间在某种程度上是可以转换的**！ 这一点我们在后续讲解二叉树的时候，会更详细的讲解到。
> 
> 那么来看一下本题，**其实逆波兰表达式相当于是二叉树中的后序遍历**。 大家可以把运算符作为中间节点，按照后序遍历的规则画出一个二叉树。
> 
> <font color="yellow"> 但我们没有必要从二叉树的角度去解决这个问题，只要知道逆波兰表达式是用后序遍历的方式把二叉树序列化了，就可以了。 </font>
> 
> 在进一步看，本题中每一个子表达式要得出一个结果，然后拿这个结果再进行运算，那么**这岂不就是一个相邻字符串消除的过程，和`1047.删除字符串中的所有相邻重复项` 中的对对碰游戏是不是就非常像了**。
> 
> 
> <div align=center>
> <img src="./images/evaluate_reverse_polish_notation_1.gif" style="zoom:100%;"/>
> </div>
>
> 如动画所示
> 
> 相信看完动画大家应该知道，这和`1047. 删除字符串中的所有相邻重复项`是差不多的，只不过本题不要相邻元素做消除了，而是做运算！
>
> C++代码如下：
>
> ```c++
> class Solution {
> public:
>     int evalRPN(vector<string>& tokens) {
>         // 力扣修改了后台测试数据，需要用longlong
>         stack<long long> st; 
>         for (int i = 0; i < tokens.size(); i++) {
>             if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
>                 long long num1 = st.top();
>                 st.pop();
>                 long long num2 = st.top();
>                 st.pop();
>                 if (tokens[i] == "+") st.push(num2 + num1);
>                 if (tokens[i] == "-") st.push(num2 - num1);
>                 if (tokens[i] == "*") st.push(num2 * num1);
>                 if (tokens[i] == "/") st.push(num2 / num1);
>             } else {
>                 st.push(stoll(tokens[i]));
>             }
>         }
> 
>         int result = st.top();
>         st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
>         return result;
>     }
> };
> ```
>
> 

##### 题外话

>
> 我们习惯看到的表达式都是中缀表达式，因为符合我们的习惯，但是中缀表达式对于计算机来说就不是很友好了。
>
> 例如：`4 + 13 / 5`，这就是中缀表达式，计算机从左到右去扫描的话，扫到`13`，还要判断`13`后面是什么运算符，还要比较一下优先级，然后`13`还和后面的`5`做运算，做完运算之后，还要向前回退到 `4` 的位置，继续做加法，你说麻不麻烦！
>
> 那么将中缀表达式，转化为后缀表达式之后：`["4", "13", "5", "/", "+"]` ，就不一样了，计算机可以利用栈来顺序处理，不需要考虑优先级了。也不用回退了， 所以后缀表达式对计算机来说是非常友好的。
>
> 可以说本题不仅仅是一道好题，也展现出计算机的思考方式。
> 
> 在1970年代和1980年代，惠普在其所有台式和手持式计算器中都使用了`RPN`（后缀表达式），直到2020年代仍在某些模型中使用了`RPN`。
>
> 参考维基百科如下：
>
> > During the 1970s and 1980s, Hewlett-Packard used RPN in all of their desktop and hand-held calculators, and continued to use it in some models into the 2020s.
> 







