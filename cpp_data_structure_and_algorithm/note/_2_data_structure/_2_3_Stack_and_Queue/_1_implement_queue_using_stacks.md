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

# 栈与队列

--------------------------------------------------------------------------------

## 用栈实现队列 implement queue using stacks

## _1_implement_queue_using_stacks.md

--------------------------------------------------------------------------------

### 232. 用栈实现队列

> Leetcode链接: https://leetcode.cn/problems/implement-queue-using-stacks/

> 请你仅使用<font color="yellow"> 两个栈 </font> 实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：
> 
> 实现 `MyQueue` 类：
> 
> * `void push(int x)` 将元素 `x` 推到队列的末尾
> * `int pop()` 从队列的开头移除并返回元素
> * `int peek()` 返回队列开头的元素
> * `boolean empty()` 如果队列为空，返回 `true` ；否则，返回 `false`
>
> **说明：**
> 
> * 你 **只能** 使用标准的栈操作 —— 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
> * 你所使用的语言也许不支持栈。你可以使用 `list` 或者 `deque`（双端队列）来模拟一个栈，只要是标准的栈操作即可。
>
> 
> **示例1：**
> 
> ```html
> 输入：
> ["MyQueue", "push", "push", "peek", "pop", "empty"]
> [[], [1], [2], [], [], []]
> 
> 输出：
> [null, null, null, 1, 1, false]
> 
> 解释：
> MyQueue myQueue = new MyQueue();
> myQueue.push(1); // queue is: [1]
> myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
> myQueue.peek(); // return 1
> myQueue.pop(); // return 1, queue is [2]
> myQueue.empty(); // return false
> ```
>
> **提示：**
> * `1 <= x <= 9`
> * 最多调用 `100` 次 `push`、`pop`、`peek` 和 `empty`
> * 假设所有操作都是有效的 （例如，一个空的队列不会调用 `pop` 或者 `peek` 操作）
>
> ```c++
> class MyQueue {
> public:
>     MyQueue() {
> 
>     }
>     
>     void push(int x) {
> 
>     }
>     
>     int pop() {
> 
>     }
>     
>     int peek() {
> 
>     }
>     
>     bool empty() {
> 
>     }
> };
> 
> /**
>  * Your MyQueue object will be instantiated and called as such:
>  * MyQueue* obj = new MyQueue();
>  * obj->push(x);
>  * int param_2 = obj->pop();
>  * int param_3 = obj->peek();
>  * bool param_4 = obj->empty();
>  */
> ```



#### （根据提示：两个栈）我的解法：一个栈存储现有队列元素，并负责输入；另一个负责输出时作为临时存储空间

```c++
class MyQueue {
protected:
    stack<int> Sta;   // 存储现有队列元素，并负责输入
    stack<int> Temp;  // 负责输出时作为临时存储空间

public:
    MyQueue() {

    }
    
    void push(int x) {
        Sta.push(x);
    }
    
    int pop() {
        // 将栈Sta的数据，弹出到临时栈Temp中
        while (!Sta.empty()) {        // 当栈不为空时
            Temp.push(Sta.top());     // 临时栈Temp 存储 栈Sta的 顶部待弹出元素
            Sta.pop();                // 栈Sta 弹出 
        }

        // 获取队列开头元素，  即获取临时栈Temp的顶部元素
        int result = Temp.top();    

        // 移除队列的开头元素, 即弹出临时栈Temp的顶部元素
        Temp.pop();

        // 将临时栈Temp的数据，弹回到栈Sta中，恢复顺序
        while (!Temp.empty()) {   
            Sta.push(Temp.top());     // 栈Sta 存储 临时栈Temp的 顶部待弹出元素
            Temp.pop();               // 临时栈Temp 弹出 
        }

        return result;  
    }
    
    int peek() {
        // 将栈Sta的数据，弹出到临时栈Temp中
        while (!Sta.empty()) {        // 当栈不为空时
            Temp.push(Sta.top());     // 临时栈Temp 存储 栈Sta的 顶部待弹出元素
            Sta.pop();                // 栈Sta 弹出 
        }

        // 获取队列开头元素，  即获取临时栈Temp的顶部元素
        int front = Temp.top();    

        // 将临时栈Temp的数据，弹回到栈Sta中，恢复顺序
        while (!Temp.empty()) {   
            Sta.push(Temp.top());     // 栈Sta 存储 临时栈Temp的 顶部待弹出元素
            Temp.pop();               // 临时栈Temp 弹出 
        }

        return front;  
    }
    
    bool empty() {
        return Sta.empty();
    }
};

```







#### 代码随想录 思路

> 这是一道模拟题，不涉及到具体算法，考察的就是对栈和队列的掌握程度。
> 
> 使用栈来模式队列的行为，如果仅仅用一个栈，是一定不行的，所以需要两个栈：**一个输入栈，一个输出栈**，这里要注意输入栈和输出栈的关系。
> 
> 下面动画模拟以下队列的执行过程：
>
> 执行语句：
> ```c++
> queue.push(1);
> queue.push(2);
> queue.pop(); 注意此时的输出栈的操作
> queue.push(3);
> queue.push(4);
> queue.pop();
> queue.pop();注意此时的输出栈的操作
> queue.pop();
> queue.empty();
> ```
>
> <div align=center>
> <img src="./images/implement_queue_using_stacks_1.gif" style="zoom:100%;"/>
> </div>
>
> 在`push`数据的时候，只要数据放进输入栈就好，**但在`pop`的时候，操作就复杂一些，输出栈如果为空，就把进栈数据全部导入进来（注意是全部导入）**，再从出栈弹出数据，如果输出栈不为空，则直接从出栈弹出数据就可以了。
> 
> 最后如何判断队列为空呢？**如果进栈和出栈都为空的话，说明模拟的队列为空了**。
> 
> 在代码实现的时候，会发现`pop()` 和 `peek()`两个函数功能类似，代码实现上也是类似的，可以思考一下如何把代码抽象一下。
> 
> C++代码如下：
> 
```c++
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};
```

> <font color="yellow"> 代码随想录的解法跟我的解法不同，这里的两个队列，连接组合起来才是队列  </font>
>
> <font color="yellow"> 我的解法中,Que栈存储的就是整个队列，Temp是中间转换顺序才使用</font>
>
> 
>
> 

#### 拓展
> <font color="yellow"> 可以看出代码随想录的解法中，`peek()`的实现，直接复用了`pop()`， 要不然，对`stOut`判空的逻辑又要重写一遍。  </font>
>
> <font color="yellow"> 但是我们的解法中，`peek()`的实现无法复用`pop()`  </font>
> 

> 再多说一些代码开发上的习惯问题，在工业级别代码开发中，最忌讳的就是 实现一个类似的函数，直接把代码粘过来改一改就完事了。
>
> 这样的项目代码会越来越乱，**一定要懂得复用，功能相近的函数要抽象出来，不要大量的复制粘贴，很容易出问题！（踩过坑的人自然懂）**
>
> 工作中如果发现某一个功能自己要经常用，同事们可能也会用到，自己就花点时间把这个功能抽象成一个好用的函数或者工具类，不仅自己方便，也方便了同事们。
>
> 同事们就会逐渐认可你的工作态度和工作能力，自己的口碑都是这么一点一点积累起来的！在同事圈里口碑起来了之后，你就发现自己走上了一个正循环，以后的升职加薪才少不了你！哈哈哈
>
> 



