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


#### 我的解法  只通过 37 / 51 个测试用例，剩下的超出时间限制

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 计算窗口数量
        size_t windows_size = nums.size() - k + 1;
        vector<int> max(windows_size, 0); // 存储每个窗口的最大值，初始化为0. 其实动态数组vector不用设置长度，这里只是明确下

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
> 令`f'(k) = -2k+n+1 = 0`，即`k=(n+1)/2 `时为最大值
>
> `k=(n+1)/2 `代入`f(k)`中得`f(k=(n+1)/2) = (n+1)^2 / 4 `
>
> 即最坏情况是`O(n^2)`
> 
> 这个时间复杂度太高了，必须降低才行
>
> 
> 算法的时间复杂度必须优于 $O(n \log n)$ , n 是数组的大小。
> 


#### 优化方法一  通过47 / 51 个测试用例，剩下的超出时间限制
> 
> * 当`k=1`时，就是遍历n次，时间复杂度不高，不用担心。
> 
> * 当`k>1`时，**临近的两个窗口中必定有大量重合的元素。由于每次只向右移动一位，那么新的窗口中的只有最右边的元素是上一个窗口中没有的**
> > 例如
> > ```html
> > 滑动窗口的位置                最大值
> > ---------------               -----
> > [1  3  -1] -3  5  3  6  7       3
> >  1 [3  -1  -3] 5  3  6  7       3
> > ```
> 第二个窗口中，只有最右边的`-3`是之前没出现的，左边`windows_size-1`个元素，都是参与过第一个窗口遍历的
>
> 
> 
> 
> 我们现在只考虑`k>1`的情况下，如何操作？是否可以通过一些方法暂存其中的最大值，只需要与刚进来的那个元素比较。
>
> * 第一个窗口必然要先遍历所有窗口内元素，找出最大值
> 
> * 后续的窗口找最大值时，要利用好上一个窗口
> 
> * 如果上一个窗口中的最大值不是最左边元素，则移动到下一个窗口后，直接用上一个窗口的最大值与新窗口最右边元素比较即可。即只需要一次操作。
>
> * 如果上一个窗口中的最大值恰是最左边元素，则移动到下一个窗口后，要先遍历所有窗口内元素，找出最大值。
>
> 这样可以降低一些时间复杂度，但是依旧未能完美解决
>
> 

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 计算窗口数量
        size_t windows_size = nums.size() - k + 1;
        vector<int> max(windows_size, 0); // 存储每个窗口的最大值，初始化为0 其实动态数组vector不用设置长度，这里只是明确下
        vector<size_t> max_site(windows_size, 0); // 存储每个窗口的最大值对应的位置，初始化为0（数组第一个元素）

        // 如果上一个窗口中的最大值不是最左边元素，则移动到下一个窗口后，
                                       // 直接用上一个窗口的最大值与新窗口最右边元素比较即可。
        // 如果上一个窗口中的最大值就是最左边元素，则移动到下一个窗口后，
                                       // 要先遍历所有窗口内元素，找出最大值。

        bool max_is_left = true; // 标志位，置true保证第一个进入for循环时，进行遍历
                                 // 也保证当k=1时，总是进入if，而不是else

        int temp_max = nums[0];  // 暂存每一个窗口中的最大值

        for(size_t i=0; i < windows_size; i++) {  // i指的是每个窗口开始的位置
            // 上一个窗口中的最大值是最左边元素
            if (max_is_left) {
                int temp_max = nums[i];  // 最大值暂时定为新窗口的最左边元素
                for (size_t j=i+1; j < i+k; j++) {  // 从新窗口内的的左数第二个元素开始比较
                    if(nums[j] >= temp_max) {
                        // 如果后面有超过或等于最左边元素的，
                        temp_max = nums[j];   // 暂存临最大值
                        max_is_left = false;  
                        max_site[i] = j;  // 暂存临时最大值的位置
                    } 
                }
                max[i] = temp_max;
            }
            // 上一个窗口中的最大值不是最左边元素            
            else { 
                // 如果新窗口最右边元素nums[i+k-1] 大于或等于 上一个窗口的最大值max[i-1]
                if(nums[i+k-1] >= max[i-1]) {
                    max_is_left = false;
                    max[i] = nums[i+k-1];
                    max_site[i] = i+k-1;
                }
                // 如果新窗口最右边元素nums[i+k-1] 小于 上一个窗口的最大值max[i-1]
                else {
                    // 当前窗口和上一个窗口的最大值不变，最大值位置也不变
                    max[i] = max[i-1]; 
                    max_site[i] = max_site[i-1];
                    // 判断上一个窗口最大值的位置max_site[i-1]，是否是当前窗口的最左边（上一个窗口内左数第二），即是否为i？
                    if(max_site[i-1] == i) {
                        max_is_left = true;
                    }
                    else{
                        max_is_left = false;                     
                    }
                }
            }
        }

        return max;
    }
};
```


#### （Leetcode）优化方法二 优先队列法：使用`std::priority_queue` 可以自动排序

>
> https://leetcode.cn/problems/sliding-window-maximum/solutions/543426/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m/\
> 
> `priority_queue<pair<int, int>> pq;`
> 
> 先把前`k`个`pair(value, location)`加入优先级队列
>
> 然后存放这k个元素的最大值`result.push_back(pq.top().first)`
>
> 开始循环`for (size_t i = k; i < nums.size(); ++i) // 从第k+1个元素开始`  
>
> * 先检测上一轮中得到的优先级队列的最大值 `location（pq.top().second）` 是否位于当前窗口中 ， 当前窗口的最左边是`i-k+1`
> 
> > * 若（队首）的 `location（pq.top().second）`在当前窗口的左侧`< (i-k+1)`，则一直弹出队首`pq.pop()`直到满足`>= (i-k+1)`;然后将新的元素入队`pq.emplace(nums[i], i);` 
> > 
> > * 若（队首）的 `location（pq.top().second）`在当前窗口中`>= (i-k+1)`, 则直接将新的元素入队`pq.emplace(nums[i], i);`
> > 
> > 
>
> * 存放最大值`result.push_back(pq.top().first)`
>
> 循环结束
>
> 返回
> 

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 用于存放结果
        vector<int> result; 

        // 先把前k个pair(value, location)加入优先级队列
        priority_queue<pair<int, int>> pq;
        for(size_t i=0; i < k; i++){
            pq.emplace(nums[i], i);
        }
        // 然后存放这k个元素的最大值
        result.push_back(pq.top().first);

        for (size_t i = k; i < nums.size(); ++i) {// 从第k+1个元素开始
            if (pq.top().second < (i-k+1)) {
                while( !pq.empty() && pq.top().second < (i-k+1)) {
                    pq.pop();                    
                }
                pq.emplace(nums[i], i);
            }
            else { // pq.top().second >= (i-k+1)
                pq.emplace(nums[i], i);
            }
            // 存放最大值
            result.push_back(pq.top().first);
        }

        return result;
    }
};
```
> 其实这样，可以把代码简化为
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 用于存放结果
        vector<int> result; 

        // 先把前k个pair(value, location)加入优先级队列
        priority_queue<pair<int, int>> pq;
        for(size_t i=0; i < k; i++){
            pq.emplace(nums[i], i);
        }
        // 然后存放这k个元素的最大值
        result.push_back(pq.top().first);

        for (size_t i = k; i < nums.size(); ++i) {// 从第k+1个元素开始
            pq.emplace(nums[i], i);
            while( !pq.empty() && pq.top().second < (i-k+1)) {  // 这里
                    pq.pop();                    
            }
            // 存放最大值
            result.push_back(pq.top().first);
        }

        return result;
    }
};
```
> 这样我们的代码逻辑可以变为
>
> `priority_queue<pair<int, int>> pq;`
> 
> 先把前`k`个`pair(value, location)`加入优先级队列
>
> 然后存放这k个元素的最大值`result.push_back(pq.top().first)`
>
> 开始循环`for (size_t i = k; i < nums.size(); ++i) // 从第k+1个元素开始`  
>
> * 把一个新的元素放入优先队列中。此时堆顶的元素就是堆中所有元素的最大值。
> 
> * 然而这个最大值可能并不在滑动窗口中，在这种情况下，这个值在数组中的位置出现在滑动窗口左边界的左侧。因此，当我们后续继续向右移动窗口时，这个值就永远不可能出现在滑动窗口中了，我们可以将其永久地从优先队列中移除。
> 
> * 我们不断地移除堆顶的元素，直到其确实出现在滑动窗口中。此时，堆顶元素就是滑动窗口中的最大值。
> 



