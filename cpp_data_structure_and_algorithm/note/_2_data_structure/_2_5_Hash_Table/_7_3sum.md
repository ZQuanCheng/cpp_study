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

## 三数之和 3sum

## _7_3sum.md

--------------------------------------------------------------------------------

### 15. 三数之和

> Leetcode链接: https://leetcode.cn/problems/3sum/

> 给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请
>
> 你返回所有和为 `0` 且不重复的三元组。
>
> **注意：答案中不可以包含重复的三元组**。
> 
>
> **示例1：**
> 
> ```html
> 输入：nums = [-1,0,1,2,-1,-4]
> 输出：[[-1,-1,2],[-1,0,1]]
> 解释：
> nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
> nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
> nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
> 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
> 注意，输出的顺序和三元组的顺序并不重要。
> ```
>
> **示例2：**
> 
> ```html
> 输入：nums = [0,1,1]
> 输出：[]
> 解释：唯一可能的三元组和不为 0 。
> ```
>
> **示例3：**
> 
> ```html
> 输入：nums = [0,0,0]
> 输出：[[0,0,0]]
> 解释：唯一可能的三元组和为 0 。
> ```
>
>
> **提示：**
> * `3 <= nums.length <= 3000`
> * `-105 <= nums[i] <= 105`
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> threeSum(vector<int>& nums) {
> 
>     }
> };
> ```
> 
>
> **提示：**
> * `3 <= nums.length <= 3000`
> * `-10^5 <= nums[i] <= 10^5`
>





#### 我的解法 没做出来, 不知道该怎么去重复三元组， 而且放入vector中再去重，恐怕时间复杂度过高，必然超时

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> xiaobiao;
        // 保证i != j && i != k && j != k
        // 由于下标不能重复，所以按照顺序来遍历
        // 选定三元组最前面的元素，就可以得到后两个的和，看看后续有没有对应的下标
        int length = nums.size();
        for(int i=0; i < length; i++) {
            int twosum = 0 - nums[i];
            for(int j=i+1; j < length; j++) {
                int third = twosum - nums[j];
                auto iter = find(nums.begin()+j+1, nums.end(), third);
                if(iter != nums.end()) {
                    int k = iter - nums.begin();
                    vector<int> temp = {i, j, k};  // 暂存三元组的下标
                    xiaobiao.push_back(temp);
                    // 要保证之前没有出现过跟当前三元组一样的组合
                }

            }
        }
        
        // 下标转换为值
        vector<vector<int>> &value = xiaobiao; // 引用
        // 因为不知道具体的长度，所以我们用迭代器更方便
        vector<vector<int>>::iterator row;
        vector<int>::iterator col;
        for(row = value.begin(); row != value.end(); row++) {
            for(col = (*row).begin(); col != (*row).end(); col++) {
                *col = nums[*col];
            }
        }      

        // 去除value中重复的三元组



        

        return value;
    }
};
```

> 可以验证上面的代码是没问题的，只是没去重
```c++
#include <iostream>  
#include <vector>
using namespace std; 

int main()
{

        vector<int> nums = {-1,0,1,2,-1,-4};
        cout << "vector<int> nums = {";
        for(size_t i=0; i < nums.size(); i++) {
            cout << nums[i] << ", ";
        }
        cout << "}" << endl;   


        vector<vector<int>> xiaobiao;
        int length = nums.size();
        cout << "length:" << length << endl;
        // 由于下标不能重复，所以按照顺序来遍历
        // 选定三元组最前面的元素，就可以得到后两个的和，看看后续有没有对应的下标
        for(int i=0; i < length; i++) {
            for(int j=i+1; j < length; j++) {
                int third = 0 - nums[i] - nums[j];
                auto iter = find(nums.begin()+j+1, nums.end(), third);
                if(iter != nums.end()) {
                    int k = iter - nums.begin();
                    vector<int> temp = {i, j, k};  // 暂存三元组的下标
                    xiaobiao.push_back(temp);
                    // 要保证之前没有出现过跟当前三元组一样的组合
                }

            }

        }


        vector<vector<int>>::iterator row;
        vector<int>::iterator col;
        cout << "下标三元组: {";
        for(row = xiaobiao.begin(); row != xiaobiao.end(); row++) {
            cout << "{";
            for(col = (*row).begin(); col != (*row).end(); col++) {
                cout << *col << ", ";
            }
            cout << "}, ";
        }
        cout << "}" << endl;


        

        vector<vector<int>> &value = xiaobiao;      
        for(row = value.begin(); row != value.end(); row++) {
            for(col = (*row).begin(); col != (*row).end(); col++) {
                *col = nums[*col];
            }
        }

        cout << "值三元组: {";
        for(row = value.begin(); row != value.end(); row++) {
            cout << "{";
            for(col = (*row).begin(); col != (*row).end(); col++) {
                cout << *col << ", ";
            }
            cout << "}, ";
        }
        cout << "}" << endl;

    cout << endl;
    pause(); // system("pause"); 

    return 0;
}

```
> 编译并运行
> ```c++
> vector<int> nums = {-1, 0, 1, 2, -1, -4, }
> length:6
> 下标三元组: {{0, 1, 2, }, {0, 3, 4, }, {1, 2, 4, }, }
> 值三元组: {{-1, 0, 1, }, {-1, 2, -1, }, {0, 1, -1, }, }
> ```
> 
> 



