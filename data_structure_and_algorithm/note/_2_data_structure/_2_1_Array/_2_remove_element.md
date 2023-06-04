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

## 移除元素 remove elements

## _2_remove_element.md

--------------------------------------------------------------------------------

### 27. 移除元素

> Leetcode链接: https://leetcode.cn/problems/remove-element/

> 给你一个数组 `nums` 和一个值 `val`，你需要 **原地** 移除所有数值等于 `val` 的元素，并返回移除后数组的新长度。
> 
> 不要使用额外的数组空间，你必须仅使用 `O(1)` 额外空间并 **原地** 修改输入数组。
> 
> 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
>
> 示例 1：
> ```html
> 输入：nums = [3,2,2,3], val = 3
> 输出：2, nums = [2,2]
> 解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
> ```
> 示例 2：
> ```html
> 输入：nums = [0,1,2,2,3,0,4,2], val = 2
> 输出：5, nums = [0,1,4,0,3]
> 解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
> ```
> 
> 提示：
> * `0 <= nums.length <= 100`
> * `0 <= nums[i] <= 50`
> * `0 <= val <= 100`
> 
> ```c++
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
> 
>     }
> };
> ```

#### 最简洁的解法，erase + remove 但是用了两个库 < vector > < algorithm > 的 库函数
> ```c++
> // 时间复杂度：O(1) 但是感觉remove执行也需要时间，估计实际效果跟O(n)一样
> // 空间复杂度：O(1)
>
> // #include <algorithm>  remove函数// Leetcode中不用include 库文件，都会自动包含，我们直接调用就可以
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
>         nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
>         return nums.size();
>     }
> };
> ```


#### 暴力求解，即遍历，找到后erase 但是还是用了个 < vector > 的库函数 erase
> ```c++
> // 时间复杂度：O(n)
> // 空间复杂度：O(1)
>
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
>         vector<int>::iterator it;
>         for (it = nums.begin(); it != nums.end(); it++) {
>             if(*it == val) {
>                 it = nums.erase(it) - 1;
>                 // erase返回值是更新后的容器的被删除元素的后一个元素的迭代器，
>                 // 如果需要指向删除元素的前面一个元素的迭代器就要-1
>                 // erase后，先将it前移一位，这样it++后才会指向被删除元素的后一个元素
>             }
>         }
>         return nums.size();
>     }
> };
> ```
#### 为了锻炼，我们尽量别用库函数，毕竟我们不懂库函数的底层，可能会出一些看不懂的错误
#### 若是不用库函数erase, 可以不把vector看作动态数组，而是看作array[]普通数组
> 这个题目暴力的解法就是两层for循环，一个for循环遍历数组元素 ，第二个for循环更新数组。
> 删除过程如下：
> <div align=center>
> <img src="./images/remove_element_1.gif"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
>
> 很明显暴力解法的时间复杂度是O(n^2)，这道题目暴力解法在leetcode上是可以过的。
> ```c++
> // 时间复杂度：O(n^2)
> // 空间复杂度：O(1)
>
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
>         int len = nums.size();
>         for (int i=0; i < len; i++) {
>             if (nums[i] == val) {  // 发现需要移除的元素，就将数组集体向前移动一位
>                 for(int j=i+1; j < len; j++) {
>                     nums[j-1] = nums[j];
>                 }
>                 i--;   // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
>                 len--; // 此时数组的大小-1
>             }
>         }
>         return len;
>     }
> };
> ```


#### 双指针法   最坏情况是2n， 如果是暴力遍历，  最坏情况是n^2
> **双指针法（快慢指针法）在数组和链表的操作中是非常常见的，很多考察数组、链表、字符串等操作的面试题，都使用双指针法。**
> 
> 双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。
> 定义快慢指针
> * 快指针(右指针)：寻找新数组的元素 ，新数组就是不含有目标元素的数组
> * 慢指针(左指针)：指向更新 新数组下标的位置
>
> 删除过程如下：
> <div align=center>
> <img src="./images/remove_element_2.gif"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
>
> **思路及算法**
> 
> <font color="yellow">左指针负责存储非`val`元素，右指针负责挑选非`val`元素 </font>
> 
> 由于题目要求删除数组中等于 `val` 的元素，因此输出数组的长度一定小于等于输入数组的长度，我们可以把输出的数组直接写在输入数组上。可以使用双指针：右指针 `right` 指向当前将要处理的元素，左指针 `left` 指向下一个将要赋值的位置。
> 
> * 如果右指针指向的元素不等于 `val`，它一定是输出数组的一个元素，我们就将右指针指向的元素复制到左指针位置，然后将左右指针同时右移；
> 
> * 如果右指针指向的元素等于 `val`，它不能在输出数组里，此时左指针不动，右指针右移一位。
> 
> 整个过程保持不变的性质是：区间 `[0,left)` 中的元素都不等于 `val`。当左右指针遍历完输入数组以后，`left` 的值就是输出数组的长度。
> 
> 这样的算法在最坏情况下（输入数组中没有元素等于 `val`，左右指针各遍历了数组一次。
> 
> 
> ```c++
> // 时间复杂度：O(n) 其中 n 为序列的长度。我们只需要遍历该序列至多两次。
> // 空间复杂度：O(1) 我们只需要常数的空间保存若干变量。
> 
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
>         int slowIndex = 0;
>         for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
>             if (nums[fastIndex] != val) {
>                 nums[slowIndex] = nums[fastIndex];
>                 slowIndex++;
>             }
>         }
>         return slowIndex;
>     }
> };
> ```
> **用 左指针 (慢指针)、右指针 (快指针) 更加形象**
> ```c++
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
>         int len = nums.size();
>         int left = 0;
>         for (int right = 0; right < len; right++) {
>             if (nums[right] != val) {
>                 nums[left] = nums[right];
>                 left++;
>             }
>         }
>         return left;
>     }
> };
> ```
> <font color="yellow">左指针负责存储非`val`元素，右指针负责挑选非`val`元素 </font>
> <font color="yellow">同向移动的双指针，不改变元素的相对位置！</font>
>

