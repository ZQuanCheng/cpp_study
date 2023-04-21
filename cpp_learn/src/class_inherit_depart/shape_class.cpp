#include "shape_class.h"

// --------------------------------------------------_Shape类---------------------------------------------------- 

// _Shape缺省构造函数
Shape::Shape():width(0), height(0)                                          // classname::classname():[数据成员初始化表]
{
    // width = 0;   // 函数名后如果跟了数据成员初始化表width(0),就不用width = 0; 因为本质一样.   
    // height = 0;   
    cout << "Shape缺省构造函数" << endl;
}
// _Shape带部分缺省参数值的构造函数
Shape::Shape(int a, int b): width(a), height(b)                             // classname::classname():[数据成员初始化表]
{
    // width = a;  // 函数名后如果跟了数据成员初始化表width(a),就不用width = a; 因为本质一样.    
    // height = b;   
    cout << "Shape带部分缺省参数值的构造函数" << endl;  
}
// _Shape拷贝构造函数
Shape::Shape(const Shape &obj): width(obj.width), height(obj.height)       // classname::classname():[数据成员初始化表]
{

    // width = obj.width;    // 函数名后如果跟了数据成员初始化表width(obj.width),就不用width = obj.width; 因为本质一样.   
    // height = obj.height; 
    cout << "Shape拷贝构造函数" << endl;
}
// _Shape虚析构函数声明
// 存在类继承的场合，基类的析构函数推荐使用虚函数。原因是防止内存泄漏
Shape::~Shape()
{
    cout << "Shape虚析构函数virtual" << endl; 
}


void Shape::setWidth(int w)
{
    width = w;
}
void Shape::setHeight(int h)
{
    height = h;
}
int Shape::getWidth()
{
    return width;
}
int Shape::getHeight()
{
    return height;
}


// (多态)虚函数,试验有无virtual关键词的区别
void Shape::print_virtual()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    cout << setw(20) << " Shape class: " << setw(20) << " width = " << width << setw(20) << " height = " << height << endl;
}

void Shape::print()  // .h头文件的类中声明已有virtual void print(); 这里不需要virtual修饰
{
    cout << setw(20) << " Shape class: " << setw(20) << " width = " << width << setw(20) << " height = " << height << endl;
}



// ------------------------------------------------------------------------------------------------------ 
