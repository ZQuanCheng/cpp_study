# C++11新特性 智能指针


>
> https://blog.csdn.net/qq_53268869/article/details/124551345
> 
> https://blog.csdn.net/qq_53268869/article/details/124539927?spm=1001.2014.3001.5501
> 






> 
> 1. <font color="yellow">什么是智能指针</font>
> 
> * 智能指针不是指针，是一个管理指针的类，用来存储指向动态分配对象的指针，负责自动释放动态分配的对象，防止堆内存泄漏。
> 
> * 动态分配的资源，交给一个类对象去管理，当类对象声明周期结束时，自动调用析构函数释放资源
>
> 







> 
> 2. <font color="yellow">智能指针发展历史</font>
>
> * C++ 98 中产生了第一个智能指针`auto_ptr`
>
> * C++boost给出了更加实用的 `scoped_ptr` 和 `shared_ptr` 和 `weak_ptr`
> 
> * <font color="gree">C++ 11 引入了 `unquie_ptr` 和 `shared_ptr` 和 `weak_ptr`</font> 。 需要注意的是，`unique_ptr`对应的是boost中的`scoped_ptr`。`并且这些智能指针的实现是参照boost中的实现的`。
>
> 
> 







> 
> 3. 为什么需要智能指针
>
> 如果一个类中有指针成员，会申请动态堆内存，如果在析构函数中忘记写了`delete`, 就可能造成内存泄漏
>
> 智能指针其作⽤是管理⼀个指针，避免程序员申请的空间在函数结束时忘记释放，造成内存泄漏这种情况滴发⽣
>
> 然后使⽤智能指针可以很⼤程度上的避免这个问题，因为智能指针就是⼀个类，当超出了类的
作⽤域是，类会⾃动调⽤析构函数，析构函数会⾃动释放资源。所以智能指针的作⽤原理就是
在函数结束时⾃动释放内存空间，不需要⼿动释放内存空间。
>
> 
> 
> 





> 
> `auto_ptr`：被抛弃了，有内存崩溃的风险，赋值运算的时候会出问题，资源所有权转移的时造成之前指针的不可用
>
> `unique_ptr`: 为了避免`auto_ptr`的问题，保证同⼀时间内只有⼀个智能指针可以指向该对
象。它对于避免资源泄露特别有⽤
> 
> 
> `shared_ptr`: 可以多个指针指向同一个对象，只要有一个指针指向，这块资源就不会被释放；
>
> 有引用计数的概念，计数为`0`时，才会释放该资源
> 
> 想一想，是不是跟之前深拷贝的作用一样，深拷贝是避免重复释放导致指针悬挂，智能指针是避免了内存泄漏？
> 
> 
> `weak_ptr`: 协助`shared_ptr`，防止出现死锁。
>
> 例如，两个 shared_ptr 相互引⽤, 类A中有指向B对象的指针，类B中有指向A对象的指针；无法释放两个类中的指针，那么这两个指针的引⽤计数永远不可能下降为0，也就是资源永远不会释放
> 
> `weak_ptr`的构造和析构不会引起引⽤记数的增加或减少
> 
> 当两个智能指针都是 `shared_ptr` 类型的时候，析构时两个资源引⽤计数会减⼀，但是两者引
⽤计数还是为 1，导致跳出函数时资源没有被释放（的析构函数没有被调⽤），解决办法：把
其中⼀个改为`weak_ptr`就可以
> 
> 







#### 夏铭珺给的参考代码

```c++
template <typename T>
class SharedPtr {
private:
    size_t* m_count;
    T* m_ptr;
public: 
    //构造函数
    SharedPtr() : m_ptr(nullptr), m_count(new size_t) {}
    SharedPtr(T* ptr) : m_ptr(ptr), m_count(new size_t) {*m_count = 1;}
    //析构函数
    ~SharedPtr() {
        --(*m_count);
        //判断是否要释放资源
        if (*m_count == 0) {
            delete m_ptr;
            delete m_count;
            m_ptr = nullptr;
            m_count = nullptr;
        }
    }
    //拷贝构造函数
    SharedPtr(const SharedPtr& ptr) {
        if (this != &ptr) {
            m_count = ptr.m_count;
            m_ptr = ptr.m_ptr;
            ++(*m_count);
        }
    }
    //拷贝赋值运算
    SharedPtr& operator=(const SharedPtr& ptr) {
        if (this->m_ptr == ptr.m_ptr) {
            return *this;
        }
        if (this->m_ptr) {
            if (--(*this->m_count) == 0) {
              delete this->m_ptr;
              delete this->m_count;
              this->m_ptr = nullptr;
              this->m_count = nullptr;
            }
        }
        this->m_ptr = ptr.m_ptr;
        this->m_count =ptr.m_count;
        *m_count++;
        return *this;
    }
    //移动构造函数
    SharedPtr(SharedPtr&& ptr) : m_count(ptr.m_count), m_ptr(ptr.m_ptr) {
        ptr->m_ptr =nullptr;
        ptr->m_count = nullptr;
    }
    //移动赋值运算符
    SharedPtr& operator=(SharedPtr&& ptr) {
        SharedPtr(ptr).swap(*this);
        return *this;
    }
    
    //解引用
    T& operator*() {return *m_ptr;}
    //箭头运算
    T* operator->() {return m_ptr;}
    //重载bool操作符
    operator bool() {return m_ptr == nullptr;}
    T* get() {return m_ptr;}
    size_t use_count() {return *m_count;}
    bool unique() {return *m_count == 1;}
    void swap(SharedPtr& ptr) {
        std::swap(this->m_ptr, ptr.m_ptr);
        std::swap(this->m_count, ptr.m_count):
   }
}
```






