#include "box_class.h"



// 构造函数定义
// 缺省构造函数定义
Box::Box()
{
    cout << "缺省构造函数" << endl;
    length = 0.0;   // 长度
    breadth = 0.0;  // 宽度
    height = 0.0;   // 高度
    
    // 为指针分配动态内存
    ptr = new int;      //为指针变量请求内存
    *ptr = 0;           // 在分配的地址上存储值 0

    // 每次创建对象时增加 1
    objectCount++;
}
// 带部分缺省参数值的构造函数定义
Box::Box(double len, double b, double h, int ptr_value)
{
    cout << "带部分缺省参数值的构造函数" << endl;
    length = len;   // 长度
    breadth = b;  // 宽度
    height = h;   // 高度
       
    // 为指针分配动态内存
    ptr = new int;      //为指针变量请求内存
    *ptr = ptr_value;           // 在分配的地址上存储值ptr_value, 缺省值为0    

    // 每次创建对象时增加 1
    objectCount++;
}
// 拷贝构造函数
Box::Box(const Box &obj)
{
    cout << "调用拷贝构造函数" << endl;
    length = obj.length;   // 长度
    breadth = obj.breadth;  // 宽度
    height = obj.height;   // 高度
    
    ptr = new int;      
    *ptr = *obj.ptr;    // 拷贝值

    // 每次创建对象时增加 1
    objectCount++;
}

// 析构函数定义
Box::~Box()
{
    cout << "调用析构函数" << endl; 
    delete ptr;
}


// 静态成员函数定义
int Box::getCount()
{
    return objectCount;

}

// 普通成员函数定义
double Box::getVolume(void)
{
    return length * breadth * height;
}

void Box::setLength(double len)
{
    length = len;
}

void Box::setBreadth(double b)
{
    breadth = b;
}

void Box::setHeight(double h)
{
    height = h;
}

// Box成员函数
void Box::display()
{
    cout << "length 大小 : " << length <<endl;
    cout << "breadth 大小 : " << breadth <<endl;
    cout << "height 大小 : " << height <<endl;
    cout << "ptr指向的value 大小 : " << *ptr <<endl;
}

/*
// 非Box成员函数
void Box::display(Box obj)
{
    cout << "length 大小 : " << obj.length <<endl;
    cout << "breadth 大小 : " << obj.breadth <<endl;
    cout << "height 大小 : " << obj.height <<endl;
    cout << "ptr指向的value 大小 : " << *obj.ptr <<endl;
}
*/

Box* Box::get_address()
{
    return this;
}


// 请注意：printWidth() 不是任何类的成员函数
void printMember( Box box )   // 不能加前缀Box::printMember
{
   /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
   cout << "友元函数 friend void printMember( Box box ): " << endl;
   cout << "Width of box : " << box.length << endl;
   cout << "breadth of box : " << box.breadth << endl;
   cout << "height of box : " << box.height << endl;
   cout << "*ptr of box : " << *box.ptr << endl;   
}

void Boxfriend::setBox( double l, double b, double h, int p_value, Box &box )
{
    box.setLength(l);
    box.setBreadth(b);
    box.setHeight(h);      
    *box.ptr = p_value;    // 拷贝值

}

void Boxfriend::displayBox(Box &box)
{
   cout << "Width of box : " << box.length << endl;
   cout << "breadth of box : " << box.breadth << endl;
   cout << "height of box : " << box.height << endl;
   cout << "*ptr of box : " << *box.ptr << endl;   
}
