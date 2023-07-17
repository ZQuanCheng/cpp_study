### 之前都用的leetcode，但是笔试很多用牛客，需要自己会写输入输出


#### OJ答题模板

```c++
// https://blog.csdn.net/weixin_43202635/article/details/107498312
// 其实这是一个包含了C++所有头文件的一个头文件，为了方便而发明的
// 一般地，oj都支持include<bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

int main() {


    return 0;
}
```




#### OJ在线编程常见输入输出练习

> 牛客OJ在线编程常见输入输出练习
>
> https://www.nowcoder.com/exam/test/71014353/detail?pid=27976983#question
>
> 
> 牛客OJ在线编程常见输入输出练习场（有很多人答案）
> 
> https://ac.nowcoder.com/acm/contest/5657#question
> 


> 参考博客：
>
> https://blog.csdn.net/weixin_47062406/article/details/124517291
> 
> 


> 我的答案：
>
> https://www.nowcoder.com/exam/test/71014353/submission?pid=27976983
>
> 

> 
> <font color="yellow">第1题</font>
>
> ```c++
> #include <iostream>  
> using namespace std; 
> 
> int main()
> {
>     int a, b;
>     while(cin >> a >> b) {
>         cout << a + b << endl;
>     }
> 
>     return 0;
> }
> ```
>
> 



> 
> <font color="yellow">第2题</font>
>
> ```c++
> #include <iostream>  
> using namespace std; 
> 
> int main()
> {
>     int lines, a, b;
>     cin >> lines;
>     for(int i = 0; i < lines; i++) {
>         cin >> a >> b;
>         cout << a + b << endl;
>     }
> 
>     return 0;
> }
> ```
>




> 
> <font color="yellow">第3题</font>
>
> ```c++
> #include <iostream>  
> using namespace std; 
> 
> int main()
> {
>     int a, b;
>     while(cin >> a >> b) {
>         if(a == 0 && b == 0) break;
>         cout << a + b << endl;
>     }
>     return 0;
> }
> ```
> 
> 





> 
> <font color="yellow">第4题</font>
>
> ```c++
> #include <iostream>  
> // #include <vector>
> using namespace std; 
> 
> int main()
> {
>     int n;
> 
>     while(cin >> n) {
>         if(n == 0) break;
> 
>         // vector<int> nums(n); // 长度为n，每个位置默认值为0. 效果和vector<int> nums(n， 0);相同
> 
>         int sum = 0;
> 
>         for(int i=0; i < n; i++) {
>             int temp;
>             cin >> temp;
>             sum += temp;
>             // nums[i] = temp;
>         }
>         cout << sum << endl;
> 
>         // cout << "{";
>         // for(int i=0; i < nums.size(); i++) {
>         //     cout << nums[i] << ", ";
>         // }
>         // cout << "}" << endl;        
>     }
> 
>     return 0;
> }
> ```
>







> 
> <font color="yellow">第5题</font>
>
> ```c++
> #include <iostream>  
> // #include <vector>
> using namespace std; 
> 
> int main()
> {
>     int t;
>     cin >> t;
> 
>     
>     for(int line=0; line < t; line++) {
>         int n;
>         cin >> n; 
> 
>         // vector<int> nums(n); // 长度为n，每个位置默认值为0. 效果和vector<int> nums(n， 0);相同
> 
>         int sum = 0;
>         for(int i=0; i < n; i++) {
>             int temp;
>             cin >> temp;
>             sum += temp;
>            // nums[i] = temp;
>         }
>         cout << sum << endl;
> 
>         // cout << "{";
>         // for(int i=0; i < nums.size(); i++) {
>         //     cout << nums[i] << ", ";
>         // }
>         // cout << "}" << endl;        
>     }
> 
>     return 0;
> }
> ```
>





> 
> <font color="yellow">第6题</font>
>
> ```c++
> #include <iostream>  
> // #include <vector>
> using namespace std; 
> 
> int main()
> {
>     int n;
> 
>     while(cin >> n) {
>         // vector<int> nums(n); // 长度为n，每个位置默认值为0. 效果和vector<int> nums(n， 0);相同
> 
>         int sum = 0;
>         for(int i=0; i < n; i++) {
>             int temp;
>             cin >> temp;
>             sum += temp;
>             // nums[i] = temp;
>         }
>         cout << sum << endl;
> 
>         // cout << "{";
>         // for(int i=0; i < nums.size(); i++) {
>         //     cout << nums[i] << ", ";
>         // }
>         // cout << "}" << endl;        
>     }
> 
> 
>     return 0;
> }
> ```
>





