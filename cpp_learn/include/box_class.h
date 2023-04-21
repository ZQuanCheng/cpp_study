#ifndef BOX_CLASS_H    // 防止头文件的重复包含和编译
#define BOX_CLASS_H

#include <iostream>
using namespace std; 

class Box
{
   public:
        static int objectCount;

      
        // 构造函数声明
        // 缺省构造函数
        Box();
        // 带部分缺省参数值的构造函数
        // 带默认/缺省值的形参 尽量写在声明里写缺省值！便于在头文件里查找修改。
        // 定义和声明分开的，只能在声明中设置默认参数
        // 带默认/缺省值的形参必须放在形参的最后面，可以是多个，调用时只能从最后一个参数开始进行缺省，
        // 如果要缺省一个参数，必须缺省它后面所有的参数。
        Box(double len, double b = 0.0, double h = 0.0, int ptr_value = 0);
        // 拷贝构造函数
        Box(const Box &obj);    //拷贝构造函数的最常见形式:classname (const classname &obj)
                                // 如果在类中没有定义拷贝构造函数,编译器会自行定义一个
                                // 如果类带有指针变量,并有动态内存分配,则它必须有一个拷贝构造函数
                                // 因为自动生成的拷贝构造函数可能造成指针悬挂、内存泄漏等灾难性后果


        // 析构函数声明
        ~Box();

        // 静态成员函数声明
        static int getCount();

        // 普通成员函数声明
        double getVolume(void);
        void setLength( double len );
        void setBreadth( double bre );
        void setHeight( double hei );

        void display();

        Box* get_address();

        // 友元函数
        friend void printMember( Box box );
        // 友元类
        friend class Boxfriend;

    private:
        double length;   // 长度
        double breadth;  // 宽度
        double height;   // 高度
        int *ptr;                  //如果类带有指针变量,并有动态内存分配,则它必须有一个拷贝构造函数
};

class Boxfriend
{
    public:
        // Boxfriend是Box的友元类，它可以直接访问Box类的任何成员
        void setBox( double l, double b, double h, int p_value, Box &box );
        void displayBox( Box &box );

};








#endif