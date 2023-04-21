#ifndef OVERLOAD_H    // 防止头文件的重复包含和编译
#define OVERLOAD_H

#include <iostream>
using namespace std; 

class PrintData
{
   public:
      // 构造函数声明
      // 缺省构造函数
      PrintData();
      // 带部分缺省参数值的构造函数
      PrintData(double i, double j, double k);
      // 拷贝构造函数
      PrintData(const PrintData &obj);     //拷贝构造函数的最常见形式:classname (const classname &obj)
      // 如果在类中没有定义拷贝构造函数,编译器会自行定义一个
      // 如果类带有指针变量,并有动态内存分配,则它必须有一个拷贝构造函数
      // 因为自动生成的拷贝构造函数可能造成指针悬挂、内存泄漏等灾难性后果

      // 析构函数声明
      ~PrintData();

      void display();

      // 重载print()函数
      void print(int i);
      void print(double f);
      // void print(char c[]); // 不能和void print(char *c)同时重载. 在编译器看来, 形参char c[]就是形参char *c
      void print(char *c);     // 不能和void print(char c[])同时重载. 在编译器看来, 形参char c[]就是形参char *c

      // 重载 + 运算符，用于把两个 PrintData 对象相加
      PrintData operator+(const PrintData& pd);

   private:
      double a;      // 长度
      double b;     // 宽度
      double c;      // 高度
};

#endif