```c++
#include <iostream>  
#include <vector> 
#include <string>
#include <algorithm>

#include <fstream>
#include <sstream>

using namespace std; 

int main()
{


    // OJ在线编程常见输入输出练习
    // https://ac.nowcoder.com/acm/contest/5657#question

    // 1
    // int a, b;
    // while(cin >> a >> b) {
    //     cout << a + b << endl;
    // }
    
    

    // 2
    // int lines, a, b;
    // cin >> lines;
    // for(int i = 0; i < lines; i++) {
    //     cin >> a >> b;
    //     cout << a + b << endl;
    // }



    // 3
    // int a, b;
    // while(cin >> a >> b) {
    //     if(a == 0 && b == 0) break;
    //     cout << a + b << endl;
    // }



    // 4
    // int length;

    // while(cin >> length) {
    //     if(length == 0) break;

    //     vector<int> nums(length); // 长度为length，每个位置默认值为0. 效果和vector<int> nums(length， 0);相同

    //     int sum = 0;
    //     for(int i=0; i < length; i++) {
    //         int temp;
    //         cin >> temp;
    //         sum += temp;
    //         // nums[i] = temp;
    //     }
    //     cout << sum << endl;

    //     // cout << "{";
    //     // for(int i=0; i < nums.size(); i++) {
    //     //     cout << nums[i] << ", ";
    //     // }
    //     // cout << "}" << endl;        
    // }




    // 5
    // int lines;
    // cin >> lines;

    // int length;
    // for(int line=0; line < lines; line++) {
    //     cin >> length; 
    //     if(length == 0) break;

    //     vector<int> nums(length); // 长度为length，每个位置默认值为0. 效果和vector<int> nums(length， 0);相同

    //     int sum = 0;
    //     for(int i=0; i < length; i++) {
    //         int temp;
    //         cin >> temp;
    //         sum += temp;
    //        // nums[i] = temp;
    //     }
    //     cout << sum << endl;

    //     // cout << "{";
    //     // for(int i=0; i < nums.size(); i++) {
    //     //     cout << nums[i] << ", ";
    //     // }
    //     // cout << "}" << endl;        
    // }



    // 6
    // int length;

    // while(cin >> length) {
    //     vector<int> nums(length); // 长度为length，每个位置默认值为0. 效果和vector<int> nums(length， 0);相同

    //     int sum = 0;
    //     for(int i=0; i < length; i++) {
    //         int temp;
    //         cin >> temp;
    //         sum += temp;
    //         // nums[i] = temp;
    //     }
    //     cout << sum << endl;

    //     // cout << "{";
    //     // for(int i=0; i < nums.size(); i++) {
    //     //     cout << nums[i] << ", ";
    //     // }
    //     // cout << "}" << endl;        
    // }




    // 7
    // int temp;
    // int sum = 0;

    // while(cin >> temp) {
    //     sum += temp;
    //     while(cin.get() == '\n') { //检测当前数字temp之后紧跟的是不是换行符
    //         cout << sum << endl; 
    //         sum = 0;
    //     }
    // }
    // // 在c++中，时常会搞不清楚cin与cin.get()的区别，那么到底两者之间的区别是什么呢？
    // // cin在遇到‘ ’（空格）时，会结束输入
    // // cin.get()用来接收字符或字符串，遇到‘ ’（空格）时，不会结束输入, 而是读取
    //     // 参考博客：https://blog.csdn.net/weixin_45878105/article/details/108903554
    //     // cin.get(字符变量名)可以用来接收字符.                    char ch;    cin.get(ch); //或者cin.get(ch);
    //     // cin.get(字符数组名,接收字符数目)用来接收一行字符串        char a[20];  cin.get(a,20);
    //     // cin.get(无参数)没有参数主要是用于舍弃输入流中的不需要的字符,或者舍弃回车,弥补cin.get(字符数组名,接收字符数目)的不足




    // 8
    // int length;
    // vector<string> str;
    // string s;
    
    // // 输入
    // cin >> length;
    // for(int i=0; i < length; i++) {
    //     cin >> s;
    //     str.push_back(s);
    // }

    // // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
    // sort(str.begin(), str.end());
    
    // // 输出
    // for(int i=0; i < str.size(); i++) {
    //     cout << str[i];
    //     if(i != str.size() - 1) cout << " "; // if(i!=str.size()-1) cout<<' ';
    // }




    // 9
    // vector<string> str;
    // string s;

    // // 输入
    // while(cin >> s) {
    //     str.push_back(s);
    //     if(cin.get() == '\n') { //检测当前数字temp之后紧跟的是不是换行符
    //         // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
    //         sort(str.begin(), str.end());
    
    //         // 输出
    //         for(int i=0; i < str.size(); i++) {
    //             cout << str[i];
    //             cout << " "; // 每个字符串通过空格隔开, 不然就是if(i!=str.size()-1) cout<<' ';
    //         }
    //         cout << endl;

    //         // 下一行
    //         str.clear(); 
    //     }
    // }




    // 10 - 方法一
    // vector<string> str;
    // string s;

    // // 由于每行没有空格，则cin读取就是一行内容，然后我们再进行分割
    // while(cin >> s) {
    //     // 分割
    //     string temp; // string temp = "";
    //     for(int i=0; i < s.size(); i++) {
    //         if(s[i] != ',') {
    //             temp += s[i];
    //         }
    //         else {
    //             str.push_back(temp);
    //             temp.clear();
    //         }
    //     }
        
    //     //每一行最后一个字符串后面没有逗号，故需要单独添加
    //     str.push_back(temp);
        
    //     // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
    //     sort(str.begin(), str.end());
    
    //     // 输出
    //     for(int i=0; i <= str.size()-2; i++) {
    //         cout << str[i];
    //         cout << ","; 
    //     }
    //     cout << str[str.size() - 1] << endl;

    //     str.clear();
    // }




    // 10 - 方法二
    // vector<string> str;
    // string s;

    // // 输入
    // // getline(cin, s) 从输入流中读取一行赋给s, 只要一遇到换行符就结束读取操作并返回结果，哪怕输入的一开始就是换行符也是如此. 如果输入真的一开始就是换行符，那么所得的结果是个空string。
    // // getline(cin, s ,ch) //从输入流中读取内容，赋给s，直到遇到字符ch，返回结果。
    
    // // 由于每行没有空格，则cin读取就是一行内容，然后我们再进行分割
    // while(cin >> s) {
    //     //定义一个stringstream对象,把读取的一整行交给这个对象
    //     stringstream ss(s); // #include<sstream>
    //     string temp;

    //     //把这个对象交给getline，就像是把cin交给getline一样
    //     while(getline(ss,temp,',')) {   // getline(cin, s ,ch) //从输入流中读取内容，赋给s，直到遇到字符ch，返回结果。
    //         str.push_back(temp);
    //     }
    //     // 每一行最后一个字符串后面没有逗号，则最后一个逗号之后的内容都放入temp
            
    //     // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
    //     sort(str.begin(), str.end());
    
    //     // 输出
    //     for(int i=0; i <= str.size()-2; i++) {
    //         cout << str[i];
    //         cout << ","; 
    //     }
    //     cout << str[str.size() - 1] << endl;

    //     str.clear();
    // }



    return 0;
}

```














