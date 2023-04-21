/* https://www.cnblogs.com/yc_sunniwell/archive/2010/07/14/1777431.html */

#ifndef TEST_1_H
#define TEST_1_H

// extern和static不能同时修饰一个变量；
// 其次，static修饰的全局变量声明与定义同时进行，也就是说当你在头文件中使用static声明了全局变量后，它也同时被定义了；
// 最后，static修饰全局变量的作用域只能是本身的编译单元


extern char g_extern_str[]; // 声明
static char g_static_str[] = "123456"; //static必须初始化，头文件中不能只声明 如果是static char g_static_str[];编译会报错 storage size of ‘g_static_str’ isn’t known








void fun1();
void fun2();

#endif