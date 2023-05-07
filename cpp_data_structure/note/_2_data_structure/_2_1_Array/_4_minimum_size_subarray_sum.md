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

# 数组

--------------------------------------------------------------------------------

## 长度最小的子数组 square of sorted Arrays

## _4_minimum_size_subarray_sum.md

--------------------------------------------------------------------------------

### 209.长度最小的子数组

> Leetcode链接: https://leetcode.cn/problems/minimum-size-subarray-sum/

> 给定一个含有 `n` 个正整数的数组和一个正整数 `target` 。
> 
> 找出该数组中满足其和 `≥ target` 的长度最小的 **连续子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度。如果不存在符合条件的子数组，返回 `0` 。
>
> 示例 1：
> ```html
> 输入：target = 7, nums = [2,3,1,2,4,3]
> 输出：2
> 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
> ```
> 示例 2：
> ```html
> 输入：target = 4, nums = [1,4,4]
> 输出：1
> ```
> 示例 3：
> ```html
> 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
> 输出：0
> ```
> 
> 提示：
> * `1 <= target <= 109`
> * `1 <= nums.length <= 105`
> * `1 <= nums[i] <= 105`
> 
> 进阶：
> * 如果你已经实现 `O(n)` 时间复杂度的解法, 请尝试设计一个 `O(n log(n))` 时间复杂度的解法。
>
> ```c++
> class Solution {
> public:
>     int minSubArrayLen(int target, vector<int>& nums) {
> 
>     }
> };
> ```

