# cpp_data_structure 

* 代码随想录 https://programmercarl.com/

* 一个有非常简明例子的cpp网站：https://en.cppreference.com/w/

--------------------------------------------------------------------------------
> **大家不必太在意leetcode上执行用时，打败多少多少用户，这个就是一个玩具，非常不准确。**
> 
> 做题的时候自己能分析出来时间复杂度就可以了，至于leetcode上执行用时，大概看一下就行，只要达到最优的时间复杂度就可以了，
> 
> 一样的代码多提交几次可能就击败百分之百了....
--------------------------------------------------------------------------------

# 栈与队列

--------------------------------------------------------------------------------

## 前 K 个高频元素 top k frequent elements

## _7_top_k_frequent_elements.md

--------------------------------------------------------------------------------

### 347. 前 K 个高频元素

> Leetcode链接: https://leetcode.cn/problems/top-k-frequent-elements/

> 给你一个整数数组 `nums` 和一个整数 `k` ，请你返回其中出现频率前 `k` 高的元素。你可以按 **任意顺序** 返回答案。
> 
> **示例1：**
> 
> ```html
> 输入: nums = [1,1,1,2,2,3], k = 2
> 输出: [1,2]
> ```
> 
> **示例2：**
> 
> ```html
> 输入: nums = [1], k = 1
> 输出: [1]
> ```
> 
> **提示：**
> * `1 <= nums.length <= 10^5`
> * `k` 的取值范围是 `[1, 数组中不相同的元素的个数]`
> * 题目数据保证答案唯一，换句话说，数组中前 `k` 个高频元素的集合是唯一的
>





#### 我的解法 

