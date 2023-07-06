# cpp_algorithms

* 代码随想录 https://programmercarl.com/

* geeksforgeeks https://www.geeksforgeeks.org

--------------------------------------------------------------------------------
> **大家不必太在意leetcode上执行用时，打败多少多少用户，这个就是一个玩具，非常不准确。**
> 
> 做题的时候自己能分析出来时间复杂度就可以了，至于leetcode上执行用时，大概看一下就行，只要达到最优的时间复杂度就可以了，
> 
> 一样的代码多提交几次可能就击败百分之百了....
--------------------------------------------------------------------------------

# 回溯算法

https://www.geeksforgeeks.org/backtracking-algorithms/

--------------------------------------------------------------------------------

>
> **回溯和递归是一一对应的，有一个递归，就要有一个回溯**
>
> **回溯要和递归永远在一起，世界上最遥远的距离是你在花括号里，而我在花括号外！**
>
> 

--------------------------------------------------------------------------------

## 回溯算法理论基础

## backtracking_algorithms.md

--------------------------------------------------------------------------------

https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html

--------------------------------------------------------------------------------

### 什么是回溯法（即递归法的回溯部分）

>
> 回溯法也可以叫做回溯搜索法，它是一种搜索的方式。
>
> 在二叉树系列中，我们已经不止一次，提到了回溯，例如[二叉树：以为使用了递归，其实还隐藏着回溯](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E9%80%92%E5%BD%92%E5%B8%A6%E7%9D%80%E5%9B%9E%E6%BA%AF.html)
>
> 具体看`.../_2_data_structure/_2_6_Binary_Tree/_6_binary_tree_paths.md`
>
> > https://programmercarl.com/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.html
>
>  
> <font color="gree">回溯是递归的副产品，只要有递归就会有回溯。
>
> **<font color="gree">所以以下讲解中，回溯函数也就是递归函数，指的都是一个函数。</font>**
>
> 

### 回溯法的效率

> 
> 回溯法的性能如何呢，这里要和大家说清楚了，**虽然回溯法很难，很不好理解，但是回溯法并不是什么高效的算法。**
>
> **因为回溯的本质是穷举，穷举所有可能，然后选出我们想要的答案**，如果想让回溯法高效一些，可以加一些剪枝的操作，但也改不了回溯法就是穷举的本质。
>
> 那么**既然回溯法并不高效为什么还要用它呢？**
> 
> **因为没得选，一些问题能暴力搜出来就不错了**，撑死了再剪枝一下，还没有更高效的解法。
>
> 此时大家应该好奇了，都什么问题，这么牛逼，只能暴力搜索。
> 
> 

### 回溯法解决的问题

> <font color="gree">
> 
> 回溯法，一般可以解决如下几种问题：
>
> * 组合问题：`N`个数里面按一定规则找出`k`个数的集合
> * 切割问题：一个字符串按一定规则有几种切割方式
> * 子集问题：一个`N`个数的集合里有多少符合条件的子集
> * 排列问题：`N`个数按一定规则全排列，有几种排列方式
> * 棋盘问题：`N`皇后，解数独等等
>
> </font>
>
> **相信大家看着这些之后会发现，每个问题，都不简单！**
>
> 另外，会有一些同学可能分不清什么是组合，什么是排列？
>
> **组合是不强调元素顺序的，排列是强调元素顺序**。
>
> 例如：`{1, 2}` 和 `{2, 1}` 在组合上，就是一个集合，因为不强调顺序，而要是排列的话，`{1, 2}` 和 `{2, 1}` 就是两个集合了。
>
> 记住组合无序，排列有序，就可以了。
> 


### 如何理解回溯法 （ 数组 -> `N`插树，遍历时需要回溯）

> 
> **回溯法解决的问题都可以抽象为树形结构**，是的，我指的是<font color="yellow">所有回溯法的问题都可以抽象为树形结构！</font>
>
> 因为回溯法解决的都是在集合中递归查找子集，**集合的大小就构成了树的宽度，递归的深度构成了树的深度**。
>
> **即，数组都可以抽象为`N`叉树， 但是很多时候并不是`N`叉树， 只是我们的逻辑结构像一个树而已，例如`_1_combinations.md`**
>
> 递归就要有终止条件，所以必然是一棵高度有限的树（`N`叉树）。
>
> 这块可能初学者还不太理解，**后面的回溯算法解决的所有题目中，我都会强调这一点并画图举相应的例子**，现在有一个印象就行
> 
> 

### 回溯法模板

