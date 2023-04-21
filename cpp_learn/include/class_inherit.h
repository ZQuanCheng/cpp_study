#ifndef CLASS_INHERIT_H    // 防止头文件的重复包含和编译
#define CLASS_INHERIT_H

#include <iostream>
#include <iomanip>

using namespace std;

// 基类 _Shape            
// 如果 _Shape中有至少一个纯虚函数,例如 getArea(), 则_Shape是抽象类. 
// 抽象类不能建立对象,但是可以说明抽象类的指针或引用,以便用这些指针和引用实现动态链接(多态性)
// 所以要么所有函数都设置为纯虚函数,要么不要定义虚函数.
// 补充:如果你基类是抽象类（有至少一个纯虚函数），但是派生类中没有对纯虚函数进行实现，那你的派生类也会成为抽象类，也不能定义对象。
class _Shape  
{
   public:
      // _Shape缺省构造函数
      _Shape();
      // _Shape带部分缺省参数值的构造函数
      _Shape(int a, int b);
      // _Shape拷贝构造函数
      _Shape(const _Shape &obj); //拷贝构造函数的最常见形式:classname (const classname &obj)
                                 // 如果在类中没有定义拷贝构造函数,编译器会自行定义一个
                                 // 如果类带有指针变量,并有动态内存分配,则它必须有一个拷贝构造函数
                                 // 因为自动生成的拷贝构造函数可能造成指针悬挂、内存泄漏等灾难性后果
        
      // _Shape虚析构函数声明
      // 存在类继承的场合，基类的析构函数推荐使用虚函数。原因是防止内存泄漏
      virtual ~_Shape();


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

// 基类 _PaintCost
class _PaintCost 
{
   public:
      int getCost(int area);
};

// 提供子对象给_Rectangle
class _AB
{
   public:
      // _AB缺省构造函数
      _AB();
      // _AB带部分缺省参数值的构造函数
      _AB(int i, int j);
      // _AB拷贝构造函数
      _AB(const _AB &obj); 
        
      // _AB析构函数声明
      ~_AB();

      void print();

   private:
      int aa, bb;
};


// 派生类 _Rectangle
class _Rectangle: public _Shape, public _PaintCost
{
   public:
      // _Rectangle缺省构造函数
      _Rectangle();
      // _Rectangle带部分缺省参数值的构造函数
      _Rectangle(int a, int b, int c, int d, int e, int ptr_value, unsigned int n);
      // _Rectangle拷贝构造函数
      _Rectangle(const _Rectangle &obj); 
        
      // _Rectangle析构函数声明
      ~_Rectangle();

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
      _AB ab;   // _Rectangle 类中包含 _AB 类的对象 ab 作为自由数据成员,即子对象
      // 简单变量
      int _rec;
   
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



// 派生类 _Triangle
class _Triangle: public _Shape, public _PaintCost
{
   public:
      // _Triangle缺省构造函数
      _Triangle();
      // _Triangle带部分缺省参数值的构造函数
      _Triangle(int a, int b, int c, int d, int e, int ptr_value, unsigned int n);
      // _Triangle拷贝构造函数
      _Triangle(const _Triangle &obj); 
        
      // _Triangle析构函数声明
      ~_Triangle();

      // (多态)虚函数,试验有无virtual关键词的区别
      virtual void print_virtual();
      void print();


      virtual int getArea();
      // 如果基类_Shape中有至少一个纯虚函数,例如 getArea(), 则_Shape是抽象类. 
      // 抽象类不能建立对象,但是可以说明抽象类的指针或引用,以便用这些指针和引用实现动态链接(多态性)
      // 所以,要么所有函数都设置为纯虚函数,要么不要定义虚函数
      // 补充:如果你基类是抽象类（有至少一个纯虚函数），但是派生类中没有对纯虚函数进行实现，那你的派生类也会成为抽象类，也不能定义对象。
   
   private:
      _AB ab;   // _Triangle 类中包含 _AB 类的对象 ab 作为自由数据成员,即子对象
      int _tri;
      
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



// 重载函数：函数名和返回值类型可以相同，但是参数列表不能相同
// （多态）虚函数：继承中的概念。函数名、返回值类型、参数列表都相同，需要在声明时加Virtual关键字
// 每个子类（派生类）都有一个相同声明的函数的独立实现。这就是多态的一般使用方式。
// 对于Virtual虚函数，只是通过基类（父类）指针或基类（父类）引用时才有多态性。
// 如果没有基类（父类）指针，有无Virtual关键字，对于我们来说没有区别。
void _print_by_base_pointer_virtual(_Shape *p);
void _print_by_base_pointer(_Shape *p);




#endif