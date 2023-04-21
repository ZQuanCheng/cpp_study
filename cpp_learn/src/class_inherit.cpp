#include "class_inherit.h"

// --------------------------------------------------_Shape类---------------------------------------------------- 

// _Shape缺省构造函数
_Shape::_Shape():width(0), height(0)                                          // classname::classname():[数据成员初始化表]
{
    // width = 0;   // 函数名后如果跟了数据成员初始化表width(0),就不用width = 0; 因为本质一样.   
    // height = 0;   
    cout << "_Shape缺省构造函数" << endl;
}
// _Shape带部分缺省参数值的构造函数
_Shape::_Shape(int a, int b): width(a), height(b)                             // classname::classname():[数据成员初始化表]
{
    // width = a;  // 函数名后如果跟了数据成员初始化表width(a),就不用width = a; 因为本质一样.    
    // height = b;   
    cout << "_Shape带部分缺省参数值的构造函数" << endl;  
}
// _Shape拷贝构造函数
_Shape::_Shape(const _Shape &obj): width(obj.width), height(obj.height)       // classname::classname():[数据成员初始化表]
{

    // width = obj.width;    // 函数名后如果跟了数据成员初始化表width(obj.width),就不用width = obj.width; 因为本质一样.   
    // height = obj.height; 
    cout << "_Shape拷贝构造函数" << endl;
}
// _Shape虚析构函数声明
// 存在类继承的场合，基类的析构函数推荐使用虚函数。原因是防止内存泄漏
_Shape::~_Shape()
{
    cout << "_Shape虚析构函数virtual" << endl; 
}


void _Shape::setWidth(int w)
{
    width = w;
}
void _Shape::setHeight(int h)
{
    height = h;
}
int _Shape::getWidth()
{
    return width;
}
int _Shape::getHeight()
{
    return height;
}


// (多态)虚函数,试验有无virtual关键词的区别
void _Shape::print_virtual()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    cout << setw(20) << " _Shape class: " << setw(20) << " width = " << width << setw(20) << " height = " << height << endl;
}

void _Shape::print()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    cout << setw(20) << " _Shape class: " << setw(20) << " width = " << width << setw(20) << " height = " << height << endl;
}



// ------------------------------------------------------------------------------------------------------ 


// --------------------------------------------------_PaintCost类---------------------------------------------------- 


int _PaintCost::getCost(int area)
{
    return area * 70;
}


// ------------------------------------------------------------------------------------------------------ 


// --------------------------------------------------_AB类---------------------------------------------------- 


// _AB缺省构造函数
_AB::_AB():aa(0), bb(0)                                                        // classname::classname():[数据成员初始化表]
{
    // aa = 0;   // 函数名后如果跟了数据成员初始化表aa(0),就不用aa = 0; 因为本质一样.   
    // bb = 0;   
    cout << "_AB缺省构造函数" << endl;
}
// _AB带部分缺省参数值的构造函数
_AB::_AB(int i, int j):aa(i), bb(j)                                           // classname::classname():[数据成员初始化表]
{
    // aa = i;  // 函数名后如果跟了数据成员初始化表aa(i),就不用aa = i; 因为本质一样.    
    // bb = j;   
    cout << "_AB带部分缺省参数值的构造函数" << endl;  
}
// _AB拷贝构造函数
_AB::_AB(const _AB &obj): aa(obj.aa), bb(obj.bb)                                // classname::classname():[数据成员初始化表]
{

    // aa = obj.aa;    // 函数名后如果跟了数据成员初始化表aa(obj.aa),就不用aa = obj.aa; 因为本质一样.   
    // bb = obj.bb; 
    cout << "_AB拷贝构造函数" << endl;
}
// _AB析构函数声明
_AB::~_AB()
{
    cout << "_AB析构函数" << endl; 
}


void _AB::print()
{
    cout << setw(20) << " _AB: " << setw(20) << " aa = " << aa << setw(20) << " bb = " << bb <<  endl;
}

// ------------------------------------------------------------------------------------------------------ 