> <font color="yellow">注意：`priority_queue<pair<>>`的比较规则：先比较第一个元素，第一个相等比较第二个</font>
> 
> <font color="yellow">算法如下</font>
>
> * 建立两个数组`v`、`f`
> > * `v` 存放不同的数字（按数字出现的顺序，将数字`push_back`入数组`v`）
> > * `f` 存放对应数字的频次（对应v的顺序，且每次重新遇到该数字，频次`+1`）
>
> * 从第`0`个，到第`nums.size()-1`个, 遍历一遍
> > * 使用find()确认之前是否已经出现过nums[i]
> > > * 如果返回的迭代器`iterator`不指向`v.end()`，则说明之前已经出现过与`nums[i]`的值。我们确认该值在`v`中的位置`location`, 并将`f[location]`中的值`+1`, 即更新频次
> > > * 如果返回的迭代器iterator指向v.end()，则说明之前未曾出现过与`nums[i]`的值。我们将该值`push_back(nums[i])`入数组`v`，并将出现次数`push_back(1)`入数组`f`
>
> * 以上已经统计完所有出现过数字，及其频次，按出现顺序在`v`和`f`中排列
>
> * 建立优先级队列`priority_queue<pair<int,int>> pq;` 
> 
> * 将`pair(f[i], v[i])`弹入,会自动按照`f[i]`从大到小排列
>
> * 建立结果数组`vector<int> result; ` 
> 
> * 将`pq`前`k`个`pair`的`v[i]`依次`push_back(pq.top().second)`进`result`
> 

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 存储value，值
        vector<int> v; 
        // 存储frequency，出现频次
        vector<int> f; 

        v.push_back(nums[0]); // 先放进去第一个
        f.push_back(1);       // 第一个数的目前出现次数为1

        // 开始遍历，从nums[1]开始，计算出现次数
        for(size_t i=1; i < nums.size(); i++) {
            // 查看是否之前已经出现该值
            vector<int>::iterator it = find(v.begin(), v.end(), nums[i]);  // 返回[first，end）中第一个等于nums[i]的位置；若未找到，返回end。
            if(it != v.end()) { // num[i] 在前面已经出现了，已经存储到v中
                // 计算出数组v中的位置
                int location = it - v.begin();
                // 修改数组f中的对应位置的频次值，+1
                f[location] = f[location] + 1;
            }
            else { // it == v.end() num[i] 之前未出现
                v.push_back(nums[i]); // 第一次出现这个数，先放进去
                f.push_back(1);       // 对应的前出现次数为1            
            }
        }
        // 截止目前，时间复杂度为O(n)
        
        // 优先级队列pair<frequency, value>
        priority_queue<pair<int,int>> pri_que; 
        for(size_t i=0; i < v.size(); i++) {
            pri_que.emplace(f[i], v[i]); 
            // priority_queue<pair<>>的比较规则：先比较第一个元素，第一个相等比较第二个
            // 按照出现频率排序，pair就需要把f放在前面
        } 
        // 截止目前，时间复杂度为O(n+k)，最坏是O(2n)

        // 存储结果
        vector<int> result; 
        for(size_t i=0; i < k; i++) {  //前k个
           result.push_back(pri_que.top().second); 
           pri_que.pop();
        }
        // 截止目前，时间复杂度为O(n+2k)，最坏是O(3n)        

        return result;
    }
};
```

#### 我的解法 优化，可以自定义比较类，不用把f[i]放在前面

```c++
class Solution {
public:
    class top_max {
    public:
        bool operator()(const pair<int, int>& front, const pair<int, int>& back) {
            return front.second < back.second; // top最大
            // return front.second > back.second; // top最小

            // 返回true时，交换位置，front排在back的后面
            // 这里是按照递增序列排序（top最小）
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 存储value，值
        vector<int> v; 
        // 存储frequency，出现频次
        vector<int> f; 

        v.push_back(nums[0]); // 先放进去第一个
        f.push_back(1);       // 第一个数的目前出现次数为1

        // 开始遍历，从nums[1]开始，计算出现次数
        for(size_t i=1; i < nums.size(); i++) {
            // 查看是否之前已经出现该值
            vector<int>::iterator it = find(v.begin(), v.end(), nums[i]);  // 返回[first，end）中第一个等于nums[i]的位置；若未找到，返回end。
            if(it != v.end()) { // num[i] 在前面已经出现了，已经存储到v中
                // 计算出数组v中的位置
                int location = it - v.begin();
                // 修改数组f中的对应位置的频次值，+1
                f[location] = f[location] + 1;
            }
            else { // it == v.end() num[i] 之前未出现
                v.push_back(nums[i]); // 第一次出现这个数，先放进去
                f.push_back(1);       // 对应的前出现次数为1            
            }
        }
        // 截止目前，时间复杂度为O(n)
        
        // 优先级队列pair<value, frequency>
        priority_queue<pair<int,int>, vector<pair<int,int>>, top_max> pri_que; 
        for(size_t i=0; i < v.size(); i++) {
            pri_que.emplace(v[i], f[i]); 
            // priority_queue<pair<>>的比较规则：比较第二个元素，top.second最大
        } 
        // 截止目前，时间复杂度为O(n+k)，最坏是O(2n)

        // 存储结果
        vector<int> result; 
        for(size_t i=0; i < k; i++) {  //前k个
           result.push_back(pri_que.top().first); 
           pri_que.pop();
        }
        // 截止目前，时间复杂度为O(n+2k)，最坏是O(3n)        

        return result;
    }
};
```




#### 可以把我的解法中“扫描每个数字的频次”，简化为用`std::unordered_map`统计频次，即代码随想录解法的大顶堆版本

```c++
class Solution {
public:
    class top_max {
    public:
        bool operator()(const pair<int, int>& front, const pair<int, int>& back) {
            return front.second < back.second; // top最大
            // return front.second > back.second; // top最小

            // 返回true时，交换位置，front排在back的后面
            // 这里是按照递增序列排序（top最小）
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个大顶堆
        //priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        priority_queue<pair<int, int>, vector<pair<int, int>>, top_max> pri_que;

        // 扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
        }

