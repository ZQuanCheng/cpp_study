# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

* 一个有非常简明例子的cpp网站：https://en.cppreference.com/w/
  <br> 例如，查看std::vector的assign的用法：https://en.cppreference.com/w/cpp/container/vector/assign
  <br> 三种方式通过一个例子完美解释了，还夹带lambda干货。

--------------------------------------------------------------------------------

```c++
// STL（标准模板库） 
#include <array>       // C++ array 容器
#include <vector>      // C++ vector 容器
#include <list>        // C++ list 容器
#include <stack>       // C++ stack 容器适配器
#include <queue>       // C++ queue 容器适配器  priority_queue 容器适配器
#include <deque>       // C++ deque 容器
#include <string>      // C++ string 容器
#include <map>         // C++ map 容器
#include <set>         // C++ set 容器

// 与STL 容器有关的头文件
// <algorithm>是标准模版库（STL）中最重要的头文件之一，提供了大量基于迭代器的非成员模板函数。
#include <algorithm>   // remove()、remove_if()、find_if()、sort、...
// https://blog.csdn.net/szplzx1314/article/details/120644640
```

--------------------------------------------------------------------------------

# STL container adapter 容器适配器

--------------------------------------------------------------------------------

## std::queue 队列 和 std::priority_queue 优先级队列

## _4_STL_queue.md 

--------------------------------------------------------------------------------

#### 队列（std::queue）的对外接口
> <font color="green"> 队列（queue）的对外接口: </font> 
>
> 函数原型
> ```c++
> void push(T)	
> void pop()
> int size()
> bool empty()
> T front()
> T back()
> void emplace()    // 在队列尾部添加一个新元素。这个新元素是通过构造函数的参数传递参数构建的。该成员函数有效地调用底层容器的成员函数emplace_back，并转发参数。
> void swap(queue& q)   // 将本容器中的元素与参数容器中的元素互换。
> ```
>
> 举例
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
> q.emplace(val)  //6. （构造并插入元素）在队列尾部添加一个新元素, 功能与push()相同。 std::deque::emplace_back()
> 
> std::stack<int> q1,q2;
> q1.swap(s2);    //7. 交换内容，用x的内容交换容器适配器（* this）的内容
> ```
> 
> 




#### 比较stack、queue、deque、priority_queue

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

--------------------------------------------------------------------------------




#### 优先级队列   std::priority_queue

> 
> `_6_sliding_window_maximum.md`
>
> https://blog.csdn.net/weixin_57761086/article/details/126802156
>
>
> 优先队列是一种容器适配器，采用了堆（`heap`, 本质上完全二叉树）这样的数据结构，保证了第一个元素总是整个优先队列中**最大的**(或**最小的**)元素。
> 
> 优先队列默认使用`vector`作为底层存储数据的容器，在`vector`上使用了堆算法将`vector`中的元素构造成堆的结构，所以其实我们就可以把它当作堆，**凡是需要用堆的位置，都可以考虑优先队列**。(所以需要先学习堆)
>
> 
> <font color="yellow"> 栈、队列、优先级的定义方式 </font>
> 
> ```c++
> stack<Type, Container> // (<数据类型，底层容器类型>） std::vector、std::list、std::deque
> queue<Type, Container> // (<数据类型，底层容器类型>） std::list、std::deque
> priority_queue<Type, Container, Compare> // (<数据类型，底层容器类型，比较方式类>）
> ``` 
>
>
> 什么是优先队列中元素的比较方式？
> 之前也提到了，优先队列其实就是堆，堆中元素都是有固定大小关系的。比如大堆：每个结点的值都不大于它的双亲结点，堆顶元素是最大的。堆中会存储各种各样的元素，所以它们的比较方式自然不会相同，**编译器中的比较方式类只能比较内置类型，所以自定义类的比较方式是需要用户自己给出的，并且需要手动填充到Compare 参数的位置**。
> 
>
> <font color="yellow"> 优先级队列`std::priority_queue`定义的举例 </font>
> 
> ```c++
> // container adapter 容器适配器
> #include <vector>  
> #include <queue>        
> // std::queue  队列, 有三种可选底层容器vector、list、deque
> // std::priority_queue  优先队列
> 
> std::queue<int> q;     
> // 默认以deque为底层容器
> 
> priority_queue<int> pq1; // 等价于priority_queue<int, vector<int>, less<int>> pq;
> // 默认以vector为底层容器；vector<int>是承载底层数据结构堆 （heap）的容器
> // 默认以less为比较方式，左边小于右边的时候返回true，此时优先队列就是大堆，所以优先队列默认就是大堆。
> 
> //大堆：每个结点的值都不大于它的双亲结点，堆顶元素是最大的。 又叫（大顶堆，大根堆）
> //小堆：每个结点的值都不小于它的双亲结点，堆顶元素是最小的。 
> 
> priority_queue<int,vector<int>,greater<int> > pq2;
> // less<int>表示数字大的优先级越大，greater<int>表示数字小的优先级越大。 
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

