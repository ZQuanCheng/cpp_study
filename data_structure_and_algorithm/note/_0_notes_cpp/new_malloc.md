# cpp_new_malloc


## new 和 malloc的区别

>
> https://blog.csdn.net/wzz953200463/article/details/103586435
>
> 
> <font color="yellow">
>
> 详述：
> 
> `malloc/free`是C++/C语言的标准`库函数`，`new/delete`是C++的`运算符`。它们`都可用于申请动态内存和释放内存。`
>
> 1. 是否需要指定内存块大小
> > 
> > * `new`分配内存无须指定内存块大小；
> > 
> > * `malloc`需要指定内存块大小 `void *malloc(int size);`
> > 
>
> 
> 2. 返回值类型不同
> > 
> > * `new`操作符内存分配成功时，返回的是对象类型的指针，类型严格与对象匹配，`无须进行类型转换`；
> > 
> > * `malloc`内存分配成功则是返回`void *` ，`需要通过强制类型转换`将`void*`指针转换成我们需要的类型。
> > 
>
> 
> 3. 对应的释放操作不同 
> > 
> > * `new` 对应 `delete`;
> > 
> > * `malloc` 对应 `free`；
> > 
> > 注意：`delete`释放数组时，要在指针名前加一个`[]`
>
> 
> 4. 能否初始化
> > 
> > * `new` 分配内存时可以初始化; 
> > 
> > * `malloc` 只管分配内存，并不能对所得的内存进行初始化，所以得到的一片新内存中，其值将是随机的。
> > 
> 
> 
> 5. 既然是分配内存，就可能分配失败，分配失败时的情况不同；
> > new内存分配失败时，会抛出bac_alloc异常，它不会返回NULL；
> > malloc分配内存失败时返回NULL。
>
> 
> 
> 6. 能否用于定义非内部数据类型的对象，为其申请动态内存
> > 
> > * 对于非内部数据类型的对象而言，`maloc/free`无法满足动态对象的要求。
> > 
> > * 对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。
> > 
> > * 由于`malloc/free`是库函数而不是运算符，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加于`malloc/free`。
> > 
> > <font color="green">我们不要企图用`malloc/free`来完成动态对象的内存管理，应该用`new/delete`。由于内部数据类型的“对象”没有构造与析构的过程，对它们而言`malloc/free`和`new/delete`是等价的。 </font>
> > 
>
> 7. 所在内存分区相同, 都是`栈（stack）`
> > 
> > https://blog.csdn.net/yanghonker/article/details/20000325
> >
> > * 在`C++`中，`内存分成4个区`，他们分别是`堆`、`栈`、`全局/静态存储区`和`常量存储区`。
> > 
> > * `栈（stack）`，就是那些由编译器在需要的时候分配，在不需要的时候自动清除的变量的存储区。里面的变量通常是`局部变量`、`函数参数`等。
> >
> > * `堆（heap）`，就是那些由`new`分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个`new`就要对应一个`delete`。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。由`malloc`等分配的内存块，`和new是十分相似的`，不过它是用`free`来结束自己的生命的。
> > 
> > * `全局/静态存储区(static)`，`全局变量`和`静态变量`被分配到同一块内存中，在以前的C语言中，全局变量又分为初始化的和未初始化的，在C++里面没有这个区分了，他们共同占用同一块内存区（未初始化的变量都被初始化成0或空串，C中也一样）。
> > 
> > * `常量存储区`，这是一块比较特殊的存储区，他们里面存放的是`常量`，不允许修改（当然，你要通过非正当手段也可以修改，而且方法很多）。`const`或者`#define`都可以定义常量
> 
> 
>
> </font>
>
> 
> ```c++
> int *p1 = new int(100); // 表示动态分配一个int变量，初始化为5
> 
> delete p1; // 释放空间
> 
> int *p2 =  (int *)malloc(sizeof(int)); // 表示动态分配一个int变量，初始化为5
> // sizeof(int) 为分配内存大小(字节数)
> // malloc 函数返回的是 void * 类型，需要强制类型转换(int *)malloc
> 
> free(p2); // 释放空间
>
>
> int *p3 = new int[100]; // 表示动态分配一个int数组，数组长度为5
> 
> delete []p3; // 释放空间
> 
>
> int *p4 =  (int *)malloc(5 * sizeof(int)); // 表示动态分配一个int数组，数组长度为5
> // 5 * sizeof(int) 为分配内存大小，字节数
>
> free(p4);  // 释放空间
> ```
> 
> 
> <font color="pink">
>
> 总结：
> 
> > 能用`new/delete`, 就不要用`malloc/free`; `特别是为类对象动态分配内存时`
>
> </font>
>
> 
> <font color="gree">
>
> 疑问：
> 
> > 既然n`ew/delete`的功能完全覆盖了`malloc/free`，为什么`C++`不把`malloc/free`淘汰出局呢？
> > 
> > 这是因为`C++`程序经常要调用`C函数`，而`C程序`只能用`malloc/free`管理动态内存。 
> 
> </font>
>
> 
> `除此之外，new可以更方便地定义多维数组`
>
> ```c++
> 一维: int *a = new int[100];    //开辟一个大小为100的整型数组空间
> 
> 二维: int **a = new int[5][6];    //开辟一个大小为30的二维整型数组空间
> 
> 三维及其以上:依此类推.
> ```
>
> 






















