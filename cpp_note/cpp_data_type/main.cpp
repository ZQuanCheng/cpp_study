/* call_data_type */

// 编译预处理
// 预处理命令以"#"开头，预处理不是程序语句，最后没有";",必须独占一行
#include <iostream>   // #include <iostream.h>  已过时，现在反对把.h符号继续用在标准的头文件中

#include <limits>     // 数据类型取值范围，最大值、最小值

#include <typeinfo>   // 查看变量类型 typeid(变量名).name()

using namespace std;  // C++标准库定义的标准命名空间. 没有这个，直接用cout、endl会报错，需要用std::cout、std::endl。
// #include <iostream> 必须跟using namespace std; 如果是#include <iostream.h>则不需要跟using namespace std;

// 已经不让用void main()了  // ‘::main’ must return ‘int’
int main()
{
    // 若没有using namespace std; 则需要cout改成std::cout，end改成std::endl

    // ----------------------------------------------数据类型所占字节数、取值范围-----------------------------------------------------

    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << endl; 

    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);  
    cout << "\t最大值：" << numeric_limits<bool>::max();  
    cout << "\t\t最小值：" << numeric_limits<bool>::min() << endl;  

    cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
    cout << "\t最大值：" << numeric_limits<char>::max();  
    cout << "\t\t最小值：" << numeric_limits<char>::min() << endl;  

    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    cout << "\t最大值：" << numeric_limits<signed char>::max();  
    cout << "\t\t最小值：" << numeric_limits<signed char>::min() << endl;  

    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);  
    cout << "\t最大值：" << numeric_limits<unsigned char>::max();  
    cout << "\t\t最小值：" << numeric_limits<unsigned char>::min() << endl;  

    cout << "short: \t\t" << "所占字节数：" << sizeof(short);  
    cout << "\t最大值：" << numeric_limits<short>::max();  
    cout << "\t\t最小值：" << numeric_limits<short>::min() << endl;  

    cout << "unsigned short: \t\t" << "所占字节数：" << sizeof(unsigned short);  
    cout << "\t最大值：" << numeric_limits<unsigned short>::max();  
    cout << "\t\t最小值：" << numeric_limits<unsigned short>::min() << endl;    

    cout << "int: \t\t" << "所占字节数：" << sizeof(int);  
    cout << "\t最大值：" << numeric_limits<int>::max();  
    cout << "\t最小值：" << numeric_limits<int>::min() << endl;  

    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);  
    cout << "\t最大值：" << numeric_limits<unsigned>::max();  
    cout << "\t最小值：" << numeric_limits<unsigned>::min() << endl;  

    cout << "long: \t\t" << "所占字节数：" << sizeof(long);  
    cout << "\t最大值：" << numeric_limits<long>::max();  
    cout << "\t最小值：" << numeric_limits<long>::min() << endl;  

    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);  
    cout << "\t最大值：" << numeric_limits<unsigned long>::max();  
    cout << "\t最小值：" << numeric_limits<unsigned long>::min() << endl;  

    cout << "float: \t\t" << "所占字节数：" << sizeof(float);  
    cout << "\t最大值：" << numeric_limits<float>::max();  
    cout << "\t最小值：" << numeric_limits<float>::min() << endl;  
    
    cout << "double: \t" << "所占字节数：" << sizeof(double);  
    cout << "\t最大值：" << numeric_limits<double>::max();  
    cout << "\t最小值：" << numeric_limits<double>::min() << endl;  
    
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);  
    cout << "\t最大值：" << numeric_limits<long double>::max();  
    cout << "\t最小值：" << numeric_limits<long double>::min() << endl;  

    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);  
    cout << "\t最大值：" << numeric_limits<wchar_t>::max();  
    cout << "\t\t最小值：" << numeric_limits<wchar_t>::min() << endl;  

    cout << endl; 

    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;  
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl; 

    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);  
    cout << "\t最大值：" << numeric_limits<size_t>::max();  
    cout << "\t最小值：" << numeric_limits<size_t>::min() << endl;  

    cout << "type: \t\t" << "************size**************"<< endl;  
    
    cout << endl << endl << endl;

    // --------------------------------------------------------------------------------------------------------------------------



    // ----------------------------------------------typedef别名-----------------------------------------------------
    cout << "typedef: \t\t" << "************为已有类型取一个新的名字**************"<< endl;  
    cout << endl; 
    typedef int feet;
    feet distance;
    // distance = 6;
    cout << "变量'distance'所占内存大小" << sizeof(distance) << endl;
    cout << endl << endl << endl;
    // --------------------------------------------------------------------------------------------------------------------------



    // ----------------------------------------------typeid(变量名).name()查看变量类型----------------------------------------------------
    cout << "typeid(变量名).name(): \t\t" << "************查看变量类型**************"<< endl; 
    cout << endl; 
	bool a1;char a2;signed char a3;unsigned char a4;
	short a5;unsigned short a6;
	int a7;unsigned int a8;
	long  a9;unsigned long a10;long long a11;unsigned long long a12;
	float a13;
	double a14;
	long double a15;
		
	cout<<typeid(a1).name()<<"表示:bool"<<endl;
	cout<<typeid(a2).name()<<"表示:char"<<endl;
	cout<<typeid(a3).name()<<"表示:signed char"<<endl;
	cout<<typeid(a4).name()<<"表示:unsigned char"<<endl;
	cout<<typeid(a5).name()<<"表示:short"<<endl;
	cout<<typeid(a6).name()<<"表示:unsigned short"<<endl;
	cout<<typeid(a7).name()<<"表示:int"<<endl;
	cout<<typeid(a8).name()<<"表示:unsigned int"<<endl;
	
	cout<<typeid(a9).name()<<"表示:long"<<endl;
	cout<<typeid(a10).name()<<"表示:unsigned long"<<endl;
	cout<<typeid(a11).name()<<"表示:long long"<<endl;
	cout<<typeid(a12).name()<<"表示:unsigned long long"<<endl;
	cout<<typeid(a13).name()<<"表示:float"<<endl;
	cout<<typeid(a14).name()<<"表示:double"<<endl;
	cout<<typeid(a15).name()<<"表示:long double"<<endl;
	
	int *aa;
	cout<<typeid(aa).name()<<"表示:int指针类型"<<endl;
	cout<<typeid(*aa).name()<<"表示:int"<<endl;
	
	char **bb;
	cout<<typeid(bb).name()<<"表示:"<<endl;
	cout<<typeid(*bb).name()<<"表示:char指针类型"<<endl;
	cout<<typeid(**bb).name()<<"表示:char"<<endl;
		
	char *cc=new char;
	cout<<typeid(cc).name()<<"表示:char指针类型"<<endl;
	cout<<typeid(*cc).name()<<"表示:char"<<endl;
	
	string *dd=new string("abc");
	cout<<typeid(dd).name()<<"表示:string指针类型"<<endl;
	cout<<typeid(*dd).name()<<"表示:string"<<endl;
    cout << endl << endl << endl;
    // --------------------------------------------------------------------------------------------------------------------------



    // ------------------------------------------------C语言中的类型转换---------------------------------------------------------
    /*
    C语言中有两种形式的类型转换，分别是隐式类型转换和显式类型转换：

    隐式类型转换：编译器在编译阶段自动进行，能转就转，不能转就编译失败。
    显式类型转换：需要用户自己处理，以(指定类型)变量的方式进行类型转换。
    
    需要注意的是，只有相近类型之间才能发生隐式类型转换，比如int和double表示的都是数值，只不过它们表示的范围和精度不同。
    而指针类型表示的是地址编号，因此整型和指针类型之间不会进行隐式类型转换，如果需要转换则只能进行显式类型转换。 
    */
    cout << "\t\t" << "************C语言的强制类型转换: **************"<< endl; 

	int i = 1;
    cout << "i=" << i << endl;
    cout << "int i 所占内存大小" << sizeof(i) << endl;    
    cout<< "typeid(i).name()返回值为: " << typeid(i).name()<<" 表示:int"<<endl;
    cout << endl;

    //隐式类型转换
	double d1 = i;
    cout << "d=" << d1 << endl;
    cout << "double d1 所占内存大小" << sizeof(d1) << endl;    
    cout<< "typeid(d1).name()返回值为: " << typeid(d1).name()<<" 表示:double"<<endl;
    cout << endl;

	//显式类型转换
    double d2 = (double)i;
    cout << "dd=" << d2 << endl;
    cout << "double d2 所占内存大小" << sizeof(d2) << endl;    
    cout<< "typeid(d2).name()返回值为: " << typeid(d2).name()<<" 表示:double"<<endl;
    cout << endl;

	//整型和指针类型之间不会进行隐式类型转换
	int *p = &i;
    cout << "p=" << p << endl;
    cout << "*p=" << *p << endl;
    cout << "p 所占内存大小" << sizeof(p) << endl; 
    cout << "*p 所占内存大小" << sizeof(*p) << endl;        
    cout<< "typeid(p).name()返回值为: " << typeid(p).name()<<" 表示:int指针类型"<<endl;
    cout<< "typeid(*p).name()返回值为: " << typeid(*p).name()<<" 表示:int"<<endl;
    // (int)p会报错
	// 整型和指针类型之间不会进行隐式类型转换
    // int address = (int)p;  

    cout << endl << endl << endl;

    // --------------------------------------------------------------------------------------------------------------------------


    // ------------------------------------------------C++ 强制类型转换。实际上很少使用---------------------------------------------------------
    cout << "\t\t" << "************C++四种类型转换: **************"<< endl;  

    cout << "类型转换: \t\t" << "************静态转换（Static Cast）**************"<< endl;  
    cout << endl; 
    //cout << "类型转换: \t\t" << "************强制转换数据类型，不进行任何运行时类型检查.通常用于比较类型相似的对象之间的转换，例如将 int 类型转换为 float 类型。**************"<< endl;
    
    int ia = 10;
    cout << "ia=" << ia << endl;
    cout << "int ia 所占内存大小" << sizeof(ia) << endl;    
    cout<< "typeid(ia).name()返回值为: " << typeid(ia).name()<<" 表示:int"<<endl;
    cout << endl;

    float fa = static_cast<float>(ia); // 静态将int类型转换为float类型
    cout << "fa=" << fa <<endl;
    cout << "float fa = static_cast<float>(ia);后 fa 所占内存大小" << sizeof(fa) << endl;
    cout<< "typeid(fa).name()返回值为: " << typeid(fa).name()<<" 表示:float"<<endl;

    cout << endl << endl << endl;



    /*
    cout << "类型转换: \t\t" << "************动态转换（Dynamic Cast）**************"<< endl; 
    cout << endl; 
    //cout << "类型转换: \t\t" << "************动态转换通常用于将一个基类指针或引用转换为派生类指针或引用。动态转换在运行时进行类型检查，如果不能进行转换则返回空指针或引发异常。**************"<< endl;
    class Base {};
    class Derived : public Base {};
    Base* ptr_base = new Derived;
    cout << "Base* ptr_base" << sizeof(ptr_base) << endl;
    Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base); // 将基类指针转换为派生类指针 
    cout << "Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base); 后 ptr_derived 所占内存大小" << sizeof(ptr_derived) << endl;
    cout << endl << endl << endl;
    */



    cout << "类型转换: \t\t" << "************常量转换（Const Cast）**************"<< endl;  
    //cout << "类型转换: \t\t" << "************常量转换用于将 const 类型的对象转换为非 const 类型的对象。常量转换只能用于转换掉 const 属性，不能改变对象的类型。**************"<< endl;
    cout << endl; 

    const int ib = 10;
    cout << "ib=" << ib << endl;
    cout << "const int ib 所占内存大小" << sizeof(ib) << endl; 
    cout<< "typeid(ib).name()返回值为: " << typeid(ib).name()<<" 表示:int"<<endl;
    cout << endl;
    
    // & 表示引用；已经定义过的变量名，还可以再取一个别名，这个别名就是引用（reference）数据类型 &引用名 = 已经定义过的变量名；
    int &r = const_cast<int&>(ib); // 常量转换，将const int转换为int
    cout << "r=" << r <<endl;
    cout << "int &r = const_cast<int&>(ib);;后 r 所占内存大小" << sizeof(r) << endl;
    cout<< "typeid(r).name()返回值为: " << typeid(r).name()<<" 表示:int"<<endl;
    cout << endl << endl << endl;




    cout << "类型转换: \t\t" << "************重新解释转换（Reinterpret Cast）**************"<< endl;  
    //cout << "类型转换: \t\t" << "************将一个数据类型的值重新解释为另一个数据类型的值。重新解释转换不进行任何类型检查**************"<< endl;
    cout << endl; 

    int ic = 10;
    cout << "ic=" << ic << endl;
    cout << "int ic 所占内存大小" << sizeof(ic) << endl;      
    cout<< "typeid(ic).name()返回值为: " << typeid(ic).name()<<" 表示:int"<<endl;
    cout << endl;

    float fc = reinterpret_cast<float&>(ic); // 重新解释将int类型转换为float类型
    cout << "fc=" << ic << endl;
    cout << "float fc = reinterpret_cast<float&>(ic);后 fc 所占内存大小" << sizeof(fc) << endl;
    cout<< "typeid(fc).name()返回值为: " << typeid(fc).name()<<" 表示:float"<<endl;
    cout << endl << endl << endl;

    // --------------------------------------------------------------------------------------------------------------------------




    return 0;
}

/*
补充：
1、旧的C++头文件是官方明确反对使用的，但旧的C头文件则没有（以保持对C的兼容性） 
2、iostream.h是包含输入/输出流处理的头文件,iostream就什么都不是了 但用iostream要加名词空间namespace
4、标准化委员会在简化非C标准头文件时用<iostream> 取代了它。但又没有完全取消 <iostream.h> 的使用，并且很多编译器都同时支持<iostream > 和< iostream.h > ，
   造成现在的局面，标准化委员会确实有不得已的苦衷。
4、 C++中新定义的方法都是有名字空间的 比如cout就属于std名字空间 
5、如果include头文件的时候加上.h，默认会using namespace 否则需要自己加上 using namespace XXX 
6、对于C中已经定义的方法如printf，没有影响的。#include <stdio.h> 不会报错
*/