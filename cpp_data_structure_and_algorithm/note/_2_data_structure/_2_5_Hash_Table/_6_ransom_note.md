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

## 赎金信 ransom note

## _6_ransom_note.md

--------------------------------------------------------------------------------

### 383. 赎金信

> Leetcode链接: https://leetcode.cn/problems/ransom-note/

> 给你两个字符串：`ransomNote` 和 `magazine` ，判断 `ransomNote` 能不能由 `magazine` 里面的字符构成。
> 
> 如果可以，返回 `true` ；否则返回 `false` 。
> 
> `magazine` 中的每个字符只能在 `ransomNote` 中使用一次。
> 
> 
>
> **示例1：**
> 
> ```html
> 输入：ransomNote = "a", magazine = "b"
> 输出：false
> ```
>
> **示例2：**
> 
> ```html
> 输入：ransomNote = "aa", magazine = "ab"
> 输出：false
> ```
>
> **示例3：**
> 
> ```html
> 输入：ransomNote = "aa", magazine = "aab"
> 输出：true
> ```
>
> **提示：**
> * `1 <= ransomNote.length, magazine.length <= 105`
> * `ransomNote` 和 `magazine` 由小写英文字母组成
>
> ```c++
> class Solution {
> public:
>     bool canConstruct(string ransomNote, string magazine) {
> 
>     }
> };
> ```
> 
> 



#### 我的解法

> **先分析**
>
> ```c++
> class Solution {
> public:
>     bool canConstruct(string ransomNote, string magazine) {
>         // 问题本质：ransomNote的每个字符必须在magazine中能找到，并且出现次数不能小于magazine中出现的次数
> 
>         // 统计magazine中每个字符出现的次数
>         // std::unordered_map<char, int> map
> 
> 
>         // 遍历ransomNote，find是否在magazine中有
>         // 只要有一次没有，直接返回false
>         // 每找到一次，就将magazine_map(key) - 1 
> 
> 
>         // 最后检查map中的value是否都>=0, 只要有<0的，返回false
> 
> 
>         // 没问题了，返回true
> 
>     }
> };
> ```
> 
> 
> 
> **再写实际代码**
>
> ```c++
> class Solution {
> public:
>     bool canConstruct(string ransomNote, string magazine) {
>         // 问题本质：ransomNote的每个字符必须在magazine中能找到，并且出现次数不能小于magazine中出现的次数
> 
>         // 统计magazine中每个字符出现的次数
>         // std::unordered_map<char, int> map
>         unordered_map<char, int> str_map;
>         for(size_t i=0; i < magazine.size(); i++) {
>             str_map[magazine[i]] = 0;                         // 每个key对应的value值，初始化为0
>         }        
>         for(size_t i=0; i < magazine.size(); i++) {
>             str_map[magazine[i]]++; // 每检测到一次key，对应的value+1
>         }
> 
>         // 遍历ransomNote，find是否在magazine中有
>         // 每找到一次，就将magazine_map(key) - 1 
>         // 只要有一次没有，直接返回false
>         for(size_t i=0; i < ransomNote.size(); i++) {
>             if(str_map.find(ransomNote[i]) != str_map.end()) {  // magazine中存在字符ransomNote[i]
>                 str_map[ransomNote[i]]--;      // 每找到一次，就将magazine_map(key) - 1 
>             }
>             else {
>                 return false;   // 只要有一种字符没有，直接返回false
>             }
>         }
> 
>         // 最后检查map中的value是否都>=0, 只要有<0的，返回false
>         unordered_map<char, int>::iterator it;
>         for(it = str_map.begin(); it != str_map.end(); it++) {
>             if(it->second < 0) {
>                 return false;   // 只要有<0的，返回false
>             }
>         }
> 
>         // 没问题了，返回true
>         return true;
> 
>     }
> };
> ```
> 
> 





#### 代码随想录


> 这道题目和`_1_valid_anagram.md`很像，`_1_valid_anagram.md`相当于求 `字符串a` 和 `字符串b` 是否可以相互组成 ，而这道题目是求 `字符串a`能否组成`字符串b`，而不用管`字符串b` 能不能组成`字符串a`。
>
> 本题判断第一个字符串`ransom`能不能由第二个字符串`magazines`里面的字符构成，但是这里需要注意两点。
> 
> * 第一点“为了不暴露赎金信(`ransom`)字迹，要从杂志(`magazines`)上搜索各个需要的字母，组成单词来表达意思”  这里说明杂志里面的字母不可重复使用。
> 
> * 第二点 “你可以假设两个字符串均只含有小写字母。” 说明只有小写字母，这一点很重要
> 
> 
> 

##### 暴力解法

> 
> 那么第一个思路其实就是暴力枚举了，两层`for`循环，不断去寻找，代码如下：
>
> ```c++
> // 时间复杂度: O(n^2)
> // 空间复杂度：O(1)
> class Solution {
> public:
>     bool canConstruct(string ransomNote, string magazine) {
>         for (int i = 0; i < magazine.length(); i++) {
>             for (int j = 0; j < ransomNote.length(); j++) {
>                 // 在ransomNote中找到和magazine相同的字符
>                 if (magazine[i] == ransomNote[j]) {
>                     ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
>                     break;
>                 }
>             }
>         }
>         // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
>         if (ransomNote.length() == 0) {
>             return true;
>         }
>         return false;
>     }
> };
> ```
> 
> 这里时间复杂度是比较高的，而且里面还有一个字符串删除也就是`erase`的操作，也是费时的，当然这段代码也可以过这道题。
>
> 


##### 哈希解法

>
> 因为题目中只有小写字母，那可以采用空间换取时间的哈希策略， 用一个长度为`26`的数组还记录`magazine`里字母出现的次数。
> 
> 然后再用`ransomNote`去验证这个数组是否包含了`ransomNote`所需要的所有字母。
> 
> 依然是数组在哈希法中的应用。
> 
> 一些同学可能想，用数组干啥，都用`map`完事了，**其实在本题的情况下，使用`map`的空间消耗要比数组大一些的，因为`map`要维护红黑树或者哈希表，而且还要做哈希函数，是费时的！数据量大的话就能体现出来差别了。 所以数组更加简单直接有效**！
>
> <font color="yellow">
> 
> 其实这里不对吧，我们用`std::unordered_map`，空间复杂度也高吗？
> 
> </font>
> 
> 代码如下：
>
> ```c++
> // 时间复杂度: O(n)
> // 空间复杂度：O(1)
> class Solution {
> public:
>     bool canConstruct(string ransomNote, string magazine) {
>         int record[26] = {0};
>         //add
>         if (ransomNote.size() > magazine.size()) {
>             return false;
>         }
>         for (int i = 0; i < magazine.length(); i++) {
>             // 通过recode数据记录 magazine里各个字符出现次数
>             record[magazine[i]-'a'] ++;
>         }
>         for (int j = 0; j < ransomNote.length(); j++) {
>             // 遍历ransomNote，在record里对应的字符个数做--操作
>             record[ransomNote[j]-'a']--;
>             // 如果小于零说明ransomNote里出现的字符，magazine没有
>             if(record[ransomNote[j]-'a'] < 0) {
>                 return false;
>             }
>         }
>         return true;
>     }
> };
> ```
> 
> 













