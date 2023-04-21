#ifndef TRIANGLE_CLASS_H    // 防止头文件的重复包含和编译
#define TRIANGLE_CLASS_H

#include "ab_class.h"
#include "shape_class.h"
#include "paintcost_class.h"


// 派生类 Triangle
class Triangle: public Shape, public PaintCost
{
   public:
      // _Triangle缺省构造函数
      Triangle();
      // _Triangle带部分缺省参数值的构造函数
         // 带默认/缺省值的形参 尽量写在声明里写缺省值！便于在头文件里查找修改。
         // 定义和声明分开的，只能在声明中设置默认参数
         // 带默认/缺省值的形参必须放在形参的最后面，可以是多个，调用时只能从最后一个参数开始进行缺省，
         // 如果要缺省一个参数，必须缺省它后面所有的参数。
      Triangle(int a, int b, int c, int d, int e, int ptr_value = 0, unsigned int n = 0);
      // _Triangle拷贝构造函数
      Triangle(const Triangle &obj); 
        
      // _Triangle析构函数声明
      ~Triangle();

      // (多态)虚函数,试验有无virtual关键词的区别
      virtual void print_virtual();
      void print();


      virtual int getArea();
      // 如果基类_Shape中有至少一个纯虚函数,例如 getArea(), 则_Shape是抽象类. 
      // 抽象类不能建立对象,但是可以说明抽象类的指针或引用,以便用这些指针和引用实现动态链接(多态性)
      // 所以,要么所有函数都设置为纯虚函数,要么不要定义虚函数
      // 补充:如果你基类是抽象类（有至少一个纯虚函数），但是派生类中没有对纯虚函数进行实现，那你的派生类也会成为抽象类，也不能定义对象。
   
   private:
      // 子对象
      AB ab;   // _Triangle 类中包含 _AB 类的对象 ab 作为自由数据成员,即子对象
      // 简单变量
      int tri;
      
      // 指针变量, 一般用于分配动态内存
      // 如果类带有指针变量,并分配动态内存给 "一个数据类型所需的存储单元",则它必须有一个拷贝构造函数. 
      // 为单个变量 动态申请内存单元时,可以同时对该单元初始化
      int *ptr;  
       
      // 如果类带有指针变量,并分配动态内存给 "一块连续的存储空间,即创建数组",则它必须有一个拷贝构造函数
      // 指针存放数组首地址
      // 为数组 动态申请内存单元时,不能对数组进行初始化
      unsigned int size;
      char *buf; 
};

#endif