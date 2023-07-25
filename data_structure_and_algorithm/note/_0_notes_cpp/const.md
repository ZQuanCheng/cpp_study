# cpp_const

--------------------------------------------------------------------------------

## ChatGPT 3.5 搜索：C++ const关键词怎么用

<https://chat.openai.com/chat>

> 在 C++ 中，`const` 关键字用于指定变量或函数的只读属性，以确保在程序执行期间不会被修改 

### 声明只读变量
* 
  > 可以使用 `const` 关键字来声明只读变量，这些变量不能被修改。声明格式为：
  > ```c++
  > const int MAX_VALUE = 100;
  > ```
  > 这里，MAX_VALUE 被声明为常量，其值在程序的运行过程中不会发生改变。
  > 

### 函数参数中使用 const
*
  > 当将变量传递给函数时，可以使用 `const` 限定符，这样可以防止函数修改该变量的值。例如：
  > ```c++
  > void printValue(const int value){
  >     std::cout << "The value is " << value << std::endl;
  > }
  > void print(const std::string& message) {
  >     std::cout << message << std::endl;
  > }
  > ```
  > 这里，message 参数被声明为 `const`，这意味着函数不会修改该参数的值。这是一种很好的编程实践，因为它可以防止无意间修改参数的值。
  >   

### 函数返回类型中使用 const
*
  > 可以将函数返回值指定为 `const`，这意味着函数返回的值不能被修改。例如：
  > ```c++
  > const int get_max_value() {
  >     return MAX_VALUE;
  > }
  > ```
  > 这里，函数 get_max_value() 返回一个常量值。这可以防止该函数返回的值被修改。
  >   

### 类成员函数中使用 const
*
  > 可以在类成员函数的末尾使用 `const` 关键字，以指示该函数不会修改任何成员变量。例如：
  > ```c++
  > class MyClass
  > {
  > public:
  >     int getValue() const {
  >         return m_value;
  >     }
  > 
  > private:
  >     int m_value = 5;
  > };
  > ```
  > 这是一个简单的示例，其中 getValue() 函数声明为 const，以确保它不会修改 MyClass 类中的任何成员变量。
  > 


> 总之，使用 const 可以帮助编写更安全、更可靠的代码。



--------------------------------------------------------------------------------

## 博客：C++中const的强大用法：修饰函数参数/返回值/函数体

<https://zhuanlan.zhihu.com/p/256423512>

> 在C++中，`const` 常用于修饰常量，告诉编译器某值保持不变。需要注意的是，常量在定义之后就不能修改，因此定义时必须初始化。<br>
> ```c++
> const int HELLO = 6;  // 正确
> const int WORLD;  // 错误
> ```
> 除此之外，`const` 更强大的地方是修饰函数参数、函数返回值、函数体。<br>
> 被 `const` 修饰的东西都受到强制保护，可以防止意外改动，提高程序的健壮性。<br>
> 很多C++的书籍建议<font color="yellow"> “use const whenever you need” </font> <br>


### 1、const 修饰函数参数
*
  > 对于函数的入参，不管是什么数据类型，也不管是 指针传递，还是 引用传递，只要加了 const 修饰，就可以防止函数内意外修改该参数，起到保护作用。
  > ```c++
  > void function(int* output, const classA& a, const classB* b) {
  >     // do something
  > }
  > ```
  > 比如上面的例子，给 a 和 b 加上const修饰后，如果函数内的语句试图修改 a 或 b，编辑器就会报出错误。
  > 

### 2、const 修饰函数返回值
*
  > 用 const 修饰返回的指针或引用，保护指针或引用的内容不被修改。比如：
  > ```c++
  > int& GetAge()
  > const int& GetAgeConst()
  > ```
  > 两者的区别在于：前者返回的是一个左值，其引用的内容可以被修改；后者返回的是一个右值，其引用的内容不可被修改。
  > 
  > ```c++
  > class Student {
  > public:
  >     int& GetAge() {
  >         return m_age;
  >     }
  > 
  >     const int& GetAgeConst() {
  >         return m_age;
  >     }
  > 
  >     void ShowAge() {
  >         cout << "Age: " << m_age << endl;
  >     }
  > 
  > private:
  >     int m_age = 0;
  > };
  > 
  > int main()
  > {
  >     Student stu;
  >     stu.ShowAge();
  > 
  >     stu.GetAge() = 5; // 会修改成员变量的值
  >     stu.ShowAge();
  > 
  >     stu.GetAgeConst() = 8; // 编译器会报错
  >     stu.ShowAge();
  > 
  >     return 0;
  > }
  > ```
  > 编译的报错信息如下，为了安全起见，在函数的返回值加上 const，使得函数体不能作为左值。
  > <div align=center>
  > <img src="./images/const_1.jpg"  width="" height="" alt="no photo" title="" style="zoom:30%;"/>
  > </div>


### 3、const 修饰函数体
*
  > const 修饰函数体时，放到函数体的行尾处，表明在该函数体内，不能修改对象的数据成员，且不能调用非 const 成员函数。比如：
  > ```c++
  > void SetAge(int age)
  > void SetAgeConst(int age) const
  > ```
  > 两者的区别在于：前者可以修改类的数据成员，而后者不可以。
  > 
  > ```c++
  > class Student {
  > public:
  >     void SetAge(int age) {
  >         m_age = age;
  >     }
  > 
  >     void SetAgeConst(int age) const {
  >         m_age = age;
  >     }
  > 
  >     void ShowAge() {
  >         cout << "Age: " << m_age << endl;
  >     }
  > 
  > private:
  >     int m_age = 0;
  > };
  > 
  > int main()
  > {
  >     Student stu;
  >     stu.ShowAge();
  > 
  >     stu.SetAge(6); // 正确
  >     stu.ShowAge();
  > 
  >     stu.SetAgeConst(8); // 错误
  >     stu.ShowAge();
  > 
  >     return 0;
  > }
  > ```
  > 编译的报错信息如下：
  > <div align=center>
  > <img src="./images/const_2.jpg"  width="" height="" alt="no photo" title="" style="zoom:30%;"/>
  > </div>







#### char * 和 char []

>
> 按理说下面的两句代码是一样的
>
> ```c++
> char *p = "hello";
> 
> char a[] = "hello";
> ```
> 
> 但是实际上，这两种写法都不足以体现其本质，本质上是
>
> ```c++
> const char *p = "hello"; // char *p = "hello";
> 
> char *const a = "hello"; //char a[] = "hello";
> ```
>
> 一个是常量指针；一个是指针常量
> 
> `（指向）常量（的）指针pointers to constant`：指向的数据不可变，但是指针可以改变来指向别的地方
>
> 
> `指针常量constant pointer`：指向固定的内存位置，该位置的值可以更改
> 
> 所以，
> 
> `p指向的内容是不能修改的，但是p可以修改`
>
> `a指向的内容可以修改，但是a不可以修改`
>
> <br>
> <br>
> <br>
> 
> 
> 如果`char *s`出现在函数形参列表中，本质上是`const char *s`
>
> https://blog.csdn.net/Scofield971031/article/details/88421258
>
> 
> 
> ```c++
> int substring(char* s, char a) // 函数内，s指向的内容，只读
> 
> 最好改为
> 
> int substring(char s[], char a) // 函数内可以修改s指向的内容
> ```
>









