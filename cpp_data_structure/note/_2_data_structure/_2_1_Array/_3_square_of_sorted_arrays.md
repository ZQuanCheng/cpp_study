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

## 有序数组的平方 square of sorted Arrays

## _3_square_of_sorted_arrays.md
--------------------------------------------------------------------------------

### 977.有序数组的平方

> Leetcode链接: https://leetcode.cn/problems/squares-of-a-sorted-array/

> 给你一个按 **非递减顺序** 排序的整数数组 `nums`，返回 **每个数字的平方** 组成的新数组，要求也按 **非递减顺序** 排序。
>
> 示例 1：
> ```html
> 输入：nums = [-4,-1,0,3,10]
> 输出：[0,1,9,16,100]
> 解释：平方后，数组变为 [16,1,0,9,100]
> 排序后，数组变为 [0,1,9,16,100]
> ```
> 示例 2：
> ```html
> 输入：nums = [-7,-3,2,3,11]
> 输出：[4,9,9,49,121]
> ```
>
> 
> 提示：
> * `1 <= nums.length <= 104`
> * `-104 <= nums[i] <= 104`
> * `nums 已按 非递减顺序 排序`
> 
> 进阶：
> * 请你设计时间复杂度为 `O(n)` 的算法解决本问题
>
> ```c++
> class Solution {
> public:
>     vector<int> sortedSquares(vector<int>& nums) {
> 
>     }
> };
> ```

#### 第一时间想到的解法: 先平方，后排序
> 时间复杂度：`O(n + nlog⁡n) = O(nlogn)`，其中 `n` 是数组 `nums` 的长度。
> 空间复杂度：`O(log⁡n)`。
> 这里默认空间复杂度是「存储答案的数组以外」的结果，所以空间复杂度为 `O(log⁡n)`。意思是，除了存储答案的数组需要的空间为 `O(n)` 以外，我们需要 `O(log⁡n)` 的栈空间进行排序。
> 没有必要纠结到底返回答案到底需不需要算在空间复杂度里面。Leetcode的题目要把它当成面试题来看。在面试中，如果你作为面试者碰到了这个题，那么一定要 (1) 和面试官沟通并确认清楚 (2) 给出尽可能全面的答案。说空间复杂度是 O(n) 还是 O(log⁡n) 都没有问题，只要你和面试官说明原因就好。
> 
> ```c++
> class Solution {
> public:
>     vector<int> sortedSquares(vector<int>& nums) {
>         vector<int> squa;
>         // 先平方
>         for (size_t i=0; i < nums.size(); i++) {
>             squa.push_back(nums[i] * nums[i]);
>         }
>         // 后排序
>         sort(squa.begin(), squa.end());  // 默认升序 // 时间复杂度O(nlogn)
>         return squa;
>     }
> }
> ```

