#include "ab_class.h"

// --------------------------------------------------_AB类---------------------------------------------------- 


// AB缺省构造函数
AB::AB():aa(0), bb(0)                                                        // classname::classname():[数据成员初始化表]
{
    // aa = 0;   // 函数名后如果跟了数据成员初始化表aa(0),就不用aa = 0; 因为本质一样.   
    // bb = 0;   
    cout << "AB缺省构造函数" << endl;
}
// AB带部分缺省参数值的构造函数
AB::AB(int i, int j):aa(i), bb(j)                                           // classname::classname():[数据成员初始化表]
{
    // aa = i;  // 函数名后如果跟了数据成员初始化表aa(i),就不用aa = i; 因为本质一样.    
    // bb = j;   
    cout << "AB带部分缺省参数值的构造函数" << endl;  
}
// AB拷贝构造函数
AB::AB(const AB &obj): aa(obj.aa), bb(obj.bb)                                // classname::classname():[数据成员初始化表]
{

    // aa = obj.aa;    // 函数名后如果跟了数据成员初始化表aa(obj.aa),就不用aa = obj.aa; 因为本质一样.   
    // bb = obj.bb; 
    cout << "AB拷贝构造函数" << endl;
}
// AB析构函数声明
AB::~AB()
{
    cout << "AB析构函数" << endl; 
}


void AB::print()
{
    cout << setw(20) << " AB: " << setw(20) << " aa = " << aa << setw(20) << " bb = " << bb <<  endl;
}

// ------------------------------------------------------------------------------------------------------ 