#### 双指针优化: 相向双指针方法 最坏情况是n ；  同向双指针法  最坏情况是2n
> **思路**
>
> <font color="yellow">依旧是，左指针负责存储非`val`元素，右指针负责挑选非`val`元素 </font>
> <font color="yellow">但是，相向移动的双指针，会改变元素的相对位置！</font>
> 
> 如果要移除的元素恰好在数组的开头，例如序列 `[1,2,3,4,5]`，当 `val` 为 `1` 时，我们需要把每一个元素都左移一位。注意到题目中说：「元素的顺序可以改变」。实际上我们可以直接将最后一个元素 `5` 移动到序列开头，取代元素 `1`，得到序列 `[5,2,3,4]`，同样满足题目要求。这个优化在序列中 `val` 元素的数量较少时非常有效。
> <font color="yellow">实现方面，我们依然使用双指针，两个指针初始时分别位于数组的首尾，向中间移动遍历该序列。</font>
>
> ```c++
> // 时间复杂度：O(n) 其中 n 为序列的长度。我们只需要遍历该序列至多一次。
> // 空间复杂度：O(1) 我们只需要常数的空间保存若干变量。
> 
> // 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
> ```
> 
> **与"同向双指针"不同的是，"相向双指针"避免了需要保留的元素的重复赋值操作。**
> 
> <br>
>

> **算法1 Leetcode官方解法**
> <https://leetcode.cn/problems/remove-element/solutions/730203/yi-chu-yuan-su-by-leetcode-solution-svxi/>
>
> 
> * 如果左指针 `left` 指向的元素 == `val`，
>   则将右指针 `right` 指向的元素覆盖左指针 `left` 的位置，然后右指针 `right` 左移一位。左指针`left`不动
> <br>
> * 如果左指针 `left` 指向的元素 ！= `val`，
>   则左指针右移一位。右指针`right`不动
> <br>  
> * 当左指针 `left` 和右指针 `right` 重合的时候，左右指针遍历完数组中所有的元素。
> <br>
> * 即使过来覆盖的元素也等于 `val`，也不影响，因为这时候左指针没动，下一次循环依旧会检查当前被覆盖的元素，直到左指针指向的元素的值不等于 `val` 为止。
> <br>
> 这样的方法两个指针在最坏的情况下合起来只遍历了数组一次。
> <br>
> ```c++
> 
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
>         int left = 0; 
>         int right = nums.size() - 1;  // 可以改成int right = nums.size() ;
>         while (left <= right) {       // 可以改成left < right
>             if (nums[left] == val) {
>                 nums[left] = nums[right]; // 可以改成 nums[right - 1]
>                 right--;
>                 // 上面只检查了左侧被覆盖的位置是val，右侧挑选出来的可能也是val，无法保证非val
>                 // 所以不能马上left++，等待下一次循环中，再进行判断
>             } else {
>                 left++;
>             }
>         }
>         return left;
>     }
> };
> ```
>
>

> **算法2 代码随想录（这个更好）** 
> <https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF>
> 
> 首先，找左边等于val的元素。
> * while判断，左指针 `left` 指向的元素是否等于 `val`。
>   * 若是 `val`，则跳出while循环，等待被覆盖；
>   * 若不是 `val`，则将左指针 `left` 一直右移，直到指向`val`，然后跳出while循环，等待被覆盖。
> 
> 然后找右边不等于val的元素。
> * while判断，右指针 `right`指向的元素是否等于 `val`。
>   * 若是 `val`，则将右指针 `left` 一直左移，直到不指向`val`，然后跳出while循环，等待被移动；
>   * 若不是 `val`，则跳出while循环，等待被移动。
>
> 最后，如果左指针 `left`仍然在右指针 `right`的左测，
> * 将右边不等于`val`的元素覆盖左边等于`val`的元素。
> * 完成覆盖后，左指针 `left`右移一位，右指针 `right`左移一位
> 
> 当左指针 `left` 和右指针 `right` 重合的时候，左右指针遍历完数组中所有的元素。
> 
> 这样的方法两个指针在最坏的情况下合起来只遍历了数组一次。
> 
>
> ```c++
> 
> class Solution {
> public:
>     int removeElement(vector<int>& nums, int val) {
>         int left = 0;
>         int right = nums.size() - 1;
>         while (left <= right) {
>             // 找左边等于val的元素
>             while (left <= right && nums[left] != val){
>                 left++;
>             }
>             // 找右边不等于val的元素
>             while (left <= right && nums[right] == val) {
>                 right--;
>             }
>             // 将右边不等于val的元素覆盖左边等于val的元素
>             if (left < right) {
>                 nums[left] = nums[right];
>                 left++;
>                 right--;
>             }
>         }
>         return left;   // left一定指向了最终数组末尾的下一个元素
>     }
> };
> ```
> <font color="yellow">  疑问？ </font>
> 为什么嵌套循环的两个while条件，仍然要加上 `left <= right &&`, 外围while的判断条件不是已经有了吗？
> 因为嵌套循环中的也在移动left，有可能造成移动一次后，出现 `left > right ` 的情况,而且这时候如果`nums[left] != val`成立，则造成left过多移动，`return left`后就变了。
>
> <br>
>

> 我觉得，leetcode官方给的相向双指针算法，更简洁； <font color="yellow">  但是，代码随想录的相向双指针算法，思路更加清晰，易记忆。 </font>
> 








