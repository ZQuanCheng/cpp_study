/* cpp_learn */

// 编译预处理
// 预处理命令以"#"开头，预处理不是程序语句，最后没有";",必须独占一行
#include <iostream>   // #include <iostream.h>  已过时，现在反对把.h符号继续用在标准的头文件中
#include <cstdio>     // gets()、puts()、getchar()、putchar()
#include <cstring>    // C语言  strlen()、strcat()、strcpy()、strcmp()、strstr()、strchr()、isupper()、islower()、toupper()、tolower()
#include <cstdlib>    // 在windows系统下，用如下语句,控制台不会输出后马上消失。system("pause"); 
#include <unistd.h>   // 在Linux系统下，用如下语句,控制台不会输出后马上消失。pause(); 
#include <stdexcept>  // 异常处理exception try throw catch

#include "swap.h"

#include "book_struct.h"

#include "box_class.h" 

#include "class_inherit.h"


// #include "paintcost_class.h"  // 不直接使用
// #include "ab_class.h"         // 不直接使用
#include "shape_class.h"
#include "rectangle_class.h" 
#include "triangle_class.h" 
#include "print_by_base_pointer.h" 


#include "overload.h"

#include "template_func_max.h"
#include "template_class_array.h"
#include "template_class_stack.h"


// STL（标准模板库）
#include <vector>     // C++ vector 容器
#include <string>     // C++ string 容器



using namespace std;  // C++标准库定义的标准命名空间. 没有这个，直接用cout、endl会报错，需要用std::cout、std::endl。
// #include <iostream> 必须跟using namespace std; 如果是#include <iostream.h>则不需要跟using namespace std;



// 初始化类 Box 的静态成员
int Box::objectCount = 0;