##### 1. 看看比较方式的具体显示

> <font color="yellow"> 1. 看看比较方式的具体显示 </font>
>
> ```c++
> #include <iostream>   
> using namespace std; 
> #include <vector>      // C++ vector 容器
> #include <queue>       // C++ queue 容器适配器  priority_queue 容器适配器
> #include <stack>       // C++ stack 容器适配器
> int main()
> {
>     cout << "input: 1, 3, -1, -3, 5, 3, 6, 7";
>     vector<int> nums = {1,3,-1,-3,5,3,6,7};  
>     cout << endl << endl; 
> 
>     // stack
>     cout << "stack<int> s: "; 
>     stack<int> s;
>     for(size_t i=0; i<nums.size(); i++){
>         s.push(nums[i]);
>     }
>     while(!s.empty()){
>         cout << s.top() << ", ";   
>         s.pop();
>     }
>     cout << endl << endl; 
> 
>     // queue
>     cout << "queue<int> q: "; 
>     queue<int> q;
>     for(size_t i=0; i<nums.size(); i++){
>         q.push(nums[i]);
>     }
>     while(!q.empty()){
>         cout << q.front() << ", "; 
>         q.pop();
>     }
>     cout << endl << endl;     
> 
>     // priority_queue  default
>     cout << "priority_queue<int> pq1: "; 
>     priority_queue<int> pq1; 
>     for(size_t i=0; i<nums.size(); i++){
>         pq1.push(nums[i]);
>     }
>     while(!pq1.empty()){
>         cout << pq1.top() << ", "; 
>         pq1.pop();
>     }
>     cout << endl << endl;     
> 
>     // priority_queue less
>     cout << "priority_queue<int, vector<int>, less<int>> pq2: ";     
>     priority_queue<int, vector<int>, less<int>> pq2;
>     for(size_t i=0; i<nums.size(); i++){
>         pq2.push(nums[i]);
>     }
>     while(!pq2.empty()){
>         cout << pq2.top() << ", "; 
>         pq2.pop();
>     }
>     cout << endl << endl;   
> 
>     // priority_queue greater
>     cout << "priority_queue<int, vector<int>, greater<int>> pq3: "; 
>     priority_queue<int, vector<int>, greater<int>> pq3;
>     for(size_t i=0; i<nums.size(); i++){
>         pq3.push(nums[i]);
>     }
>     while(!pq3.empty()){
>         cout << pq3.top() << ", "; 
>         pq3.pop();
>     }
>     cout << endl << endl;   
> 
>     cout << endl;
>     pause();
> 
>     return 0;
> }        
> ```
> 编译并运行，结果如下
> ```html
> input: 1, 3, -1, -3, 5, 3, 6, 7
> 
> stack<int> s: 7, 6, 3, 5, -3, -1, 3, 1, 
> 
> queue<int> q: 1, 3, -1, -3, 5, 3, 6, 7, 
> 
> priority_queue<int> pq1: 7, 6, 5, 3, 3, 1, -1, -3, 
> 
> priority_queue<int, vector<int>, less<int>> pq2: 7, 6, 5, 3, 3, 1, -1, -3, 
> 
> priority_queue<int, vector<int>, greater<int>> pq3: -3, -1, 1, 3, 3, 5, 6, 7, 
>     
> ```
>
> 插入元素后自动排序了
>