> 
> <font color="yellow">第7题</font>
>
> ```c++
> #include <iostream>  
> using namespace std; 
> 
> int main()
> {
>     int temp;
>     int sum = 0;
> 
>     while(cin >> temp) {
>         sum += temp;
>         while(cin.get() == '\n') { //检测当前数字temp之后紧跟的单个字符，是不是换行符
>             cout << sum << endl; 
>             sum = 0;
>         }
>     }
>     // 在c++中，时常会搞不清楚cin与cin.get()的区别，那么到底两者之间的区别是什么呢？
>     // cin在遇到‘ ’（空格）时，会结束输入
>     // cin.get()用来接收字符或字符串，遇到‘ ’（空格）时，不会结束输入, 而是读取
>         // 参考博客：https://blog.csdn.net/weixin_45878105/article/details/108903554
>         // cin.get(字符变量名)可以用来接收字符.                    char ch;    cin.get(ch); //或者cin.get(ch);
>         // cin.get(字符数组名,接收字符数目)用来接收一行字符串        char a[20];  cin.get(a,20);
>         // cin.get(无参数)没有参数主要是用于舍弃输入流中的不需要的字符,或者舍弃回车,弥补cin.get(字符数组名,接收字符数目)的不足
> 
>     return 0;
> }
> ```
>







> 
> <font color="yellow">第8题</font>
>
> ```c++
> #include <iostream>  
> #include <vector>
> #include <string>
> #include <algorithm>
> using namespace std; 
> 
> int main()
> {
>     int n;
>     cin >> n;    
>     
>     // 输入
>     vector<string> str;
>     for(int i=0; i < n; i++) {
>         string s;
>         cin >> s;
>         str.push_back(s);
>     }
> 
>     // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
>     sort(str.begin(), str.end()); // #include <algorithm>
>     
>     // 输出
>     for(int i=0; i < str.size() - 1; i++) {
>         cout << str[i] << " ";
>     }
>     cout << str[str.size() - 1] << endl;
> 
>     return 0;
> }
> ```
> 
> <font color="yellow">或者</font>
>
> ```c++
> #include <iostream>  
> #include <vector>
> #include <string>
> #include <algorithm>
> using namespace std; 
> 
> int main()
> {
>     int n;
>     cin >> n;    
>     
>     // 输入
>     vector<string> str(n); // 长度为n
>     for(int i=0; i < n; i++) {
>         string s;
>         cin >> s;
>         str[i] = s;
>     }
> 
>     // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
>     sort(str.begin(), str.end()); // #include <algorithm>
>     
>     // 输出
>     for(int i=0; i < n - 1; i++) {  // 先输出n-1个
>         cout << str[i] << " ";
>     }
>     cout << str[n - 1] << endl;    // 最后一个单独输出
> 
>     return 0;
> }
> ```
>
> 




> 
> <font color="yellow">第9题</font>
>
> ```c++
> #include <iostream>  
> #include <vector>
> #include <string>
> #include <algorithm>
> using namespace std; 
> 
> int main()
> {
>     vector<string> str;
>     string s;
> 
>     // 输入
>     while(cin >> s) {
>         str.push_back(s);
>         if(cin.get() == '\n') { //检测当前数字temp之后紧跟的单个字符，是不是换行符
>             // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
>             sort(str.begin(), str.end()); // #include <algorithm>
>     
>             // 输出
>             for(int i=0; i < str.size() - 1; i++) {  // 先输出n-1个
>                 cout << str[i] << " ";
>             }
>             cout << str[str.size()-1] << endl;  // 最后一个单独输出
> 
>             // 下一行
>             str.clear(); 
>         }
>     }
> 
> 
>     return 0;
> }
> ```
>







