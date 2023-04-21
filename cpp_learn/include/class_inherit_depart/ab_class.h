#ifndef AB_CLASS_H    // 防止头文件的重复包含和编译
#define AB_CLASS_H


#include <iostream>
#include <iomanip>

using namespace std;

// 提供子对象给Rectangle
class AB
{
   public:
      // AB缺省构造函数
      AB();
      // _AB带部分缺省参数值的构造函数
      AB(int i, int j);
      // _AB拷贝构造函数
      AB(const AB &obj); 
        
      // AB析构函数声明
      ~AB();

      void print();

   private:
      int aa, bb;
};


#endif