> 
> 这里给出`Carl`总结的回溯算法模板。
>
> 在讲[二叉树的递归](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html)中我们说了**递归三部曲**，这里我再给大家列出**回溯三部曲**。
> 
>
> * **回溯函数模板返回值以及参数**
> > 
> > 在回溯算法中，我的习惯是函数起名字为`backtracking()`，这个起名大家随意。
> > ( 递归法中，我习惯起`recursion()` )
> > 
> > 回溯算法中函数返回值一般为`void`。
> > 
> > 再来看一下参数
> > 
> > <font color="gree">因为回溯算法需要的参数可不像二叉树递归的时候那么容易一次性确定下来，所以一般是先写逻辑，然后需要什么参数，就填什么参数。</font>
> > 
> > 因为：二叉树递归，参数经常是`(TreeNode* node, vector<int>& result)`之类的，有经验的可以直接写出来，相对容易确定参数。
> > 
> > <font color="yellow">但后面的回溯题目的讲解中，为了方便大家理解，我在一开始就帮大家把参数确定下来。</font>
> > 
> >  **回溯函数伪代码如下：**
> >  
> > ```c++ {.line-numbers}
> > void backtracking(参数)
> > ```
> > 
> 
> * **回溯函数终止条件**
> > 
> > 既然是树形结构，那么我们在讲解二叉树的递归=的时候，就知道遍历树形结构一定要有终止条件。
> > 所以回溯也有要终止条件。
> > 
> > 什么时候达到了终止条件，树中就可以看出，<font color="yellow">一般来说搜到叶子节点了，也就找到了满足条件的一条答案，把这个答案存放起来，并结束本层递归。</font>
> > 
> > **回溯函数终止条件伪代码如下：**
> >  
> > ```c++ {.line-numbers}
> > if (终止条件) {
> > 存放结果;
> > return;
> > }
> > ```
> > 
>
> * **回溯搜索的遍历过程**
> > 
> > 在上面我们提到了，回溯法一般是在集合中递归搜索，集合的大小构成了树的宽度，递归的深度构成了树的深度。
> > 
> > 如图：**图中并不是`4叉树`, 只是树形而已**
> > 
> > <div align=center>
> > <img src="./images/backtracking_algorithms_1.png" style="zoom:100%;"/>
> > </div>
> >  
> > <font color="gree">注意图中，我特意举例集合大小和孩子的数量是相等的！</font> 
> > 
> > 这句话我没看懂，代码随想录想表达什么？
> > 就是图中节点的说明而已：节点的`size：i`中的`i`表示孩子节点数量
> > 
> > **回溯函数遍历过程伪代码如下：**
> > ```c++ {.line-numbers}
> > for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
> >     处理节点;
> >     backtracking(路径，选择列表); // 递归
> >     回溯，撤销处理结果
> > }
> > ```
> > 
> > `for`循环就是遍历集合区间，可以理解一个节点有多少个孩子，这个`for`循环就执行多少次。二叉树中没用`for`循环，是因为最多有两个左右孩子；如果是`N`叉树，孩子较多，用`for`循环就更加间接。
> > 
> > `backtracking`这里自己调用自己，实现递归。
> > 
> > 大家可以从图中看出 **<font color="gree"> `for`循环可以理解是横向遍历，`backtracking`（递归）就是纵向遍历</font>**，这样就把这棵树全遍历完了，一般来说，搜索叶子节点就是找的其中一个结果了。
> > 
> 
> * **分析完过程，回溯算法模板框架如下：**
> 
> ```c++ {.line-numbers}
> void backtracking(参数) {
>     if (终止条件) {
>         存放结果;
>         return;
>     }
> 
>     for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
>         处理节点;
>         backtracking(路径，选择列表); // 递归
>         回溯，撤销处理结果
>     }
> }
> ```
> 
> **<font color="gree"> 这份模板很重要，后面做回溯法的题目都靠它了！</font>**
>
> 如果从来没有学过回溯算法的录友们，看到这里会有点懵，后面开始讲解具体题目的时候就会好一些了，已经做过回溯法题目的录友，看到这里应该会感同身受了。
>
> 
> **<font color="gree"> 其实，将回溯法模板，与二叉树的前序的递归法模板，对比后，我们会发现，逻辑完全一样！！！</font>**
> 
> **因为回溯法的模板本身就是`N`叉树的前序遍历，当然适用于`N=2`的情况了！！！ 我们一般会选用前序遍历，如果选用中序和后序，思考起来别扭一些。**
>
> 



### 总结