#### 第一时间想到的解法: 刚开始只能通过一半用例,  修改后，仍然有2个用例超时
> ```c++
> class Solution {
> public:
>     int minSubArrayLen(int target, vector<int>& nums) {
>         int len = nums.size();
>         int mini_sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_len = len + 1;    // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_sum = 0;          // 临时存储当前起始元素对应的最小子数组总和
> 
>         for(int i=0; i<len; i++) { // 从每个元素开始，计算出满足总和>=target的长度最小子数组，然后比较每个元素对应的长度
>             sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新
>             sub_sum = 0;           
>             for (int j=i; j<len;j++) {
>                 if(sub_sum >= target) {  // 满足sub_sum>=target条件后，计算子数组长度，并离开循环
>                     sub_len = j - i;  
>                     break;            
>                 } else { // 不满足sub_sum>=target条, 继续相加
>                     sub_sum = sub_sum + nums[j];
>                 }
>             }
>             if(mini_sub_len > sub_len) { // 上一个子数组长度 > 当前子数组长度
>                 mini_sub_len = sub_len;  // 更新
>             }
>         }
> 
>         if(mini_sub_len == len + 1) {  // 说明不存在满足条件的子数组
>             return 0;                  // 返回0
>         } else  {                       // 说明存在满足条件的子数组
>             return mini_sub_len;       // 返回最小的长度
>         }
>     }
> };
> ```
> 算法缺陷是：
> 如果子数组最后一位，正好是原数组的最后一位，这样，j++后，无法进入循环，就不会执行下面两句话
> ```c++
> sub_len = j - i;  
> break;
> ```
>
> 我们cout一下，试一试每次循环的结果
> ```c++
>         vector<int> nums = {2,3,1,2,4,3};
>         int target = 7;
> 
>         int len = nums.size();
>         int mini_sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_len = len + 1;    // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_sum = 0;          // 临时存储当前起始元素对应的最小子数组总和
> 
>         for(int i=0; i<len; i++) { // 从每个元素开始，计算出满足总和>=target的长度最小子数组，然后比较每个元素对应的长度
>             sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新
>             sub_sum = 0;           
>             for (int j=i; j<len;j++) {
>                 if(sub_sum >= target) {  // 满足sub_sum>=target条件后，计算子数组长度，并离开循环
>                     sub_len = j - i;  
>                     break;            
>                 } else { // 不满足sub_sum>=target条, 继续相加
>                     sub_sum = sub_sum + nums[j];
>                 }
>             }
>             cout << "第 " << i << " 次循环：" << "sub_len = " << sub_len << endl;
> 
>             if(mini_sub_len > sub_len) { // 上一个子数组长度 > 当前子数组长度
>                 mini_sub_len = sub_len;  // 更新
>             }
>         }
>         cout << "mini_sub_len = " << mini_sub_len << endl;
> 
>         if(mini_sub_len == len + 1) {  // 说明不存在满足条件的子数组
>             return 0;                  // 返回0
>         } else  {                       // 说明存在满足条件的子数组
>             return mini_sub_len;       // 返回最小的长度
>         }
> ```
> 运行结果
> ```c++
> 第 0 次循环：sub_len = 4
> 第 1 次循环：sub_len = 4
> 第 2 次循环：sub_len = 3
> 第 3 次循环：sub_len = 7
> 第 4 次循环：sub_len = 7
> 第 5 次循环：sub_len = 7
> mini_sub_len = 3
> ```
> 第3次循环时，按理说存在子数组`[2,4,3]`满足条件，应该有`sub_len = 3`，但是`cout`却显示`sub_len = 7`，这说明最后一次加上`nums[5] = 3`后，虽然满足条件，但是由于`j=6`，无法进入`for (int j=i; j<len;j++)`循环。就无法更新`sub_len`
>
> 那我们就要想办法，在执行`j++`之前，就判断`sub_sum`是否`>=target`
> 
> 修改`for (int j=i; j<len;j++) `的循环体
> ```c++
> class Solution {
> public:
>     int minSubArrayLen(int target, vector<int>& nums) {
>         int len = nums.size();
>         int mini_sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_len = len + 1;    // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_sum = 0;          // 临时存储当前起始元素对应的最小子数组总和
> 
>         for (int i=0; i<len; i++) { // 从每个元素开始，计算出满足总和>=target的长度最小子数组，然后比较每个元素对应的长度
>             sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新
>             sub_sum = 0;           
>             for (int j=i; j<len;j++) {
>                 sub_sum = sub_sum + nums[j];
>                 if (sub_sum >= target) {  // 满足sub_sum>=target条件后，计算子数组长度，并离开循环
>                     sub_len = j - i + 1;  
>                     if (mini_sub_len > sub_len) { // 上一个子数组长度 > 当前子数组长度
>                          mini_sub_len = sub_len;  // 更新
>                     }
>                     break;            
>                 } 
>             }
>         }
> 
>         if(mini_sub_len == len + 1) {  // 说明不存在满足条件的子数组
>             return 0;                  // 返回0
>         } else  {                       // 说明存在满足条件的子数组
>             return mini_sub_len;       // 返回最小的长度
>         }
>     }
> };
> ```
> <font color="yellow">只有18 / 20 个通过的测试， 是因为有2个用例，运行结果超时。</font>
> 时间复杂度：O(n^2)
> 空间复杂度：O(1)
>
> 我们还可以简化代码，虽然不能减少用时，但是可以使得代码可读性更高。
> ```c++
> class Solution {
> public:
>     int minSubArrayLen(int target, vector<int>& nums) {
>         int len = nums.size();
>         int mini_sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_len = len + 1;    // 初始化为len + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_sum = 0;          // 临时存储当前起始元素对应的最小子数组总和
> 
>         for(int i=0; i<len; i++) { // 从每个元素开始，计算出满足总和>=target的长度最小子数组，然后比较每个元素对应的长度
>             sub_len = len + 1; // 初始化为len + 1，只要存在一个子数组满足>=target，就更新
>             sub_sum = 0;           
>             for (int j=i; j<len;j++) {
>                 sub_sum = sub_sum + nums[j];
>                 if(sub_sum >= target) {  // 满足sub_sum>=target条件后，计算子数组长度，并离开循环
>                     sub_len = j - i + 1;  
>                     mini_sub_len = (mini_sub_len > sub_len) ? sub_len : mini_sub_len;
>                     break;            
>                 } 
>             }
>         }
>         
>         return (mini_sub_len == len + 1) ? 0 : mini_sub_len;
>     }
> };
> ```
> 很多初始值，以及有些语句是多余的
> 
> <font color="yellow">最终版代码如下(18 / 20 个通过)：</font>
> ```c++
> class Solution {
> public:
>     int minSubArrayLen(int target, vector<int>& nums) {
>         int mini_sub_len = nums.size() + 1; // 初始化为nums.size() + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_len = 0;    
>         int sub_sum = 0;  
> 
>         for(int i=0; i<nums.size(); i++) { // 从每个元素开始，计算出满足总和>=target的长度最小子数组，然后比较最小值
>             sub_sum = 0;           
>             for (int j=i; j<nums.size();j++) {
>                 sub_sum += nums[j];
>                 if(sub_sum >= target) {  // 满足sub_sum>=target条件后，计算子数组长度，并离开循环
>                     sub_len = j - i + 1;  
>                     mini_sub_len = (mini_sub_len > sub_len) ? sub_len : mini_sub_len;
>                     break;            
>                 } 
>             }
>         }
>         // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
>         return (mini_sub_len == nums.size() + 1) ? 0 : mini_sub_len;
>     }
> };
> ```
> **时间复杂度**：`O(n^2)`，其中 `n` 是数组的长度。需要遍历每个下标作为子数组的开始下标，对于每个开始下标，需要遍历其后面的下标得到长度最小的子数组。
> 
> **空间复杂度**：`O(1)`。




####  滑动窗口法（双指针）

