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

## 四数相加 II 4sum ii

## _5_4sum_ii.md

--------------------------------------------------------------------------------

### 454. 四数相加 II

> Leetcode链接: https://leetcode.cn/problems/4sum-ii/

> 给你四个整数数组 `nums1`、`nums2`、`nums3` 和 `nums4` ，数组长度都是 `n` ，请你计算有多少个元组 `(i, j, k, l)` 能满足：
> 
> * `0 <= i, j, k, l < n`
> * `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`
>
>
> **示例1：**
> 
> ```html
> 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
> 输出：2
> 解释：
> 两个元组如下：
> 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
> 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
> ```
>
>
> **示例2：**
> 
> ```html
> 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
> 输出：1
> ```
> 
>
> **提示：**
> * `n == nums1.length`
> * `n == nums2.length`
> * `n == nums3.length`
> * `n == nums4.length`
> * `1 <= n <= 200`
> * `-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228`
>
> ```c++
> class Solution {
> public:
>     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
> 
>     }
> };
> ```
> 
> 










#### 我的解法  超出时间限制 57 / 132 个通过的测试用例

> 
>
> 本题做法借鉴`_4_two_sum.md`
>
> 我们可以拆分成两个部分
>
> * `add12`：`nums1[i]`+`nums2[j]`   ==========   `target`
> * `add34`: `nums3[i]`+`nums4[j]`   ==========   `_target`
> 
> 寻找`add12`和`add34`求和为`0`的两个互为相反数的值`target` 和 `_target`
>
> 
> 对于`add12` ====== `target`
>
> 如何借鉴`_4_two_sum.md`中的方法？（`_target`也是一样）
> 
>
> `_4_two_sum.md`中是从同一个数组中寻找，`vector<int> twoSum(vector<int>& nums, int target){}`, 因为只有一个答案，所以需要返回下标
>
> 我们这里需要新建一个函数`int twoSum(vector<int>& nums1, vector<int>& nums2, int target){}`，这里面可能有不同的组合，不返回下标，返回组合种类就行
> 
>
> 

```c++
class Solution {
public:

    int twoSum(vector<int>& nums1, vector<int>& nums2, int target) {
        int result = 0;
        for(int i=0; i < nums1.size(); i++) {
            for(int j=0; j < nums2.size(); j++) {
                int add = nums1[i] + nums2[j];
                if(add == target) {
                    ++result;
                }
            }
        }
        return result;
    }


    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 统计nums1[i]+nums2[j]各种组合值
        unordered_set<int> add12;    
        unordered_set<int> set1(nums1.begin(), nums1.end()); // 去重
        unordered_set<int> set2(nums2.begin(), nums2.end()); // 去重
        unordered_set<int>::iterator it1;
        unordered_set<int>::iterator it2;
        for(it1 = set1.begin(); it1 != set1.end(); it1++) {
            for(it2 = set2.begin(); it2 != set2.end(); it2 ++) {
                add12.insert(*it1 + *it2);
            }           
        }
        // 统计nums3[i]+nums4[j]各种组合值
        unordered_set<int> add34;    
        unordered_set<int> set3(nums3.begin(), nums3.end()); // 去重
        unordered_set<int> set4(nums4.begin(), nums4.end()); // 去重
        unordered_set<int>::iterator it3;
        unordered_set<int>::iterator it4;
        for(it3 = set3.begin(); it3 != set3.end(); it3++) {
            for(it4 = set4.begin(); it4 != set4.end(); it4++) {
                add34.insert(*it3 + *it4);
            }           
        }
        
        // 计算
        int result = 0;
        unordered_set<int>::iterator it;
        for(it = add12.begin(); it != add12.end(); it++) { 
            if(add34.find(0 - *it) != add34.end()) { // add34中存在add12对应的相反值
                int temp1 = twoSum(nums1, nums2, *it);     // nums1[i]+nums2[j] = *it的两数相加组合种类有几种
                int temp2 = twoSum(nums3, nums4, (0-*it)); // nums3[i]+nums4[j] = 0 - *it的两数相加组合种类有几种      
                result = result + temp1 * temp2;      // 更新四数相加为0的种类数      
            }
        }

        
        return result;
    } 

};
```




#### 代码随想录

>
> 本题咋眼一看好像和`_7_3sum.md`，`_8_4sum.md`差不多，其实差很多。
>
> **本题是使用哈希法的经典题目**，而`_7_3sum.md`，`_8_4sum.md`**并不合适使用哈希法**，因为三数之和和四数之和这两道题目使用哈希法在不超时的情况下做到对结果去重是很困难的，很有多细节需要处理。
>
> **而这道题目是四个独立的数组，只要找到`A[i] + B[j] + C[k] + D[l] = 0`就可以，不用考虑有重复的四个元素相加等于`0`的情况，所以相对于`_7_3sum.md`，`_8_4sum.md`，还是简单了不少！**
>
> 如果本题想难度升级：就是给出一个数组（而不是四个数组），在这里找出四个元素相加等于0，答案中不可以包含重复的四元组，大家可以思考一下，后续的文章我也会讲到的。
>
> 本题解题步骤：
> 
> 1. 首先定义 一个`unordered_map`，`key`放`a`和`b`两数之和，`value` 放`a`和`b`两数之和出现的次数。
> 2. 遍历大`A`和大`B`数组，统计两个数组元素之和，和出现的次数，放到`map`中。
> 3. 定义`int`变量`count`，用来统计 `a+b+c+d = 0` 出现的次数。
> 4. 在遍历大`C`和大`D`数组，找到如果 `0-(c+d)` 在`map`中出现过的话，就用`count`把`map`中`key`对应的`value`也就是出现次数统计出来。
> 5. 最后返回统计值 `count` 就可以了
> 
> 
> C++代码:
>
> ```c++
> class Solution {
> public:
>     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
>         unordered_map<int, int> umap; //key:a+b的数值，value:a+b数值出现的次数
>         // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
>         for (int a : A) {
>             for (int b : B) {
>                 umap[a + b]++;
>             }
>         }
>         int count = 0; // 统计a+b+c+d = 0 出现的次数
>         // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
>         for (int c : C) {
>             for (int d : D) {
>                 if (umap.find(0 - (c + d)) != umap.end()) {
>                     count += umap[0 - (c + d)];
>                 }
>             }
>         }
>         return count;
>     }
> };
> ```
> 
> 




















