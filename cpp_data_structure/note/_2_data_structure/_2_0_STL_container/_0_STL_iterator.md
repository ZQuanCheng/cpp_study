# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

* 一个有非常简明例子的cpp网站：https://en.cppreference.com/w/
  <br> 例如，查看std::vector的assign的用法：https://en.cppreference.com/w/cpp/container/vector/assign
  <br> 三种方式通过一个例子完美解释了，还夹带lambda干货。

--------------------------------------------------------------------------------

```c++
// STL（标准模板库） 
#include <array>               // std::array                                    容器
#include <vector>              // std::vector                                   容器
#include <list>                // std::list                                     容器
#include <stack>               // std::stack                                    容器适配器
#include <queue>               // std::queue          std::priority_queue       容器适配器
#include <deque>               // std::deque                                    容器
#include <string>              // std::string                                   容器
#include <map>                 // std::map            std::multimap             容器   
#include <set>                 // std::set            std::multiset             容器
#include <unordered_map>       // std::unordered_map  std::unordered_multimap   容器
#include <unordered_set>       // std::unordered_set  std::unordered_multiset   容器

// 与STL 容器有关的头文件
// <algorithm>是标准模版库（STL）中最重要的头文件之一，提供了大量基于迭代器的非成员模板函数。
#include <algorithm>   // remove()、remove_if()、find_if()、sort、...
// https://blog.csdn.net/szplzx1314/article/details/120644640

#include <iterator> // next() prev() distance() advance()
```

--------------------------------------------------------------------------------

## _0_STL_iterator.md

--------------------------------------------------------------------------------

### `iterator`的几个辅助函数

> 
> 1. `std::advance`
> 增加迭代器`it` `n`个元素的步长
>
> ```c++
> // (until C++17)
> template< class InputIt, class Distance >
> void advance( InputIt& it, Distance n );       
>     
> // (since C++17)
> template< class InputIt, class Distance >
> constexpr void advance( InputIt& it, Distance n );
> ```
> 

> 
> 2. `std::distance`
> 返回迭代器 `first` 到 `last` 的 路程（可正可负）
>
> ```c++
> // (until C++17)
> template< class InputIt >
> typename std::iterator_traits<InputIt>::difference_type 
>     distance( InputIt first, InputIt last );
>        
> // (since C++17)
> template< class InputIt >
> constexpr typename std::iterator_traits<InputIt>::difference_type 
>     distance( InputIt first, InputIt last );    
> ```
> 

> 
> 3. `std::next（C++11）`
> 返回 `it` 后第`n`个迭代器
>
> ```c++
> // (since C++11) (until C++17)
> template< class ForwardIt >
> ForwardIt next(
>   ForwardIt it, 
>   typename std::iterator_traits<ForwardIt>::difference_type n = 1 ); 
>  
> //  (since C++17)
> template< class InputIt >
> constexpr InputIt next(
>   InputIt it, 
>   typename std::iterator_traits<InputIt>::difference_type n = 1 );
> ```
> 

> 
> 4. `std::prev （C++11） `
> 返回 `it` 前第`n`个迭代器
>
> ```c++
> // (since C++11) (until C++17)
> template< class BidirIt >
> BidirIt prev(
>   BidirIt it, 
>   typename std::iterator_traits<BidirIt>::difference_type n = 1 ); 
> 
> //  (since C++17)
> template< class BidirIt >
> constexpr BidirIt prev(
>   BidirIt it, 
>   typename std::iterator_traits<BidirIt>::difference_type n = 1 );
> ```
> 


> 例子
> 
> ```c++
> #include <iostream>
> #include <iterator> // next() prev() distance() advance()
> #include <vector>
>  
> int main() {
> 
>     // 几个辅助函数 (去掉所有cout输出代码；注意例子中的正负)
>     std::vector<int> vc {0,1,2,3,4,5,6,7,8,9};
>     auto iter = vc.begin();
>     std::cout << *iter << std::endl;  // 当前iter指向vc[0]
>     
>     // std::next
>     iter = std::next(iter, 7);        // 返回iter后的第7个迭代器, 新iter指向vc[7]
>     std::cout << *iter << std::endl;  // 7
>     iter = std::next(iter, -1);       // 返回iter后的第-1个迭代器（反向）, 新iter指向vc[6]
>     std::cout << *iter << std::endl;  // 6
>  
>     // std::prev
>     iter = std::prev(iter, 1);        // 返回iter前的第1个迭代器, 新iter指向vc[5]
>     std::cout << *iter << std::endl;  // 5
>     iter = std::prev(iter, -1);       // 返回iter前的第-1个迭代器（反向）, 新iter指向vc[6]
>     std::cout << *iter << std::endl;  // 6
>   
>     // std::distance
>     std::distance(iter, vc.end());    // 返回迭代器 first 到 last 的 路程（可正可负），这里为4. 因为end()返回的是最后一个元素的后一位置, 所以不是3
>     std::cout << std::distance(iter, vc.end()) << std::endl;    // 4
>     std::distance(iter, vc.begin());  // 返回迭代器 first 到 last 的 路程（可正可负），这里为-6.
>     std::cout << std::distance(iter, vc.begin()) << std::endl;  // -6  
>  
>     // std::advance
>     std::advance(iter, 1);            // 增加迭代器iter 1个元素的步长, 新iter指向vc[7]
>     std::cout << *iter << std::endl;  // 7
>     std::advance(iter, -1);           // 增加迭代器iter -1个元素的步长, 新iter指向vc[6]
>     std::cout << *iter << std::endl;  // 6
> 
>   
>     cout << endl;
>     pause();
>     return 0;
> }
> ```
> 