> 
> <font color="yellow">第10题</font>
> 
> <font color="yellow">流处理</font>
>
> ```c++
> #include <iostream> 
> #include <vector>
> #include <string> 
> #include <sstream>
> using namespace std; 
> 
> int main()
> {
>     vector<string> str;
>     string s;
> 
>     // 输入
>     // getline(cin, s) 从输入流中读取一行赋给s, 只要一遇到换行符就结束读取操作并返回结果，哪怕输入的一开始就是换行符也是如此. 如果输入真的一开始就是换行符，那么所得的结果是个空string。
>     // getline(cin, s ,ch) //从输入流中读取内容，赋给s，直到遇到字符ch，返回结> 果。
>     
>     // 由于每行没有空格，则cin读取就是一行内容，然后我们再进行分割
>     while(cin >> s) {
>         //定义一个stringstream对象,把读取的一整行交给这个对象
>         stringstream ss(s); // #include<sstream>
>         string temp;
> 
>         //把这个对象交给getline，就像是把cin交给getline一样
>         while(getline(ss,temp,',')) {   // getline(cin, s ,ch) //从输入流中读取内容，赋给s，直到遇到字符ch，返回结果。
>             str.push_back(temp);
>         }
>         // 每一行最后一个字符串后面没有逗号，则最后一个逗号之后的内容都放入temp
>             
>         // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
>         sort(str.begin(), str.end());
>     
>         // 输出
>         for(int i=0; i < str.size() - 1; i++) {  // 先输出n-1个
>             cout << str[i] << ","; 
>         }
>         cout << str[str.size() - 1] << endl;  // 最后一个单独输出
> 
>         str.clear();
>     }
> 
> 
>     return 0;
> }
> ```
> 
> <font color="yellow">不用流处理</font>
>
> ```c++
> #include <iostream>  
> #include <vector>
> #include <string>
> #include <algorithm> 
> using namespace std; 
> 
> int main()
> {
>     vector<string> str;
>     string s;
> 
>     // 由于每行没有空格，则cin读取就是一行内容，然后我们再进行分割
>     while(cin >> s) {
>         // 分割
>         string temp; // string temp = "";
>         for(int i=0; i < s.size(); i++) {
>             if(s[i] != ',') {
>                 temp += s[i];
>             }
>             else {
>                 str.push_back(temp);
>                 temp.clear();
>             }
>         }
>         
>         //每一行最后一个字符串后面没有逗号，故需要单独添加
>         str.push_back(temp);
>         
>         // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
>         sort(str.begin(), str.end()); // #include <algorithm>
>     
>         // 输出
>         for(int i=0; i < str.size() - 1; i++) {  // 先输出n-1个
>             cout << str[i] << ","; 
>         }
>         cout << str[str.size() - 1] << endl;  // 最后一个单独输出
> 
>         str.clear();
>     }
> 
>     return 0;
> }
> ```
>



> 
> <font color="yellow">第11题</font>
>
> ```c++
> #include <iostream>
> using namespace std;
> 
> int main() {
>     long a, b;  // 求和可能突破int范围，所以要用long
> 
>     while(cin >> a >> b) {
>         cout << a + b << endl;
>     }
> 
>     return 0;
> }
> ```
> 








#### 补充知识


##### `cin`与`cin.get()`与`getline()`

>
> 对于非文件类型的内容，一般是相当于`读取命令行的输入`、`在命令行界面输出`
> 
> 输入有三种：`cin`、`cin.get()`、`getline()`
>
> 输出有一种：`cout`
> 
> 
> <font color="yellow">在`c++`中，时常会搞不清楚`cin`与`cin.get()`与`getline()`的区别，那么到底两者之间的区别是什么呢？</font>
>
> `区别1：` 
> 
> > * `cin`在遇到`‘ ’（空格）`时，会`结束输入`
> > 
> > * `cin.get()`用来接收字符或字符串，遇到`‘ ’（空格）`时，不会结束输入, 而是读取；遇到换行符`‘\n’`就结束读取操作并返回结果。
> > 
> > * `getline()`用来读取一行字符串，遇到`‘ ’（空格）`时，不会结束输入, 而是读取；遇到换行符`‘\n’`就结束读取操作并返回结果。
> > 
> 
>
> 这样看，`cin.get()`和`getline()`比较相似，可以读取空格，但是遇到换行符就停止，只读取到换行符前的最后一个字符。
>
> `区别2： `
> 
> > * `cin` 除了可以接收单个字符，还可以接收其他类型的单个变量，例如整型`int`
> > 
> > * `cin.get()`可以接收单个字符，还可以接收字符数组
> > 
> > * `getline()`接收一整行的输入，遇到`'\n'`停止，算作一行
> 
> 
> 


>
> <font color="yellow">`cin`怎么用呢？</font>
>
> > 
> > `cin` 输入接触到第一个非空格字符时开始阅读，
> > 
> > 当遇到下一个空白符（空格、制表符、换行符）时就会停止读取，
> > 
> > ```c++
> > string s;
> > printf("输入:\n");
> > cin >> s;
> > printf("输出:\n");
> > cout << s;
> > ```
> > 
> > 命令行情况如下
> > 
> > ```c++
> > 输入:
> >    152k
> > 输出:
> > 152k
> > ```
> > 
> > ```c++
> > 输入:
> > asd 845 ddd
> > 输出:
> > asd
> > ```
> > 
>
> > 
> > C++ 编译器根据要输入值的数据类型，选择合适的流提取运算符来提取值，并把它存储在给定的变量中。
> > 流提取运算符 `>>` 在一个语句中可以多次使用，如果要求输入多个数据，可以使用如下语句：
> > 
> > ```c++
> > cin >> name >> age;
> > ```
> > 
> > 这相当于下面两个语句：
> > 
> > ```c++
> > cin >> name;
> > cin >> age;
> > ```
> > 
> > 
>
> 
> <font color="gree">
> 
> 总结:
> 
> `cin`会忽略前面的空白符（空格、制表符、换行符），从第一个非空白字符开始读取，当遇到下一个空白符时停止。
>
> 即前面和后面的空白符都被忽略了
>
> </font>
>
> <font color="yellow">为了避免`cin`对于空白符的忽略问题，可以用`getline()`函数</font>
> 
> 




