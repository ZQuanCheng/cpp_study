#include "triangle_class.h"



// --------------------------------------------------_Triangle---------------------------------------------------- 

// _Triangle缺省构造函数                                                                   // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
Triangle::Triangle():Shape(), ab(), tri(0)                                          // :Shape() 显式调用基类_Shape的缺省构造函数   :ab() 显式调用子对象ab的缺省构造函数
{
    // ab.aa = 0;        // 函数名后如果跟了子对象初始化表 ab(),就不用ab.aa = 0; ab.bb = 0; 因为本质一样.   
    // ab.bb = 0;
    // _tri = 0;         // 函数名后如果跟了数据成员初始化表_tri(0),就不用_tri = 0; 因为本质一样.    
    
    // 分配动态内存 单个
    // 指针变量, 一般用于分配动态内存
    // 如果类带有指针变量,并分配动态内存给 "一个数据类型所需的存储单元",则它必须有一个拷贝构造函数. 
    // 为单个变量 动态申请内存单元时,可以同时对该单元初始化
    ptr = NULL;  // 不分配动态内容 单个 
    // ptr = new int;   
    // ptr = 0;            // 可以直接ptr = new int(0)

    // 分配动态内存 数组, 但是这里其实就是单个
    // 如果类带有指针变量,并分配动态内存给 "一块连续的存储空间,即创建数组",则它必须有一个拷贝构造函数
    // 指针存放数组首地址
    // 为数组 动态申请内存单元时,不能对数组进行初始化
    size = 0;   // 不分配动态内容 数组
    buf = NULL; // 没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯    
    
    cout << "Triangle缺省构造函数" << endl;
}
// _Triangle带部分缺省参数值的构造函数                                                       // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
Triangle::Triangle(int a, int b, int c, int d, int e, int ptr_value, unsigned int n):Shape(a, b), ab(c, d), tri(e) // :_Shape(a, b) 显式调用基类_Shape的带部分缺省参数值的构造函数  :ab(c, d) 显式调用子对象ab的带部分缺省参数值的构造函数
{
    // ab.aa = c;        // 函数名后如果跟了子对象初始化表 ab(c, d),就不用ab.aa = c; ab.bb = d; 因为本质一样.   
    // ab.bb = d;
    // _tri = e;         // 函数名后如果跟了数据成员初始化表_tri(e),就不用_tri = e; 因为本质一样.    
    
    
    // 分配动态内存 单个
    // 指针变量, 一般用于分配动态内存
    // 如果类带有指针变量,并分配动态内存给 "一个数据类型所需的存储单元",则它必须有一个拷贝构造函数. 
    // 为单个变量 动态申请内存单元时,可以同时对该单元初始化
    ptr = new int;      
    *ptr = ptr_value;      // 可以直接ptr = new int(ptr_value)
   
    // 分配动态内存 数组
    // 如果类带有指针变量,并分配动态内存给 "一块连续的存储空间,即创建数组",则它必须有一个拷贝构造函数
    // 指针存放数组首地址
    // 为数组 动态申请内存单元时,不能对数组进行初始化
    if (n != 0)
    {
        size = n; 
        buf = new char[size];
        cout << "输入" << size-1 << "个字符:" << endl;
        for(unsigned int k =0; k < size-1; k++)
        {
            cin >> buf[k];  // buf[0]、buf[1]、buf[2]、... 、buf[size-2]、
        }
        buf[size-1] = '\0';  // buf[size-1]最后需要存储'\0'      
    }
    else
    {
        size = 0;   // 不分配动态内容 数组
        buf = NULL; // 没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯
    }
    
    cout << "Triangle带部分缺省参数值的构造函数" << endl;
}
// _Triangle拷贝构造函数                                                                   // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
Triangle::Triangle(const Triangle &obj):Shape(obj), ab(obj.ab), tri(obj.tri)     // :Shape(obj) 显式调用基类_Shape的拷贝构造函数    :ab(obj.ab) 显式调用子对象ab的带部分缺省参数值的构造函数
{
    // ab = obj.ab;        // 函数名后如果跟了子对象初始化表 ab(obj.ab),就不用ab = obj.ab; 因为本质一样.  
    // _tri = obj._tri;    // 函数名后如果跟了数据成员初始化表_tri(obj._tri),就不用_tri = obj._tri; 因为本质一样.  

    // 分配动态内存 单个
    // 指针变量, 一般用于分配动态内存
    // 如果类带有指针变量,并分配动态内存给 "一个数据类型所需的存储单元",则它必须有一个拷贝构造函数. 
    // 为单个变量 动态申请内存单元时,可以同时对该单元初始化
    if(obj.ptr != NULL)
    {
        ptr = new int;      
        *ptr = *obj.ptr;    // 可以直接ptr = new int(*obj.ptr)
    }
    else
    {
        ptr = NULL;   //如果obj的ptr是空指针,那么拷贝后也应该是空指针
    }
    
    // 分配动态内存 数组
    // 如果类带有指针变量,并分配动态内存给 "一块连续的存储空间,即创建数组",则它必须有一个拷贝构造函数
    // 指针存放数组首地址
    // 为数组 动态申请内存单元时,不能对数组进行初始化
    if (obj.size != 0)
    {
        size = obj.size; 
        buf  = new char[size];  
        for(unsigned int k =0; k < size-1; k++)
        {
            buf[k] = obj.buf[k];  // 拷贝值 // buf[0]、buf[1]、buf[2]、... 、buf[size-2]、
        }
        buf[size-1] = '\0';  // buf[size-1]最后需要存储'\0' 

    }
    else
    {
        size = 0;   // 不分配动态内容 数组
        buf = NULL; // 没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯
    }

    
    cout << "Triangle拷贝构造函数" << endl; 
} 
 