##### 比较stack、queue、deque、priority_queue

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


> <font color="green"> 优先级队列（priority_queue）的对外接口: </font> 
> ```c++
> #include<queue>
> priority_queue<int> pq;
> pq.push()      //1. 入队首元素（即堆顶元素），自动排序到对应位置
> pq.pop()       //2. 出队首元素（即堆顶元素）
> pq.size()      //3. 返回队列中元素个数，求队列的大小 ，
> pq.empty()     //4. 判断队列是否为空，如果队列为空则返回 true, 否则返回 false;
> pq.top()       //5. 返回优先级队列的队首元素（即堆顶元素）的引用
>
> pq.emplace(val)  //6. （构造并插入元素）功能与push()相同，只是多了调用构造函数的功能
> 
> std::priority_queue<int> pq1,pq2;
> pq1.swap(pq2);    //7. 交换内容，用x的内容交换容器适配器（* this）的内容，将一个优先级队列的内容与另一个相同类型（大小可以不同）的优先级队列进行交换。
> ```
>










#### 能使用stack、queue、deque完美解决吗？？？

> 根据上面的分析
>
> 以左侧为头部，右侧为尾部来看
> 
> 每次移动窗口一次，相当于头部出列`pop_front()`，尾部入列`push_back()`，是`queue`的特性，`stack`不行. 当然`deque`更是可以
> 
> <font color="yellow"> 但是怎么使用呢？无从下手啊 </font>
>
> https://leetcode.cn/problems/sliding-window-maximum/solutions/2183793/dan-diao-dui-lie-by-sanders-wang-vj9e/
>
> <font color="yellow"> leetcode的这个解法叫单调队列，代码随想录的解法也叫单调队列，但是方式不同 </font>
>
>
> <font color="yellow"> 看代码随想录 </font>
>