> 在前面的暴力解法中，是一个for循环滑动窗口的起始位置，一个for循环为滑动窗口的终止位置，用两个for循环 完成了一个不断搜索区间的过程。
> 
> 所谓滑动窗口，就是**不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果。**
> 
> 那么滑动窗口如何用一个for循环来完成这个操作呢。
>
> 首先要思考 如果用一个for循环，那么应该表示 滑动窗口的起始位置，还是终止位置。
> 
> 如果只用一个for循环来表示 滑动窗口的起始位置，那么如何遍历剩下的终止位置？
> 
> 此时难免再次陷入 暴力解法的怪圈。
> 
> 所以 只用一个for循环，那么这个循环的索引，一定是表示 滑动窗口的终止位置。
> 
> 那么问题来了， 滑动窗口的起始位置如何移动呢？
> 
> 这里还是以题目中的示例来举例，s=7， 数组是 2，3，1，2，4，3，来看一下查找的过程：
> 
> <div align=center>
> <img src="./images/minimum_size_subarray_sum_1.gif"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
> 
> 最后找到 4，3 是最短距离。
> 
> 其实从动画中可以发现滑动窗口也可以理解为双指针法的一种！只不过这种解法更像是一个窗口的移动，所以叫做滑动窗口更适合一些。
>
> 在本题中实现滑动窗口，主要确定如下三点：
> 
> * 窗口内是什么？
> * 如何移动窗口的起始位置？
> * 如何移动窗口的结束位置？
>
> 窗口就是 满足其和 ≥ s ( 这里 s 就是题中的 target ) 的长度最小的 连续 子数组。
> 
> 窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口的起始位置就要向右移动了（也就是该缩小了）。
> 
> 窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，也就是for循环里的索引。
>
> 解题的关键在于 窗口的起始位置如何移动，如图所示：
> 
> <div align=center>
> <img src="./images/minimum_size_subarray_sum_2.png"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
>
> 可以发现**滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置。从而将O(n^2)暴力解法降为O(n)。**
>
> **算法：**
> 定义两个指针 `start` 和 `end` 分别表示子数组（滑动窗口窗口）的开始位置和结束位置，维护变量 `sum` 存储子数组中的元素和（即从 `nums[start]` 到 `nums[end]` 的元素和）。
> 
> 初始状态下，`start` 和 `end` 都指向下标 `0`，`sum` 的值为 `0`。
> 
> 每一轮迭代，将 `nums[end]` 加到 `sum`，如果 `sum≥s`，则说明:子数组可能过长了。
> 需要更新子数组的最小长度(此时子数组的长度是 `end−start+1`): 
> * 将 `nums[start]` 从 `sum` 中减去，然后 `start` 右移，
> * 直到 `sum<s`，
> 
> 在此过程中更新子数组的最小长度。
> 
> 在每一轮迭代的最后，将 `end` 右移。
>
> ```c++
> // 时间复杂度：O(n)，其中 n 是数组的长度。指针 start 和 end 最多各移动 n 次。
> // 空间复杂度：O(1)。
> 
> class Solution {
> public:
>     int minSubArrayLen(int target, vector<int>& nums) {
>         int mini_sub_len = nums.size() + 1; // 初始化为nums.size() + 1，只要存在一个子数组满足>=target，就更新为更小值
>         int sub_len = 0;    
>         int sub_sum = 0;  
>         size_t start = 0;
>         size_t end = 0;
> 
>         for( end=0 ; end < nums.size(); end++) { // 从每个元素开始，计算出满足总和>=target的长度最小子数组，然后比较最小值
>             sub_sum += nums[end]; 
>             while (sub_sum >= target) {
>                 sub_len = end - start + 1;
>                 mini_sub_len = (mini_sub_len > sub_len) ? sub_len : mini_sub_len;
>                 sub_sum -= nums[start];
>                 ++start;
>             }       
>         }   
>         // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
>         return (mini_sub_len == nums.size() + 1) ? 0 : mini_sub_len;
>     }
> };
> ```
> 时间复杂度：`O(n)`，其中 `n` 是数组的长度。指针 `start` 和 `end` 最多各移动 `n` 次。
> 空间复杂度：`O(1)`。
> <font color="yellow"> 不要以为for里放一个while就以为是O(n^2)， 主要是看每一个元素被操作的次数，每个元素在滑动窗后进来操作一次，出去操作一次，每个元素都是被操作两次，所以时间复杂度是 2 × n 也就是O(n)。</font>
> 




####  前缀和 + 二分查找
> https://leetcode.cn/problems/minimum-size-subarray-sum/solutions/305704/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/

> 
> 时间复杂度：`O(nlog⁡n)`，其中 `n` 是数组的长度。需要遍历每个下标作为子数组的开始下标，遍历的时间复杂度是 `O(n)`，对于每个开始下标，需要通过二分查找得到长度最小的子数组，二分查找得时间复杂度是 `O(log⁡n)`，因此总时间复杂度是 `O(nlog⁡n)`。
> 
> 空间复杂度：O(n)，其中 n 是数组的长度。额外创建数组 sums 存储前缀和。
> 




