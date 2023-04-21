/* https://www.cnblogs.com/yc_sunniwell/archive/2010/07/14/1777431.html */

#include "test_1.h"

#include <iostream>
using namespace std;

void fun2()
{ 
    // g_extern_str[0] = 'b';    
    cout << "fun2  g_extern_str:" << g_extern_str << endl;

    // g_static_str[0] = 'b';
    cout << "fun2  g_static_str:" << g_static_str << endl;


}