#### 代码随想录 单调队列法

> 这是使用单调队列的经典题目。
> 
> 难点是如何求一个区间里的最大值呢？ （这好像是废话），暴力一下不就得了。
> 
> 暴力方法，遍历一遍的过程中每次从窗口中再找到最大的数值，这样很明显是`O(n × k)`的算法。
> 
> 有的同学可能会想用一个大顶堆（优先级队列）来存放这个窗口里的k个数字，这样就可以知道最大的最大值是多少了， **但是问题是这个窗口是移动的，而大顶堆每次只能弹出最大值，我们无法移除其他数值，这样就造成大顶堆维护的不是滑动窗口里面的数值了。所以用大顶堆（优先级队列）需要解决这个问题才行，这里我们不采用优先级队列**。
>
> <font color="yellow"> 这里我们使用**自建单调队列** </font>
> 
> 此时我们需要一个队列，这个队列呢，放进去窗口里的元素，然后随着窗口的移动，队列也一进一出，每次移动之后，队列告诉我们里面的最大值是什么。
> 
> 这个队列应该长这个样子：
> 
> ```c++
> class MyQueue {
> public:
>     void pop(int value) {
>     }
>     void push(int value) {
>     }
>     int front() {
>         return que.front();
>     }
> };
> ```
> 
> 每次窗口移动的时候，调用`que.pop`(滑动窗口中移除元素的数值)，`que.push`(滑动窗口添加元素的数值)，然后`que.front()`就返回我们要的最大值。
> 
> 这么个队列香不香，要是有现成的这种数据结构是不是更香了！
> 
> 可惜了，没有！ **我们需要自己实现这么个队列**。
> 
> 然后再分析一下，队列里的元素一定是要排序的，而且要最大值放在出队口，要不然怎么通过`front()`知道最大值呢。
> 
> 但如果把窗口里的元素都放进队列里，窗口移动的时候，队列需要弹出元素。
> 
> 那么问题来了，已经排序之后的队列 怎么能把窗口要移除的元素（这个元素可不一定是最大值）弹出呢。
> 
> 大家此时应该陷入深思.....
> 
> **其实队列没有必要维护窗口里的所有元素，只需要维护有可能成为窗口里最大值的元素就可以了，同时保证队列里的元素数值是由大到小的**。
> 
> **那么这个维护元素单调递减的队列就叫做单调队列，即单调递减或单调递增的队列。C++中没有直接支持单调队列，需要我们自己来实现一个单调队列**
> 
> **不要以为实现的单调队列就是 对窗口里面的数进行排序，如果排序的话，那和优先级队列又有什么区别了呢**。
> 
> 来看一下单调队列如何维护队列里的元素。
> 
> 动画如下：
> 
> <div align=center>
> <img src="./images/sliding_window_maximum_1.gif" style="zoom:100%;"/>
> </div>
>
> 对于窗口里的元素`{2, 3, 5, 1 ,4}`，单调队列里只维护`{5, 4}` 就够了，保持单调队列里单调递减，此时队列出口元素就是窗口里最大元素。
>
> 此时大家应该怀疑单调队列里维护着`{5, 4}` 怎么配合窗口进行滑动呢？
> 
> 设计单调队列的时候，`pop`，和`push`操作要保持如下规则：
> 
> 1. `pop(value)`：如果窗口移除的元素`value`等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
> 2. `push(value)`：如果`push`的元素`value`大于入口元素的数值，那么就将队列入口的元素弹出，直到`push`元素的数值小于等于队列入口元素的数值为止
>
> 保持如上规则，每次窗口移动的时候，只要问`que.front()`就可以返回当前窗口的最大值。
> 
> 为了更直观的感受到单调队列的工作过程，以题目示例为例，输入: `nums = [1,3,-1,-3,5,3,6,7]`, 和 `k = 3`，动画如下： 
> 
> <div align=center>
> <img src="./images/sliding_window_maximum_2.gif" style="zoom:100%;"/>
> </div>
>
> 那么我们用什么数据结构来实现这个单调队列呢？
> 
> 使用`deque`最为合适
> 
> 基于刚刚说过的单调队列`pop`和`push`的规则，代码不难实现，如下：
>
> ```c++
> class MonoQueue { //单调队列（从大到小）
> protected:
>     deque<int> deq; // 使用deque来实现单调队列
>
> public:
>      MonoQueue(){}  // 构造函数
>      ~MonoQueue(){} // 析构函数
>      
>     // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
>     // 同时pop之前判断队列当前是否为空。
>     void pop(int value) {
>         if (!deq.empty() && value == deq.front()) {
>             deq.pop_front();
>         }
>     }
>
>     // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
>     // 这样就保持了队列里的数值是单调从大到小的了。
>     void push(int value) {
>         while (!deq.empty() && value > deq.back()) {
>             deq.pop_back();
>         }
>         deq.push_back(value);
>     }
>
>     // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
>     int front() {
>         return deq.front();
>     }
> };
> ```
> 
> 这样我们就用`deque`实现了一个单调队列，接下来解决滑动窗口最大值的问题就很简单了，直接看代码吧。
>
> ```c++
> class Solution {
> private:
>     class MonoQueue { //单调队列（从大到小）monotonous queue
>     protected:
>         deque<int> deq; // 使用deque来实现单调队列
>     public:
>         MonoQueue(){}  // 构造函数
>         ~MonoQueue(){} // 析构函数
>         // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
>         // 同时pop之前判断队列当前是否为空。
>         void pop(int value) {
>             if (!deq.empty() && value == deq.front()) {
>                 deq.pop_front();
>             }
>         }
>         // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
>         // 这样就保持了队列里的数值是单调从大到小的了。
>         void push(int value) {
>             while (!deq.empty() && value > deq.back()) {
>                 deq.pop_back();
>             }
>             deq.push_back(value);
> 
>         }
>         // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
>         int front() {
>             return deq.front();
>         }
>     };
> 
> public:
>     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
>         MonoQueue que;  // que本质上不是队列，而是类对象
>         vector<int> result;
>         for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
>             que.push(nums[i]);
>         }
> 
>         result.push_back(que.front()); // result 记录前k的元素的最大值que.front() 
>         // vector也有push_back函数
> 
>         for (int i = k; i < nums.size(); i++) {
>             que.pop(nums[i - k]); // 滑动窗口移除最前面元素
>             que.push(nums[i]);    // 滑动窗口前加入最后面的元素
>             result.push_back(que.front()); // 记录对应的最大值
>         }
>         return result;
>     }
> };
> ```
> 再来看一下时间复杂度，使用单调队列的时间复杂度是 `O(n)`。
> 
> 有的同学可能想了，在队列中`push`元素的过程中，还有`pop`操作呢，感觉不是纯粹的O(n)。
> 
> 其实，大家可以自己观察一下单调队列的实现，`nums` 中的每个元素最多也就被 `push_back` 和 `pop_back` 各一次，没有任何多余操作，所以整体的复杂度还是 `O(n)`。
>
> 详细计算的话，`k+(n-k+1)*2=2n-k+2` 是最坏情况, 当`k=1`时为最大值，`O(2n+1)`, 即`O(n)`
> 
> 空间复杂度因为我们定义一个辅助队列，所以是`O(k)`。
>

##### 扩展
> 大家貌似对单调队列 都有一些疑惑，首先要明确的是，**题解中单调队列里的`pop`和`push`接口，仅适用于本题**。**单调队列不是一成不变的**，而是**不同场景不同写法**，**总之要保证队列里单调递减或递增的原则**，所以叫做单调队列。 不要以为本题中的单调队列实现就是固定的写法哈。
> 
> 大家貌似对`deque`也有一些疑惑，C++中`deque`是`stack`和`queue`默认的底层实现容器（这个我们之前已经讲过啦），`deque`是可以两边扩展的，而且`deque`里元素并不是严格的连续分布的。
>
> 








##### leetcode 社区 有各种解法


> https://leetcode.cn/problems/sliding-window-maximum/solutions/2234962/shuang-zhi-zhen-shuang-duan-dui-lie-by-z-n8rl/
> 
> https://leetcode.cn/problems/sliding-window-maximum/solutions/5458/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-z/
> 
> https://leetcode.cn/problems/sliding-window-maximum/solutions/2253677/dan-diao-dui-lie-by-xue-mro-zhhu/
>