// 已经不让用void main()了  // ‘::main’ must return ‘int’
int main(){

    // ---------------------------------------------------------strstr()和strncpy()------------------------------------------------
    /*
	char str[] = "This is a simple string";
	char *pch;
	pch = strstr(str, "simple");
	if (pch != NULL)
		strncpy(pch, "sample", 6);   // simple换成sample。 显示This is a sample string
	puts(str);
	*/
    // ---------------------------------------------------------------------------------------------------------



    // ---------------------------------------------------------strcpy()和strncpy()------------------------------------------------
	/*
    char src[40];
    char dest[12] = "123456789a0";  //只能11个字符，再多就报错

    
    // memset(dest, '\0', sizeof(dest));   // void *memset(void *s, int c, size_t n);   s指向要填充的内存块。    c是要被设置的值。  n是要被设置该值的字符数。 返回类型是一个指向存储区s的指针。
                                        // memset是一个初始化函数，作用是将某一块内存中的全部设置为指定的值。 
	cout << "sizeof(dest):\t" << sizeof(dest) <<endl;
	cout << "dest:\t" << dest <<endl;
	cout << endl;	

    strcpy(src, "This is runoob.com");
	cout << "src:\t" << src <<endl;	
	cout << endl;	


    strncpy(dest, src, 10);
	cout << "sizeof(dest):\t" << sizeof(dest) <<endl;
	cout << "dest:\t" << dest <<endl;
	cout << endl;	

    printf("最终的目标字符串： %s\n", dest);
    */
    // ---------------------------------------------------------------------------------------------------------



    // ---------------------------------------------------------islower()和isupper()------------------------------------------------
    /*
    int var1 = 'Q';
    int var2 = 'q';
    
    if( islower(var1) )
    {
        printf("var1 = |%c| 是小写字母\n", var1 );
    }
    else
    {
        printf("var1 = |%c| 不是小写字母\n", var1 );
    }
    if( isupper(var2) )
    {
        printf("var2 = |%c| 是大写字母\n", var2 );
    }
    else
    {
        printf("var2 = |%c| 不是大写字母\n", var2 );
    }
	*/
    // ---------------------------------------------------------------------------------------------------------    




    // ---------------------------------------------------------tolower()和toupper()------------------------------------------------
	/*
	int i;
    char str_1[] = "runoob";
    char str_2[] = "RUNOOB";
	
	cout << "str_1:\t" << str_1 << endl;
	cout << "str_2:\t" << str_2 << endl;

	i = 0;
	cout << "After toupper() str_1:\t";	
    while(str_1[i])
    {
        putchar (toupper(str_1[i]));
        i++;
    }
	cout << endl;
    
	i = 0;
	cout << "After tolower() str_2:\t";	
	while(str_2[i])
    {
        putchar (tolower(str_2[i]));
        i++;
    }
	cout << endl;
    */
    // ---------------------------------------------------------------------------------------------------------    
   



    // ---------------------------------------------------------strlen()-----------------------------------------------
	/*
	char site_1[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
	char site_2[7] = {'R', 'U', 'N', 'O', 'O', 'B', '0'};
 
    cout << "strlen(site_1):\t" << strlen(site_1) << endl;
    cout << "strlen(site_2):\t" << strlen(site_2) << endl;	
    */
    // ---------------------------------------------------------------------------------------------------------    
   

    


    // --------------------------------------------指针--------------------------------------------    
    /*
    int  *ptr_a;
    int  *ptr_null = NULL;
    int a = 1;
     
    cout << "ptr_a 的值是 " << ptr_a << endl;
    cout << "ptr_null 的值是 " << ptr_null << endl;
    ptr_a = & a;
    cout << "ptr_a 的值是 " << ptr_a << endl;
    */
    // ---------------------------------------------------------------------------------------- 


    // -----------------------------------------指针的算术运算--------------------------------------------
    /*
    ptr_a++;
    cout << "ptr_a 的值是 " << ptr_a << endl;   
    ptr_a--;
    cout << "ptr_a 的值是 " << ptr_a << endl;   
    cout << endl;

    int  var[3] = {10, 100, 200};
    int  *ptr_var;
 
    // 指针中的数组地址
    ptr_var = var;
    for (int i = 0; i < 3; i++)
    { 
       cout << "Address of var[" << i << "] = ";
       cout << ptr_var << endl;
 
       cout << "Value of var[" << i << "] = ";
       cout << *ptr_var << endl;
 
       // 移动到下一个位置
       ptr_var++;
    }
    cout << endl;
    */
    // ----------------------------------------------------------------------------------------     

    
    // -------------------------------------------------指针数组--------------------------------------
    /*
    int  *ptr_arr[3];
    for (int i = 0; i < 3; i++)
    {
        ptr_arr[i] = &var[i]; // 赋值为整数的地址
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Value of var[" << i << "] = ";
        cout << *ptr_arr[i] << endl;
    }
    cout << endl;

    const char *names[4] = {
                   "Zara Ali",
                   "Hina Ali",
                   "Nuha Ali",
                   "Sara Ali",
    };
 
    for (int i = 0; i < 4; i++)
    {
        cout << "Value of names[" << i << "] = ";
        cout << names[i] << endl;
    }
    cout << endl;
    */
    // ---------------------------------------------------------------------------------------

    //-----------------------------指向指针的指针（多级间接寻址）-------------------------------------

    /*
    int  var;
    int  *ptr;
    int  **pptr;
 
    var = 3000;
 
    // 获取 var 的地址
    ptr = &var;
 
    // 使用运算符 & 获取 ptr 的地址
    pptr = &ptr;
 
    // 使用 pptr 获取值
    cout << "var 值为 :" << var << endl;
    cout << "*ptr 值为:" << *ptr << endl;
    cout << "**pptr 值为:" << **pptr << endl;
    */

    //----------------------------------------------------------------------------
   
    








    


    // --------------------------------------------------------数组名a、数组名取地址&a、数组首地址&a[0]、数组指针*p--------------------------------------------- 
	/*
	int a[5]={1,2,3,4,5};
	int *pa=&a[0];//指针指向第一个元素
	cout<<"a:      "<<a<<endl; 
	cout<<"&a:     "<<&a<<endl;
	cout<<"&a[0]:  "<<&a[0]<<endl;      
	cout<<"a+1:    "<<a+1<<endl;
	cout<<"&a+1:   "<<&a+1<<endl;        
	cout<<"&a[0]+1:"<<&a[0]+1<<endl;     
    cout<<"&a[1]:  "<<&a[1]<<endl;       
	cout<<"pa:     "<<pa<<endl;
	cout<<"pa+1:   "<<pa+1<<endl; 
	cout<<"sizeof(a):   "<<sizeof(a)<<endl;
	cout<<"sizeof(&a):   "<<sizeof(&a)<<endl;  
	cout<<"sizeof(pa):   "<<sizeof(pa)<<endl;       
    cout << endl; 
    // 总结：对于char以外的数组或指针
    // a    &a       &a[0]    三者数值上相同。                         但是&a本质上是指向整个数组，a和&a[0]本质上指向数组的第一个元素
    // a+1  &a[i]    &a[0]+1  三者相同都是取第i个元素的存储地址一样。
    // &a + 1 是数组结束之后的下一“段”的起始位置地址。这是因为&a本质上是指向整个数组，而a和&a[0]本质上指向数组的第一个元素

    // 但是，当一切来到char类型时，就变了


    char c[5]={'g','o','o','d','\0'};       //  cout遇到字符指针/地址，会当作字符串显示，如果没有'\0'就可能是乱码了加一个'\0'就可以避免 输出未初始化区域的内容 
	char *pc=&c[0];//指针指向第一个元素
	cout<<"c:      "<<c<<endl; 
	cout<<"&c:     "<<&c<<endl;           // 只有&c是指向整个数组，而其他的都是指向某一个元素。由于cout“自作聪明”，将以指向元素为起始位置，输出一个字符串。
	cout<<"&c[0]:  "<<&c[0]<<endl;
	cout<<"c+1:    "<<c+1<<endl;
	cout<<"&c+1:   "<<&c+1<<endl;
	cout<<"&c[0]+1:"<<&c[0]+1<<endl;
    cout<<"&c[1]:  "<<&c[1]<<endl;
	cout<<"pc:     "<<pc<<endl;               
	cout<<"pc+1:   "<<pc+1<<endl; 
    cout<<"sizeof(c):   "<<sizeof(c)<<endl;
	cout<<"sizeof(&c):   "<<sizeof(&c)<<endl;  
    cout<<"sizeof(pc):   "<<sizeof(pc)<<endl;
    cout << endl; 
    // 总结： 对于char
    // c    &c[0]    二者相同。   c和&c[0]本质上指向数组的第一个元素
    // c+1  &c[i]    &c[0]+1  三者相同都是取第i个元素的存储地址一样。
    // 在C语言里，输出一个字符串的指针很方便，直接printf("%p/n",p) ;就输出了。
    // 而C++里cout太自作聪明了，为了省去我们循环输出字符的麻烦，cout<<p<<endl ;被翻译为输出p指向的字符串值。
    // 只有&c是指向整个数组，而其他的都是指向某一个元素。于是都将以这些元素为起始位置，输出一个字符串。这也就解释了为什么只有&c和&c+1能正确输出地址。
    // &c + 1 是数组结束之后的下一“段”的起始位置地址。
    
    */
    // ----------------------------------------------------------------------------------------------------- 





    // ------------------------------------------------cout 显示char * 指针的讨论，和其他数据类型不同--------------------------------------------- 
    /*
	int  var1 = 20;           
    cout << "&var1： " << &var1 << endl;                      // int型变量可以直接使用“&”获取地址，而char型变量取不行。
    cout << "(void *)&var1： " << (void *)&var1 << endl;
    printf( "&var1: %p \n", &var1); 

    int  *ip_var1 = &var1;  
    cout << "ip_var1： " << ip_var1 << endl;   
    cout << "(void *)ip_var1： " << (void *)ip_var1 << endl;    
    printf("ip_var1: %p \n", ip_var1) ; 
    cout << endl;  

    
    char var2 = 'a';
    cout << "&var2： " << &var2 << endl;                      // &a是一个char*变量，cout会认为其指向一个字符串，但&a却没有终止符（“\0”），所以会输出后面的乱码
    cout << "(void *)&var2： " << (void *)&var2 << endl;      // 解决办法：1. 将&a强制转换成（void *）&a
    printf( "&var2: %p \n", &var2);                           // 解决办法：2. 可以用printf代替cout输出
    // 在C语言里，输出一个字符串的指针很方便，直接printf("%p/n",p) ;就输出了。
    // 而C++里cout太自作聪明了，为了省去我们循环输出字符的麻烦，cout<<p<<endl ;被翻译为输出p指向的字符串值。
    // cout遇到字符指针/地址，会当作字符串显示，如果没有'\0'就可能是乱码了加一个'\0'就可以避免 输出未初始化区域的内容 

    char *ip_var2 = &var2;
    cout << "ip_var2： " << ip_var2 << endl;   
    cout << "(void *)ip_var2： " << (void *)ip_var2 << endl;    
    printf("ip_var2: %p \n", ip_var2) ; 
    cout << endl;




	int  arr1[5] = {1,2,3,4,5};              
    cout << "&arr1： " << &arr1 << endl;                      
    cout << "(void *)&arr1： " << (void *)&arr1 << endl;
    printf( "&arr1: %p \n", &arr1); 

    int  *ip_arr1 = arr1;  
    cout << "ip_arr1： " << ip_arr1 << endl;   
    cout << "(void *)ip_arr1： " << (void *)ip_arr1 << endl;    
    printf("ip_arr1: %p \n", ip_arr1) ; 
    cout << endl;  


	char  arr2[5] = {'g','o','o','d','\0'};         
    cout << "&arr2： " << &arr2 << endl;                      
    cout << "(void *)&arr2： " << (void *)&arr2 << endl;
    printf( "&arr2: %p \n", &arr2); 

    char  *ip_arr2 = &arr2[0];   
    cout << "ip_arr2： " << ip_arr2 << endl;                    // cout遇到字符指针/地址，会当作字符串显示，而不是打印地址。遇到'\0'终止打印   
    cout << "(void *)ip_arr2： " << (void *)ip_arr2 << endl;    // 想要打印地址，将强制转换成（void *）
    printf("ip_arr2: %p \n", ip_arr2) ;                         // 想要打印地址，可以用printf代替cout输出
    cout << endl; 
    */
    // ---------------------------------------------------------------------------------------------------------   






    // ----------------------------------------------指针常量、常量指针-----------------------------------------------   
    /*
    int m = 10;
    const int n = 20; // const常量必须在定义的同时初始化
 
    const int *ptr1 = &m;  // 常量指针是被指向的对象是常量。即常量的指针，指向的内容不可改变。但可以改变指向的地方
    int *const ptr2 = &m; // 指针常量指的是指针本身是常量。即指针是常量，不可以指向其他的地方。但可以改变指向的内容
 
    ptr1 = &n;    // 正确，ptr1可以改变指向的地方
    // ptr2 = &n; // 错误，ptr2不能改变指向的地方。
 
    // *ptr1 = 3; // 错误，ptr1不能改变指向的内容。
    *ptr2 = 4;    // 正确，ptr2可以改变指向的内容。
 
    // int *ptr3 = &n;    // 错误，常量地址不能初始化普通指针，常量地址只能赋值给常量指针，因为要保证"指向的内容不可改变"
    const int *ptr4 = &n; // 正确，常量地址只能赋值给常量指针，指向的内容不可改变。
 
    // int *const ptr5; // 错误，指针常量定义时必须初始化
    // ptr5 = &m; // 错误，指针常量不能在定义后赋值
 
    const int *const ptr6 = &m; // 第一个const修饰指针指向的内容，第二个const修饰指针。
                                // 指向“常量”的指针常量，具有常量指针和指针常量的特点，指针内容不能改变，也不能指向其他地方，定义同时要进行初始化
    // *ptr6 = 5; // 错误，不能改变指针内容
    // ptr6 = &n; // 错误，不能指向其他地方
 
    const int *ptr7; // 正确
    ptr7 = &m; // 正确
 
    // int *const ptr8 = &n; // 错误，常量地址只能赋值给常量指针，不能给指针常量
    // *ptr8 = 8;  

    */
    // ---------------------------------------------------------------------------------------------------------    



    



    // ----------------------------------------------结构体 struct-----------------------------------------------      

    struct Books book1;  // 定义结构体类型 Books 的变量 Book1
    Books book2;         // 前面不加struct关键词，编译器也可以识别到结构体类型

    // Book1 详述
    strcpy( book1.title, "C++ 教程");
    strcpy( book1.author, "Runoob"); 
    strcpy( book1.subject, "编程语言");
    book1.book_id = 1;
    
    // Book2 详述
    strcpy( book2.title, "CSS 教程");
    strcpy( book2.author, "Runoob");
    strcpy( book2.subject, "前端技术");
    book2.book_id = 2;
 
    // 输出 Book1 信息
    printBook_1( book1 );
    cout << endl;

    // 输出 Book2 信息
    printBook_ptr_2( &book2 );
    cout << endl;


    struct Papers paper1;     // 一般地，不管有没有struct关键词，编译器都可以识别到结构体
    Papers paper2;         
    // struct paper  paper3;  // 如果是typedef起的别名，那么别名前不能加struct关键词，否则g++编译器会报错
    paper  paper3;         
    // struct papers  paper4;  // 如果是typedef起的别名，那么别名前不能加struct关键词，否则g++编译器会报错  
    papers paper4;         

    // paper1 详述
    strcpy( paper1.title, "a");
    strcpy( paper1.author, "aa"); 
    strcpy( paper1.subject, "aaa");
    paper1.paper_id = 1;
    
    // paper2 详述
    strcpy( paper2.title, "b");
    strcpy( paper2.author, "bb"); 
    strcpy( paper2.subject, "bbb");
    paper2.paper_id = 2;
 
    // paper3 详述
    strcpy( paper3.title, "c");
    strcpy( paper3.author, "cc"); 
    strcpy( paper3.subject, "ccc");
    paper3.paper_id = 3;

    // paper4 详述
    strcpy( paper4.title, "d");
    strcpy( paper4.author, "dd"); 
    strcpy( paper4.subject, "ddd");
    paper4.paper_id = 4;

    // 输出 paper1 信息
    printPaper_1( paper1 );
    cout << endl;

    // 输出 paper2 信息
    printPaper_ptr_2( &paper2 );
    cout << endl;

    // 输出 paper3 信息
    printPaper_3( paper3 );
    cout << endl;

    // 输出 paper4 信息
    printPaper_ptr_4( &paper4 );
    cout << endl;




    
    // ---------------------------------------------------------------------------------------------------------    

    



    //------------------------------------------------类与对象-------------------------------------------------- 
    /*

    //-----------构造函数 & 析构函数 &  拷贝构造函数-----------
    double volume = 0.0;     // 用于存储体积

    Box Box1;      //自动调用缺省构造函数Box::Box();  
    // box 1 的体积
    volume = Box1.getVolume();
    cout << "Box1 的体积：" << volume <<endl;
    Box1.display();
    cout << endl;
 
    Box Box2(12.0, 13.0, 10.0, 100);     //带部分缺省参数值的构造函数   Box::Box(double len, double b = 0.0, double h = 0.0);
    // box 2 的体积
    volume = Box2.getVolume();
    cout << "Box2 的体积：" << volume <<endl;
    Box2.display();
    cout << endl;

    Box Box3;      //自动调用缺省构造函数Box::Box();  
    // box 3 详述
    Box3.setLength(6.0); 
    Box3.setBreadth(7.0); 
    Box3.setHeight(5.0);
    // box 3 的体积
    volume = Box3.getVolume();
    cout << "Box3 的体积：" << volume <<endl;
    Box3.display();
    cout << endl;

    Box Box4 = Box2; // 这里调用了拷贝构造函数
    cout << endl;
    //-------------------------------------------------------

    //-----------this 指针  指向类的指针（ ->访问符 ）-----------
    Box* p = NULL;
    p = Box1.get_address();  
    cout << "Box1 的地址:" << p << endl;
    p = & Box1;
    // cout << "Box1 的地址:" << p << endl;
    cout << "Volume of Box1: " << p->getVolume() << endl;
    
    // p = Box2.get_address();
    // cout << "Box2 的地址:" << p << endl; 
    p = & Box2;
    cout << "Box2 的地址:" << p << endl;
    cout << "Volume of Box2: " << p->getVolume() << endl;

    // p = Box3.get_address();
    // cout << "Box3 的地址:" << p << endl; 
    p = & Box3;
    cout << "Box3 的地址:" << p << endl;
    cout << "Volume of Box3: " << p->getVolume() << endl;

    // p = Box4.get_address();
    // cout << "Box4 的地址:" << p << endl; 
    p = & Box4;
    cout << "Box4 的地址:" << p << endl;
    cout << "Volume of Box4: " << p->getVolume() << endl;
    cout << endl;
    
    // 输出对象的总数
    cout << "Total objects: " << Box::objectCount << endl;
    // 输出对象的总数
    cout << "Final Stage Count: " << Box::getCount() << endl;
    cout << endl;
    //-------------------------------------------------------

    //-------------使用友元函数输出成员信息,和Box::display();效果相同-------------------
    cout << "Box5" << endl;
    Box Box5; 
    Box5.display();
    cout << endl;

    printMember( Box5 );
    cout << endl;
    //-------------------------------------------------------

    //----------------使用友元类,和Box::display();效果相同-------------------
    cout << "Box6" << endl;
    Box Box6;   //缺省拷贝构造函数
    Box6.display();
    cout << endl;    

    Boxfriend Box_friend;
    Box_friend.setBox(1.0, 2.0, 3.0, 100, Box6);
    Box_friend.displayBox( Box6 );
    cout << endl;
    //-------------------------------------------------------

    */
    // ---------------------------------------------------------------------------------------------------------  


    // --------------------------------------------------重载运算符和重载函数--------------------------------------------------------------------------------------
    /*
    // 重载函数
    PrintData pd;
 
    // 输出整数
    int i = 5;
    pd.print(i);
    // 输出浮点数
    double f = 500.263;
    pd.print(f);
    // 输出字符数组
    char c[] = "Hello C++  c";    // 调用的是void print(char *c),在编译器看来, 形参char c[]就是形参char *c .void print(char c[]) = void print(char *c)
    pd.print(c);
    // 输出字符指针指向内容                       // 我们要习惯用char[]存储字符串常量“xxx”，而不是用字符指针char * 指向字符串常量, 不然会warning
    // char *pc = "Hello C++  pointer c";    // warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
    // pd.print(pc);   


    // 重载运算符
    PrintData pd1;
    pd1.display();
    PrintData pd2(10.0, 20.0, 30.0);
    pd2.display();
    PrintData pd3(40.0, 50.0, 60.0);
    pd3.display();    

    PrintData pd4;
    // 把两个对象相加，得到 pd3
    pd4 = pd1 + pd2 + pd3;
    pd4.display();
    
    */
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------



    // --------------------------------------------------------------------------------继承--------------------------------------------------------------------------------
    
    // ----------------------------简单对象掉用----------------------------------------------
    /*

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Rectangle Rect_0;" << endl;
    Rectangle Rect_0;  
    // _Rectangle Rect_0;
    cout << "调用派生类同名函数_Rectangle::print();" << endl;
    Rect_0.print();
    cout << "强制调用基类同名函数_Shape::print();" << endl;
    Rect_0.Shape::print(); 
    // Rect_0._Shape::print();
    cout << "----------------------------------------------------------------------" << endl;


    cout << "----------------------------------------------------------------------" << endl;
    cout << "_Rectangle Rect_1;"<< endl;
    Rectangle Rect_1(10, 20, 30, 40, 50, 60, 3);
    // _Rectangle Rect_1(10, 20, 30, 40, 50, 60, 3);     // 倒数第二个参数,会存储在动态内存中;  最后一个参数是unsigned int , 为0,说明我们不想分配动态内存给数, 非0,说明我们想分配动态内存给数组     
    cout << "调用派生类同名函数_Rectangle::print();" << endl;
    Rect_1.print();
    cout << "强制调用基类同名函数_Shape::print();" << endl;
    Rect_1.Shape::print();
    // Rect_1._Shape::print();
    cout << "----------------------------------------------------------------------" << endl;

    cout << "----------------------------------------------------------------------" << endl;
    cout << "_Rectangle Rect_2(Rect_1);"<< endl;
    Rectangle Rect_2(Rect_1);  
    // _Rectangle Rect_2 = Rect_1;
    cout << "调用派生类同名函数_Rectangle::print();" << endl;
    Rect_2.print();
    cout << "强制调用基类同名函数_Shape::print();" << endl;
    Rect_2.Shape::print();
    // Rect_2._Shape::print();
    cout << "----------------------------------------------------------------------" << endl;

    */
    // ----------------------------------------------------------------------------------------   
    

    // ---------（多态）虚函数--通过基类指针或基类对象引用时,Virtual虚函数才有多态性, 才能实现动态链接------ 
    /*

    //  *重载函数：函数名和返回值类型可以相同，但是参数列表不能相同
    //  *（多态）虚函数：继承中的概念。函数名、返回值类型、参数列表都相同，需要在声明时加Virtual关键字
    //  *每个子类（派生类）都有一个相同声明的函数的独立实现。这就是多态的一般使用方式。
    //  *对于Virtual虚函数，只是通过基类（父类）指针或基类（父类）引用时才有多态性。
    //  *如果没有基类（父类）指针，有无Virtual关键字，对于我们来说没有区别。
    
    // (多态)虚函数,试验有无virtual关键词的区别
    Shape sha(1, 2);  //如果基类_Shape中有至少一个纯虚函数,则基类_Shape为抽象类, 抽象类不能建立对象. 但是可以说明抽象类的指针或引用
    // _Shape sha(1, 2);
    cout << "----------------------------------------------------------------------" << endl;
    Rectangle rec(10, 20, 30, 40, 50, 60, 3);  
    // _Rectangle rec(10, 20, 30, 40, 50, 60, 3);  
    cout << "----------------------------------------------------------------------" << endl;
    Triangle  tri(100, 200, 300, 400, 500, 600, 4);
    // _Triangle  tri(100, 200, 300, 400, 500, 600, 4);
    cout << "----------------------------------------------------------------------" << endl;

    // 从下面可以看到无virtual关键词, 都是静态链接。 函数调用在程序执行前就准备好了
    print_by_base_pointer(&sha);
    // _print_by_base_pointer(&sha);
    cout << "----------------------------------------------------------------------" << endl;
    print_by_base_pointer(&rec);
    // _print_by_base_pointer(&rec);
    cout << "----------------------------------------------------------------------" << endl;
    print_by_base_pointer(&tri);
    // _print_by_base_pointer(&tri);
    cout << "----------------------------------------------------------------------" << endl;

    // 从下面可以看到有virtual关键词, 是动态链接。 函数调用在程序执行前就准备好了

    print_by_base_pointer_virtual(&sha);
    // _print_by_base_pointer_virtual(&sha);
    cout << "----------------------------------------------------------------------" << endl;
    print_by_base_pointer_virtual(&rec);
    // _print_by_base_pointer_virtual(&rec);
    cout << "----------------------------------------------------------------------" << endl;
    print_by_base_pointer_virtual(&tri);
    // _print_by_base_pointer_virtual(&tri);
    cout << "----------------------------------------------------------------------" << endl;
 
    
    //如果基类_Shape中有至少一个纯虚函数,则基类_Shape为抽象类, 抽象类不能建立对象. 但是可以说明抽象类的指针或引用
    Shape *shape;  
    // _Shape *shape;  

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 getArea()
    shape->getArea();
 
    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 getArea()
    shape->getArea();
    cout << "----------------------------------------------------------------------" << endl;
    
    */
    // ----------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------------------------------------------------------------------
    




    // --------------------------------------------------------------------模板---------------------------------------------------------------------------
    // --------------------------------------------函数模板--------------------------------------------
    /*
    int a = -15, b = 23;
    double c = 50.678, d = 32.089;
    string s1 = "Hello", s2 = "World";

    // 编译器从调用max(a,b)的实参a,b中推导出函数模板中的T为int
    cout << "template_max(a, b):" << setw(20) << template_max(a, b) << endl;
    // 编译器从调用max(c,d)的实参c,d中推导出函数模板中的T为double
    cout << "template_max(c, d):" << setw(20) << template_max(c, d) << endl;
    // 编译器从调用max(s1,s2)的实参s1,s2中推导出函数模板中的T为string
    cout << "template_max(s1, s2):" << setw(20) << template_max(s1, s2) << endl;
    cout << endl;


    int size = 5;
    int array1[size] = {1, 2, 3, 4, 5};
    int array2[size] = {10, 20, 30, 40, 50};
    double array3[size] = {3.1, 3.2, 3.3, 3.4, 3.5};
    double array4[size] = {6.1, 6.2, 6.3, 6.4, 6.5};
    
    cout << "array1[]:";
    template_print_array(array1, size);

    template_addarray(array1,array2,size);
    cout << "After addarray();  array1[]:";
    template_print_array(array1, size);
    cout << endl;

    cout << "array3[]:";
    template_print_array(array3, size);

    template_addarray(array3,array4,size);
    cout << "After addarray();  array3[]:";
    template_print_array(array3, size);
    cout << endl;

    char array5[size] = {'a', 'b', 'c', 'd', 'e'};
    char array6[size] = {'a', 'b', 'c', 'd', '\0'};  
    char array7[size] = {'a', 'b', 'c', 'd'};       
    cout << "array5[]:";
    template_print_array(array5, size);    
    cout << "array6[]:";
    template_print_array(array6, size);   
    cout << "array7[]:";
    template_print_array(array7, size);   
    cout << endl;
    
    */
    // ----------------------------------------------------------------------------------------------
    // --------------------------------------------类模板--------------------------------------------
    
    // 类模板实例化建立对象的形式如下:(只是加了一个<实际参数表>)
    //类名 <实际参数表> 对象名1,...,对象名n;
    
    //-------------------template_class_array--------------------------
    /*

    int i;
    // 模板参数T设置成int, 对象m调用构造函数,分配3个连续单元的动态内存,并初始化为0
    Template_Array<int> m(3);  
    for(i=0; i<3; i++)
    {
        m.SetELem(i, i*10);
        cout << m.GetELem(i) <<" ";
    }
    cout << endl;
    m.SetELem(5, -1);

    Template_Array<double> x(5);
    for(i=0; i<5; i++)
    {
        x.SetELem(i,i+10.5);
        cout << x.GetELem(i) <<" ";
    }
    cout << endl;
    x.GetELem(i);

    char p[]="abcd";
    Template_Array<char> s(4);
    for(i=0; i<4; i++)
    {
        s.SetELem(i,p[i]);
        cout << s.GetELem(i) <<" ";
    }    
    cout << endl;

    */
    //------------------------------------------------------------------
    
    //-------------------template_class_stack--------------------------
    /*
    try
    {
        Stack<int> intStack;       //int 类型的栈
        Stack<string> stringStack; //string 类型的栈

        // 操作 int 类型的栈
        intStack.push(7);
        cout << intStack.top() << endl;

        // 操作 string 类型的栈
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch(exception const& ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
    */
    //-------------------------------------------------------------------
    // ------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------------------------------------------------

    
    // -------------------------------------------------------------------STL（标准模板库）----------------------------------------------------------------------   
    
    // -----------------------------vector向量------------------------------------------
    /*
    
    // push_back() 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
    // size() 函数显示向量的大小。
    // begin() 函数返回一个指向向量开头的迭代器。
    // end() 函数返回一个指向向量末尾的迭代器。

    // 创建一个向量存储 int
    vector<int> vec;
    int i;

    // 显示vec的原始大小
    cout << "vector size = " << vec.size() << endl;

    // 推入5个值到向量中
    for(i = 0; i <5; i++)
    {
        vec.push_back(i);
    }

    // 显示vec扩展后的大小
    cout << "extended vector size = " << vec.size() <<endl;

    // 访问向量中的5个值
    for(i = 0; i < 5; i++)
    {
        cout << "value of vec [" << i <<"] = " << vec[i] << endl;
    }
    
    // 使用迭代器 iterator 访问值
    vector<int>::iterator v = vec.begin();
    while( v != vec.end())
    {
        cout << "value of v pointer = " << *v << endl;
        v++;
    }

    */
    // ------------------------------------------------------------------------------------
    











    
    /*
    // 在C语言中一般通过添加getchar();
    // 在C++中一般在main函数中的return之前添加system("pause")或pause();这样就可以看清楚输出的结果

    // 在windows系统下，用如下语句,控制台不会输出后马上消失。 
    // 在windows平台就是执行DOS命令
    #include <cstdlib>    
    system("pause"); 

    // 在Linux系统下，用如下语句,控制台不会输出后马上消失,需要按下Ctrl+C才可以(pause可能会输出"press any key to continue. . .")。 
    // 在linux平台就是执行shell命令
    #include <unistd.h>   
    pause(); 
    */
    cout << endl;
    pause(); // system("pause"); 


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