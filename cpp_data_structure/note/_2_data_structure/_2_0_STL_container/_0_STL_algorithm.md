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

## _0_STL_algorithm.md

--------------------------------------------------------------------------------

### algorithm是STL的一个非常重要的头文件

```c++
#include <algorithm> 
/*
std::find
std::remove
std::sort
std::for_each
std::distance

*/
```
> std::find()
> 用法：find(first, end, value);
> 返回区间[first，end）中第一个值等于value的元素位置；若未找到，返回end。函数返回的是迭代器或指针，即位置信息。
> 
> ```c++
> // 搜索目标值下标 find(first, end, value);
> // 函数返回的是迭代器或指针，即位置信息。
> // 返回区间[first，end）中第一个值等于value的元素位置；
> // 若未找到，返回end。
> int val = 4;
> int xiabiao;
> vector<int>::iterator it = find(v.begin(), v.end(), val);
> xiabiao = it - v.begin();
> ```


> std::remove, 配合erase才能实现删除
> ```c++
> // 删除值为value的所有元素 remove
> // 删除对应指定值的元素：我们要注意，有remove的地方，必须配合erase删除iter到end()的部分
> vector<int> v = {1,2,3,4,5,4,6};
> int val = 4;
> v.erase(remove(v.begin(), v.end(), val), v.end());  
> // remove(v1.begin(),v1.end(),val);会遍历[begin,end)，将与val相等的元素,移动到末尾。
> // 即变成了{1,2,3,5,6,4,4}; 返回一个指向新的末尾元素的迭代器v.end()-2。
> // 后续就相当于v.erase(v.end()-2, v.end())，即删除最后2个元素
> ```

> std::sort
> ```c++
> vector<int> nums = {16,-4,0,-1,0,3,10};
> // 显示每一个元素
> vector<int>::iterator it;
> for (it = nums.begin(); it != nums.end(); it++) {
>     cout << *it << ", ";
> }
> cout << endl;
> sort(nums.begin(), nums.end()); // 默认升序
> // 显示每一个元素
> for (it = nums.begin(); it != nums.end(); it++) {
>     cout << *it << ", ";
> }
> cout << endl;
> ```
> 显示结果
> ```html
> 16, -4, 0, -1, 0, 3, 10, 
> -4, -1, 0, 0, 3, 10, 16, 
> ```