>
> 本篇我们讲解了，什么是回溯算法，知道了回溯和递归是相辅相成的。
> 
> 接着提到了回溯法的效率，回溯法其实就是暴力查找，并不是什么高效的算法。
> 
> 然后列出了回溯法可以解决几类问题，可以看出每一类问题都不简单。
> 
> 最后我们讲到回溯法解决的问题都可以抽象为树形结构（`N`叉树），并给出了回溯法的模板。
> 
> 今天是回溯算法的第一天，按照惯例`Carl`都是先概述一波，然后在开始讲解具体题目，没有接触过回溯法的同学刚学起来有点看不懂很正常，后面和具体题目结合起来会好一些。
> 
> 



### 举例

> 
> `.../_2_data_structure/_2_6_Binary_Tree/_6_binary_tree_paths.md`
>
> `leetcode`: `257. 二叉树的所有路径` https://leetcode.cn/problems/binary-tree-paths/
> 
> > 代码随想录：https://programmercarl.com/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.html
>
> **该题目，可以明确写出回溯，代码结构就是用了回溯法的模板**
> 
> ```c++
> class Solution {
> public:  
>     // 递归函数
>     // 结果集 vector<string>& allpath: 传引用，因为所有路径都需要存进去， 需要使用同一个路径容器
>     // root到当前节点路径上的节点集 vector<TreeNode*>& nodeset：传引用，方便回溯到上一层的父节点
>     void recursion(TreeNode* node, vector<string>& allpath, vector<TreeNode*>& nodeset) {      
>         // 先中
>         nodeset.push_back(node); // 当前节点，加入路径
>         // 如果当前节点node为叶子节点，则转化为字符串，返回到父节点
>         if(node->left == nullptr && node->right == nullptr) {
>             // 路径转化为string
>             string str;
>             for (int i = 0; i < nodeset.size() - 1; i++) {
>                 str += to_string(nodeset[i]->val);
>                 str += "->";
>             }
>             str += to_string(nodeset[nodeset.size() - 1]->val);
>             allpath.push_back(str);
>             return;
>         }   
>         // 再左
>         if(node->left != nullptr) {
>             recursion(node->left, allpath, nodeset); // 递归深入  
>             nodeset.pop_back(); // 回溯
>             // 恢复到进入左孩子之前，这样我们才能进入右孩子，正确建立路径数组
>         }
>         // 最后右
>         if(node->right != nullptr) {
>             recursion(node->right, allpath, nodeset); // 递归深入  
>             nodeset.pop_back(); // 回溯
>             // 恢复到进入左右孩子之前，这样我们才能返回父节点，保证路径数组正确
>         }
>     }
> 
>     vector<string> binaryTreePaths(TreeNode* root) {
>         vector<string> allpath;
>         if(root == nullptr) return allpath; // 若root为空则返回空集
>         // 从root开始遍历
>         vector<TreeNode*> nodeset; // 路径上的节点集
>         recursion(root, allpath, nodeset);
>         // 返回
>         return allpath;
>     } 
> };
> ```
> 
>
> **也可以隐含回溯，代码结构也是用了回溯法的模板**
> 
> 
> ```c++
> class Solution {
> public:  
>     // 递归函数
>     // 结果集 vector<string>& allpath: 传引用，因为所有路径都需要存进去， 需要使用同一个路径容器
>     // 从root开始已走过的路径 string nodepath：传值，这样每次都会拷贝nodepath，将每条路径的分开，不会互相影响
>     void recursion(TreeNode* node, string nodepath, vector<string>& allpath) { 
>         // 若node为空则返回
>         // 其实这里多此一举了，进入之前就已经判断过不为空
>         if(node == nullptr) return;        
>         // 先中
>         nodepath += to_string(node->val); // 当前路径加入节点, int值转为string值
>         // 如果当前节点node为叶子节点，则返回
>         if(node->left == nullptr && node->right == nullptr) {
>             allpath.push_back(nodepath);
>             return;
>         }   
>         // 如果是非叶子节点，则string加入值后，需要加入"->"
>         nodepath += "->";     
>         // 开始向下到左右孩子
>         // 再左
>         if(node->left != nullptr) recursion(node->left, nodepath, allpath);
>         // 最后右
>         if(node->right != nullptr) recursion(node->right, nodepath, allpath);
>         return;
>     }
> 
>     vector<string> binaryTreePaths(TreeNode* root) {
>         vector<string> allpath;
>         if(root == nullptr) return allpath; // 若root为空则返回空集
>         // 从root开始遍历
>         string nodepath; // 空路径
>         recursion(root, nodepath, allpath);
>         // 返回
>         return allpath;
>     } 
> };
> ```
>