>
> <font color="yellow">`cin.get()`怎么用呢？</font>
> 
> > 参考博客：https://blog.csdn.net/weixin_45878105/article/details/108903554
> > 
> > **1. `cin.get(字符变量名)`可以用来接收字符.**                
> > 
> > ```c++ 
> > char ch; 
> > ch = cin.get();               //或者cin.get(ch); 
> > cout << ch << endl; 
> > ```
> > 
> > 此时，无论输入多少，在`ch`中仅保存了一个字符+'\n'，此时`cin.get()`接受到的只有两个字节。
> > 
> > ```c++
> > 输入：baijljkljkl 
> > 输出：b
> > ```
> > 
> > **2. `cin.get(字符数组名,接收字符数目)`用来接收一行字符串**     
> > 
> > ```c++ 
> > char a[20]; 
> > cin.get(a,20); 
> > cout << a << endl; 
> > ```
> > 
> > 注意，可以接收空格
> > 
> > ```c++
> > 输入：jkl jkl jkl 
> > 输出：jkl jkl jkl
> > ```
> > ```c++
> > 输入：abcdeabcdeabcdeabcdeabcde （输入25个字符） 
> > 输出：abcdeabcdeabcdeabcd              （接收19个字符+1个'\0'）
> > ```
> > 
> > 
> > **3. `cin.get(无参数)`没有参数主要是用于舍弃输入流中的不需要的字符,或者舍弃回车,弥补`cin.get(字符数组名,接收字符数目)`的不足**
> > 
> > ```c++ 
> > string a;
> > cin >> a;
> > cout << a << endl;
> > cin.get();
> > cin.get();
> > //cin.ignore(1024,'\n');
> > //cin.get();
> > ```
> > 
> > 此时的第一个`cin.get()`获取的是`cin`中最后的`'\n'`，第二个的作用在于在程序结束时输入一个字符，让程序停留在运行界面
> > 
> > 注意：此时的第一个`cin.get()`与`cin.ignore()`的用法相似，均是消除输入流中的`'\n'`
> > 
> > 
> 
> 



>
> <font color="yellow">`getline()`怎么用呢？</font>
>
> **1. `getline(cin, s)` 从输入流中读取一整行,包括前面和中间的空格，并将其存储在字符串对象`s`中**
> 
> 只要一遇到换行符就结束读取操作并返回结果，哪怕输入的一开始就是换行符也是如此. 如果输入真的一开始就是换行符，那么所得的结果是个`空string`。
>
> **2. `getline(cin, s ,ch)` 从输入流中读取内容，赋给`s`，直到遇到字符`ch`，返回结果。**
>
> ```c++
> for (int i = 0; i < 2; i++)
> {
> 	 string city, state;
> 	 getline(cin, city,',');
> 	 getline(cin, state);
> 	 cout << "City: " << city << "\t"
> 		 << "State: " << state << endl;
> }
> ```
>
> 命令行如下：
> 
> ```c++
> 输入：Beijing,China
> 输出：City: Beijing   State: China
> 输入：San Francisco,the United States
> 输出：City: San Francisco     State: the United States
> ```
> 
> <font color="gree">接下来，我们来看具体信息</font>
> > 
> > `getline()`在头文件`#include <string>`中，是普通函数，有四种重载形式。
> > 
> > ```c++
> > istream& getline(istream& is, string& str, char delim);
> >  
> > istream& getline(istream&& is, string& str, char delim);
> >  
> > istream& getline(istream& is, string& str);
> > 
> > istream& getline(istream&& is, string& str);
> > ```
> > 
> > 读取的`istream`是作为参数 `is` 传进函数的，读取的字符串保存在`string`类型的`str`中。
> > 
> > `is` : 表示一个输入流，例如`cin`
> > 
> > `str` : 为`string`类型的引用，用来存储输入流中的流信息
> > 
> > `delim` ：为`char`类型的变量，截断字符。不定义的情况下，默认遇到 `‘\n'`代表一行的输入结束。
> > 
> > 例1：
> > 
> > ```c++
> > string s;
> > printf("输入:\n");
> > getline(cin, s);
> >  
> > printf("输出;\n");
> > cout << s;
> > ```
> > 
> > 在输入时，直至遇到`'\n'`或`EOF`， 才终止一行字符串输入操作：
> > 
> > ```c++
> > 输入:
> > sd45d 54 88
> > 输出;
> > sd45d 54 88
> > ```
> > 
> > 
> > 例2：
> > 
> > ```c++
> > string s;
> > printf("输入:\n");
> > getline(cin, s,'?');
> >  
> > printf("输出;\n");
> > cout << s;
> > ```
> > 
> > 以输入遇到回车换行符`'\n'`或`EOF`作为一行字符串输入操作结束, 或者遇到设定的字符也可作为字符流读取结束：（这里设定的字符是`？`）
> > 
> > ```c++
> > 输入:
> > 48 b?hvj
> > 输出;
> > 48 b
> > ```
> > 
> 
> 




