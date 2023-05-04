# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

--------------------------------------------------------------------------------

# 栈与队列

--------------------------------------------------------------------------------

## 栈与队列理论基础

## Stack_and_Queue.md
--------------------------------------------------------------------------------

## 滑动窗口最大值 sliding window maximum

## _6_sliding_window_maximum.md
--------------------------------------------------------------------------------

### 239. 滑动窗口最大值

> Leetcode链接: https://leetcode.cn/problems/sliding-window-maximum/

> 给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。
> 
> 返回 滑动窗口中的最大值 。
>
> **示例1：**
> 
> ```html
> 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
> 输出：[3,3,5,5,6,7]
> 解释：
> 滑动窗口的位置                最大值
> ---------------               -----
> [1  3  -1] -3  5  3  6  7       3
>  1 [3  -1  -3] 5  3  6  7       3
>  1  3 [-1  -3  5] 3  6  7       5
>  1  3  -1 [-3  5  3] 6  7       5
>  1  3  -1  -3 [5  3  6] 7       6
>  1  3  -1  -3  5 [3  6  7]      7
> ```
> 
> **示例2：**
> 
> ```html
> 输入：nums = [1], k = 1
> 输出：[1]
> ```
> 
> **提示：**
> * `1 <= nums.length <= 105`
> * `-104 <= nums[i] <= 104`
> * `1 <= k <= nums.length`
>
> ```c++
> class Solution {
> public:
>     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
> 
>     }
> };
> ```
>


#### 我的解法  只通过 37 / 51 个测试用例，超出时间限制

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 遍历试试，不知道会不会超时
        size_t windows_size = nums.size() - k + 1;
        vector<int> max(windows_size, 0); // 存储每个窗口的最大值，初始化为0

        for(size_t i=0; i < windows_size; i++) {  // i指的是每个窗口开始的位置
            // 每个窗口内单独比较
            int temp_max = nums[i];
            for (size_t j=i; j < i+k; j++) {
                if(nums[j] > temp_max) {
                    temp_max = nums[j];
                } 
            }
            max[i] = temp_max;
        }

        return max;
    }
};
```

> 分析时间复杂度
> * `1 <= k <= nums.length`
> * 循环中运行语句个数为`(nums.length-k+1)*k`
>
> 函数`f(k) = (n-k+1)*k= -k^2 + (n+1)*k`, `n`为常量，`k`的取值范围为`1 <= k <= n`
> 
> 二次函数求导
> 
> 令`f'(k) = -2k+n+1 = 0`，即`k=(n+1)/2 `时为最大值，代入其中的
>
> `f(k=(n+1)/2) = (n+1)^2 / 4 `
>
> 即最坏情况是`O(n^2)`
> 
> 这个时间复杂度太高了，必须降低才行
>
> 
> 算法的时间复杂度必须优于 $O(n \log n)$ , n 是数组的大小。
> 




#### 代码随想录用了 双端队列 deque





#### leetcode 社区 也有很多人用双端队列 deque

https://leetcode.cn/problems/sliding-window-maximum/solutions/2234962/shuang-zhi-zhen-shuang-duan-dui-lie-by-z-n8rl/

https://leetcode.cn/problems/sliding-window-maximum/solutions/5458/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-z/

https://leetcode.cn/problems/sliding-window-maximum/solutions/2253677/dan-diao-dui-lie-by-xue-mro-zhhu/

#### 学习一下deque的常用操作，跟stack和queue比较一下

> <font color="green"> 栈（stack）的对外接口：</font>
> ```c++
> // 只能在栈顶(栈的尾部)进行插入和删除操作。
> #include<stack>
> stack<int> s;
> s.push();       //1. 入栈（压栈），栈顶(栈的尾部)插入元素。即 std::depue::push_back()
> s.pop();        //2. 出栈（弹栈），栈顶(栈的尾部)删除元素。即 std::depue::pop_back()
> s.size();       //3. 返回栈中元素个数，求栈的大小 ，
> s.empty();      //4. 判断栈是否为空，如果栈为空则返回 true, 否则返回 false;
> s.top();        //5. 返回栈顶(栈的尾部)元素的值
>                 //   如果堆栈容器为空，则会导致未定义的行为
>
> s.emplace(val)  //6. 在堆栈顶部添加一个新元素, 功能与push()相同。std::deque::emplace_back()
> 
> std::stack<int> s1,s2;
> s1.swap(s2);    //7. 交换内容，用x的内容交换容器适配器（* this）的内容
> ```
> 

> <font color="green"> 队列（queue）的对外接口: </font> 
> ```c++
> #include<queue>
> queue<int> q;
> q.push()      //1. 入队列，队尾插入元素。即 std::depue::push_back()
> q.pop()       //2. 出队列，队头删除元素。即 std::depue::pop_front()
> q.size()      //3. 返回队列中元素个数，求队列的大小 ，
> q.empty()     //4. 判断队列是否为空，如果队列为空则返回 true, 否则返回 false;
> q.front()     //5. 返回队头元素的引用
> q.back()      //6. 返回队尾元素的引用
>
> q.emplace(val)  //6. 在队列尾部添加一个新元素, 功能与push()相同。 std::deque::emplace_back()
> 
> std::stack<int> q1,q2;
> q1.swap(s2);    //7. 交换内容，用x的内容交换容器适配器（* this）的内容
> ```
> 

> <font color="green"> 双端队列（deque）的对外接口: </font>
> ```c++
> #include<deque>
> deque<int> d;
> d.push_front()     //1. 入队列，队头插入元素。
> d.push_back()      //2. 入队列，队尾插入元素。
> d.pop_front()      //3. 出队列，队头删除元素。
> d.pop_back()       //4. 出队列，队尾删除元素。 
> d.size()           //5. 返回队列中元素个数，求队列的大小 ，
> d.empty()          //6. 判断队列是否为空，如果队列为空则返回 true, 否则返回 false;
> d.front()          //7. 返回队头元素的引用
> d.back()           //8. 返回队尾元素的引用
>
> d.insert(iterator, value);  //9. 指定位置添加新元素
>
> d.emplace(iterator, value)  //10. 在队列中的某个位置添加一个新元素, 功能与insert()相同。
> d.emplace_front()  //11. 在队列头部添加一个新元素, 功能与push_front()相同。 
> d.emplace_back()   //12. 在队列尾部添加一个新元素, 功能与push_back()相同。 
> 
> std::deque<int> d1,d2;
> d1.swap(d2);    //13. 交换内容，用x的内容交换容器适配器（* this）的内容
> ```
>








