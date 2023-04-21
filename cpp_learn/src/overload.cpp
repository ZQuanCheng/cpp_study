#include "overload.h"

// 构造函数定义
// 缺省构造函数定义
PrintData::PrintData()
{
    cout << "缺省构造函数" << endl;
    a = 0.0;  
    b = 0.0;  
    c = 0.0;   
}
// 带部分缺省参数值的构造函数定义
PrintData::PrintData(double i = 0.0, double j = 0.0, double k = 0.0)
{
    cout << "带部分缺省参数值的构造函数" << endl;
    a = i;   
    b = j;  
    c = k;      
}
// 拷贝构造函数
PrintData::PrintData(const PrintData &obj)
{
    cout << "拷贝构造函数" << endl;
    a = obj.a;   
    b = obj.b;  
    c = obj.c;   
}


// 析构函数定义
PrintData::~PrintData()
{
    cout << "析构函数" << endl; 
}


// PrintData成员函数
void PrintData::display()
{
    cout << "a 大小 : " << a <<endl;
    cout << "b 大小 : " << b <<endl;
    cout << "c 大小 : " << c <<endl;
}


// 重载print()函数
void PrintData::print(int i)
{
    cout << "整数为: " << i << endl;
}


void PrintData::print(double f)
{
    cout << "浮点数为: " << f << endl;
}

/*
void PrintData::print(char c[])       // 不能和void print(char *c)同时重载. 在编译器看来, 形参char c[]就是形参char *c
{
    cout << "字符数组为: " << c << endl;
}
*/

void PrintData::print(char *c)        // 不能和void print(char c[])同时重载. 在编译器看来, 形参char c[]就是形参char *c
{
    cout << "字符指针指向的内容为: " << c << endl;
}


// 重载 + 运算符，用于把两个 PrintData 对象相加
PrintData PrintData::operator+(const PrintData& pd)
{
    PrintData p(0.0, 0.0, 0.0); // 只是声明PrintData p;的话,会报错 call of overloaded ‘PrintData()’ is ambiguous
    p.a= this->a + pd.a;
    p.b = this->b + pd.b;
    p.c = this->c + pd.c;
    return p;
}