##### 流处理

> 
> <font color="yellow">第10题</font>
> 
> <font color="yellow">流处理</font>
>
> ```c++
> #include <iostream> 
> #include <vector>
> #include <string> 
> #include <sstream>
> using namespace std; 
> 
> int main()
> {
>     vector<string> str;
>     string s;
> 
>     // 输入
>     // getline(cin, s) 从输入流中读取一行赋给s, 只要一遇到换行符就结束读取操作并返回结果，哪怕输入的一开始就是换行符也是如此. 如果输入真的一开始就是换行符，那么所得的结果是个空string。
>     // getline(cin, s ,ch) //从输入流中读取内容，赋给s，直到遇到字符ch，返回结> 果。
>     
>     // 由于每行没有空格，则cin读取就是一行内容，然后我们再进行分割
>     while(cin >> s) {
>         //定义一个stringstream对象,把读取的一整行交给这个对象
>         stringstream ss(s); // #include<sstream>
>         string temp;
> 
>         //把这个对象交给getline，就像是把cin交给getline一样
>         while(getline(ss,temp,',')) {   // getline(cin, s ,ch) //从输入流中读取内容，赋给s，直到遇到字符ch，返回结果。
>             str.push_back(temp);
>         }
>         // 每一行最后一个字符串后面没有逗号，则最后一个逗号之后的内容都放入temp
>             
>         // 由于string类型内置了比较大小的操作，所以可以用sort来排序。
>         sort(str.begin(), str.end());
>     
>         // 输出
>         for(int i=0; i < str.size() - 1; i++) {  // 先输出n-1个
>             cout << str[i] << ","; 
>         }
>         cout << str[str.size() - 1] << endl;  // 最后一个单独输出
> 
>         str.clear();
>     }
> 
> 
>     return 0;
> }
> ```
> 
> https://blog.csdn.net/liuzubing/article/details/116004214
>
>
> `#include <sstream>`头文件中主要包含了`stringstream`，可以`用于进行数据格式转换`。
>
> 1.注意每当调用一次`<<`和`>>`后，`stringstream`都会设置oef标志位，oef标志位会导致后面读写操作全部失效。
> 
> 多次转换需要清除`oef`标志位 `ss.clear()`,
> 
> 或者清空缓存`ss.str("")`;
> 
> 2.重置数据类容
> 
> ```c++
> std::string test_str = "test_string"`;
> 
> ss.str(test_str); //注意返回值为void,清空缓存，最好不要放任何内容，并且把转换标志位移动到流的开始位置
> 
> ss.str();//注意返回值为string
> ```
> 
> 3.转化成`std::string`
> 
> ```c++
> `ss.str();`
> ```
>
> 4.输入各种类型的数据
> 
> ```c++
> ss << 123;
> 
> ss << "asdf";
> 
> ss << true;
> 
> ss << 2.34;
> ```
>
>
> 5.输出成为各种类型的数据
> 
> ```c++
> int a;
> 
> ss >> a;
> 
> double b;
> 
> ss >> b;
> 
> bool c;
> 
> ss >> c;
> 
> string str = ss.str();
> ```
>
> 6.以空格作为流的分隔符
> 
> ```c++
> #include <string>       // std::string
> #include <iostream>     // std::cout
> #include <sstream>      // std::stringstream, std::stringbuf
>  
> using namespace std;
>  
> int main()
> {	
>  	int a;
> 	stringstream ss;	
> 	ss << "1 2 3 4 5 6";
> 	
> 	while(	ss >> a){
> 	    cout<<ss.str()<<"  "<<a<<endl;
> 	}
>    return 0;
> }
> ```
>
> 











