#### 深拷贝Deep Copy与浅拷贝Shallow Copy



>
> <font color="yellow"> 
> 
> 如果一个类的成员中有指针，特别是指针指向`new`分配的堆内存时，一定要注意使用深拷贝，见下面`Class A`
>
> 系统默认生成的拷贝构造函数，一般都是浅拷贝，见下面`Class B`
>
> 
> 如果没有在拷贝构造函数中进行一个个值的复制, 而是采用系统默认的拷贝构造函数的话，可能造成内存泄漏、指针悬挂
>
> </font> 
>
> 例如类`Class A 深拷贝; Class B 浅拷贝`
>
> ```c++
> // 深拷贝
> Class A {
> public:
>     A(int size):buf_size(size){
>         buf = new int[buf_size];
>     }
>     
>     A(const A &obj) {
>         buf_size = obj.buf_size;
> 
>         buf = new int[buf_size]; 
> 
>         for(int i=0; i < buf_size; i++) {
>             buf[i] = obj.buf[i];    // 一个个值拷贝过来，深拷贝
>         }
>     }
> 
>     ~A(){
>         delete buf[];
>     }
>     
> private:
>     unsigned int buf_size;
>     int *buf;
> }
> 
> ```
> 
> ```c++
> // 浅拷贝
> Class B {
> public:
>     B(int size):buf_size(size){
>         buf = new int[buf_size];
>     }
>     
>     B(const B &obj) {
>         buf_size = obj.buf_size; 
> 
>         buf = obj.buf; // 直接引用，如果我们不手动定义构造函数，编译器就会这样写
>     }
> 
>     ~B(){
>         delete buf[];
>     }
>  
> private:
>     unsigned int buf_size;
>     int *buf;
> }
> ```
> 
> `A、B使用相同的方式定义2个对象`
>
> ```c++
> int main() {
> A a1;
> A a2(a1); // 调用拷贝构造函数
> 
> B b1;
> B b2(b1); // 调用拷贝构造函数
> 
> ...
> }
> 
> 
> ```
>
> <font color="gree"> 
>
> 指针悬挂？详细描述一下
>
> `b1.buf`和`b2.buf`指向的的`堆内存`空间实际上是同一个
>
> 对于栈对象和全局对象，类似于入栈与出栈的顺序，`最后构造的对象最先被析构`。
> 
> 由于`b2`后创建，程序结束时`b2`先析构`delete buf[];`，那么`b1`中的`b1.buf`指向的`堆内存`就已经`释放`掉了, `b1.buf`指针悬挂；当`b1`析构函数被调用时，`elete buf[];`就回发生异常，因为该内存已经释放掉了，为什么还要释放？
> 
> </font> 
> 









