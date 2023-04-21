/* https://www.cnblogs.com/yc_sunniwell/archive/2010/07/14/1777431.html */

#include "test_1.h"

#include <iostream>
using namespace std;

char g_extern_str[] = "123456"; // 定义
const char g_extern_const_str[] = "123456"; 


// C++中const修饰的全局常量据有跟static相同的特性，即它们只能作用于本编译模块中，
// 但是const可以与extern连用来声明该常量可以作用于其他编译模块中, 如extern const char g_str[];
// 所以当const单独使用时它就与static相同，而当与extern一起合作的时候，它的特性就跟extern的一样了！ 
extern const char g_extern_const_str[]; 


// const char* g_str = "123456" 与 const char g_str[] ="123465"是不同的， 
// 前面那个const 修饰的是char* 而不是g_str,它的g_str并不是常量，它被看做是一个定义了的全局变量（可以被其他编译单元使用）， 
// 所以如果你像让char *g_str遵守const的全局常量的规则，最好这么定义const char* const g_str="123456".
// const char g_const_str[] = "123456";                //cosnt必须初始化，头文件中不能只声明 如果是const char g_const_str[];编译会报错 uninitialized const ‘g_const_str’ 和 报错storage size of ‘g_const_str’ isn’t known

// const char*不能在这里定义，因为会被test_1.cpp和test_2.cpp同时创建，
// const char* g_const_pointer_str = "123456";        // const char*指针指向的内容是固定的，不可改变的。对传入的参数，不会对指针指向的内容进行修改

void fun1()
{   
    g_extern_str[0] = 'e';
    cout << "fun1  g_extern_str:" << g_extern_str << endl;

    g_static_str[0] = 's';
    cout << "fun1  g_static_str:" << g_static_str << endl;

    // g_extern_const_str[0] = "c" // const不能修改
    // cout << "fun1  g_extern_const_str:" << g_extern_const_str << endl;




}

