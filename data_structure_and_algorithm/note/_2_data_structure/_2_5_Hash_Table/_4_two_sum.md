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

# 哈希表

--------------------------------------------------------------------------------

## 两数之和 two sum

## _4_two_sum.md

--------------------------------------------------------------------------------

### 202. 快乐数

> Leetcode链接: https://leetcode.cn/problems/two-sum/

> 给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** `target`  的那 **两个** 整数，并返回它们的数组下标。
> 
> 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
> 
> 你可以按任意顺序返回答案。
> 
>
> **示例1：**
> 
> ```html
> 输入：nums = [2,7,11,15], target = 9
> 输出：[0,1]
> 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
> ```
>
> **示例2：**
> 
> ```html
> 输入：nums = [3,2,4], target = 6
> 输出：[1,2]
> ```
> 
> **示例3：**
> 
> ```html
> 输入：nums = [3,3], target = 6
> 输出：[0,1]
> ```
>
> **提示：**
> * `2 <= nums.length <= 104`
> * `-109 <= nums[i] <= 109`
> * `-109 <= target <= 109`
> * **只会存在一个有效答案**
>
>
> ```c++
> class Solution {
> public:
>     vector<int> twoSum(vector<int>& nums, int target) {
>         
>     }
> };
> ```
> 
> 





#### 我的解法


```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {0, 0}; // 用于存储两个整数值在nums中的下标

        // 同一个的元素不能重复出现，就是说两个下标不同相同，但是可以有相同数值
        // 所以有两种情况
        // result[0] 和 result[1] 两个下标对应的数值相同，即nums[result[0]] = nums[result[1]]
        // result[0] 和 result[1] 两个下标对应的数值不同，即nums[result[0]] ！= nums[result[1]]

        // 虽然是可以有相同数值，但是我们还是先去重. 这样可以节省我们进行遍历所需时间

        // 存入set, 再取出来，就可以实现去重的目的，得到所有可能的整数值
        set<int> set_nums(nums.begin(), nums.end()); // 默认set<int,less<int>>：key越小，优先级越高，越靠近队头begin()
        vector<int> temp(set_nums.begin(), set_nums.end());

        // 使用双指针遍历
        vector<int>::iterator left;         
        vector<int>::iterator right;       
        for(left = temp.begin(); left !=temp.end(); left++ ) {     // 左指针到倒数第二个位置end()-1为止 
            right = left; // right从left当前值开始
            // 循环计算
            while(right != temp.end()) {                           // 右指针到倒数第一个位置end()-1为止
                int add = *left + *right;   
                if(add == target) {
                    if (*left == *right) { // 如果两个元素的数值相同  // vector没有内置find函数，需要使用泛型find函数
                        
                        result[0] = find(nums.begin(), nums.end(), *left) - nums.begin(); // find返回数值出现的第一个位置 
                        nums[result[0]] = nums[result[0]] + 1;                          //将第一个位置的值改变
                        // 上面改变之后，再用find函数，就能检测到第二个位置了
                        result[1] = find(nums.begin(), nums.end(), *right) - nums.begin(); 
                    }
                    else{  // 如果两个元素的数值不同，直接检测下标返回就行
                        result[0] = find(nums.begin(), nums.end(), *left) - nums.begin();  // 下标
                        result[1] = find(nums.begin(), nums.end(), *right) - nums.begin(); // 下标                        
                    }
                    return result;              
                }
                ++right; 
            }
        }
        
        // 题目保证了一定有一个对应答案，所以不用考虑无答案的情况
        // 但是这里的问题是如果不写一个return，就会报错；还是得写一个return
        return result; 
        
    }
};
```




#### 代码随想录 非常巧妙