#####  2. 结合`pair`使用

> <font color="yellow"> 2. 结合`pair`使用</font>
>
> ```c++
> #include <iostream>   
> using namespace std; 
> #include <vector>      // C++ vector 容器
> #include <queue>       // C++ queue 容器适配器  priority_queue 容器适配器
> #include <stack>       // C++ stack 容器适配器
> int main()
> {
>     cout << "input: 1, 3, -1, -3, 5, 3, 6, 7";
>     vector<int> nums = {1,3,-1,-3,5,3,6,7};  
>     cout << endl << endl; 
> 
>     // priority_queue  default
>     cout << "priority_queue<int> pq1: "; 
>     priority_queue<int> pq1; 
>     for(size_t i=0; i<nums.size(); i++){
>         pq1.push(nums[i]);
>     }
>     while(!pq1.empty()){
>         cout << pq1.top() << ", "; 
>         pq1.pop();
>     }
>     cout << endl << endl;     
> 
>     // pq1.emplace(0);
>     for(size_t i=0; i<nums.size(); i++){
>         pq1.push(nums[i]);
>     }
>     pq1.emplace(0);
>     cout << "After pq1.emplace(0): "; 
>     while(!pq1.empty()){
>         cout << pq1.top() << ", "; 
>         pq1.pop();
>     }
>     cout << endl << endl;        
> 
> 
>     // priority_queue  pair
>     cout << "priority_queue<pair<int, int>> pq2: "; 
>     priority_queue<pair<int, int>> pq2; 
>     for(size_t i=0; i<nums.size(); i++){
>         pq2.emplace(nums[i], i);
>     }
>     while(!pq2.empty()){
>         cout << pq2.top().first << "(i[" << pq2.top().second << "])" << ", "; 
>         pq2.pop();
>     }
>     cout << endl << endl;     
> 
>     // pq2.emplace(16, 8);
>     for(size_t i=0; i<nums.size(); i++){
>         pq2.emplace(nums[i], i);
>     }
>     pq2.emplace(16, 8);
>     cout << "After pq2.emplace(16, 8): "; 
>     while(!pq2.empty()){
>         cout << pq2.top().first << "(i[" << pq2.top().second << "])" << ", "; 
>         pq2.pop();
>     }
>     cout << endl << endl;        
> 
> 
> 
>     cout << endl;
>     pause();
> 
>     return 0;
> }        
> ```
> 
> 编译并运行，结果如下
> ```html
> input: 1, 3, -1, -3, 5, 3, 6, 7
> 
> priority_queue<int> pq1: 7, 6, 5, 3, 3, 1, -1, -3, 
> 
> After pq1.emplace(0): 7, 6, 5, 3, 3, 1, 0, -1, -3, 
> 
> priority_queue<pair<int, int>> pq2: 7(i[7]), 6(i[6]), 5(i[4]), 3(i[5]), 3(i[1]), 1(i[0]), -1(i[2]), -3(i[3]), 
> 
> After pq2.emplace(16, 8): 16(i[8]), 7(i[7]), 6(i[6]), 5(i[4]), 3(i[5]), 3(i[1]), 1(i[0]), -1(i[2]), -3(i[3]), 
> ```
>
>

#####  3. 自定义比较类