#### 进阶 `O(n)` ，试一试双指针
> **思路1**
> 方法一没有利用「数组 `nums` 已经按照升序排序」这个条件。显然，如果数组 `nums` 中的所有数都是非负数，那么将每个数平方后，数组仍然保持升序；如果数组 `nums` 中的所有数都是负数，那么将每个数平方后，数组会保持降序。
> 
> 这样一来，如果我们能够找到数组 `nums` 中负数与非负数的分界线，那么就可以用类似「归并排序」的方法了。具体地，我们设 `neg` 为数组 `nums` 中负数与非负数的分界线，也就是说，`nums[0]` 到 `nums[neg]` 均为负数，而 `nums[neg+1]` 到 `nums[n−1]` 均为非负数。当我们将数组 `nums` 中的数平方后，那么 `nums[0]` 到 `nums[neg]` 单调递减，`nums[neg+1]` 到 `nums[n−1]` 单调递增。
> 
> 由于我们得到了两个已经有序的子数组，因此就可以使用归并的方法进行排序了。具体地，使用两个指针分别指向位置 `neg` 和 `neg+1`，每次比较两个指针对应的数，选择较小的那个放入答案并移动指针。当某一指针移至边界时，将另一指针还未遍历到的数依次放入答案。
>
> **思路1:实现1**
> 时间复杂度：`O(n)`，其中 `n` 是数组 `nums` 的长度。
> 空间复杂度：`O(1)`。除了存储答案的数组以外，我们只需要维护常量空间。
> 这里默认空间复杂度是「存储答案的数组以外」的结果，所以空间复杂度为 `O(1)`。意思是，除了存储答案的数组需要的空间为 `O(n)` 以外，我们需要 `O(1)` 的栈空间进行排序。
> 没有必要纠结到底返回答案到底需不需要算在空间复杂度里面。Leetcode的题目要把它当成面试题来看。在面试中，如果你作为面试者碰到了这个题，那么一定要 (1) 和面试官沟通并确认清楚 (2) 给出尽可能全面的答案。说空间复杂度是 O(n) 还是 O(1) 都没有问题，只要你和面试官说明原因就好。
> ```c++
> class Solution {
> public:
>     vector<int> sortedSquares(vector<int>& nums) {
>         int len = nums.size();
> 
>         // neg 为数组 nums 中负数与非负数的分界线
>         // nums[0] 到 nums[neg] 均为负数，而 nums[neg+1] 到 nums[n−1] 均为非负数
>         int neg = -1; // size_t 是非负，不能定义-1
> 
>         /*
>         while (nums[neg + 1] < 0) {
>             neg ++;
>         } // 当num[neg+1] >= 0时，不进入循环，保证neg指向最靠近0的负数
>         */
>         /*
>         *不能用上面的while循环来确定neg的位置。
>         *如果数组皆为负数，最后一次判断时，nums[neg + 1]会指向尾部下一个位置。
>         *虽然我们在本机上跑是正常的，但是leetcode会报错，“发生溢出”。 
>         *应该是leetcode后台写了异常处理。 
>         */
>         for (size_t i=0; i<len;i++)  {
>             if (nums[i] < 0) {
>                 neg = i;
>             } else {
>                 break;
>             }
>         }
>                 
>         vector<int> squa;
>         int left = neg;
>         int right = neg + 1;
>         while(left >= 0 && right <= len-1) {
>             if(nums[left]*nums[left]  <= nums[right]*nums[right]) {
>                 squa.push_back(nums[left]*nums[left]);
>                 left--;
>             } else {
>                 squa.push_back(nums[right]*nums[right]);    
>                 right++;            
>             } 
>         } // 当某一指针超出边界时，停止比较。
>         
>         // 将另一指针还未遍历到的数依次放入答案。
>         while(left >= 0) { // 左指针未超出边界，
>             squa.push_back(nums[left]*nums[left]);    
>             left--; 
>         }
>         while(right <= len-1) { // 右指针仍未超出边界，
>             squa.push_back(nums[right]*nums[right]);    
>             right++; 
>         }
>         return squa;
>     }
> };
> ```
> **思路1:实现2 优化实现1的结构**
> 时间复杂度：`O(n)`，其中 `n` 是数组 `nums` 的长度。
> 空间复杂度：`O(1)`。除了存储答案的数组以外，我们只需要维护常量空间。
> 这里默认空间复杂度是「存储答案的数组以外」的结果，所以空间复杂度为 `O(1)`。意思是，除了存储答案的数组需要的空间为 `O(n)` 以外，我们需要 `O(1)` 的栈空间进行排序。
> 没有必要纠结到底返回答案到底需不需要算在空间复杂度里面。Leetcode的题目要把它当成面试题来看。在面试中，如果你作为面试者碰到了这个题，那么一定要 (1) 和面试官沟通并确认清楚 (2) 给出尽可能全面的答案。说空间复杂度是 O(n) 还是 O(1) 都没有问题，只要你和面试官说明原因就好。
> ```c++
> class Solution {
> public:
>     vector<int> sortedSquares(vector<int>& nums) {
>         int len = nums.size();
>         int neg = -1; 
>         for (size_t i=0; i<len;i++)  {
>             if (nums[i] < 0) {
>                 neg = i;
>             } else {
>                 break;
>             }
>         }
> 
>         vector<int> squa;
>         int left = neg;
>         int right = neg + 1;
>         while (left >= 0 || right < len) {
>             if (left < 0) {
>                 squa.push_back(nums[right] * nums[right]);
>                 ++right;
>             }
>             else if (right == len) {
>                 squa.push_back(nums[left] * nums[left]);
>                 --left;
>             }
>             else if (nums[left] * nums[left] < nums[right] * nums[right]) {
>                 squa.push_back(nums[left] * nums[left]);
>                 --left;
>             }
>             else {
>                 squa.push_back(nums[right] * nums[right]);
>                 ++right;
>             }
>         }
> 
>         return squa;
>     }
> };
> ```

> **思路2**
> `思路2`也利用了「数组 `nums` 已经按照升序排序」这个条件。显然，如果数组 `nums` 中的所有数都是非负数，那么将每个数平方后，数组仍然保持升序；如果数组 `nums` 中的所有数都是负数，那么将每个数平方后，数组会保持降序。
> 
> 我们可以使用两个指针分别指向位置 `0` 和 `n−1`，每次比较两个指针对应的数，选择较大的那个逆序放入答案并移动指针。
>
> 由于我们得到了两个已经有序的子数组。使用两个指针分别指向两个子数组中平方值分别最大的两个端点位置，每次比较两个指针对应的数，选择较大的那个逆序放入答案并移动指针。当指针重合时，就完成了。
> 
> <font color="yellow">思路2这种方法无需处理某一指针移动至边界的情况，读者可以仔细思考其精髓所在。</font>
>
> **思路2：实现**
> 时间复杂度：`O(n)`，其中 `n` 是数组 `nums` 的长度。
> 空间复杂度：`O(1)`。除了存储答案的数组以外，我们只需要维护常量空间。
> 这里默认空间复杂度是「存储答案的数组以外」的结果，所以空间复杂度为 `O(1)`。意思是，除了存储答案的数组需要的空间为 `O(n)` 以外，我们需要 `O(1)` 的栈空间进行排序。
> 没有必要纠结到底返回答案到底需不需要算在空间复杂度里面。Leetcode的题目要把它当成面试题来看。在面试中，如果你作为面试者碰到了这个题，那么一定要 (1) 和面试官沟通并确认清楚 (2) 给出尽可能全面的答案。说空间复杂度是 O(n) 还是 O(1) 都没有问题，只要你和面试官说明原因就好。
> ```c++
> class Solution {
> public:
>     vector<int> sortedSquares(vector<int>& nums) {   
>         int len = nums.size();
>         vector<int> squa(len);  // 开辟相同长度的空vector
>         int left = 0;
>         int right = len -1;
>         int ptr = len -1; //逆序存放
>         while(left <= right) {
>             if ( nums[left]*nums[left] >= nums[right]*nums[right]) {
>                 squa[ptr] = nums[left]*nums[left];
>                 ++left;
>                 --ptr;
>             } else {
>                 squa[ptr] = nums[right]*nums[right];
>                 --right;
>                 --ptr;                
>             }
>         } 
>         return squa;
>     }
> };
> ```
> 此时的时间复杂度为O(n)，相对于暴力排序的解法O(n + nlog n)还是提升不少的。
> 