// --------------------------------------------------_Rectangle类---------------------------------------------------- 


// _Rectangle缺省构造函数                                                                   // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
_Rectangle::_Rectangle():_Shape(), ab(), _rec(0)                                          // :_Shape() 显式调用基类_Shape的缺省构造函数   :ab() 显式调用子对象ab的缺省构造函数
{
    // ab.aa = 0;        // 函数名后如果跟了子对象初始化表 ab(),就不用ab.aa = 0; ab.bb = 0; 因为本质一样.   
    // ab.bb = 0;
    // _rec = 0;         // 函数名后如果跟了数据成员初始化表_rec(0),就不用_rec = 0; 因为本质一样.    
    
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

    cout << "_Rectangle缺省构造函数" << endl;
}
// _Rectangle带部分缺省参数值的构造函数                                                       // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
_Rectangle::_Rectangle(int a, int b, int c, int d, int e, int ptr_value = 0, unsigned int n = 0):_Shape(a, b), ab(c, d), _rec(e) // :_Shape(a, b) 显式调用基类_Shape的带部分缺省参数值的构造函数  :ab(c, d) 显式调用子对象ab的带部分缺省参数值的构造函数
{
    // ab.aa = c;        // 函数名后如果跟了子对象初始化表 ab(c, d),就不用ab.aa = c; ab.bb = d; 因为本质一样.   
    // ab.bb = d;
    // _rec = e;         // 函数名后如果跟了数据成员初始化表_rec(e),就不用_rec = e; 因为本质一样.   


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

    cout << "_Rectangle带部分缺省参数值的构造函数" << endl;
}
// _Rectangle拷贝构造函数                                                                   // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
_Rectangle::_Rectangle(const _Rectangle &obj):_Shape(obj), ab(obj.ab), _rec(obj._rec)     // :_Shape(obj) 显式调用基类_Shape的拷贝构造函数    :ab(obj.ab) 显式调用子对象ab的带部分缺省参数值的构造函数
{
    // ab = obj.ab;        // 函数名后如果跟了子对象初始化表 ab(obj.ab),就不用ab = obj.ab; 因为本质一样.  
    // _rec = obj._rec;    // 函数名后如果跟了数据成员初始化表_rec(obj._rec),就不用_rec = obj._rec; 因为本质一样.  
    
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

  

    cout << "_Rectangle拷贝构造函数" << endl; 
} 

// _Rectangle析构函数声明
_Rectangle::~_Rectangle()        
{
    delete ptr;    //释放内存单元 单个
    delete []buf;  //释放内存单元 数组

    cout << "_Rectangle析构函数" << endl; 
}