#### 代码随想录： 哈希解法

> 两层`for`循环就可以确定 `a` 和`b` 的数值了，可以使用哈希法来确定 `0-(a+b)` 是否在 数组里出现过，其实这个思路是正确的，但是我们有一个非常棘手的问题，就是题目中说的不可以包含重复的三元组。
>
> 把符合条件的三元组放进`vector`中，然后再去重，这样是非常费时的，很容易超时，也是这道题目通过率如此之低的根源所在。
>
> 去重的过程不好处理，有很多小细节，如果在面试中很难想到位。
>
> 时间复杂度可以做到`O(n^2)`，但还是比较费时的，因为不好做剪枝操作。
>
> 大家可以尝试使用哈希法写一写，就知道其困难的程度了。
> 
> 哈希法C++代码:
> 
> ```c++
> class Solution {
> public:
>     vector<vector<int>> threeSum(vector<int>& nums) {
>         vector<vector<int>> result;
>         sort(nums.begin(), nums.end());
>         // 找出a + b + c = 0
>         // a = nums[i], b = nums[j], c = -(a + b)
>         for (int i = 0; i < nums.size(); i++) {
>             // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
>             if (nums[i] > 0) {
>                 break;
>             }
>             if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
>                 continue;
>             }
>             unordered_set<int> set;
>             for (int j = i + 1; j < nums.size(); j++) {
>                 if (j > i + 2
>                         && nums[j] == nums[j-1]
>                         && nums[j-1] == nums[j-2]) { // 三元组元素b去重
>                     continue;
>                 }
>                 int c = 0 - (nums[i] + nums[j]);
>                 if (set.find(c) != set.end()) {
>                     result.push_back({nums[i], nums[j], c});
>                     set.erase(c);// 三元组元素c去重
>                 } else {
>                     set.insert(nums[j]);
>                 }
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 



#### 代码随想录： 双指针

>
> **其实这道题目使用哈希法并不十分合适**，因为在去重的操作中有很多细节需要注意，<font color="yellow">在面试中很难直接写出没有`bug`的代码。</font>
>
> 而且使用哈希法 在使用两层for循环的时候，能做的剪枝操作很有限，虽然时间复杂度是`O(n^2)`，也是可以在`leetcode`上通过，但是程序的执行时间依然比较长 。
>
> 接下来我来介绍另一个解法：双指针法，**这道题目使用双指针法 要比哈希法高效一些**，那么来讲解一下具体实现的思路。
>
> 动画效果如下：
>
> 
> <div align=center>
> <img src="./images/3sum_1.gif" style="zoom:100%;"/>
> </div>
>
> 
> 拿这个`nums`数组来举例，首先将数组排序，然后有一层`for`循环，`i`从下标`0`的地方开始，同时定一个下标 `left` 定义在`i+1`的位置上，定义下标`right` 在数组结尾的位置上。
>
> 依然还是在数组中找到 `abc` 使得`a + b +c =0`，我们这里相当于 `a = nums[i]`，`b = nums[left]`，`c = nums[right]`。
> 
> 接下来如何移动`left` 和`right`呢， 如果`nums[i] + nums[left] + nums[right] > 0` 就说明 此时三数之和大了，因为数组是排序后了，所以`right`下标就应该向左移动，这样才能让三数之和小一些。
> 
> 如果 `nums[i] + nums[left] + nums[right] < 0` 说明 此时 三数之和小了，`left` 就向右移动，才能让三数之和大一些，直到`left`与`right`相遇为止。
>
> 时间复杂度：`O(n^2)`。
>
> C++代码代码如下：
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> threeSum(vector<int>& nums) {
>         vector<vector<int>> result;
>         sort(nums.begin(), nums.end());
>         // 找出a + b + c = 0
>         // a = nums[i], b = nums[left], c = nums[right]
>         for (int i = 0; i < nums.size(); i++) {
>             // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
>             if (nums[i] > 0) {
>                 return result;
>             }
>             // 错误去重a方法，将会漏掉-1,-1,2 这种情况
>             /*
>             if (nums[i] == nums[i + 1]) {
>                 continue;
>             }
>             */
>             // 正确去重a方法
>             if (i > 0 && nums[i] == nums[i - 1]) {
>                 continue;
>             }
>             int left = i + 1;
>             int right = nums.size() - 1;
>             while (right > left) {
>                 // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
>                 /*
>                 while (right > left && nums[right] == nums[right - 1]) right--;
>                 while (right > left && nums[left] == nums[left + 1]) left++;
>                 */
>                 if (nums[i] + nums[left] + nums[right] > 0) right--;
>                 else if (nums[i] + nums[left] + nums[right] < 0) left++;
>                 else {
>                     result.push_back(vector<int>{nums[i], nums[left], nums[right]});
>                     // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
>                     while (right > left && nums[right] == nums[right - 1]) right--;
>                     while (right > left && nums[left] == nums[left + 1]) left++;
> // 上面保证了left后面，right前面都不是重复的元素（left左移，right右移后不会出现重复三元组）
> 
>                     // 找到答案时，双指针同时收缩
>                     right--;
>                     left++;
>                 }
>             }
> 
>         }
>         return result;
>     }
> };
> ```
> 
> 
> 
> 

