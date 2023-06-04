# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

* 一个有非常简明例子的cpp网站：https://en.cppreference.com/w/
  <br> 例如，查看std::vector的assign的用法：https://en.cppreference.com/w/cpp/container/vector/assign
  <br> 三种方式通过一个例子完美解释了，还夹带lambda干货。

--------------------------------------------------------------------------------

```c++
// STL（标准模板库） 
#include <array>               // std::array                                    容器
#include <vector>              // std::vector                                   容器
#include <list>                // std::list                                     容器
#include <stack>               // std::stack                                    容器适配器
#include <queue>               // std::queue          std::priority_queue       容器适配器
#include <deque>               // std::deque                                    容器
#include <string>              // std::string                                   容器
#include <map>                 // std::map            std::multimap             容器   
#include <set>                 // std::set            std::multiset             容器
#include <unordered_map>       // std::unordered_map  std::unordered_multimap   容器
#include <unordered_set>       // std::unordered_set  std::unordered_multiset   容器

// 与STL 容器有关的头文件
// <algorithm>是标准模版库（STL）中最重要的头文件之一，提供了大量基于迭代器的非成员模板函数。
#include <algorithm>   // remove()、remove_if()、find_if()、sort、...
// https://blog.csdn.net/szplzx1314/article/details/120644640

#include <iterator> // next() prev() distance() advance()
```

--------------------------------------------------------------------------------

# STL container adapter 容器适配器

--------------------------------------------------------------------------------

## std::stack 栈

## _3_STL_stack.md

--------------------------------------------------------------------------------

#### 栈（std::stack）的对外接口
> <font color="green"> 栈（stack）的对外接口：</font>
>
> 函数原型
> ```c++
> void push(T)	
> void pop()
> int size()
> bool empty()
> T top()
> void emplace()    // 在堆栈顶部添加一个新元素。这个新元素是通过构造函数的参数传递参数构建的。该成员函数有效地调用底层容器的成员函数emplace_back，并转发参数。
> void swap(stack& s)   // 将本容器中的元素与参数容器中的元素互换。
> ```
>
> 举例
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
> `std::stack::emplace()` 和 `std::stack::push()`的区别
> ```c++
> stack::emplace()是stack::push()功能的扩展
> 
> stack::emplace()是C++11 才推出
> https://blog.csdn.net/u013271656/article/details/110493477
> 
> stack::push()  Insert element //插入元素
> stack::emplace()  Construct and insert element //构造并插入元素
> 
> stack::push()调用了底层容器deque的deque::push_back()
> stack::emplace()调用了底层容器deque的deque::emplace_back(), 其实deque::emplace_back()也是deque::push_back()实现的
> ```
> 
> 如何理解`emplace()`是构造并插入元素？
> https://blog.csdn.net/weixin_39564151/article/details/114020112
> ```c++
> //假设栈内的数据类型是data
> class data {
> private:
>    int a;
>    int b;
> public:
>    data(int x, int y):a(x), b(y) {}
> };
>
> 1. 直接传入对象(int, double 或者 构造好了的对象)
> 
> data d(1,2);
> S.push(d)  
> S.emplace(d); 都可以
> 
> 2. 在传入时候构造对象
> 
> S.push(data(1,2));
> S.emplce(data(1,2));
> 
> 3. emplace可以直接传入构造对象需要的元素，然后自己调用其构造函数！
>
> S.emplace(1,2)
> // S.push(1,2) 
> stack::emplace() 接受新对象的时候，自己会调用其构造函数生成对象然后放在容器内(比如这里传入了1，2，它则会自动调用一次data(1,2))
> stack::push()，只能让其构造函数构造好了对象之后，再使用复制构造函数！
> 相当于stack::emplace()直接把原料拿进家，造了一个。而stack::push()是造好了之后，再复制到自己家里，多了复制这一步。
> 所以emplace相对于push，使用第三种方法会更节省内存。
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
