// (多态)虚函数,试验有无virtual关键词的区别
void _Rectangle::print_virtual()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    _Shape::print_virtual();   
    ab.print();

    if(ptr != NULL)   
    {
        cout << setw(20) << " _Rectangle class: " << setw(20) << " _rec = " << _rec << setw(20) <<  " *ptr = " << *ptr;
    }
    else   // 如果指针ptr = NULL, 就不能直接打印cout<< ptr; 否则运行时会报错Segmentation fault (core dumped)
    {
        cout << setw(20) << " _Rectangle class: " << setw(20) << " _rec = " << _rec;
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
void _Rectangle::print()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    _Shape::print();  
    ab.print(); 

    if(ptr != NULL)
    {
        cout << setw(20) << " _Rectangle class: " << setw(20) << " _rec = " << _rec << setw(20) <<  " *ptr = " << *ptr;
    }
    else    // 如果指针ptr = NULL, 就不能直接打印cout<< ptr; 否则运行时会报错Segmentation fault (core dumped)
    {
        cout << setw(20) << " _Rectangle class: " << setw(20) << " _rec = " << _rec;
    }

    if (size != 0)
    {
        cout << setw(20) << " buf[" << size << "] = { " ;
        for(unsigned int k =0; k < size-1; k++)
        {
            cout << buf[k] << ", ";  // 拷贝值
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

int _Rectangle::getArea()
{
    int area = getWidth() * getHeight();
    cout << "_Rectangle class area :" << area << endl;

    return area;
}


// ----------------------------------------------------------------------------------------------------------------------------------------------------------- 



// --------------------------------------------------_Triangle类---------------------------------------------------- 

// _Triangle缺省构造函数                                                                   // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
_Triangle::_Triangle():_Shape(), ab(), _tri(0)                                          // :_Shape() 显式调用基类_Shape的缺省构造函数   :ab() 显式调用子对象ab的缺省构造函数
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
    
    cout << "_Triangle缺省构造函数" << endl;
}
// _Triangle带部分缺省参数值的构造函数                                                       // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
_Triangle::_Triangle(int a, int b, int c, int d, int e, int ptr_value = 0, unsigned int n = 0):_Shape(a, b), ab(c, d), _tri(e) // :_Shape(a, b) 显式调用基类_Shape的带部分缺省参数值的构造函数  :ab(c, d) 显式调用子对象ab的带部分缺省参数值的构造函数
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
    
    cout << "_Triangle带部分缺省参数值的构造函数" << endl;
}
// _Triangle拷贝构造函数                                                                   // classname::classname():[直接基类初始化表], [子对象初始化表], [数据成员初始化表]
_Triangle::_Triangle(const _Triangle &obj):_Shape(obj), ab(obj.ab), _tri(obj._tri)     // :_Shape(obj) 显式调用基类_Shape的拷贝构造函数    :ab(obj.ab) 显式调用子对象ab的带部分缺省参数值的构造函数
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

    
    cout << "_Triangle拷贝构造函数" << endl; 
} 
 
// _Triangle析构函数声明
_Triangle::~_Triangle()        
{
    delete ptr;    //释放内存单元 单个
    delete []buf;  //释放内存单元 数组

    cout << "_Triangle析构函数" << endl; 
}

// (多态)虚函数,试验有无virtual关键词的区别
void _Triangle::print_virtual()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    _Shape::print_virtual();   
    ab.print();

    if(ptr != NULL)   
    {
        cout << setw(20) << " _Triangle class: " << setw(20) << " _tri = " << _tri << setw(20) <<  " *ptr = " << *ptr;
    }
    else   // 如果指针ptr = NULL, 就不能直接打印cout<< ptr; 否则运行时会报错Segmentation fault (core dumped)
    {
        cout << setw(20) << " _Triangle class: " << setw(20) << " _tri = " << _tri;
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
void _Triangle::print()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    _Shape::print();   
    ab.print();

    if(ptr != NULL)   
    {
        cout << setw(20) << " _Triangle class: " << setw(20) << " _tri = " << _tri << setw(20) <<  " *ptr = " << *ptr;
    }
    else   // 如果指针ptr = NULL, 就不能直接打印cout<< ptr; 否则运行时会报错Segmentation fault (core dumped)
    {
        cout << setw(20) << " _Triangle class: " << setw(20) << " _tri = " << _tri;
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


int _Triangle::getArea()
{
    int area = getWidth() * getHeight() / 2;
    cout << "_Triangle class area :" << area << endl;

    return area;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------- 




// --------------------------------------通过基类指针或基类对象引用时,Virtual虚函数才有多态性, 才能实现动态链接---------------------------------------------------------------- 

// 重载函数：函数名和返回值类型可以相同，但是参数列表不能相同
// （多态）虚函数：继承中的概念。函数名、返回值类型、参数列表都相同，需要在声明时加Virtual关键字
// 每个子类（派生类）都有一个相同声明的函数的独立实现。这就是多态的一般使用方式。
// 对于Virtual虚函数，只是通过基类（父类）指针或基类（父类）引用时才有多态性。
// 如果没有基类（父类）指针，有无Virtual关键字，对于我们来说没有区别。

// (多态)虚函数,试验有无virtual关键词的区别
void _print_by_base_pointer_virtual(_Shape *p)
{
    p->print_virtual();
}
void _print_by_base_pointer(_Shape *p)
{
    p->print();
}



// ------------------------------------------------------------------------------------------------------ ----------------------------------------------------- 