> <font color="yellow">
>
> 可以看出，先排序，可以保证`i != j && i != k && j != k`，
>
> 排序后，也可以更方便保证三元组不重复
>
> </font>
>
> 




#### 代码随想录： 去重逻辑的思考


##### a的去重

>
> 说到去重，其实主要考虑三个数的去重。 `a`, `b` ,`c`, 对应的就是 `nums[i]`，`nums[left]`，`nums[right]`
>
> `a` 如果重复了怎么办，`a`是`nums`里遍历的元素，那么应该直接跳过去。
> 
> 但这里有一个问题，是判断 `nums[i]` 与 `nums[i + 1]`是否相同，还是判断 `nums[i]` 与 `nums[i-1]` 是否相同。
> 
> 有同学可能想，这不都一样吗。
> 
> 其实不一样！
> 
> 都是和 `nums[i]`进行比较，是比较它的前一个，还是比较他的后一个。
> 
> 如果我们的写法是 这样：
> 
> ```c++
> if (nums[i] == nums[i + 1]) { // 去重操作
>     continue;
> }
> ```
> 
> 那就我们就把 三元组中出现重复元素的情况直接pass掉了。 例如`{-1, -1 ,2}` 这组数据，当遍历到第一个`-1` 的时候，判断 下一个也是`-1`，那这组数据就pass了。
>
> **我们要做的是 不能有重复的三元组，但三元组内的元素是可以重复的！**
>
> 所以这里是有两个重复的维度。
> 
> 那么应该这么写：
> 
> ```c++
> if (i > 0 && nums[i] == nums[i - 1]) {
>     continue;
> }
> ```
> 
> 这么写就是当前使用 `nums[i]`，我们判断前一位是不是一样的元素，在看 `{-1, -1 ,2}` 这组数据，当遍历到 第一个 `-1` 的时候，只要前一位没有`-1`，那么 `{-1, -1 ,2}` 这组数据一样可以收录到 结果集里。
>
> 这是一个非常细节的思考过程。
>
> 

##### b与c的去重

>
> 很多同学写本题的时候，去重的逻辑多加了 对right 和left 的去重：（代码中注释部分）
>
> ```c++
> while (right > left) {
>     if (nums[i] + nums[left] + nums[right] > 0) {
>         right--;
>         // 去重 right
>         while (left < right && nums[right] == nums[right + 1]) right--;
>     } 
>     else if (nums[i] + nums[left] + nums[right] < 0) {
>         left++;
>         // 去重 left
>         while (left < right && nums[left] == nums[left - 1]) left++;
>     } 
>     else {
>     }
> }
> ```
> 
> 但细想一下，这种去重其实对提升程序运行效率是没有帮助的。
>
> 拿`right`去重为例，即使不加这个去重逻辑，依然根据 `while (right > left)` 和 `if (nums[i] + nums[left] + nums[right] > 0)` 去完成`right--` 的操作。
>
> 多加了 `while (left < right && nums[right] == nums[right + 1]) right--;` 这一行代码，其实就是把 需要执行的逻辑提前执行了，但并没有减少 判断的逻辑。
>
> 最直白的思考过程，就是`right`还是一个数一个数的减下去的，所以在哪里减的都是一样的。
> 
> 所以这种去重 是可以不加的。 仅仅是 把去重的逻辑提前了而已。
> 
> 


#### 思考题

> 既然三数之和可以使用双指针法，我们之前讲过的1.两数之和 (`_4_two_sum.md`)，可不可以使用双指针法呢？
> 
> 如果不能，题意如何更改就可以使用双指针法呢？ 大家留言说出自己的想法吧！
> 
> 两数之和 就不能使用双指针法，因为1.两数之和 (`_4_two_sum.md`)要求返回的是索引下标， 而**双指针法一定要排序**，一旦排序之后原数组的索引就被改变了。
> 
> 如果1.两数之和 (`_4_two_sum.md`)要求返回的是数值的话，就可以使用双指针法了。
>
> 
> 


