        // 找出前K个高频元素，大顶堆先弹出的是最大的
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};
```













#### 代码随想录

> 这道题目主要涉及到如下三块内容：
> 
> 1. 要统计元素出现频率
> 2. 对频率排序
> 3. 找出前K个高频元素
> 
> 首先统计元素出现的频率，这一类的问题可以使用map来进行统计。
> 
> 然后是对频率进行排序，这里我们可以使用一种 容器适配器 就是**优先级队列**。
> 
> 什么是优先级队列呢？
>  
> 其实**就是一个披着队列外衣的堆**，因为优先级队列对外接口只是从队头取元素，从队尾添加元素，再无其他取元素的方式，看起来就是一个队列。
>
> 而且优先级队列内部元素是自动依照元素的权值排列。那么它是如何有序排列的呢？
> 
> 缺省情况下`priority_queue`利用`max-heap`（大顶堆）完成对元素的排序，这个大顶堆是以`vector`为表现形式的`complete binary tree`（完全二叉树）。
> 
> 什么是堆呢？
> 
> **堆是一棵完全二叉树，树中每个结点的值都不小于（或不大于）其左右孩子的值**。 如果父亲结点是大于等于左右孩子就是大顶堆，小于等于左右孩子就是小顶堆。
> 
> <font color="yellow">所以大家经常说的大顶堆（堆头是最大元素），小顶堆（堆头是最小元素），如果懒得自己实现的话，就直接用`priority_queue`（优先级队列）就可以了，底层实现都是一样的，从小到大排就是小顶堆，从大到小排就是大顶堆。</font>
>
> 本题我们就要使用优先级队列来对部分频率进行排序。
> 
> 为什么不用快排呢， 使用快排要将`map`转换为`vector`的结构，然后对整个数组进行排序， 而这种场景下，我们其实只需要维护`k`个有序的序列就可以了，所以使用优先级队列是最优的。
> 
> 此时要思考一下，是使用小顶堆呢，还是大顶堆？
> 
> 有的同学一想，题目要求前 `K` 个高频元素，那么果断用大顶堆啊。
> 
> 那么问题来了，定义一个大小为`k`的大顶堆，在每次移动更新大顶堆的时候，每次弹出都把最大的元素弹出去了，那么怎么保留下来前`K`个高频元素呢。
> 
> 而且使用大顶堆就要把所有元素都进行排序，那能不能只排序`k`个元素呢？
> 
> **所以我们要用小顶堆，因为要统计最大前`k`个元素，只有小顶堆每次将最小的元素弹出，最后小顶堆里积累的才是前k个最大元素。**
>
> 寻找前`k`个最大元素流程如图所示：（图中的频率只有三个，所以正好构成一个大小为`3`的小顶堆，如果频率更多一些，则用这个小顶堆进行扫描）
>
> 
> <div align=center>
> <img src="./images/top_k_frequent_elements_1.jpg" style="zoom:100%;"/>
> </div>
>
```c++
// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;  // top的second最小
            // 返回true时，交换位置，lhs排在rhs的后面
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};
```


##### 代码随想录优化：不用小顶堆，用大顶堆也可以。优点：代码更简洁，不用固定堆大小
```c++
class Solution {
public:
    class top_max {
    public:
        bool operator()(const pair<int, int>& front, const pair<int, int>& back) {
            return front.second < back.second; // top最大
            // return front.second > back.second; // top最小

            // 返回true时，交换位置，front排在back的后面
            // 这里是按照递增序列排序（top最小）
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个大顶堆
        //priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        priority_queue<pair<int, int>, vector<pair<int, int>>, top_max> pri_que;

        // 扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
        }

        // 找出前K个高频元素，大顶堆先弹出的是最大的
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};
```






##### 拓展

> 大家对这个比较运算在建堆时是如何应用的，为什么左大于右就会建立小顶堆，反而建立大顶堆比较困惑。
> 
> 确实 例如我们在写快排的`cmp`函数的时候，`return left>right` 就是从大到小，`return left<right` 就是从小到大。
> 
> 优先级队列的定义正好反过来了，可能和优先级队列的源码实现有关（我没有仔细研究），我估计是底层实现上优先队列队首指向后面，队尾指向最前面的缘故！
> 
> 
> 






