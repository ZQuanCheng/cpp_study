#ifndef SHAPE_CLASS_H    // 防止头文件的重复包含和编译
#define SHAPE_CLASS_H


#include <iostream>
#include <iomanip>

using namespace std;

// 基类 _Shape            
// 如果 _Shape中有至少一个纯虚函数,例如 getArea(), 则_Shape是抽象类. 
// 抽象类不能建立对象,但是可以说明抽象类的指针或引用,以便用这些指针和引用实现动态链接(多态性)
// 所以要么所有函数都设置为纯虚函数,要么不要定义虚函数.
// 补充:如果你基类是抽象类（有至少一个纯虚函数），但是派生类中没有对纯虚函数进行实现，那你的派生类也会成为抽象类，也不能定义对象。
class Shape  
{
   public:
      // Shape缺省构造函数
      Shape();
      // Shape带部分缺省参数值的构造函数
      Shape(int a, int b);
      // Shape拷贝构造函数
      Shape(const Shape &obj); //拷贝构造函数的最常见形式:classname (const classname &obj)
                                 // 如果在类中没有定义拷贝构造函数,编译器会自行定义一个
                                 // 如果类带有指针变量,并有动态内存分配,则它必须有一个拷贝构造函数
                                 // 因为自动生成的拷贝构造函数可能造成指针悬挂、内存泄漏等灾难性后果
        
      // Shape虚析构函数声明
      // 存在类继承的场合，基类的析构函数推荐使用虚函数。原因是防止内存泄漏
      virtual ~Shape();


      void setWidth(int w);
      void setHeight(int h);
      int getWidth();
      int getHeight();      

      // (多态)虚函数,试验有无virtual关键词的区别
      virtual void print_virtual();            // 如果
      void print();

      
      // virtual int getArea() = 0;  // 纯虚函数. 即基类中不对虚函数给出有意义的实现 
      virtual int getArea(){ return 0; }
      // 如果基类_Shape中有至少一个纯虚函数,例如 getArea(), 则_Shape是抽象类. 
      // 抽象类不能建立对象,但是可以说明抽象类的指针或引用,以便用这些指针和引用实现动态链接(多态性)
      // 所以,要么所有函数都设置为纯虚函数,要么不要定义虚函数
      // 补充:如果你基类是抽象类（有至少一个纯虚函数），但是派生类中没有对纯虚函数进行实现，那你的派生类也会成为抽象类，也不能定义对象。

   private:
      int width;
      int height;
};



 

#endif