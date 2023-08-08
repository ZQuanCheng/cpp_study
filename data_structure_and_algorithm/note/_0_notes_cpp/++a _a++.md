
```c++
#include <iostream>
using namespace std;

int main() {
    
    int a = 1;

    ++a; 

    cout << a << endl;

    a++;

    cout << a << endl;

    return 0;
}

```
运行结果如下

```c++
10
11
```



```c++
#include <iostream>
using namespace std;

int main() {
    
    int a = 1;

    ++a = 3;   // ++a 返回的是左值

    cout << a << endl;
    

    // a++ = 3; // a++返回的是临时变量，是右值，不是左值

    // cout << a << endl;

    return 0;
}

```

运行结果如下

```c++
3
```

注意`a++ = 3`会报错，原因如下

1. `++a`返回的是自身，即a
2. `a++`返回的是临时变量；可以看作`a = a +1;int tmp = a;return tmp;`

```c++
int& a++ (int& a) {
    a = a + 1;
    return a;
}

int ++a (int& a) {
    a = a + 1;
    int tmp = a;
    return tmp;
}
```