> 
> 很明显暴力的解法是两层`for`循环查找，时间复杂度是`O(n^2)`。
>
> <font color="yellow">建议大家做这道题目之前，先做一下这两道</font>
> 
> * `_1_valid_anagram.md`  这道题目是用数组作为哈希表来解决哈希问题
> * `_2_intersection_of_two_arrays.md` 这道题目是通过set作为哈希表来解决哈希问题。
>
> 首先我在强调一下 **什么时候使用哈希法**，当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法。
>
> 本题呢，我就需要一个集合来存放我们遍历过的元素，然后在遍历数组的时候去询问这个集合，某元素是否遍历过，也就是 是否出现在这个集合。
>
> 那么我们就应该想到使用哈希法了。
>
> 因为本地，我们不仅要知道元素有没有遍历过，还有知道这个元素对应的下标，**需要使用 key value结构来存放，key来存元素，value来存下标，那么使用map正合适**。
>
> 再来看一下使用`数组`和`set`来做哈希法的局限。
>
> * `数组`的大小是受限制的，而且如果元素很少，而哈希值太大会造成内存空间的浪费。
> * `set`是一个集合，里面放的元素只能是一个`key`，而两数之和这道题目，不仅要判断`y`是否存在而且还要记录`y`的下标位置，因为要返回`x` 和 `y`的下标。所以`set` 也不能用。
>
> 此时就要选择另一种数据结构：`map` ，`map`是一种`key` `value`的存储结构，可以用`key`保存数值，用`value`在保存数值所在的下标。
>
> **这道题目中并不需要`key`有序，选择`std::unordered_map` 效率更高**！
>
> 
> 接下来需要明确两点：
>
> `map`用来做什么
> `map`中`key`和`value`分别表示什么
>
> 
> `map`目的用来存放我们访问过的元素，因为遍历数组的时候，需要记录我们之前遍历过哪些元素和对应的下标，这样才能找到与当前元素相匹配的（也就是相加等于`target`）
>
> 接下来是`map`中`key`和`value`分别表示什么。
>
> 这道题 我们需要 给出一个元素，判断这个元素是否出现过，如果出现过，返回这个元素的下标。
>
> 那么判断元素是否出现，这个元素就要作为`key`，所以数组中的元素作为`key`，有`key`对应的就是`value`，`value`用来存下标。
> 
> 所以 `map`中的存储结构为 {`key`：数据元素，`value`：数组元素对应的下标}。
>
> 在遍历数组的时候，只需要向`map`去查询是否有和目前遍历元素匹配的数值，如果有，就找到的匹配对，如果没有，就把目前遍历的元素放进`map`中，因为`map`存放的就是我们访问过的元素。
>
> 过程如下：
>
> 
> <div align=center>
> <img src="./images/two_sum_1.png" style="zoom:100%;"/>
> <img src="./images/two_sum_2.png" style="zoom:100%;"/>
> </div>
> 
> 
> C++代码：
>
> ```c++
> class Solution {
> public:
>     vector<int> twoSum(vector<int>& nums, int target) {
>         std::unordered_map <int,int> map;
>         for(int i = 0; i < nums.size(); i++) {
>             // 遍历当前元素，并在map中寻找是否有匹配的key
>             auto iter = map.find(target - nums[i]); 
>             if(iter != map.end()) {
>                 return {iter->second, i};
>             }
>             // 如果没找到匹配对，就把访问过的元素和下标加入到map中
>             map.insert(pair<int, int>(nums[i], i)); 
>         }
>         return {};
>     }
> };
> ```
> 
> 
> 


#### 总结
 
> 
> <font color="yellow">
> 
> 本题其实有四个重点：
> 
> * 为什么会想到用哈希表
> * 哈希表为什么用map
> * 本题`map`是用来存什么的
> * `map`中的`key`和`value`用来存什么的
>
> </font>
> 
> **把这四点想清楚了，本题才算是理解透彻了**。
> 
> 很多录友把这道题目 通过了，但都没想清楚`map`是用来做什么的，以至于对代码的理解其实是 一知半解的。
>
> 
> 