> <font color="yellow"> 3. 自定义比较类 </font>
>
> https://blog.csdn.net/Strengthennn/article/details/119078911
> 
> <font color="yellow"> 需要注意的是：使用仿函数对优先队列进行自定义排序，需要在声明priority_queue对象时显式地定义Container类型和Compare类型，即: </font>
> ```c++
> priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que
> // priority_queue<pair<int,int>> pri_que;
> ```
> <font color="yellow"> 比较类的定义方式如下（返回true时，前后交换位置）</font>
> 
> ```c++
> // 返回true时，front的优先级低于back的优先级。即返回true时，交换位置，front排在back的后面)
> class Cmp {
> public:
>     bool operator()(const pair<string, int>& front, const pair<string, int>& back) {
>         return front.second > back.second; // 如果想要得到int递增序列（top最小） 
>         return front.second < back.second; // 如果想要得到int递减序列（top最大）      
>         // priority_queue自定义函数的比较与sort正好是相反的
>         // 也就是说，如果你是把大于号作为第一关键字的比较方式，那么堆顶的元素就是第一关键字最小的
>    }
> };
> 
> // 大顶堆，top最大
> class top_max {
> public:
>     bool operator()(const pair<string, int>& front, const pair<string, int>& back) {
>         return front.second < back.second; // top最大     
>         // 返回true时，交换位置，front排在back的后面
>         // 这里是按照递减序列排序（top最大）
>    }
> };
> 
> // 大小顶堆，top最小
> class top_min {
> public:
>     bool operator()(const pair<string, int>& front, const pair<string, int>& back) {
>         return front.second > back.second; // top最小
>         // 返回true时，交换位置，front排在back的后面
>         // 这里是按照递增序列排序（top最小）
>    }
> };
> ```
> <font color="yellow"> 例子如下</font>
> ```c++
> #include<queue>
> #include<vector>
> #include<string>
> 
> // 返回true时，交换位置，front排在back的后面
> class top_max {
> public:
>     bool operator()(const pair<string, int>& front, const pair<string, int>& back) {
>         return front.second < back.second; // top最小
>         // return front.second > back.second; // top最大
> 
>         // 返回true时，交换位置，front排在back的后面
>         // 这里是按照递减序列排序（top最大）
>    }
> };
> 
> int main()
> {
>     priority_queue<pair<string, int>, vector<pair<string, int>>, top_max> pri_que;
>
>     vector<string> name = {"wang", "zhang", "liu", "li", "zhao", "zhou"};
>     vector<int> grade = {78, 69, 97, 85, 100, 92};
> 
>     for(size_t i=0; i < name.size(); i++){
>         pri_que.emplace(name[i], grade[i]); // 不能是push
>     }
>     
>     while(!pri_que.empty()){
>         cout << "name:" << pri_que.top().first << ", grade:" << pri_que.top().second << endl; 
>         pri_que.pop();
>     }
> 
>     cout << endl;
>     pause();
> 
>     return 0;
> }        
> ```
> 编译并运行，结果如下
> ```c++
> name:zhao, grade:100
> name:liu, grade:97
> name:zhou, grade:92
> name:li, grade:85
> name:wang, grade:78
> name:zhang, grade:69
> ```
>
> <font color="yellow"> 题目：见`_7_top_k_frequent_elements.md`代码随想录的解法</font>
>
> <font color="yellow"> 代码随想录的讨论：</font>
> > https://leetcode.cn/problems/top-k-frequent-elements/description/
> > 
> > 大家对这个比较运算在建堆时是如何应用的，为什么左大于右就会建立小顶堆，反而建立大顶堆比较困惑。
> > 
> > <font color="yellow"> 例如我们在写快排的`cmp`函数的时候，`return left>right` 就是从大到小，`return left<right` 就是从小到大。</font>
> > 
> > <font color="yellow"> 优先级队列的定义正好反过来了，可能和优先级队列的源码实现有关（我没有仔细研究），我估计是底层实现上优先队列队首指向后面，队尾指向最前面的缘故！</font>
> > 
> 


#### 优先级队列（std::priority_queue）的对外接口

> <font color="green"> 优先级队列（priority_queue）的对外接口: </font>
> 
> https://zhuanlan.zhihu.com/p/364408441
>
>
> 函数原型
> ```c++
> void push(T)	
> void pop()
> int size()
> bool empty()
> T top()
> void emplace()   //（构造并插入元素）功能与push()相同，只是多了调用构造函数的功能
> void swap(priority_queue& pq)   // 将本容器中的元素与参数容器中的元素互换。
> ```
>
> 举例
> 
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






#### 比较stack、queue、deque、priority_queue

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





