// _Triangle析构函数声明
Triangle::~Triangle()        
{
    delete ptr;    //释放内存单元 单个
    delete []buf;  //释放内存单元 数组

    cout << "Triangle析构函数" << endl; 
}

// (多态)虚函数,试验有无virtual关键词的区别
void Triangle::print_virtual()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    Shape::print_virtual();   
    ab.print();

    if(ptr != NULL)   
    {
        cout << setw(20) << " Triangle class: " << setw(20) << " _tri = " << tri << setw(20) <<  " *ptr = " << *ptr;
    }
    else   // 如果指针ptr = NULL, 就不能直接打印cout<< ptr; 否则运行时会报错Segmentation fault (core dumped)
    {
        cout << setw(20) << " Triangle class: " << setw(20) << " _tri = " << tri;
    }

    if (size != 0)
    {
        cout << setw(20) << " buf[" << size << "] = { " ;
        for(unsigned int k =0; k < size-1; k++)
        {
            cout << buf[k] << ", ";  // buf[0]、buf[1]、buf[2]、... 、buf[size-2]、
        } 
        cout << "\'\\0\' }";  // buf[size-1]最后存储'\0',无法直接显示. \' 打印单引号 \\打印斜线
    }
    else
    {
        cout << setw(20) << " buf[" << size << "] = { }" ;
    }
    cout << endl;
}
void Triangle::print()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    Shape::print();   
    ab.print();

    if(ptr != NULL)   
    {
        cout << setw(20) << " Triangle class: " << setw(20) << " _tri = " << tri << setw(20) <<  " *ptr = " << *ptr;
    }
    else   // 如果指针ptr = NULL, 就不能直接打印cout<< ptr; 否则运行时会报错Segmentation fault (core dumped)
    {
        cout << setw(20) << " Triangle class: " << setw(20) << " _tri = " << tri;
    }

    if (size != 0)
    {
        cout << setw(20) << " buf[" << size << "] = { " ;
        for(unsigned int k =0; k < size-1; k++)
        {
            cout << buf[k] << ", ";  // buf[0]、buf[1]、buf[2]、... 、buf[size-2]、
        } 
        cout << "\'\\0\' }";  // buf[size-1]最后存储'\0',无法直接显示. \' 打印单引号 \\打印斜线
    }
    else
    {
        cout << setw(20) << " buf[" << size << "] = { }" ;
    }
    cout << endl;
}


// 纯虚函数. 即基类中不对虚函数给出有意义的实现 // virtual int getArea() = 0;
// 如果基类_Shape中有至少一个纯虚函数,例如 getArea(), 则_Shape是抽象类. 
// 抽象类不能建立对象,但是可以说明抽象类的指针或引用,以便用这些指针和引用实现动态链接(多态性)
// 所以,要么所有函数都设置为纯虚函数,要么不要定义虚函数
// 补充:如果你基类是抽象类（有至少一个纯虚函数），但是派生类中没有对纯虚函数进行实现，那你的派生类也会成为抽象类，也不能定义对象。


int Triangle::getArea()
{
    int area = getWidth() * getHeight() / 2;
    cout << "Triangle class area :" << area << endl;

    return area;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------- 

