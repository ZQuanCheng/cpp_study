> **使用基于范围的for语句遍历**
>> <https://blog.csdn.net/weixin_43744293/article/details/118048380>
>> 基于范围的for语句是C++11新提供的一种语句，其语法形式是
>> ```c++ 
>> for (declaration : expression)
>>     statement
>> ```
>> 其中
>> expression部分是一个对象，必须是一个序列，比方说用花括号括起来的初始值列表、数组或者vector或string等类型的对象。这些类型的共同特点是拥有能返回迭代器的begin和end成员。
>> declaration 部分负责定义一个变量，该变量将被用于访问序列中的基础元素。每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值。确保类型相容最简单的办法是使用auto类型说明符。
>> 
>> 这样看上去还不明白的话，请看下面的例子，通过例子就可以很好理解：
>> ```c++
>> string str("some string");
>> for (auto c : str)
>> 	cout << c << ",";
>> cout << endl;
>> ```
>> c就是declaration；str就是expression；cout << c << “,”;就是statement。<br>
>> for循环把c和str联系起来了。此例中，通过auto关键字让编译器推断c的类型，c这里的类型实际上推断出的是char类型，c每次的值都是str中的一个字符，上述代码的运行的结果如下：
>> ```c++
>> s,o,m,e, ,s,t,r,i,n,g,
>> ```
> **注意：在基于范围的for循环中，如果想要改变expression对象中的值，必须把循环变量定义成引用类型**
>> ```c++
>> #include <string>   // string类
>> #include <cctype>   // string对象的各种字符处理函数，如toupper、isupper
>> 
>> string s("Hello, World!!!");
>> for(auto c : s){   // 未使用引用操作符       
>>    c=toupper(c);   
>> }
>> cout << s << endl;
>> for(auto &c : s){           
>>    c=toupper(c);   //toupper函数完成大写字符的替换
>> }
>> cout << s << endl;
>> ```
>> 运行：
>> ```c++
>> Hello, World!!!
>> HELLO, WORLD!!!
>> ```
> **此外，如果我们既想用引用，又不想改变原始值，那么可以用const 引用。**
>> ```c++
>> void string_print(string &s) {
>>     for (const auto &c : s)
>>         std::cout << c << " ";
>> }
>> ```
> **总结for(auto a:b)用法：**
>> 1. b的第一个和最后一个元素就是a的范围。
>> 2. 可以对STL标准模板库中（如：vector,set,list,map,queue,deque,string等）的各种容器使用“基于范围的for循环”
>> 3. 若想对自己定义的类使用这种语法，类中必须定义begin、end函数（不能是Begin和End这样的函数）和重载前++、==、!= 和解引用*操作符。
>
> **补充一点：**
>> 范围for语句for(auto& r:v)的定义等价于：
>> ```c++
>> for(auto beg = v.begin() , end = v.end() ; beg != end ; ++beg){
>> 	auto &r = *beg;
>> }
>> ```
>> <font color="yellow"> 可以看到，在范围for里面，总是预存了v.end()的值，所以，一旦在范围for里面添加（删除）序列v的元素，获取的end值就变得无效了，这一点很重要。</font> 







#### 智能指针



















