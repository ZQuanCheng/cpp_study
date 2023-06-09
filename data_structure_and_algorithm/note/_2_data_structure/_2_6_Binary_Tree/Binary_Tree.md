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

# 二叉树

--------------------------------------------------------------------------------

## 二叉树理论

## Binary_Tree.md

--------------------------------------------------------------------------------

## 配套：回溯算法理论基础

## backtracking_algorithms.md

--------------------------------------------------------------------------------

<font color="yellow">当我们想保证查找效率时，可以用顺序表(数组)存储，当我们想保证插入和删除效率时，我们可以用链式表存储，有没有一种存储方法可以同时兼顾顺序表和链式表的优点？ 
使用二叉树 ，便可兼顾查找效率和插入删除效率~</font>

<font color="gree">针对二叉树的问题，解题之前一定要想清楚究竟是前中后序遍历，还是层序遍历。</font>

**二叉树解题的大忌就是自己稀里糊涂的过了，但是也不知道自己是怎么遍历的。**

--------------------------------------------------------------------------------

### 二叉树理论基础 各种博客总结(包括 代码随想录)

#### 树的基础知识概述
> 树状图是一种数据结构，它是由 $n(n>=1)$ 个有限结点组成一个具有层次关系的集合。把它叫做“树”是因为它看起来像一棵倒挂的树，也就是说它是根朝上，而叶朝下的。
> 
> 它具有以下的特点：
> 
> 每个结点有零个或多个子结点；没有父结点的结点称为根结点；每一个非根结点有且只有一个父结点；除了根结点外，每个子结点可以分为多个不相交的子树；
> 
> <div align=center>
> <img src="./images/tree_1.jpg" style="zoom:100%;"/>
> </div>
> 
> 
> **注释**：`Height`节点高度的定义需要修改：从当前节点到叶子节点最长路径的边数之和。注意是最长路径，
> 
> 
> **总结**：`Depth`、`Height`、`Level`都是与`edge`关联的概念
>
> `Depth` 深度： 根节点----当前节点               （自上到下称为计算深度）
> `Height`高度：          当前节点----叶子节点   （自下到上称为计算高度）
> `Level` 层级：从根开始定义起，根为第0层，根的子节点为第1层
>
> 
> **疑问**：
> 
> <font color="yellow">
> 
> `Level`层级和`Depth`深度有区别吗？？？层级是针对整个二叉树而言的，深度只是针对当前一个节点而言的。
>
> 一般来说，层级从`1`开始：第`1`层的根节点深度为`1`，第`2`层的节点深度为`2`，第`3`层的节点深度`3`，...
>
> 二叉树的最大深度：根节点到最远叶子节点的最长路径上的节点数量。
> 二叉树的最小深度：根节点到最近叶子节点的最短路径上的节点数量。
> 叶子节点：没有子节点的节点。
> 
> </font>
>
> **补充定义：**
> 
> 节点的度：一个节点含有的子树的个数称为该节点的度（一个节点的孩子个数）
> 树的度：一棵树中，所有节点的度 求最大值，称为树的度（拥有最多孩子的节点的孩子个数）
> 森林：由$m（m>0）$棵互不相交的树的集合称为森林；
> 
> 
> 如图所示：
> 
> <div align=center>
> <img src="./images/tree_2.jpg" style="zoom:50%;"/>
> <img src="./images/tree_3.jpg" style="zoom:50%;"/>
> </div>
>
> 注意：上图中层级从`0`开始了，但是我们一般层级从`1`开始，即根节点为第`1`层
> 

#### 二叉树
##### 1. 二叉树的理论定义
> 二叉树(Binary Tree) 是由$n$个结点构成的有限集$(n≥0)$，$n=0$时为空树，$n>0$时为非空树。对于非空树T：
> 
> * 有且仅有一个根结点；
> * 除根结点外的其余结点又可分为两个不相交的子集$T_L$和$T_R$，分别称为$T$的左子树和右子树，且$T_L$和$T_R$本身又都是二叉树。
>
> <font color="yellow"> 很明显该定义属于递归定义，所以有关二叉树的操作使用递归往往更容易理解和实现。</font>
> 
> <font color="gree">简单来说，二叉树是一个每个结点最多只能有两个分支的树，左边的分支称之为左子树，右边的分支称之为右子树~</font>
> 
> <div align=center>
> <img src="./images/tree_4.jpg" style="zoom:60%;"/>
> </div>
> 
> 
> <font color="yellow">二叉树与一般树的区别主要是两点:
> 
> * 每个结点的度(`Degree`)最多为`2`；
> * 结点的子树有左右之分，不能随意调换，调换后又是一棵新的二叉树。</font>
> 

##### 2. 二叉树的性质

> 
> * 第$i$层的结点总数不超过$2^{i-1},i≥1$
> 
> * 深度为$d$的二叉树最多有$2^d-1$个结点，最少有$d$个结点, $d≥1$。
>
> 性质一是针对一层节点，性质二是整个二叉树的结点总数
> 

> 
> **疑问**：
> 
> <font color="yellow">
> 
> `Level`层级和`Depth`深度有区别吗？？？层级是针对整个二叉树而言的，深度只是针对当前一个节点而言的。
>
> 一般来说，层级从`1`开始：第`1`层的根节点深度为`1`，第`2`层的节点深度为`2`，第`3`层的节点深度`3`，...
>
> 二叉树的最大深度：根节点到最远叶子节点的最长路径上的节点数量。
> 二叉树的最小深度：根节点到最近叶子节点的最短路径上的节点数量。
> 叶子节点：没有子节点的节点。
> 
> </font>
>
>
> 
> 

##### 3. 常见二叉树分类（五种）

**在我们解题过程中二叉树有两种主要的形式：满二叉树和完全二叉树。**

> 1. 满二叉树（完美二叉树）
> 
> > 定义1：除了叶结点外每一个结点都有左右子节点且叶子结点都处在最底层。
> > 
> > 定义2：只有度为`0`的结点和度为`2`的结点，并且度为`0`的结点在同一层上。
> >   
> > <div align=center>
> > <img src="./images/tree_5.jpg" style="zoom:30%;"/>
> > </div>
> > 
> > 这棵二叉树为满二叉树，也可以说深度为$k$（有$k+1$层），有 $2^{k+1}-1$ 个节点的二叉树。
>

> 2. 完全二叉树 
> 
> > 定义1：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且**最下面一层的节点都集中在该层最左边的若干位置**。
> > 
> > 定义2：若设二叉树的高度为 $h$，除第 $h$ 层外，其它各层 ($1～h-1$) 的结点数都达到最大个数，第 $h$ 层有叶子节点，并且**叶子结点都是从左到右依次排布**，这就是完全二叉树。
> > 
> > 
> > <div align=center>
> > <img src="./images/tree_6.jpg" style="zoom:60%;"/>
> > </div>
> > 
> 
> <font color="yellow">有一种数据结构"堆"（也叫优先队列）, 堆可以被看做一棵完全二叉树的数组对象</font>
> > 
> > 堆在物理层面上，表现为一组连续的数组区间：`long[] array` ；将整个数组看作是堆。
> > 
> > 堆在逻辑结构上，一般被视为是一颗完全二叉树。
> > 
> > 堆满足下列性质：
> > 
> > * 堆中某个节点的值总是**不大于或不小于**其父节点的值。
> > * 堆总是一棵完全二叉树。
> > 
> > 这样做是为了保证父子节点的顺序关系
> > 
> > 对应的STL模板类为`std::priority_queue`
> > 
> > ```c++
> > priority_queue<int> pq1; // 等价于priority_queue<int, vector<int>, less<int>> pq;
> > // 默认以vector为底层容器；vector<int>是承载底层数据结构堆 （heap）的容器
> > // 默认以less为比较方式，左边小于右边的时候返回true, 返回true则交换位置，所以排在top的最大，此时优先队列就是大堆，所以优先队列默认就是大堆。 
> > // 如果以greater为比较方式，左边大于右边的时候返回true, 返回true则交换位置，所以排在top的最小，此时优先队列就是小堆，所以优先队列默认就是小堆。 
> > 
> > //大堆：每个结点的值都不大于它的父结点，堆顶元素是最大的。 又叫（大顶堆，大根堆）
> > //小堆：每个结点的值都不小于它的父结点，堆顶元素是最小的。
> > 
> > // 优先级队列`std::priority_queue`更像是`std::stack`，只有`top()`，没有`front()`，没有`back()`
> > 
> > // ``std::priority_queue``和`std::stack`都是可以看作 “ 只能从队尾访问元素的队列`std::queue` ”
> > 
> > // less<int>使得队头元素最小，队尾元素最大，`top()`从队尾访问元素，所以是大顶堆
> > // greater<int>使得队头元素最大，队尾元素最小，`top()`从队尾访问元素，所以是小顶堆
> > ```
> > 
> 
> 






> 3. 二叉搜索树 ——又称二叉查找树、二叉排序树（Binary Sort Tree）
> 
> 二叉搜索树是一个有序树。
> 
> > 它是**一颗空树或是满足下列性质**的二叉树：
> > 
> > 1）若左子树不空，则左子树上所有节点的值均小于或等于它的根节点的值；
> > 
> > 2）若右子树不空，则右子树上所有节点的值均大于或等于它的根节点的值；
> > 
> > 3）左、右子树也分别为二叉排序树。 
> > 
> > 即 **左边<=根<=右边**
> > 
> > 下面这两棵树都是搜索树
> > 
> > 
> > <div align=center>
> > <img src="./images/tree_7.jpg" style="zoom:60%;"/>
> > </div>
> > 
>

> 4. 平衡二叉搜索树---又称 AVL 树（Adelson-Velsky and Landis）
>
> <font color="gree">在 二叉搜索树 的基础上加入限制条件，定义 平衡二叉搜索树</font>
> 
> > 它是**一颗空树或左右两个子树的高度差的绝对值不超过 1**，并且左右两个子树都是一棵平衡二叉树。
> > 
> > <div align=center>
> > <img src="./images/tree_8.jpg" style="zoom:60%;"/>
> > </div>
> > 
> > 最后一棵 不是平衡二叉树，因为它的左右两个子树的高度差的绝对值超过了1。
> > 
>

> 5. 红黑树---平衡二叉查找树（AVL树）+颜色属性
> 
> <font color="gree">在 平衡二叉搜索树 的基础上加入限制条件，定义 红黑树</font>
> 
> > 每个节点都带有颜色属性（颜色为红色或黑色）的自平衡二叉查找树，满足下列性质：
> > 
> > 1）节点是红色或黑色；
> > 
> > 2）根节点是黑色；
> > 
> > 3）所有叶子节点都是黑色；
> > 
> > 4）每个红色节点必须有两个黑色的子节点。(即，从每个叶子到根的所有路径上不能有两个连续为红色的结点)；
> > 
> > 5）从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点。 （没有度为1的结点）。
> > 
> > 以上规则可以保证左右子树结点数差距不超过两倍~
> > 
> > <div align=center>
> > <img src="./images/tree_9.jpg" style="zoom:60%;"/>
> > </div>
> > 
> > <font color="yellow">红黑树很难，我们不需要掌握</font>
> 
> > C++中`map`、`set`、`multimap`，`multiset`的底层实现都是红黑树，所以`map`、`set`的增删操作时间时间复杂度是`logn`.注意我这里没有说`unordered_map`、`unordered_set`.因为`unordered_map`、`unordered_set`底层实现是哈希表。
> > C++ STL中的`set`,`map`底层实现是红黑树，而不是`AVL`，否则需要频繁旋转操作
> > 
> > <div align=center>
> > <img src="./images/hash_table_6.jpg" style="zoom:100%;"/>
> > <img src="./images/hash_table_7.jpg" style="zoom:100%;"/>
> > </div>
> > 
> > 注：红黑树是自平衡的二叉查找树，并不一定是完美的二叉查找树。
> >
> 


##### 4. 二叉树的存储方式

> **二叉树可以链式存储，也可以顺序存储。**
> 
> 那么链式存储方式就用指针， 顺序存储的方式就是用数组。
> 
> 顾名思义就是顺序存储的元素在内存是连续分布的，而链式存储则是通过指针把分布在各个地址的节点串联一起。
> 
> > 链式存储如图：
> >  
> > <div align=center>
> > <img src="./images/tree_10.jpg" style="zoom:100%;"/>
> > </div>
> > 
> 
> > 链式存储是大家很熟悉的一种方式，那么我们来看看如何顺序存储呢？
> > 
> > 其实就是用数组来存储二叉树，顺序存储的方式如图：
> > 
> > <div align=center>
> > <img src="./images/tree_11.jpg" style="zoom:100%;"/>
> > </div>
> > 
> > 用数组来存储二叉树如何遍历的呢？
> > 
> > 如果父节点的数组下标是 $i$，那么它的左孩子就是 $i * 2 + 1$，右孩子就是 $i * 2 + 2$。
> 
> 
> <font color="yellow">用链式表示的二叉树，更有利于我们理解，所以一般我们都是用链式存储二叉树。但是大家要了解，用数组依然可以表示二叉树。</font>
>

##### 5. 二叉树的遍历方式

> 二叉树主要有两种遍历方式：
> 
> > * 深度优先遍历：先往深走，遇到叶子节点再往回走。
> > * 广度优先遍历：一层一层的去遍历。
> 
> 
> 这两种遍历是图论中最基本的两种遍历方式
> 
> 那么**从深度优先遍历和广度优先遍历进一步拓展，才有如下遍历方式：**
>
> > 
> > <font color="green">
> > 
> > * 深度优先遍历
> >   * 前序遍历（递归法，迭代法）  --- 栈(stack)实现
> >   * 中序遍历（递归法，迭代法）  --- 栈(stack)实现
> >   * 后序遍历（递归法，迭代法）  --- 栈(stack)实现
> > * 广度优先遍历
> >   * 层次遍历（迭代法）  --- 队列(queue)实现
> > </font>
> > 
> 
> <font color="green">有时候，前序遍历被称为先序遍历</font>
> 
> 以下是解释：
> > 
> > 在深度优先遍历中：有三个顺序，前中后序遍历，这里前中后，其实指的就是中间节点的遍历顺序.
> > **<font color="green">只要记住 前中后序指的就是中间节点的位置就可以了。</font>**
> > 
> > 看如下中间节点的顺序，就可以发现，中间节点的顺序就是所谓的遍历方式
> > * 前序遍历：中左右
> > * 中序遍历：左中右
> > * 后序遍历：左右中
> > 
> > <div align=center>
> > <img src="./images/tree_12.jpg" style="zoom:100%;"/>
> > </div>
> > 
> >
>
> > 再举一个例子
> > 
> > <div align=center>
> > <img src="./images/tree_13.jpg" style="zoom:100%;"/>
> > </div>
> > 
> > 先序：ABDEHCFIG
> > 中序：DBHEAFICG
> > 后序：DHEBIFGCA
> > 
> > <div align=center>
> > <img src="./images/tree_14.jpg" style="zoom:100%;"/>
> > </div>
>
> 
> > 最后再说一说二叉树中深度优先和广度优先遍历实现方式，<font color="gree">我们做二叉树相关题目，经常会使用递归的方式来实现**深度优先遍历**，也就是实现前中后序遍历，使用递归是比较方便的。</font>
> 
> > 之前我们讲栈与队列的时候，就说过**栈其实就是递归的一种实现结构**，也就说前中后序遍历的逻辑其实都是可以借助栈使用非递归的方式来实现的。
> 
> > <font color="gree">而**广度优先遍历**的实现一般使用队列来实现，这也是队列先进先出的特点所决定的，因为需要先进先出的结构，才能一层一层的来遍历二叉树。</font>
> 
> 
> **这里其实我们又了解了栈与队列的一个应用场景了**。
> 
> 具体的实现我们后面都会讲的，这里大家先要清楚这些理论基础。
>


#### 二叉树的实现
> 之前我们说过了二叉树有两种存储方式顺序存储，和链式存储，顺序存储就是用数组来存，这个定义没啥可说的，我们来看看链式存储的二叉树节点的定义方式。<br>
> ```c++
> // 创建二叉树 TreeNode
> struct TreeNode {
>     int val;
>     TreeNode *left;
>     TreeNode *right;
>     TreeNode() : val(0), left(NULL), right(NULL) {}
>     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
>     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
> };
> 
> 
> // 创建单链表 ListNode
> struct ListNode {
>     int val;  // 节点上存储的元素
>     ListNode *next;  // 指向下一个节点的指针
>     ListNode() : val(0), next(NULL) {}  // 节点的构造函数
>     ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
>     ListNode(int x, ListNode *next) : val(x), next(next) {}  // 节点的构造函数
> };
> 
> ```
> 
> <font color="yellow">大家会发现二叉树的定义 和 链表 是差不多的，相对于链表 ，二叉树的节点里多了一个指针，有两个指针，指向左右子节点。</font>
> 
> 这里要提醒大家要注意二叉树节点定义的书写方式。
> 
> **在现场面试的时候 面试官可能要求手写代码，所以数据结构的定义以及简单逻辑的代码一定要锻炼白纸写出来。**
> 
> 因为我们在刷`leetcode`的时候，节点的定义默认都定义好了，真到面试的时候，需要自己写节点定义的时候，有时候会一脸懵逼！
> 
> 


#### 总结

>
> 二叉树是一种基础数据结构，在算法面试中都是常客，也是众多数据结构的基石。
> 
> 本篇我们介绍了二叉树的种类、存储方式、遍历方式以及定义，比较全面的介绍了二叉树各个方面的重点，帮助大家扫一遍基础。
>
> **说到二叉树，就不得不说递归，很多同学对递归都是又熟悉又陌生，递归的代码一般很简短，但每次都是一看就会，一写就废**。
>
> 



#### 二叉搜索树的实现，各种操作
<https://blog.csdn.net/qq_54169998/article/details/121108627>





--------------------------------------------------------------------------------

### 二叉树的深度优先遍历（递归法）

> 
> https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
> 

>
> https://www.bilibili.com/video/BV1Wh411S7xt
>
> 评论区：
>  
> 写递归靠直觉,这句话没毛病。其实关键的关键是递归终止条件，否则就会写入无限递归。
> 
> 至于递归层本身的处理代码，这个对于大多数人都是没有问题的。
> 
> 递归的难点是如何让递归下探到下一层然后再回归到本层，这也是大多数人没有把握的地方。
>
> 你要学习栈的原理，回过头来就能理解。因为栈`stack`的原理是：后进先出，也就是位于栈顶的元素会首先弹出，这是递归能实现的根本性计算机原理。每一层递归就是一个独立的栈，从栈顶逐步弹出，也就一层层回归到本层，直至回归到最初始的那一层。
> 
> 函数的调用也是栈结构，每次调用就是压栈，`return`就是出栈，顶层`return`之后自然回到上一次调用
>
> 
> 


>
> 一看就会，一写就废！
>
> 这次我们要好好谈一谈递归，为什么很多同学看递归算法都是“一看就会，一写就废”。
>
> 主要是对递归不成体系，没有方法论，每次写递归算法 ，都是靠玄学来写代码，代码能不能编过都靠运气。
>
> **本篇将介绍前后中序的递归写法，一些同学可能会感觉很简单，其实不然，我们要通过简单题目把方法论确定下来，有了方法论，后面才能应付复杂的递归。**
>
> 这里帮助大家确定下来递归算法的三个要素。**每次写递归，都按照这三要素来写，可以保证大家写出正确的递归算法！**
>
> 1. **确定递归函数的参数和返回值**： 确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
> 
> 2. **确定终止条件**： 写完了递归算法, 运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
> 
> 3. **确定单层递归的逻辑**： 确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。
>
> 
> 好了，我们确认了递归的三要素，接下来就来练练手：
> 


> 
> <font color="yellow">先自己做一做`leetcode`上三道题目，分别是：</font>
> 
> 144.二叉树的前序遍历(https://leetcode.cn/problems/binary-tree-preorder-traversal/)
> 
> 94.二叉树的中序遍历(https://leetcode.cn/problems/binary-tree-inorder-traversal/)
>
> 145.二叉树的后序遍历(https://leetcode.cn/problems/binary-tree-postorder-traversal/)
> 
> 
> 
> **前序遍历**
> 
> https://leetcode.cn/problems/binary-tree-preorder-traversal/
> 
> <font color="yellow">我的递归解法为</font>
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     // 递归函数
>     void recursion(TreeNode* node, vector<int>& vec) {
>         // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意传指针或传引用，不要传值
>         // 2. 确定终止条件：只要节点不为空，就往下探索
>         // 3. 确定单层递归的逻辑：先中，再左，最后右
>         if(node != nullptr) {
>             // 先中
>             vec.push_back(node->val);
>             // 再左
>             if(node->left != nullptr) {
>                 recursion(node->left, vec);
>             }
>             // 最后右
>             if(node->right != nullptr) {
>                 recursion(node->right, vec);
>             }            
>         } 
>         return; // void其实不用return
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> preorderTraversal(TreeNode* root) {
>         vector<int> result;
>         recursion(root, result);
>         return result;
>     }
> };
> ```
> 
> 
> 
> 
> **中序遍历**
> 
> https://leetcode.cn/problems/binary-tree-inorder-traversal/
> 
> <font color="yellow">我的递归解法为</font>
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     // 递归函数
>     void recursion(TreeNode* node, vector<int>& vec) {
>         // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意传指针或传引用，不要传值
>         // 2. 确定终止条件：只要节点不为空，就往下探索
>         // 3. 确定单层递归的逻辑：先左，再中，最后右
>         if(node != nullptr) {
>             // 先左
>             if(node->left != nullptr) {
>                 recursion(node->left, vec);
>             }
>             // 再中
>             vec.push_back(node->val);            
>             // 最后右
>             if(node->right != nullptr) {
>                 recursion(node->right, vec);
>             }            
>         } 
>         return; // void其实不用return
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> inorderTraversal(TreeNode* root) {
>         vector<int> result;
>         recursion(root, result);
>         return result;
>     }
> };
> ```
> 
> 
> 
> 
> **后序遍历**
> 
> https://leetcode.cn/problems/binary-tree-postorder-traversal/
> 
> <font color="yellow">我的递归解法为</font>
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     // 递归函数
>     void recursion(TreeNode* node, vector<int>& vec) {
>         // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意传指针或传引用，不要传值
>         // 2. 确定终止条件：只要节点不为空，就往下探索
>         // 3. 确定单层递归的逻辑：先左，再右，最后中
>         if(node != nullptr) {
>             // 先左
>             if(node->left != nullptr) {
>                 recursion(node->left, vec);
>             }         
>             // 再右
>             if(node->right != nullptr) {
>                 recursion(node->right, vec);
>             }      
>             // 最后中
>             vec.push_back(node->val);         
>         } 
>         return; // void其实不用return
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> postorderTraversal(TreeNode* root) {
>         vector<int> result;
>         recursion(root, result);
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
> 反思我的代码哪里有可以优化的 
>
> `if(node->left != nullptr)`和`if(node->right != nullptr)`完全没必要
>
> 因为`recursion(node->left, vec);`和`recursion(node->right, vec);`会进行检查
>
> 这样冗余了
> 
> 修改后的代码如下
> 
> </font>
> 
> 
> **前序遍历**
> 
> https://leetcode.cn/problems/binary-tree-preorder-traversal/
> 
> <font color="yellow">我的优化后的递归解法为</font>
>
> ```c++
> class Solution {
> public:
>     // 递归函数
>     void recursion(TreeNode* node, vector<int>& vec) {
>         // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意传指针或传引用，不要传值
>         // 2. 确定终止条件：只要节点不为空，就往下探索
>         // 3. 确定单层递归的逻辑：先中，再左，最后右
>         if(node != nullptr) {
>             vec.push_back(node->val);     // 先中
>             recursion(node->left, vec);   // 再左
>             recursion(node->right, vec);  // 最后右
>         }
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> preorderTraversal(TreeNode* root) {
>         vector<int> result;
>         recursion(root, result);
>         return result;
>     }
> };
> ```
> 
> 
> **中序遍历**
> 
> https://leetcode.cn/problems/binary-tree-inorder-traversal/
> 
> <font color="yellow">我的优化后的递归解法为</font>
>
> ```c++
> class Solution {
> public:
>     // 递归函数
>     void recursion(TreeNode* node, vector<int>& vec) {
>         // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意传指针或传引用，不要传值
>         // 2. 确定终止条件：只要节点不为空，就往下探索
>         // 3. 确定单层递归的逻辑：先左，再中，最后右
>         if(node != nullptr) {
>             recursion(node->left, vec);   // 先左
>             vec.push_back(node->val);     // 再中            
>             recursion(node->right, vec);  // 最后右
>         }
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> inorderTraversal(TreeNode* root) {
>         vector<int> result;
>         recursion(root, result);
>         return result;
>     }
> };
> ```
>
> 
> **后序遍历**
> 
> https://leetcode.cn/problems/binary-tree-postorder-traversal/
> 
> <font color="yellow">我的优化后的递归解法为</font>
>
> ```c++
> class Solution {
> public:
>     // 递归函数
>     void recursion(TreeNode* node, vector<int>& vec) {
>         // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意传指针或传引用，不要传值
>         // 2. 确定终止条件：只要节点不为空，就往下探索
>         // 3. 确定单层递归的逻辑：先左，再右，最后中
>         if(node != nullptr) {
>             recursion(node->left, vec);   // 先左           
>             recursion(node->right, vec);  // 再右
>             vec.push_back(node->val);     // 最后中             
>         }
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> postorderTraversal(TreeNode* root) {
>         vector<int> result;
>         recursion(root, result);
>         return result;
>     }
> };
> ```
> 




> 
> <font color="gree">接下来是代码随想录的解析</font>
> 
> **以下以前序遍历为例：**
>
> 1. **确定递归函数的参数和返回值**：因为要打印出前序遍历节点的数值，所以参数里需要传入vector来放节点的数值，除了这一点就不需要再处理什么数据了也不需要有返回值，所以递归函数返回类型就是void，代码如下：
>
> ```c++ {.line-numbers}
> void traversal(TreeNode* cur, vector<int>& vec)
> ```
> 
> 2. **确定终止条件**：在递归的过程中，如何算是递归结束了呢，当然是当前遍历的节点是空了，那么本层递归就要结束了，所以如果当前遍历的这个节点是空，就直接`return`，代码如下：
>
> ```c++ {.line-numbers}
> if (cur == NULL) return;
> ```
>
> 3. **确定单层递归的逻辑**：前序遍历是中左右的循序，所以在单层递归的逻辑，是要先取中节点的数值，代码如下：
>
> ```c++ {.line-numbers}
> vec.push_back(cur->val);    // 中
> traversal(cur->left, vec);  // 左
> traversal(cur->right, vec); // 右
> ```
> 
> 单层递归的逻辑就是按照中左右的顺序来处理的，这样二叉树的前序遍历，基本就写完了，再看一下完整代码：
>
> 前序遍历：
> 
> ```c++
> class Solution {
> public:
>     void traversal(TreeNode* cur, vector<int>& vec) {
>         if (cur == NULL) return;
>         vec.push_back(cur->val);    // 中
>         traversal(cur->left, vec);  // 左
>         traversal(cur->right, vec); // 右
>     }
>     vector<int> preorderTraversal(TreeNode* root) {
>         vector<int> result;
>         traversal(root, result);
>         return result;
>     }
> };
> ```
>
> 那么前序遍历写出来之后，中序和后序遍历就不难理解了，代码如下：
>
> 
> 中序遍历：
> 
> ```c++
> void traversal(TreeNode* cur, vector<int>& vec) {
>     if (cur == NULL) return;
>     traversal(cur->left, vec);  // 左
>     vec.push_back(cur->val);    // 中
>     traversal(cur->right, vec); // 右
> }
> ```
> 
> 后序遍历：
> 
> ```c++
> void traversal(TreeNode* cur, vector<int>& vec) {
>     if (cur == NULL) return;
>     traversal(cur->left, vec);  // 左
>     traversal(cur->right, vec); // 右
>     vec.push_back(cur->val);    // 中
> }
> ```
> 
> 
> 



>
> 可能有同学感觉前后中序遍历的递归太简单了，要打迭代法（非递归），别急，我们明天打迭代法，打个通透！
> 
> 



--------------------------------------------------------------------------------

### 二叉树的深度优先遍历（迭代法）

> 
> https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html
>
> 

> 
> 为什么可以用迭代法（非递归的方式）来实现二叉树的前后中序遍历呢？
> 
> 我们在`栈与队列：匹配问题都是栈的强项` (`../_2_3_Stack_and_Queue/_4_remove_all_adjacent_duplicates_in_string.md`)中提到了，**递归的实现就是：每一次递归调用都会把函数的局部变量、参数值和返回地址等压入调用栈中**，然后递归返回的时候，从栈顶弹出上一次递归的各项参数，所以这就是递归为什么可以返回上一层位置的原因。
> 
> 此时大家应该知道我们迭代法（非递归）用栈也可以是实现二叉树的前后中序遍历了。
> 
> <font color="yellow">
>
> 递归法 隐式 使用栈存储参数和返回值
> 迭代法 明式 使用栈存储？？？
> 
> </font>
> 

> 
> <font color="yellow">先自己做一做`leetcode`上三道题目，分别是：</font>
> 
> 144.二叉树的前序遍历(https://leetcode.cn/problems/binary-tree-preorder-traversal/)
> 
> 94.二叉树的中序遍历(https://leetcode.cn/problems/binary-tree-inorder-traversal/)
>
> 145.二叉树的后序遍历(https://leetcode.cn/problems/binary-tree-postorder-traversal/)
> 
> 
> 
> **前序遍历**
> 
> https://leetcode.cn/problems/binary-tree-preorder-traversal/
> 
> <font color="yellow">我的迭代解法为</font>
>
> ```c++
> class Solution {
> public:
>     vector<int> preorderTraversal(TreeNode* root) {
>         vector<int> vec;
>         // 使用栈暂存右节点
>         stack<TreeNode*> sta;        
>         TreeNode* node = root;
>         while(node != nullptr) {
>             vec.push_back(node->val); // 先中
>             if(node->left != nullptr) { // 若左侧有节点
>                 if(node->right != nullptr) sta.push(node->right); // 如果有右节点，就暂存右节点地址           
>                 node = node->left;        // node更新为左节点
>             }  
>             else if(node->right != nullptr){ // 若左侧无节点，但是右侧有节点
>                 node = node->right;     // node更新为右节点
>             }
>             else { // 若两侧都无节点，查看栈
>                 if(!sta.empty()) {   // sta不为空，说明未遍历完
>                    node = sta.top(); // 向上返回，转向sta中暂存的右节点
>                    sta.pop();
>                 }
>                 else{  // sta为空，说明全部都遍历完了
>                     break;
>                 }
>             }
>         }
> 
>         return vec;
>     }
> };
> ```
> 
> 
> **中序遍历**
> 
> https://leetcode.cn/problems/binary-tree-inorder-traversal/
> 
> <font color="yellow">我的迭代解法为</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> inorderTraversal(TreeNode* root) {
>         vector<int> vec;
>         // 使用栈暂存中和右节点对
>         stack<pair<TreeNode*, TreeNode*>> sta;        
>         TreeNode* node = root;
>         while(node != nullptr) {
>             if(node->left != nullptr) { // 若左下有节点
>                 sta.push({node, node->right});  // 暂存<中，右>节点对                           
>                 node = node->left;      // node更新为左下节点
>             }  
>             else if(node->right != nullptr){ // 若左下无节点，但是右下有节点
>                 vec.push_back(node->val); // 存值
>                 node = node->right;     // node更新为右下节点
>             }
>             else { // 若两侧都无节点
>                 vec.push_back(node->val); // 存值 
>                 // 查看栈
>                 if(!sta.empty()) {
>                     // 节点对中second为空，那么存中节点的值即可，直到节点对中的second不为空
>                     while(!sta.empty() && sta.top().second == nullptr) { 
>                         vec.push_back(sta.top().first->val);  //
>                         sta.pop();
>                     } 
>                     // 此时只要sta不为空，则top().second必然不为空的
>                     if(!sta.empty()) {
>                         vec.push_back(sta.top().first->val);                     
>                         node = sta.top().second;  // 将指针指向sta中存储的右下节点
>                         sta.pop();                        
>                     } 
>                     else {
>                         break;
>                     }
>                 }
>                 else{
>                     break;
>                 }
>             }
>         }
> 
>         return vec;
>     }
> };
> ```
> 
> 
> 
> 
> **后序遍历（在先序遍历的基础上修改，左右互换， 最后再将vector反转顺序即可）**
> 
> https://leetcode.cn/problems/binary-tree-postorder-traversal/
> 
> <font color="yellow">我的迭代解法为（看了代码随想录的思路才会的）</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> postorderTraversal(TreeNode* root) {
>         // 先序遍历是中左右
>         // 由于左右是对称的概念，我们镜像修改left和right，就可以得到中右左
>         // 反转后就可以得到左右中
>         // 先序遍历的代码将left改为right，right改为left，最后reverse
>         vector<int> vec;
>         // 使用栈暂存左节点
>         stack<TreeNode*> sta;        
>         TreeNode* node = root;
>         while(node != nullptr) {
>             vec.push_back(node->val); // 先中
>             if(node->right != nullptr) { // 若左侧有节点
>                 if(node->left != nullptr) sta.push(node->left); // 如果有左节点，就暂存左节点地址           
>                 node = node->right;        // node更新为右节点
>             }  
>             else if(node->left != nullptr){ // 若右侧无节点，但是左侧有节点
>                 node = node->left;     // node更新为左节点
>             }
>             else { // 若两侧都无节点，查看栈
>                 if(!sta.empty()) {   // sta不为空，说明未遍历完
>                    node = sta.top(); // 向上返回，转向sta中暂存的左节点
>                    sta.pop();
>                 }
>                 else{  // sta为空，说明全部都遍历完了
>                     break;
>                 }
>             }
>         }
>         // 以上得到中右左的顺序
>         reverse(vec.begin(), vec.end()); // 将结果反转之后就是左右中的顺序了
>         return vec;
>     }
> };
> ```
> 










>
> <font color="yellow"> 
> 
> 反思我的代码哪里有可以优化的 
>
> 栈只用来存储部分节点了，应该让其存储所有未处理节点，这样逻辑更加简洁
> 
> 修改后的代码如下
> 
> </font>
>
> 
> **前序遍历**
> 
> https://leetcode.cn/problems/binary-tree-preorder-traversal/
> 
> <font color="yellow">我的优化后的迭代解法为</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> preorderTraversal(TreeNode* root) {
>         // 结果集
>         vector<int> result;
>         // 若root为空则返回空集
>         if(root == nullptr) return result; 
>         // 使用栈暂存未处理的节点
>         stack<TreeNode*> sta;     
>         // root节点入栈   
>         sta.push(root);   
>         // 遍历待处理的节点
>         while (!sta.empty()) {
>             // 取出待处理节点
>             TreeNode* node = sta.top();                       
>             sta.pop();
>             // 先中
>             result.push_back(node->val);
>             // 再左，最后右
>             // 先入的后处理，所以先将右节点入栈
>             if (node->right) sta.push(node->right);  // 右（空节点不入栈）
>             if (node->left) sta.push(node->left);    // 左（空节点不入栈）
>         }
> 
>         return result;
>     }
> };
> ``` 
> 
> 
> 
> **中序遍历**
> 
> https://leetcode.cn/problems/binary-tree-inorder-traversal/
> 
> <font color="yellow">我的优化后的迭代解法为</font>
>
> ```c++
> class Solution {
> public:
>     vector<int> inorderTraversal(TreeNode* root) {
>         // 结果集
>         vector<int> result;
>         // 若root为空则返回空集
>         if(root == nullptr) return result; 
>         // 使用栈暂存未处理的节点
>         stack<TreeNode*> sta;    
>         // 从root开始
>         TreeNode* node = root;
>         while (node != nullptr || !sta.empty()) {
>             if (node != nullptr) { // 指针来访问节点，访问到最底层
>                 sta.push(node); // 将访问的节点放进栈
>                 node = node->left;                // 左
>             } else {
>                 node = sta.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
>                 sta.pop();
>                 result.push_back(node->val);     // 中
>                 node = node->right;               // 右
>             }
>         }
>         return result;
>     }
> };
> ``` 
> 
> 
> 
> **后序遍历（在先序遍历的基础上修改，左右互换， 最后再将vector反转顺序即可）**
> 
> https://leetcode.cn/problems/binary-tree-postorder-traversal/
> 
> <font color="yellow">我的优化后的迭代解法为（看了代码随想录的思路才会的）</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> postorderTraversal(TreeNode* root) {
>         // 先序遍历是中左右
>         // 由于左右是对称的概念，我们镜像修改left和right，就可以得到中右左
>         // 反转后就可以得到左右中
>         // 先序遍历的代码将left改为right，right改为left，最后reverse
> 
>         // 结果集
>         vector<int> result;
>         // 若root为空则返回空集
>         if(root == nullptr) return result; 
>         // 使用栈暂存未处理的节点
>         stack<TreeNode*> sta;     
>         // root节点入栈   
>         sta.push(root);   
>         // 遍历待处理的节点
>         while (!sta.empty()) {
>             // 取出待处理节点
>             TreeNode* node = sta.top();                       
>             sta.pop();
>             // 先中
>             result.push_back(node->val);
>             // 再左，最后右
>             // 先入的后处理，所以先将右节点入栈
>             if (node->left) sta.push(node->left);    // 左（空节点不入栈）
>             if (node->right) sta.push(node->right);  // 右（空节点不入栈）
>         }
> 
>         // 以上得到中右左的顺序
>         reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
>         return result;
>     }
> };
> ``` 
> 
> 
> 

> 
> <font color="gree">接下来是代码随想录的解析</font>
>

> **前序遍历（迭代法）**
>
> 我们先看一下前序遍历。
> 
> 前序遍历是`中左右`，每次先处理的是中间节点，那么先将根节点放入栈中，然后将右孩子加入栈，再加入左孩子。
> 
> 为什么要先加入 右孩子，再加入左孩子呢？ 因为这样出栈的时候才是中左右的顺序。
> 
> 动画如下：
> 
> <div align=center>
> <img src="./images/tree_15.gif" style="zoom:100%;"/>
> </div>
>
> 不难写出如下代码: （**注意代码中空节点不入栈**）
>
> ```c++
> class Solution {
> public:
>     vector<int> preorderTraversal(TreeNode* root) {
>         stack<TreeNode*> st;
>         vector<int> result;
>         if (root == NULL) return result;
>         st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();                       // 中
>             st.pop();
>             result.push_back(node->val);
>             if (node->right) st.push(node->right);           // 右（空节点不入栈）
>             if (node->left) st.push(node->left);             // 左（空节点不入栈）
>         }
>         return result;
>     }
> };
> ```
> 
> 此时会发现貌似使用迭代法写出前序遍历并不难，确实不难。
> 
> **此时是不是想改一点前序遍历代码顺序就把中序遍历搞出来了？**
> 
> 其实还真不行！
> 
> 但接下来，**再用迭代法写中序遍历的时候，会发现套路又不一样了，目前的前序遍历的逻辑无法直接应用到中序遍历上**。
>

> 
> **中序遍历（迭代法）**
>
> 为了解释清楚，我说明一下 刚刚在迭代的过程中，其实我们有两个操作：
>
> * 处理：将元素放进`result`数组中
> * 访问：遍历节点
> 
> 分析一下为什么刚刚写的前序遍历的代码，不能和中序遍历通用呢，因为前序遍历的顺序是中左右，先访问的元素是中间节点，要处理的元素也是中间节点，所以刚刚才能写出相对简洁的代码，**因为要访问的元素和要处理的元素顺序是一致的，都是中间节点**。
>
> 那么再看看中序遍历，中序遍历是左中右，先访问的是二叉树顶部的节点，然后一层一层向下访问，直到到达树左面的最底部，再开始处理节点（也就是在把节点的数值放进`result`数组中），这就造成了**处理顺序和访问顺序是不一致的**。
>
> 那么**在使用迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素**。
> 
> 动画如下：
> 
> <div align=center>
> <img src="./images/tree_16.gif" style="zoom:100%;"/>
> </div>
>
> 中序遍历，可以写出如下代码：
>
> ```c++
> class Solution {
> public:
>     vector<int> inorderTraversal(TreeNode* root) {
>         vector<int> result;
>         stack<TreeNode*> st;
>         TreeNode* cur = root;
>         while (cur != NULL || !st.empty()) {
>             if (cur != NULL) { // 指针来访问节点，访问到最底层
>                 st.push(cur); // 将访问的节点放进栈
>                 cur = cur->left;                // 左
>             } else {
>                 cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
>                 st.pop();
>                 result.push_back(cur->val);     // 中
>                 cur = cur->right;               // 右
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 
> 

>
> **后序遍历（迭代法）**
>
> 再来看后序遍历，先序遍历是中左右，后续遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了，如下图：
> 
> <div align=center>
> <img src="./images/tree_17.png" style="zoom:100%;"/>
> </div>
>
> **所以后序遍历只需要前序遍历的代码稍作修改就可以了，代码如下：**
>
> ```c++
> class Solution {
> public:
>     vector<int> postorderTraversal(TreeNode* root) {
>         stack<TreeNode*> st;
>         vector<int> result;
>         if (root == NULL) return result;
>         st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             st.pop();
>             result.push_back(node->val);
>             if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
>             if (node->right) st.push(node->right); // 空节点不入栈
>         }
>         reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
>         return result;
>     }
> };
> ```
> 
> 
> 


> 
> **总结**
>
> 此时我们用迭代法写出了二叉树的前后中序遍历，大家可以看出前序和中序是完全两种代码风格，并不像递归写法那样代码稍做调整，就可以实现前后中序。
>
> **这是因为前序遍历中访问节点（遍历节点）和处理节点（将元素放进`result`数组中）可以同步处理，但是中序就无法做到同步！**
>
> 上面这句话，可能一些同学不太理解，建议自己亲手用迭代法，先写出来前序，再试试能不能写出中序，就能理解了。
>
> **那么问题又来了，难道 二叉树前后中序遍历的迭代法实现，就不能风格统一么（即前序遍历 改变代码顺序就可以实现中序 和 后序）？**
>
> 当然可以，这种写法，还不是很好理解，我们将在下一篇文章里重点讲解，敬请期待！
>
> 



--------------------------------------------------------------------------------

### 二叉树的深度优先遍历（统一迭代法）

>
> https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.html#%E8%BF%AD%E4%BB%A3%E6%B3%95%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86
>

>
> 此时我们在[二叉树：一入递归深似海，从此offer是路人](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html) 中用递归的方式，实现了二叉树前中后序的遍历。
> 
> 在[二叉树：听说递归能做的，栈也能做！](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html)中用栈实现了二叉树前后中序的迭代遍历（非递归）。
>
> 之后我们发现**迭代法实现的先中后序，其实风格也不是那么统一，除了先序和后序，有关联，中序完全就是另一个风格了，一会用栈遍历，一会又用指针来遍历**。
>
> 实践过的同学，也会发现使用迭代法实现先中后序遍历，很难写出统一的代码，不像是递归法，实现了其中的一种遍历方式，其他两种只要稍稍改一下节点顺序就可以了。
>
> 其实**针对三种遍历方式，使用迭代法是可以写出统一风格的代码！**
> 
> **重头戏来了，接下来介绍一下统一写法**。
>
> 我们以中序遍历为例，在[二叉树：听说递归能做的，栈也能做！](https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html)中提到说使用栈的话，**无法同时解决访问节点（遍历节点）和处理节点（将元素放进结果集）不一致的情况**。
>
> **那我们就将访问的节点放入栈中，把要处理的节点也放入栈中但是要做标记。**
> 
> 如何标记呢，**就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记**。 这种方法也可以叫做标记法。
>
> 
> 

#### 迭代法中序遍历

> 
> 看代码有点抽象我们来看一下动画(中序遍历)：
> 
> <div align=center>
> <img src="./images/tree_18.gif" style="zoom:100%;"/>
> </div>
>
> 动画中，`result`数组就是最终结果集。
> 
> 可以看出我们将访问的节点直接加入到栈中，但如果是处理的节点则后面放入一个空节点， 这样只有空节点弹出的时候，才将下一个节点放进结果集。
> 
> 此时我们再来看前序遍历代码。
> 
>
> 中序遍历代码如下：（详细注释）
>
> ```c++
> class Solution {
> public:
>     vector<int> inorderTraversal(TreeNode* root) {
>         vector<int> result;
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             if (node != NULL) {
>                 st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
>                 if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）
> 
>                 st.push(node);                          // 添加中节点
>                 st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
> 
>                 if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
>             } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
>                 st.pop();           // 将空节点弹出
>                 node = st.top();    // 重新取出栈中元素
>                 st.pop();
>                 result.push_back(node->val); // 加入到结果集
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 
> <font color="yellow">将`st.pop()`提出来</font>
>
> ```c++
> class Solution {
> public:
>     vector<int> inorderTraversal(TreeNode* root) {
>         vector<int> result;
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             st.pop();        
>             if (node != NULL) {
>                 if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）
> 
>                 st.push(node);                          // 添加中节点
>                 st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
> 
>                 if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
>             } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
>                 node = st.top();    // 重新取出栈中元素
>                 st.pop();
>                 result.push_back(node->val); // 加入到结果集
>             }
>         }
>         return result;
>     }
> };
> ```
>
> 
> 
> <font color="yellow">我的理解如下</font>
>
> <font color="yellow">从`root`节点开始，</font>
> 
> * <font color="yellow">如果`sta.top() != nullptr`</font>
> > 
> > 栈`sta`中按顺序存入`右中左`节点，`中`后添加`nullptr`作为标记, 即`右-中-nullptr-左`， 然后进入下一次循环。
> > 
> > 注意：只有如果`右`或`左`为空，就不放入。也就是说，`sta`不会有连续两个元素为`nullptr`。
> > 
> > 可能有各种情况, 例如
> > `第1次循环-第二次循环-第三四循环-第四次循环的情况为`
> > `（右中-null-左）-（中-null-左）-（中-null-左）-（右中-null）`
> > 
> > 疑问：上一次循环的`左`和这次循环的`中`不是同一个吗？
> > 是的，所以每次进入循环，我们会先取出`sta.top()`，然后作为新的中节点开始检测左右，然后再放入，不会有重复的节点
> > 
> > 
> > 只要没探索到最左侧，每次进入循环时，栈`sta`顶部`sta.top()`必定不为空`nullptr`(左侧的节点一直有)，当检测到最左侧时，存入`右中左`节点后，`sta.top() == nullptr`，因为最左侧节点的左侧已经没有了。这时候重新进入循环，转到了`sta.top() == nullptr`
> > 
> > 所以当最左侧探测完后，实际放入`result`的情况是这样
> > `（右中-null）-（中-null）-（中-null）-（右中-null）`
>
> * <font color="yellow">如果`sta.top() == nullptr`</font>
> > 
> > 说明该进行处理了
> > 
> > 取出下一个`top()`，由于之前我们保证了`sta`不会有连续两个元素为`nullptr`。,此时取出的元素必然为`node`，所以不需要判定是否为空 ，直接放入结果集即可
> > 
> > 当把`中`放入后，下一次循环检测到的`sta.top()`可能为`右`，则会针对`右子树`进行与`root`同样的检测，直到处理完成，返回
> > 
> > 直到处理到`root`，然后处理`root`的右子树，同样的检测流程
>
> 
> <font color="yellow">可以看出，统一风格的迭代法并不好理解，而且想在面试直接写出来还有难度的。</font>
> 
> 
> 
> <font color="gree">总结
>
> **将访问的节点放入栈中**: 中序遍历，每次循环结束时，下一次循环要访问的是左节点，所以最后把按照右中左的顺序放入栈中
> 
> **把要处理的节点也放入栈中，紧接着放入一个空指针作为标记**：无论哪种遍历，要处理的节点是每次循环进入时的节点（作为当前中节点）
>
> 
> </font>
> 















#### 迭代法前序遍历

>
> 迭代法前序遍历代码如下： (**注意此时我们和中序遍历相比仅仅改变了两行代码的顺序**)
>
> ```c++
> class Solution {
> public:
>     vector<int> preorderTraversal(TreeNode* root) {
>         vector<int> result;
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             if (node != NULL) {
>                 st.pop();
>                 if (node->right) st.push(node->right);  // 右
>                 if (node->left) st.push(node->left);    // 左
>                 st.push(node);                          // 中
>                 st.push(NULL);
>             } else {
>                 st.pop();
>                 node = st.top();
>                 st.pop();
>                 result.push_back(node->val);
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 
> <font color="yellow">将`st.pop()`提出来</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> preorderTraversal(TreeNode* root) {
>         vector<int> result;
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             st.pop();
>             if (node != NULL) {
>                 if (node->right) st.push(node->right);  // 右
>                 if (node->left) st.push(node->left);    // 左
>                 st.push(node);                          // 中
>                 st.push(NULL);
>             } else {
>                 node = st.top();
>                 st.pop();
>                 result.push_back(node->val);
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 
> <font color="yellow">我的理解如下</font>
>
> <font color="yellow">从`root`节点开始，</font>
> 
> * <font color="yellow">如果`sta.top() != nullptr`</font>
> > 
> > 栈`sta`中按顺序存入`右左中`节点，`中`后添加`nullptr`作为标记, 即`右-左-中-nullptr`， 然后进入下一次循环。
> > 
> > 下一次循环会检测到`sta.top() == nullptr`，从而需要再出栈紧跟后面的中节点，加入`result`集
> > 
> > 再下一次循环就会检测到`左`节点，进入`sta.top() != nullptr`，即开始处理左子树，与`root`一样的方式。等到处理完左子树，就会重新检测到`右`节点，进行处理。
> > 
> 
> 
> 
> <font color="gree">总结
>
> **将访问的节点放入栈中**: 前序遍历，每次循环结束时，下一次循环要访问的是中节点（要存储），所以最后把按照右左中的顺序放入栈中
> 
> **把要处理的节点也放入栈中，紧接着放入一个空指针作为标记**：无论哪种遍历，要处理的节点是每次循环进入时的节点（作为当前中节点）
>
> 
> </font>




#### 迭代法后序遍历

> 
> 后续遍历代码如下： (**注意此时我们和中序遍历相比仅仅改变了两行代码的顺序**)
>
> ```c++
> class Solution {
> public:
>     vector<int> postorderTraversal(TreeNode* root) {
>         vector<int> result;
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             if (node != NULL) {
>                 st.pop();
>                 st.push(node);                          // 中
>                 st.push(NULL);
> 
>                 if (node->right) st.push(node->right);  // 右
>                 if (node->left) st.push(node->left);    // 左
> 
>             } else {
>                 st.pop();
>                 node = st.top();
>                 st.pop();
>                 result.push_back(node->val);
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 
> <font color="yellow">将`st.pop()`提出来</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> postorderTraversal(TreeNode* root) {
>         vector<int> result;
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             st.pop();
>             if (node != NULL) {
>                 st.push(node);                          // 中
>                 st.push(NULL);
> 
>                 if (node->right) st.push(node->right);  // 右
>                 if (node->left) st.push(node->left);    // 左
> 
>             } else {
>                 node = st.top();
>                 st.pop();
>                 result.push_back(node->val);
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 
> 
> <font color="yellow">我的理解如下</font>
>
> <font color="yellow">从`root`节点开始，</font>
> 
> * <font color="yellow">如果`sta.top() != nullptr`</font>
> > 
> > 栈`sta`中按顺序存入`中右左`节点，`中`后添加`nullptr`作为标记, 即`中-nullptr-右-左`， 然后进入下一次循环。
> > 
> > 下一次循环就会检测到`左`节点，进入`sta.top() != nullptr`，即开始处理左子树，与`root`一样的方式。等到处理完左子树，就会重新检测到`右`节点，进行处理。
> > 
> > 再之后，会检测到`sta.top() == nullptr`，从而需要再出栈紧跟后面的中节点，加入`result`集
> > 
> > 
> 
> 
> 
> <font color="gree">总结
>
> **将访问的节点放入栈中**: 后序遍历，每次循环结束时，下一次循环要访问的是左节点（要存储），所以最后把按照中右左的顺序放入栈中
> 
> **把要处理的节点也放入栈中，紧接着放入一个空指针作为标记**：无论哪种遍历，要处理的节点是每次循环进入时的节点（作为当前中节点）
> 
> 
> </font>
> 
> 
> 




#### 总结

>
> 此时我们写出了统一风格的迭代法，不用在纠结于前序写出来了，中序写不出来的情况了。
> 
> 但是**统一风格的迭代法并不好理解，而且想在面试直接写出来还有难度的**。
> 
> 所以**大家根据自己的个人喜好，对于二叉树的前中后序遍历，选择一种自己容易理解的递归和迭代法**。
> 
> 
> 




--------------------------------------------------------------------------------

### 二叉树的广度优先遍历（层序遍历法）(用`std::queue`实现)





> 
> 层序遍历：即逐层地，从左到右访问所有节点
> 
> **学会二叉树的层序遍历，可以一口气打完以下十题：**
> 
> * `102.`二叉树的层序遍历
> * `107.`二叉树的层次遍历II
> * `199.`二叉树的右视图
> * `637.`二叉树的层平均值
> * `429.`N叉树的层序遍历
> * `515.`在每个树行中找最大值
> * `116.`填充每个节点的下一个右侧节点指针
> * `117.`填充每个节点的下一个右侧节点指针II
> * `104.`二叉树的最大深度
> * `111.`二叉树的最小深度
> 
> 
> <div align=center>
> <img src="./images/tree_19.gif" style="zoom:100%"/>
> </div>
>
> 
> 




#### 102.二叉树的层序遍历

> 
> `Leetcode`链接: https://leetcode.cn/problems/binary-tree-level-order-traversal/
>
> **102. 二叉树的层序遍历**
> 
> 给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_21.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [3,9,20,null,null,15,7]
> 输出：[[3],[9,20],[15,7]]
> ```
>
> **示例2：**
> 
> ```html
> 输入：root = [1]
> 输出：[[1]]
> ```
>
> **示例3：**
> 
> ```html
> 输入：root = []
> 输出：[]
> ```
>
> **提示：**
> * 树中节点数目在范围 `[0, 2000]` 内
> * `-1000 <= Node.val <= 1000`
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     vector<vector<int>> levelOrder(TreeNode* root) {
> 
>     }
> };
> ```
> 

> 
> **我自己的第一次做的时候的思路**
> 
> 设置两个队列`que1`，`que2`
>
> 设置结果集`vector<vector<int>> result`
>
> 将第`1`层的`root`节点入队列`que1`, 将`root->val`加入`result[0]`
>
> 设置层数标志`floor`
>
> 开始`while(floor)`循环
> 
> * 内嵌`while(!que1.empty())`循环， 将`que1`中存储的单层节点的子节点全部存入`que2`
> 
> > 注意不能用`for(int i=0; i < que1.size(); i++)`循环，因为当`que1.pop()`后，`que1.size()`会发生变化
> > 
> > 具体做法如下：
> > 
> > 出队列元素`node = que1.front(); que1.pop();`
> > 
> > 将`node`的左右子节点`node->left`和`node->right`都入队列`que2.push()`; 注意，空节点不入队列;
> > 
> > 最后所有的下一层的节点都在`que2`中, 且`que1`为空
>
> * 检查`que2`，若为空，说明已经是上一次循环已经到达最后一层，全部节点检测左右都未发现子节点，需要停止`while(floor)`外循环，`break`
>
> * `floor++` 更新层数标志
> 
> * 内嵌`while(!que2.empty())`循环, 存储`que2`这一层节点的值, 并将`que2`的节点放入`que1`
>
> > 注意不能用`for(int i=0; i < que2.size(); i++)`循环，因为当`que2.pop()`后，`que2.size()`会发生变化
> > 
> > 具体做法如下：
> > 
> > 设置临时`vector<int> vec`,将`que2`中的节点`node`出队列，将这些节点的值加入`vec.push_back(node->val);`，最后将`node`放入`que1`; 
> > 
> > 最后`result.push_back(vec)`;
> > 
> 
>
> **我的代码如下：**
> 
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrder(TreeNode* root) {
>         // 设置两个队列que1，que2； 设置结果集result; 
>         queue<TreeNode*> que1;
>         queue<TreeNode*> que2;
>         vector<vector<int>> result;
> 
>         // 如果root 为空，直接返回
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que1, 将root->val加入result
>         que1.push(root);
>         result.push_back(vector<int>{root->val});
> 
>         // 设置层数标志floor
>         int floor = 1; // 因为root已经处理过了，所以从第2层开始
>         
>         // 开始循环
>         while(floor) {
>             // 将que1中存储的单层节点的子节点全部存入que2
>             while(!que1.empty()) { // 不能for(int i=0; i < que1.size(); i++) 因为size()会变化
>                 TreeNode* node = que1.front();
>                 que1.pop();
>                 if(node->left != nullptr) que2.push(node->left);
>                 if(node->right != nullptr) que2.push(node->right);
>             } // 循环结束后que1为空
> 
>             // 若que2为空，则说明已经到达最后一层，停止循环
>             if(que2.empty()) break;
> 
>             // 更新层数标志
>             floor++;
> 
>             // 存储que2这一层节点的值, 并将que2的节点放入que1
>             vector<int> vec;
>             while(!que2.empty()) { // 不能for(int i=0; i < que2.size(); i++) 因为size()会变化
>                 TreeNode* node = que2.front();
>                 que2.pop();
>                 vec.push_back(node->val);
>                 que1.push(node);
>             } 
>             result.push_back(vec);
> 
>         }
> 
>         return result;
>     }
> };
> ```
> 
>
> **我的实机测试代码如下：**
>
> ```c++
> #include <iostream> 
> #include <vector>
> #include <queue>
> using namespace std;
> 
> struct TreeNode {
>     int val;
>     TreeNode *left;
>     TreeNode *right;
>     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
> };
> 
> int main()
> {
>     TreeNode* node_5 = new TreeNode(7);
>     TreeNode* node_4 = new TreeNode(15);
>     TreeNode* node_3 = new TreeNode(20, node_4, node_5);
>     TreeNode* node_2 = new TreeNode(9);
>     TreeNode* root = new TreeNode(3, node_2, node_3);
> 
> 
>     // 设置两个队列que1，que2； 设置结果集result; 
>     queue<TreeNode*> que1;
>     queue<TreeNode*> que2;
>     vector<vector<int>> result;
> 
>     // 如果root 为空，直接返回
>     if(root == nullptr) return 0;
> 
>     // 将第1层的root节点入队列que1, 将root->val加入result
>     que1.push(root);
>     result.push_back(vector<int>{root->val});
> 
>     // 设置层数标志floor
>     int floor = 1;
>     
>     // 开始循环
>     while(floor) {
>         // 将que1中存储的单层节点的子节点全部存入que2
>         while(!que1.empty()) {
>             TreeNode* node = que1.front();
>             que1.pop();
>             if(node->left != nullptr) que2.push(node->left);
>             if(node->right != nullptr) que2.push(node->right);
>         } // 循环结束后que1为空
> 
>         // 若que2为空，则说明已经到达最后一层，停止循环
>         if(que2.empty()) break;
> 
>         // 更新层数标志
>         floor++;
> 
>         // 显示当前层数，以及节点数
>         cout << "floor: " << floor << ", que2.size(): " << que2.size() << endl;
> 
>         // 存储que2这一层节点的值, 并将que2的节点放入que1
>         vector<int> vec;
>         while(!que2.empty())  {            
>             TreeNode* node = que2.front();
>             que2.pop();
>             vec.push_back(node->val);
>             que1.push(node);
> 
>             // 显示当前层数，以及节点值
>             cout << "floor: " << floor << ", node->val: " << node->val << endl;
>         } 
>         cout << endl;
> 
>         result.push_back(vec);
> 
>     }
> 
> 
>     delete root;
>     delete node_2; 
>     delete node_3; 
>     delete node_4; 
>     delete node_5; 
> 
>     cout << endl;
>     pause(); // system("pause"); 
> 
>     return 0;
> }
> ```
> 
>
> **实机运行结果如下：**
>
> ```c++
> floor: 2, que2.size(): 2
> floor: 2, node->val: 9
> floor: 2, node->val: 20
> 
> floor: 3, que2.size(): 2
> floor: 3, node->val: 15
> floor: 3, node->val: 7
> ```
>
>
> **优化思路：只用一个辅助队列**
>
> 设置一个队列`que`，设置结果集`result`
>
> 将第`1`层的`root`节点入队列`que1`, 将`root->val`加入`result`
>
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点的子节点全部存入`que`队尾, 同时记得存储左右子节点的节点值
> > 
> > 具体做法如下：
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环，将当前层的节点一一取出，找到左右子节点，并将子节点的值存入result，将子节点入队列`que`
> > 
> > 
> > 层数标志增加`floor++`
> > 
> >  
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrder(TreeNode* root) {
>         // 设置队列que； 设置结果集result; 
>         queue<TreeNode*> que;
>         vector<vector<int>> result;
> 
>         // 如果root 为空，直接返回
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que, 将root->val加入result
>         que.push(root);
>         result.push_back(vector<int>{root->val});
> 
>         // 设置层数标志floor
>         int floor = 1; 
> 
>         // 将que中存储的单层节点的子节点全部存入que队尾, 同时记得存储节点值
>         while(!que.empty()) { 
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，找到左右子节点，并将子节点的值存入vector<int>，将子节点入队列que
>             vector<int> vec; 
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 if(node->left != nullptr) {
>                     vec.push_back(node->left->val);
>                     que.push(node->left);
>                 }
>                 if(node->right != nullptr) {
>                     vec.push_back(node->right->val);
>                     que.push(node->right);
>                 }
>             }
> 
>             // 若que为空，则说明已经到达最后一层，停止循环
>             if(que.empty()) break;
>                 
>             // 将子节点值存储result
>             result.push_back(vec);
> 
>             // 更新层数标志
>             floor++;
>         }
> 
>         return result;
>     }
> };
> ```
> 
>
> **更进一步优化：代码更简洁**
>
> <font color="gree">
> 
> 思路如下：
> 
> 设置一个队列`que`，设置结果集`result`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点值放入vector<int>,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下： 
> > > * 将当前层的节点一一取出
> > > * 将当前层的节点值存入`result`
> > > * 找到左右子节点，将子节点入队列`que`
> > 
>
> 返回结果集`result`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrder(TreeNode* root) {
>         // 设置队列que； 设置结果集result; 
>         queue<TreeNode*> que;
>         vector<vector<int>> result;
> 
>         // 如果root 为空，直接返回空集
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que
>         que.push(root);
> 
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点值放入vector<int>,然后将左右子节点全部存入que队尾
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;    
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，节点值存入vector<int>，找到左右子节点，将下一层的子节点入队que
>             vector<int> vec; 
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 vec.push_back(node->val);
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>             }
>                 
>             // 将当前层的节点值存储result
>             result.push_back(vec);
> 
>         }
> 
>         return result;
>     }
> };
> ```
> 
> 






> <font color="gree"> 代码随想录 </font>
>
> 我们之前讲过了三篇关于二叉树的深度优先遍历的文章：
>
> 接下来我们再来介绍二叉树的另一种遍历方式：层序遍历。
> 
> 层序遍历一个二叉树。就是从左到右一层一层的去遍历二叉树。这种遍历的方式和我们之前讲过的都不太一样。
> 
> 需要借用一个辅助数据结构即队列来实现，**队列先进先出，符合一层一层遍历的逻辑，而用栈先进后出适合模拟深度优先遍历也就是递归的逻辑。**
>
> **而这种层序遍历方式就是图论中的广度优先遍历，只不过我们应用在二叉树上。**
>
> 使用队列实现二叉树广度优先遍历，动画如下：
>
> 
> <div align=center>
> <img src="./images/tree_20.gif" style="zoom:100%"/>
> </div>
> 
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrder(TreeNode* root) {
>         queue<TreeNode*> que;
>         if (root != NULL) que.push(root);
>         vector<vector<int>> result;
>         while (!que.empty()) {
>             int size = que.size();
>             vector<int> vec;
>             // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 vec.push_back(node->val);
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>             result.push_back(vec);
>         }
>         return result;
>     }
> };
> ```
> 
> ```c++
> # 递归法
> class Solution {
> public:
>     void order(TreeNode* cur, vector<vector<int>>& result, int depth)
>     {
>         if (cur == nullptr) return;
>         if (result.size() == depth) result.push_back(vector<int>());
>         result[depth].push_back(cur->val);
>         order(cur->left, result, depth + 1);
>         order(cur->right, result, depth + 1);
>     }
>     vector<vector<int>> levelOrder(TreeNode* root) {
>         vector<vector<int>> result;
>         int depth = 0;
>         order(root, result, depth);
>         return result;
>     }
> };
> ```
> 
> <font color="yellow"> 层序遍历的递归法很难懂，我们掌握迭代法就可以了 </font>
> 
> **此时我们就掌握了二叉树的层序遍历了，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>
> 




#### 107.二叉树的层次遍历 II

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>


>
> `Leetcode`链接: https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
>
> **107. 二叉树的层序遍历 II**
> 
> 给你二叉树的根节点 `root` ，返回其节点值 **自底向上的层序遍历** 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_22.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [3,9,20,null,null,15,7]
> 输出：[[15,7],[9,20],[3]]
> ```
>
> **示例2：**
> 
> ```html
> 输入：root = [1]
> 输出：[[1]]
> ```
>
> **示例3：**
> 
> ```html
> 输入：root = []
> 输出：[]
> ```
>
> **提示：**
> * 树中节点数目在范围 `[0, 2000]` 内
> * `-1000 <= Node.val <= 1000`
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     vector<vector<int>> levelOrderBottom(TreeNode* root) {
> 
>     }
> };
> ```
> 



>
> <font color="yellow"> 与`102.二叉树的层序遍历`的区别是，每一层保持从左到右，但是层数是自底向上的</font>
>
> <font color="yellow"> 那么只需要`reverse(result.begin(), result.end())`翻转外层顺序就可以了</font>
> 
>
> <font color="gree">
>
> 思路如下：
> 
> 设置一个队列`que`，设置结果集`result`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点值放入vector<int>,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出
> > > * 将当前层的节点值存入result
> > > * 找到左右子节点，将子节点入队列`que`
> > 
>
> 翻转结果集外层顺序`reverse(result.begin(), result.end())`
> 
> 返回结果集`result`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrderBottom(TreeNode* root) {
>         // 设置队列que； 设置结果集result; 
>         queue<TreeNode*> que;
>         vector<vector<int>> result;
> 
>         // 如果root 为空，直接返回空集
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que
>         que.push(root);
> 
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点值放入vector<int>,然后将左右子节点全部存入que队尾
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;    
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，节点值存入vector<int>，找到左右子节点，将下一层的子节点入队que
>             vector<int> vec; 
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 vec.push_back(node->val);
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>             }
>                 
>             // 将当前层的节点值存储result
>             result.push_back(vec);
> 
>         }
> 
>         // 翻转结果集外层顺序, 变成自底向上的层序遍历
>         reverse(result.begin(), result.end());
> 
>         return result;
>     }
> };
> ```
> 
> 


> <font color="gree"> 代码随想录 </font>
>
> 相对于102.二叉树的层序遍历，就是最后把result数组反转一下就可以了。
>
> C++代码：
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrderBottom(TreeNode* root) {
>         queue<TreeNode*> que;
>         if (root != NULL) que.push(root);
>         vector<vector<int>> result;
>         while (!que.empty()) {
>             int size = que.size();
>             vector<int> vec;
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 vec.push_back(node->val);
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>             result.push_back(vec);
>         }
>         reverse(result.begin(), result.end()); // 在这里反转一下数组即可
>         return result;
> 
>     }
> };
> ```
> 
> 
> 


#### 199.二叉树的右视图

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>



>
> `Leetcode`链接: https://leetcode.cn/problems/binary-tree-right-side-view/
>
> **199. 二叉树的右视图**
> 
> 给定一个二叉树的 根节点 `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_23.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入: [1,2,3,null,5,null,4]
> 输出: [1,3,4]
> ```
>
> **示例2：**
> 
> ```html
> 输入: [1,null,3]
> 输出: [1,3]
> ```
>
> **示例3：**
> 
> ```html
> 输入: []
> 输出: []
> ```
>
> **提示：**
> * 二叉树的节点个数的范围是 `[0,100]`
> * `-100 <= Node.val <= 100 `
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     vector<int> rightSideView(TreeNode* root) {
> 
>     }
> };
> ```
> 


>
> **本质上是统计每一层最右侧的节点, 在层序遍历的基础上修改**
> 
>
> <font color="gree">
>
> 思路如下：
> 
> 设置一个队列`que`，设置结果集`result`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点,然后将左右子节点全部存入`que`队尾， 最后一个节点的值放入`result`
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出； 
> > > * 找到左右子节点，将子节点入队列`que`; 
> > > * 将当前层的最右侧节点值存入`result`
> > 
>
> 
> 返回结果集`result`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     vector<int> rightSideView(TreeNode* root) {
>         // 本质上是统计每一层最右侧的节点, 在层序遍历的基础上修改
> 
>         // 设置队列que； 设置结果集result; 
>         queue<TreeNode*> que;
>         vector<int> result;
> 
>         // 如果root 为空，直接返回空集
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que
>         que.push(root);
> 
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点取出，然后将左右子节点全部存入que队尾, 将最后一个节点的值（最右侧）放入result
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;    
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，找到左右子节点，将下一层的子节点入队que， 最后一个节点值（最右侧）存入vector<int>，
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>                 // 存储最右侧节点的值
>                 if(i == floor_size - 1) result.push_back(node->val);
>             }
>                 
>         }
> 
>         return result;
>     }
> };
> ```
> 
> 


> <font color="gree"> 代码随想录 </font>
>
> 层序遍历的时候，判断是否遍历到单层的最后面的元素，如果是，就放进result数组中，随后返回result就可以了。
>
> C++代码：
>
> ```c++
> class Solution {
> public:
>     vector<int> rightSideView(TreeNode* root) {
>         queue<TreeNode*> que;
>         if (root != NULL) que.push(root);
>         vector<int> result;
>         while (!que.empty()) {
>             int size = que.size();
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 if (i == (size - 1)) result.push_back(node->val); // 将每一层的最后元素放入result数组中
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>         }
>         return result;
>     }
> };
> ```
> 
> 


#### 637.二叉树的层平均值

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>


>
> `Leetcode`链接: https://leetcode.cn/problems/average-of-levels-in-binary-tree/
>
> **637. 二叉树的层平均值**
> 
> 给定一个非空二叉树的根节点 `root` , 以数组的形式返回每一层节点的平均值。与实际答案相差 `10^-5` 以内的答案可以被接受。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_24.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [3,9,20,null,null,15,7]
> 输出：[3.00000,14.50000,11.00000]
> 解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
> 因此返回 [3, 14.5, 11] 。
> ```
>
> **示例2：**
> > 
> > <div align=center>
> > <img src="./images/tree_25.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [3,9,20,15,7]
> 输出：[3.00000,14.50000,11.00000]
> ```
>
> **提示：**
> * 树中节点数量在 `[1, 104]` 范围内
> * `-231 <= Node.val <= 231 - 1`
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     vector<double> averageOfLevels(TreeNode* root) {
> 
>     }
> };
> ```
> 




> <font color="gree">
> 
> 思路如下：
> 
> 设置一个队列`que`，设置结果集`result`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点值求和，然后平均,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> >
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 设置`double sum = 0;`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出，
> > > * 将当前层的节点值加入`sum`； 
> > > * 找到左右子节点，将子节点入队列`que`
> > 
> > * 将`sum / floor_size`存入`result`
> > 
> >  
>
> 返回结果集`result`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     vector<double> averageOfLevels(TreeNode* root) {
>         // 本质上是统计每一层最右侧的节点, 在层序遍历的基础上修改
> 
>         // 设置队列que； 设置结果集result; 
>         queue<TreeNode*> que;
>         vector<double> result;
> 
>         // 如果root 为空，直接返回空集
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que
>         que.push(root);
> 
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点取出，值求和, 然后将左右子节点全部存入que队尾, 最后求平均值放入result
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;    
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 新建double sum = 0;
>             double sum = 0;
>             // 将当前层的节点取出，找到左右子节点，将下一层的子节点入队que，所有节点值求和
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 sum += (double)node->val; // 类型转换
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>             }
>             // 平均值
>             double average = sum / (double)floor_size;
>             result.push_back(average);            
>                 
>         }
> 
>         return result;
>     }
> };
> ```
> 
> 
> 

> <font color="gree"> 代码随想录 </font>
>
> 本题就是层序遍历的时候把一层求个总和在取一个均值。
>
> C++代码：
>
> ```c++
> class Solution {
> public:
>     vector<double> averageOfLevels(TreeNode* root) {
>         queue<TreeNode*> que;
>         if (root != NULL) que.push(root);
>         vector<double> result;
>         while (!que.empty()) {
>             int size = que.size();
>             double sum = 0; // 统计每一层的和
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 sum += node->val;
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>             result.push_back(sum / size); // 将每一层均值放进结果集
>         }
>         return result;
>     }
> };
> ```
> 



#### 429.N叉树的层序遍历

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>

>
> `Leetcode`链接: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
>
>
> **429. N 叉树的层序遍历**
> 
> 给定一个 `N` 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
> 
> 树的序列化输入是用层序遍历，每组子节点都由 `null` 值分隔（参见示例）。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_26.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,3,2,4,null,5,6]
> 输出：[[1],[3,2,4],[5,6]]
> ```
>
> **示例2：**
> > 
> > <div align=center>
> > <img src="./images/tree_27.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
> 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
> ```
>
> **提示：**
> * 树的高度不会超过 `1000`
> * 树的节点总数在 `[0, 10^4]` 之间
>
> ```c++
> /*
> // Definition for a Node.
> class Node {
> public:
>     int val;
>     vector<Node*> children;
> 
>     Node() {}
> 
>     Node(int _val) {
>         val = _val;
>     }
> 
>     Node(int _val, vector<Node*> _children) {
>         val = _val;
>         children = _children;
>     }
> };
> */
> 
> class Solution {
> public:
>     vector<vector<int>> levelOrder(Node* root) {
>         
>     }
> };
> ```
> 
> 





> 这道题与二叉树的层序遍历本质没有差别，只不过是多了几个树杈
>
> <font color="gree">
> 
> 思路如下：
> 
> 设置一个队列`que`，设置结果集`result`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点值放入vector<int>,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出，
> > > * 将当前层的节点值存入`result`； 
> > > * 找到所有子节点，将子节点入队列`que`
> > 
> > 
> >  
>
> 返回结果集`result`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrder(Node* root) {
>         // 设置队列que； 设置结果集result; 
>         queue<Node*> que;
>         vector<vector<int>> result;
> 
>         // 如果root 为空，直接返回空集
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que
>         que.push(root);
> 
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点值放入vector<int>,然后将所有子节点全部存入que队尾
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，节点值存入vector<int>，找到所有子节点，将下一层的子节点入队que
>             vector<int> vec; 
>             for(int i=0; i < floor_size; i++) {
>                 Node* node = que.front();
>                 que.pop();
>                 vec.push_back(node->val);
>                 // 对于每一个节点，遍历其children数组，将每一个子节点都放入
>                 for(int k=0; k < node->children.size(); k++) {
>                     if(node->children[k] != nullptr) que.push(node->children[k]);
>                 }
>             }
>                 
>             // 将当前层的节点值存储result
>             result.push_back(vec);
> 
>         }
> 
>         return result;        
>     }
> };
> ```
> 
> 


> <font color="gree"> 代码随想录 </font>
>
> 这道题依旧是模板题，只不过一个节点有多个孩子了
>
> C++代码：
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrder(Node* root) {
>         queue<Node*> que;
>         if (root != NULL) que.push(root);
>         vector<vector<int>> result;
>         while (!que.empty()) {
>             int size = que.size();
>             vector<int> vec;
>             for (int i = 0; i < size; i++) {
>                 Node* node = que.front();
>                 que.pop();
>                 vec.push_back(node->val);
>                 for (int i = 0; i < node->children.size(); i++) { // 将节点孩子加入队列
>                     if (node->children[i]) que.push(node->children[i]);
>                 }
>             }
>             result.push_back(vec);
>         }
>         return result;
> 
>     }
> };
> ```
> 
> 



#### 515.在每个树行中找最大值

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>

>
> `Leetcode`链接: https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
>
> **515. 在每个树行中找最大值**
> 
> 给定一棵二叉树的根节点 `root` ，请找出该二叉树中每一层的最大值。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_28.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入: root = [1,3,2,5,3,null,9]
> 输出: [1,3,9]
> ```
>
> **示例2：**
> 
> ```html
> 输入: root = [1,2,3]
> 输出: [1,3]
> ```
>
> **提示：**
> * 二叉树的节点个数的范围是 `[0,104]`
> * `-2^31 <= Node.val <= 2^31 - 1`
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     vector<int> largestValues(TreeNode* root) {
> 
>     }
> };
> ```
> 



> <font color="gree">
> 
> 思路如下：
> 
> 设置一个队列`que`，设置结果集`result`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点值放入vector<int>,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 设置`int maxValue = INT_MIN;`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环，
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出，
> > > * 将当前层的节点值与`maxValue`比较，判断是否需要更新； 
> > > * 找到左右子节点，将子节点入队列`que`；
> > 
> > * 将当前层的最大节点值存储`result`
> > 
> >  
>
> 返回结果集`result`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     vector<int> largestValues(TreeNode* root) {
>         // 设置队列que； 设置结果集result; 
>         queue<TreeNode*> que;
>         vector<int> result;
> 
>         // 如果root 为空，直接返回空集
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que
>         que.push(root);
> 
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点值放入vector<int>,然后将左右子节点全部存入que队尾
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 初始化max为int类型的最小值INT_MIN，只要进行循环就能
>             int maxValue = INT_MIN; 
>             // 将当前层的节点取出，比较节点值，找到左右子节点，将下一层的子节点入队que
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 maxValue = (node->val > maxValue) ? node->val : maxValue; // 只要节点值大于max暂存值，就将max更新为节点值，否则不变
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>             }
> 
>             // 将当前层的最大节点值存储result
>             result.push_back(maxValue);
> 
>         }
> 
>         return result;
>     }
> };
> ```



> <font color="gree"> 代码随想录 </font>
>
> 层序遍历，取每一层的最大值
>
> C++代码：
>
> ```c++
> class Solution {
> public:
>     vector<int> largestValues(TreeNode* root) {
>         queue<TreeNode*> que;
>         if (root != NULL) que.push(root);
>         vector<int> result;
>         while (!que.empty()) {
>             int size = que.size();
>             int maxValue = INT_MIN; // 取每一层的最大值
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 maxValue = node->val > maxValue ? node->val : maxValue;
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>             result.push_back(maxValue); // 把最大值放进数组
>         }
>         return result;
>     }
> };
> ```
> 
> 

#### 116.填充每个节点的下一个右侧节点指针

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>

>
> `Leetcode`链接: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
>
> **116. 填充每个节点的下一个右侧节点指针**
> 
> 给定一个 **完美二叉树** ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
> ```c++
> struct Node {
>   int val;
>   Node *left;
>   Node *right;
>   Node *next;
> }
> ```
>
> 填充它的每个 `next` 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 `next` 指针设置为 `NULL`。
>
> 初始状态下，所有 `next` 指针都被设置为 `NULL`。
> 
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_29.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,2,3,4,5,6,7]
> 输出：[1,#,2,3,#,4,5,6,7,#]
> 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，
> 如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，
> '#' 标志着每一层的结束。
> ```
>
> **示例2：**
> 
> ```html
> 输入：root = []
> 输出：[]
> ```
>
> **提示：**
> * 树中节点的数量在 `[0, 212 - 1]` 范围内
> * `-1000 <= node.val <= 1000`
>
> ```c++
> /*
> // Definition for a Node.
> class Node {
> public:
>     int val;
>     Node* left;
>     Node* right;
>     Node* next;
> 
>     Node() : val(0), left(NULL), right(NULL), next(NULL) {}
> 
>     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
> 
>     Node(int _val, Node* _left, Node* _right, Node* _next)
>         : val(_val), left(_left), right(_right), next(_next) {}
> };
> */
> 
> class Solution {
> public:
>     Node* connect(Node* root) {
>         
>     }
> };
> ```
> 





> <font color="gree">
> 
> 思路如下：
>
> 如果`root`为空，直接返回空指针`nullptr`
> 
> 设置一个队列`que`
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点出队列, 将左右子节点全部存入`que`队尾， 如果不是当前层的最后一个节点，将节点的`next`指向同层右侧节点
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环，
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出； 
> > > * 找到左右子节点，将子节点入队列`que`； 
> > > * 如果不是当前层的最后一个节点，将next指向同层右侧节点que.front()
> > 
> > 
> >  
>
> 返回根节点`root`
>
> </font>
>
> **写代码前先写思路**
>
> ```c++
> class Solution {
> public:
>     Node* connect(Node* root) {
> 
>         // 如果root为空，直接返回空指针nullptr
>     
>         // 设置队列que
> 
>         // 将root入队列que
> 
>         // 设置层数标志
> 
>         // while循环 
>             // 层数标志更新
>             // 暂存当前层节点数量
>             // for循环遍历当前层的所有节点
>                // 暂存出栈的节点
>                // 左右子节点入队列
>                // 如果不是当前层的最后一个节点，将next指向同层右侧节点que.front()
>         
> 
>         // 返回root节点
> 
>     }
> };
> ```
> **实际代码如下**
> ```c++
> class Solution {
> public:
>     Node* connect(Node* root) {
>         // 如果root为空，直接返回空指针nullptr
>         if(root == nullptr) return nullptr;    
>         // 设置队列que
>         queue<Node*> que;
>         // 将root入队列que
>         que.push(root);
>         // 设置层数标志
>         int floor = 0;
> 
>         // while循环
>         while(!que.empty()) {
>             // 层数标志更新
>             floor++;    
>             // 暂存当前层节点数量
>             int floor_size = que.size();
>             
>             // for循环遍历当前层的所有节点
>             for(int i=0; i < floor_size; i++) {
>                // 暂存出栈的节点
>                Node* node = que.front();
>                que.pop();
>                // 左右子节点入队列
>                if(node->left != nullptr) que.push(node->left);
>                if(node->right != nullptr) que.push(node->right);
>                // 如果不是当前层的最后一个节点，将next指向同层右侧节点que.front()
>                if(i != floor_size - 1) node->next = que.front();
>             }
> 
>         }
> 
>         // 返回root节点
>         return root;
>     }
> };
> ```
> 
> 


> <font color="gree"> 代码随想录 </font>
>
> 本题依然是层序遍历，只不过在单层遍历的时候记录一下本层的头部节点，然后在遍历的时候让前一个节点指向本节点就可以了
>
> C++代码：
>
> ```c++
> class Solution {
> public:
>     Node* connect(Node* root) {
>         queue<Node*> que;
>         if (root != NULL) que.push(root);
>         while (!que.empty()) {
>             int size = que.size();
>             // vector<int> vec;
>             Node* nodePre;
>             Node* node;
>             for (int i = 0; i < size; i++) {
>                 if (i == 0) {
>                     nodePre = que.front(); // 取出一层的头结点
>                     que.pop();
>                     node = nodePre;
>                 } else {
>                     node = que.front();
>                     que.pop();
>                     nodePre->next = node; // 本层前一个节点next指向本节点
>                     nodePre = nodePre->next;
>                 }
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>             nodePre->next = NULL; // 本层最后一个节点指向NULL
>         }
>         return root;
> 
>     }
> };
> ```
> 
> 




#### 117.填充每个节点的下一个右侧节点指针II

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>

>
> `Leetcode`链接: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
>
> **117. 填充每个节点的下一个右侧节点指针 II**
> 
> 给定一个二叉树：
> ```c++
> struct Node {
>   int val;
>   Node *left;
>   Node *right;
>   Node *next;
> }
> ```
>
> 填充它的每个 `next` 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 `next` 指针设置为 `NULL` 。
>
> 初始状态下，所有 `next` 指针都被设置为 `NULL`。
> 
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_30.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,2,3,4,5,null,7]
> 输出：[1,#,2,3,#,4,5,7,#]
> 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，
> 如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。
> ```
>
> **示例2：**
> 
> ```html
> 输入：root = []
> 输出：[]
> ```
>
> **提示：**
> * 树中节点的数量在 `[0, 6000]` 内
> * `-100 <= Node.val <= 100`
>
> ```c++
> /*
> // Definition for a Node.
> class Node {
> public:
>     int val;
>     Node* left;
>     Node* right;
>     Node* next;
> 
>     Node() : val(0), left(NULL), right(NULL), next(NULL) {}
> 
>     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
> 
>     Node(int _val, Node* _left, Node* _right, Node* _next)
>         : val(_val), left(_left), right(_right), next(_next) {}
> };
> */
> 
> class Solution {
> public:
>     Node* connect(Node* root) {
>         
>     }
> };
> ```
> 






> 与`116.填充每个节点的下一个右侧节点指针`没有任何区别
>
>
> <font color="gree">
> 
> 思路如下：
>
> 如果`root`为空，直接返回空指针`nullptr`
> 
> 设置一个队列`que`
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点出队列, 将左右子节点全部存入`que`队尾， 如果不是当前层的最后一个节点，将节点的`next`指向同层右侧节点
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环，
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出； 
> > > * 找到左右子节点，将子节点入队列`que`； 
> > > * 如果不是当前层的最后一个节点，将next指向同层右侧节点que.front()
> > 
> > 
> >  
>
> 返回根节点`root`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     Node* connect(Node* root) {
>         // 如果root为空，直接返回空指针nullptr
>         if(root == nullptr) return nullptr;    
>         // 设置队列que
>         queue<Node*> que;
>         // 将root入队列que
>         que.push(root);
>         // 设置层数标志
>         int floor = 0;
> 
>         // while循环
>         while(!que.empty()) {
>             // 层数标志更新
>             floor++;    
>             // 暂存当前层节点数量
>             int floor_size = que.size();
>             
>             // for循环遍历当前层的所有节点
>             for(int i=0; i < floor_size; i++) {
>                // 暂存出栈的节点
>                Node* node = que.front();
>                que.pop();
>                // 左右子节点入队列
>                if(node->left != nullptr) que.push(node->left);
>                if(node->right != nullptr) que.push(node->right);
>                // 如果不是当前层的最后一个节点，将next指向同层右侧节点que.front()
>                if(i != floor_size - 1) node->next = que.front();
>             }
> 
>         }
> 
>         // 返回root节点
>         return root;
>     }
> };
> ```
> 
> 


> <font color="gree"> 代码随想录 </font>
>
> 这道题目说是二叉树，但116题目说是完整二叉树，其实没有任何差别，一样的代码一样的逻辑一样的味道
>
> C++代码：
>
> ```c++
> class Solution {
> public:
>     Node* connect(Node* root) {
>         queue<Node*> que;
>         if (root != NULL) que.push(root);
>         while (!que.empty()) {
>             int size = que.size();
>             // vector<int> vec;
>             Node* nodePre;
>             Node* node;
>             for (int i = 0; i < size; i++) {
>                 if (i == 0) {
>                     nodePre = que.front(); // 取出一层的头结点
>                     que.pop();
>                     node = nodePre;
>                 } else {
>                     node = que.front();
>                     que.pop();
>                     nodePre->next = node; // 本层前一个节点next指向本节点
>                     nodePre = nodePre->next;
>                 }
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>             nodePre->next = NULL; // 本层最后一个节点指向NULL
>         }
>         return root;
> 
>     }
> };
> ```
> 
> 


#### 104.二叉树的最大深度

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>

>
> `Leetcode`链接: https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
>
> **104. 二叉树的最大深度**
>
> 给定一个二叉树，找出其最大深度。
>
> 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
>
> **说明:** 叶子节点是指没有子节点的节点。
>
>
> **示例：**
> 
> 给定二叉树 [3,9,20,null,null,15,7]，
> 
> ```html
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```
> 
> 返回它的最大深度 `3` 。
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     int maxDepth(TreeNode* root) {
> 
>     }
> };
> ```
> 




> 
> <font color="gree">
>
> 思路如下：
> 
> 设置一个队列`que`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点取出,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出
> > > * 找到左右子节点，将子节点入队列`que`
> > 
> > 
> >  
>
> 返回层数`floor`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     int maxDepth(TreeNode* root) {
>         // 设置队列que
>         queue<TreeNode*> que;
>         // 如果root 为空，直接返回0
>         if(root == nullptr) return 0;
>         // 将第1层的root节点入队列que
>         que.push(root);
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点取出,然后将左右子节点全部存入que队尾
>         while(!que.empty()) {
>             // 更新层数标志
>             floor++;     
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，找到左右子节点，将下一层的子节点入队que
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>             }
>         }
>         
>         // 返回层数floor, 即最大深度
>         return floor;
>     }
> };
> ```
> 
> 


> <font color="gree"> 代码随想录 </font>
>
> 使用迭代法的话，使用层序遍历是最为合适的，因为最大的深度就是二叉树的层数，和层序遍历的方式极其吻合。
> 
> 在二叉树中，一层一层的来遍历二叉树，记录一下遍历的层数就是二叉树的深度，如图所示：
> 
> <div align=center>
> <img src="./images/tree_31.png" style="zoom:100%"/>
> </div>
>
> 所以这道题的迭代法就是一道模板题，可以使用二叉树层序遍历的模板来解决的。
> 
> C++代码：
>
> ```c++
> class Solution {
> public:
>     int maxDepth(TreeNode* root) {
>         if (root == NULL) return 0;
>         int depth = 0;
>         queue<TreeNode*> que;
>         que.push(root);
>         while(!que.empty()) {
>             int size = que.size();
>             depth++; // 记录深度
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>         }
>         return depth;
>     }
> };
> ```
> 
> 



#### 111.二叉树的最小深度

> 
> **我们掌握了二叉树的层序遍历，那么如下九道力扣上的题目，只需要修改模板的两三行代码（不能再多了），便可打倒！**
>

>
> `Leetcode`链接: https://leetcode.cn/problems/minimum-depth-of-binary-tree/
>
> **111. 二叉树的最小深度**
>
> 给定一个二叉树，找出其最小深度。
>
> 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
>
> **说明:** 叶子节点是指没有子节点的节点。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_32.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [3,9,20,null,null,15,7]
> 输出：2
> ```
>
> **示例2：**
> 
> ```html
> 输入：root = [2,null,3,null,4,null,5,null,6]
> 输出：5
> ```
>
> **提示：**
> * 树中节点数的范围在 `[0, 105]` 内
> * `-1000 <= Node.val <= 1000`
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     int minDepth(TreeNode* root) {
> 
>     }
> };
> ```
> 



> 
> <font color="gree">
>
> 思路如下：
>
> 如果`root`为空，直接返回`0`
> 
> 设置一个队列`que`
>
> `root`节点入队
> 
> 设置层数标志`floor`
> 
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点取出,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出
> > > * 找到左右子节点，将子节点入队列`que`
> > > * 判断是否为叶子节点，只要出现一次叶子节点，则就可以得到最小深度, 直接返回当前层数`floor`即可
> > 
> > 
> >  
> 
> 返回层数`floor`
>
> </font>
>
> 
> ```c++
> class Solution {
> public:
>     int minDepth(TreeNode* root) {
>         // 如果root 为空，直接返回0
>         if(root == nullptr) return 0;             
>         // 设置队列que
>         queue<TreeNode*> que;
>         // 将第1层的root节点入队列que
>         que.push(root);
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点取出,然后将左右子节点全部存入que队尾
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;    
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
> 
>             // 将当前层的节点取出，找到左右子节点，将下一层的子节点入队que
>             for(int i=0; i < floor_size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>                 // 判断是否为叶子节点，只要出现一次叶子节点，则就可以得到最小深度, 直接返回当前层数即可
>                 if(node->left == nullptr && node->right == nullptr) return floor;
>             }
>         }
> 
>         // 其实这里没必要加return，但是不加的话，编译又不通过
>         return floor;
>     }
> };
> ```
> 
> 


> <font color="gree"> 代码随想录 </font>
>
> **需要注意的是，只有当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点**
>
> 代码如下：（详细注释）
>
> ```c++
> class Solution {
> public:
>     int minDepth(TreeNode* root) {
>         if (root == NULL) return 0;
>         int depth = 0;
>         queue<TreeNode*> que;
>         que.push(root);
>         while(!que.empty()) {
>             int size = que.size();
>             depth++; // 记录最小深度
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>                 if (!node->left && !node->right) { // 当左右孩子都为空的时候，说明是最低点的一层了，退出
>                     return depth;
>                 }
>             }
>         }
>         return depth;
>     }
> };
> ```
> 
> 


#### 总结 层序遍历法

>
> 二叉树的层序遍历，**就是图论中的广度优先搜索在二叉树中的应用**，需要借助队列来实现（此时又发现队列的一个应用了）。
>
> 来吧，一口气打十个
>
> **致敬叶师傅！**
> 
> 






--------------------------------------------------------------------------------

### 非常经典的题目 226.翻转二叉树


> 
> Leetcode链接: https://leetcode.cn/problems/invert-binary-tree/
> 
>
> 给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_33.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [4,2,7,1,3,6,9]
> 输出：[4,7,2,9,6,3,1]
> ```
>
> **示例2：**
> > 
> > <div align=center>
> > <img src="./images/tree_34.jpg" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [2,1,3]
> 输出：[2,3,1]
> ```
>
>
> **示例3：**
> 
> ```html
> 输入：root = []
> 输出：[]
> ```
>
>
> **提示：**
> * 树中节点数目范围在 `[0, 100]` 内
> * `-100 <= Node.val <= 100`
>
>
> ```c++
> /**
>  * Definition for a binary tree node.
>  * struct TreeNode {
>  *     int val;
>  *     TreeNode *left;
>  *     TreeNode *right;
>  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
>  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
>  * };
>  */
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
> 
>     }
> };
> ```
> 

> 
> <font color="yellow">
> 
> **层序遍历**的思路？ **迭代法**能写出来吗？
>
> **前序遍历**的思路？ **递归法**能写出来吗？（深度优先遍历一般用递归法，迭代法复杂）
>
> **中序遍历**的思路？ **递归法**能写出来吗？（深度优先遍历一般用递归法，迭代法复杂）
> 
> **后序遍历**的思路？ **递归法**能写出来吗？（深度优先遍历一般用递归法，迭代法复杂）
>
> </font>
> 



> 
> <font color="yellow">层序遍历的思路如下：（层序遍历一般只有迭代法）</font>
>
> <font color="gree">
> 
> 如果`root`为空，直接返回空指针`nullptr`
> 
> 设置一个队列`que`
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点取出,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出
> > > * 交换左右指针`left`和`right`
> > > * 找到左右子节点，将子节点入队列`que`
> > 
> > 
> >  
>
> 返回根节点`root`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         // 设置队列que
>         queue<TreeNode*> que;
>         // 如果root 为空，直接返回0
>         if(root == nullptr) return 0;
>         // 将第1层的root节点入队列que
>         que.push(root);
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点取出,然后将左右子节点全部存入que队尾
>         while(!que.empty()) {
>             // 更新层数标志
>             floor++;     
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，找到左右子节点，将下一层的子节点入队que
>             for(int i=0; i < floor_size; i++) {
>                 // 从que中取出节点
>                 TreeNode* node = que.front();
>                 que.pop();
>                 // left和right交换
>                 TreeNode* temp = node->left;
>                 node->left = node->right;
>                 node->right = temp;
>                 // left和right入队            
>                 if(node->left != nullptr) que.push(node->left);
>                 if(node->right != nullptr) que.push(node->right);
>             }
>         }
>         
>         // 返回root
>         return root;
>     }
> };
> ```
> 
> 




> 
> <font color="yellow">前序遍历的思路如下：</font>
>
> <font color="gree">
>
> 主要是写递归函数，然后主函数进行调用
>
> 1. **确定递归函数的参数和返回值**：因为不需要处理值之类的操作，参数只需要传入节点即可, 也不需要返回值
>
> ```c++ {.line-numbers}
> void recursion(TreeNode* node)
> ```
> 
> 2. **确定终止条件**：当前遍历的节点是空了，那么本层递归就要结束了，所以如果当前遍历的这个节点是空，就直接`return`，代码如下：
>
> ```c++ {.line-numbers}
> if (node == nullptr) return;
> ```
>
> 3. **确定单层递归的逻辑**：前序遍历是中左右的循序，所以在单层递归的逻辑，是要先处理中节点代码如下：
>
> ```c++ {.line-numbers}
> // 先中
> TreeNode* temp = node->left;
> node->left = node->right;
> node->right = temp;
> // 再左
> recursion(node->left); // 不用先判断if(node->left != nullptr), 因为进入recursion函数体第一句就会判断
> // 最后右
> recursion(node->right); // 不用先判断if(node->right != nullptr), 因为进入recursion函数体第一句就会判断
> ```
> 
> 单层递归的逻辑就是按照中左右的顺序来处理的，这样二叉树的前序遍历，基本就写完了，再看一下完整代码：
>
> </font>
>
> ```c++
> class Solution {
> public:
>     // 递归函数法
>     // 1. 确定递归函数的参数和返回值: 只需要处理一个node
>     // 2. 确定终止条件：只要节点不为空，就往下探索
>     // 3. 确定（前序遍历）单层递归的逻辑：先中，再左，最后右； 
>     void recursion(TreeNode* node) {
>         if(node == nullptr) return;
>         // 先中
>         TreeNode* temp = node->left;
>         node->left = node->right;
>         node->right = temp;
>         // 再左
>         recursion(node->left); // 不用先判断if(node->left != nullptr), 因为进入recursion函数体第一句就会判断
>         // 最后右
>         recursion(node->right); // 不用先判断if(node->right != nullptr), 因为进入recursion函数体第一句就会判断
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     TreeNode* invertTree(TreeNode* root) {
>         recursion(root);
>         return root;
>     }
> };
> ```
> 
> 



> 
> <font color="yellow">后序遍历的代码如下：</font>
>
> ```c++
> class Solution {
> public:
>     // 递归函数法
>     // 1. 确定递归函数的参数和返回值: 只需要处理一个node
>     // 2. 确定终止条件：只要节点不为空，就往下探索
>     // 3. 确定（后序遍历）单层递归的逻辑：先左，再右，最后中； 
>     void recursion(TreeNode* node) {
>         if(node == nullptr) return;
>         // 先左
>         recursion(node->left); // 不用先判断if(node->left != nullptr), 因为进入recursion函数体第一句就会判断
>         // 再右
>         recursion(node->right); // 不用先判断if(node->right != nullptr), 因为进入recursion函数体第一句就会判断
>         // 最后中
>         TreeNode* temp = node->left;
>         node->left = node->right;
>         node->right = temp;        
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     TreeNode* invertTree(TreeNode* root) {
>         recursion(root);
>         return root;
>     }
> };
> ```
>




> 
> <font color="yellow">中序遍历的代码如下（有问题，需要修改）：</font>
>
> ```c++
> class Solution {
> public:
>     // 递归函数法
>     // 1. 确定递归函数的参数和返回值: 只需要处理一个node
>     // 2. 确定终止条件：只要节点不为空，就往下探索
>     // 3. 确定（中序遍历）单层递归的逻辑：先左，再中，最后右； 
>     void recursion(TreeNode* node) {
>         if(node == nullptr) return;
>         // 先左
>         recursion(node->left); // 不用先判断if(node->left != nullptr), 因为进入recursion函数体第一句就会判断
>         // 再中
>         TreeNode* temp = node->left;
>         node->left = node->right;
>         node->right = temp;        
>         // 最后右
>         recursion(node->right); // 不用先判断if(node->right != nullptr), 因为进入recursion函数体第一句就会判断
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     TreeNode* invertTree(TreeNode* root) {
>         recursion(root);
>         return root;
>     }
> };
> ```
> 
> <div align=center>
> <img src="./images/tree_35.jpg" style="zoom:100%;"/>
> </div>
>  
> **代码随想录：中序遍历会把某些节点的左右孩子翻转了两次**
>
> 由于我们`再中`是，已经翻转了左右顺序，所以`最后右`的`recursion(node->right);`应该改为`recursion(node->left);`
> ```c++
> class Solution {
> public:
>     // 递归函数法
>     // 1. 确定递归函数的参数和返回值: 只需要处理一个node
>     // 2. 确定终止条件：只要节点不为空，就往下探索
>     // 3. 确定（中序遍历）单层递归的逻辑：先左，再中，最后右； 
>     void recursion(TreeNode* node) {
>         if(node == nullptr) return;
>         // 先左
>         recursion(node->left); // 不用先判断if(node->left != nullptr), 因为进入recursion函数体第一句就会判断
>         // 再中
>         TreeNode* temp = node->left;
>         node->left = node->right;
>         node->right = temp;        
>         // 最后右
>         recursion(node->left); // 翻转后，原来的右节点现在是node->left
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     TreeNode* invertTree(TreeNode* root) {
>         recursion(root);
>         return root;
>     }
> };
> ```
> 










> <font color="gree"> 以下是代码随想录 </font>
>
> 这道题目背后有一个让程序员心酸的故事，听说`Homebrew`的作者`Max Howell`，就是因为没在白板上写出翻转二叉树，最后被`Google`拒绝了。（真假不做判断，权当一个乐子哈）
>
> **题外话**
> 
> 这道题目是非常经典的题目，也是比较简单的题目（至少一看就会）。
> 
> 但正是因为这道题太简单，一看就会，一些同学都没有抓住起本质，稀里糊涂的就把这道题目过了。
> 
> 如果做过这道题的同学也建议认真看完，相信一定有所收获！
>
> **思路**
>
> 我们之前介绍的都是各种方式遍历二叉树，这次要翻转了，感觉还是有点懵逼。
> 
> 这得怎么翻转呢？
> 
> 如果要从整个树来看，翻转还真的挺复杂，整个树以中间分割线进行翻转，如图：
> 
> 
> <div align=center>
> <img src="./images/tree_36.png" style="zoom:100%;"/>
> </div>
>  
> 可以发现想要翻转它，其实就把每一个节点的左右孩子交换一下就可以了。
>
> 关键在于遍历顺序，前中后序应该选哪一种遍历顺序？ （一些同学这道题都过了，但是不知道自己用的是什么顺序）
>
> 遍历的过程中去翻转每一个节点的左右孩子就可以达到整体翻转的效果。
>
> **注意只要把每一个节点的左右孩子翻转一下，就可以达到整体翻转的效果**
>
> **这道题目使用前序遍历和后序遍历都可以，唯独中序遍历不方便，因为中序遍历会把某些节点的左右孩子翻转了两次！建议拿纸画一画，就理解了**
>
> 那么层序遍历可以不可以呢？**依然可以的！只要把每一个节点的左右孩子翻转一下的遍历方式都是可以的！**
> 
> 
> **递归法**
> 
> 对于二叉树的递归法的前中后序遍历，已经详细讲解了。
> 
> 我们下文以前序遍历为例，通过动画来看一下翻转的过程:
> 
> <div align=center>
> <img src="./images/tree_37.gif" style="zoom:100%;"/>
> </div>
>  
> 我们来看一下递归三部曲：
> 
> 1. 确定递归函数的参数和返回值
>
> 参数就是要传入节点的指针，不需要其他参数了，通常此时定下来主要参数，如果在写递归的逻辑中发现还需要其他参数的时候，随时补充。
>
> 返回值的话其实也不需要，但是题目中给出的要返回`root`节点的指针，可以直接使用题目定义好的函数，所以就函数的返回类型为`TreeNode*`。
>
> ```c++
> TreeNode* invertTree(TreeNode* root)
> ```
>
> 2. 确定终止条件
>
> 当前节点为空的时候，就返回
>
> ```c++
> if (root == NULL) return root;
> ```
> 
> 3. 确定单层递归的逻辑
>
> 因为是先前序遍历，所以先进行交换左右孩子节点，然后反转左子树，反转右子树。
>
> ```c++
> swap(root->left, root->right);
> invertTree(root->left);
> invertTree(root->right);
> ```
> 
> 基于这递归三步法，代码基本写完，C++代码如下：
>
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         if (root == NULL) return root;
>         swap(root->left, root->right);  // 中
>         invertTree(root->left);         // 左
>         invertTree(root->right);        // 右
>         return root;
>     }
> };
> ```
> 
> **迭代法： 深度优先遍历**
>
> 之前给出了前中后序迭代方式的写法，所以本题可以很轻松的写出如下迭代法的代码：
> 
> C++代码迭代法（前序遍历）
> 
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         if (root == NULL) return root;
>         stack<TreeNode*> st;
>         st.push(root);
>         while(!st.empty()) {
>             TreeNode* node = st.top();              // 中
>             st.pop();
>             swap(node->left, node->right);
>             if(node->right) st.push(node->right);   // 右
>             if(node->left) st.push(node->left);     // 左
>         }
>         return root;
>     }
> };
> ```
>
> 统一的深度遍历迭代法，也只需将文中的代码少做修改便可。
>
> 
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             if (node != NULL) {
>                 st.pop();
>                 if (node->right) st.push(node->right);  // 右
>                 if (node->left) st.push(node->left);    // 左
>                 st.push(node);                          // 中
>                 st.push(NULL);
>             } else {
>                 st.pop();
>                 node = st.top();
>                 st.pop();
>                 swap(node->left, node->right);          // 节点处理逻辑
>             }
>         }
>         return root;
>     }
> };
> ```
>
> 
> **迭代法： 广度优先遍历**
>
> 也就是层序遍历，层数遍历也是可以翻转这棵树的，因为层序遍历也可以把每个节点的左右孩子都翻转一遍，代码如下：
>
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         queue<TreeNode*> que;
>         if (root != NULL) que.push(root);
>         while (!que.empty()) {
>             int size = que.size();
>             for (int i = 0; i < size; i++) {
>                 TreeNode* node = que.front();
>                 que.pop();
>                 swap(node->left, node->right); // 节点处理
>                 if (node->left) que.push(node->left);
>                 if (node->right) que.push(node->right);
>             }
>         }
>         return root;
>     }
> };
> ```
>
> **拓展**
>
> **文中我指的是递归的中序遍历是不行的，因为使用递归的中序遍历，某些节点的左右孩子会翻转两次**。
>
> 如果非要使用递归中序的方式写，也可以，如下代码就可以避免节点左右孩子翻转两次的情况：
>
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         if (root == NULL) return root;
>         invertTree(root->left);         // 左
>         swap(root->left, root->right);  // 中
>         invertTree(root->left);         // 注意 这里依然要遍历左孩子，因为中间节点已经翻转了
>         return root;
>     }
> };
> ```
> 
> 代码虽然可以，但这毕竟不是真正的递归中序遍历了。
> 
> 但使用迭代方式统一写法的中序是可以的。
> 
> 代码如下：
>
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             if (node != NULL) {
>                 st.pop();
>                 if (node->right) st.push(node->right);  // 右
>                 st.push(node);                          // 中
>                 st.push(NULL);
>                 if (node->left) st.push(node->left);    // 左
> 
>             } else {
>                 st.pop();
>                 node = st.top();
>                 st.pop();
>                 swap(node->left, node->right);          // 节点处理逻辑
>             }
>         }
>         return root;
>     }
> };
> ```
> 
> 为什么这个中序就是可以的呢，因为这是用栈来遍历，而不是靠指针来遍历，避免了递归法中翻转了两次的情况，大家可以画图理解一下，这里有点意思的。
>
> 
> **总结**
>
> <font color="gree">针对二叉树的问题，解题之前一定要想清楚究竟是前中后序遍历，还是层序遍历。</font>
>
> **二叉树解题的大忌就是自己稀里糊涂的过了（因为这道题相对简单），但是也不知道自己是怎么遍历的。**
>
> 这也是造成了二叉树的题目“一看就会，一写就废”的原因。
> 
> **针对翻转二叉树，我给出了一种递归，三种迭代（两种模拟深度优先遍历，一种层序遍历）的写法，都是之前我们讲过的写法，融汇贯通一下而已。**
>
> 大家一定也有自己的解法，但一定要成方法论，这样才能通用，才能举一反三！
>
> 



### 本周小结！（不是系列总结，二叉树还远没有结束）

>
> **周日我做一个针对本周的打卡留言疑问以及在刷题群里的讨论内容做一下梳理吧**。这样也有助于大家补一补本周的内容，消化消化。
>
> **注意这个周末总结和系列总结还是不一样的（二叉树还远没有结束），这个总结是针对留言疑问以及刷题群里讨论内容的归纳。**
>
> 

#### 周一

> 
> https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html
>
> 讲解了二叉树的理论基础
>
> 有同学会把红黑树和二叉平衡搜索树弄分开了，其实红黑树就是一种二叉平衡搜索树，这两个树不是独立的，所以`C++`中`map`、`multimap`、`set`、`multiset`的底层实现机制是二叉平衡搜索树，再具体一点是红黑树。
>
> 对于二叉树节点的定义，C++代码如下：
>
> ```c++
> struct TreeNode {
>     int val;
>     TreeNode *left;
>     TreeNode *right;
>     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
> };
> ```
>
> 对于这个定义中`TreeNode(int x) : val(x), left(NULL), right(NULL) {}` 有同学不清楚干什么的。
>
> 这是构造函数，**这么说吧`C`语言中的结构体是`C++`中类的祖先，所以`C++`结构体也可以有构造函数**。
> 
> 构造函数也可以不写，但是`new`一个新的节点的时候就比较麻烦。
> 
> 例如有构造函数，定义初始值为9的节点：
>
> ```c++ {.line-numbers}
> TreeNode* a = new TreeNode(9);
> ```
>
> 没有构造函数的话就要这么写：
>
> ```c++ {.line-numbers}
> TreeNode* a = new TreeNode();
> a->val = 9;
> a->left = NULL;
> a->right = NULL;
> ```
>
> 在介绍前中后序遍历的时候，有递归和迭代（非递归），还有一种牛逼的遍历方式：`morris`遍历。
>
> `morris`遍历是二叉树遍历算法的超强进阶算法，`morris`遍历可以将非递归遍历中的空间复杂度降为`O(1)`，感兴趣大家就去查一查学习学习，比较小众，面试几乎不会考。我其实也没有研究过，就不做过多介绍了。
>
> 
> 


#### 周二

>
> https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
>
> 讲到了递归三要素，以及前中后序的递归写法。
>
> <font color="gree">文章中我给出了`leetcode`上三道二叉树的前中后序题目，依然可以解决`n`叉树的前后序遍历，在leetcode上分别是</font>
> 
> [589. N叉树的前序遍历](https://leetcode.cn/problems/n-ary-tree-preorder-traversal/)
> [590. N叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/)
> 
> **由于`N(N > 2)`叉树无法确定把中节点放在第几个位置, 所以没有中序遍历**
> 
> [429. N叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)
>
> 


##### 429.N叉树的层序遍历

>
> `Leetcode`链接: https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
>
>
> **429. N 叉树的层序遍历**
> 
> 给定一个 `N` 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
> 
> 树的序列化输入是用层序遍历，每组子节点都由 `null` 值分隔（参见示例）。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_26.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,3,2,4,null,5,6]
> 输出：[[1],[3,2,4],[5,6]]
> ```
>
> **示例2：**
> > 
> > <div align=center>
> > <img src="./images/tree_27.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
> 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
> ```
>
> **提示：**
> * 树的高度不会超过 `1000`
> * 树的节点总数在 `[0, 10^4]` 之间
>
> ```c++
> /*
> // Definition for a Node.
> class Node {
> public:
>     int val;
>     vector<Node*> children;
> 
>     Node() {}
> 
>     Node(int _val) {
>         val = _val;
>     }
> 
>     Node(int _val, vector<Node*> _children) {
>         val = _val;
>         children = _children;
>     }
> };
> */
> 
> class Solution {
> public:
>     vector<vector<int>> levelOrder(Node* root) {
>         
>     }
> };
> ```
> 
> 
> 这道题与二叉树的层序遍历本质没有差别，只不过是多了几个树杈
>
> <font color="gree">
> 
> 迭代法思路如下：
> 
> 设置一个队列`que`，设置结果集`result`
>
> 如果`root`为空，直接返回空集
>
> `root`节点入队
> 
> 设置层数标志`floor`
>
> 开始`while(!que.empty())`循环，将`que`中存储的单层节点值放入vector<int>,然后将左右子节点全部存入`que`队尾
> > 
> > `while`循环体如下：
> > 
> > * 层数标志增加`floor++`
> > 
> > * 暂存当前层的节点数量`int floor_size = que.size()`
> > 
> > * 内嵌`for(int i=0; i < floor_size; i++)`循环
> > 
> > > `for`循环体如下：
> > > * 将当前层的节点一一取出，
> > > * 将当前层的节点值存入`result`； 
> > > * 找到所有子节点，将子节点入队列`que`
> > 
> > 
> >  
>
> 返回结果集`result`
>
> </font>
>
> ```c++
> class Solution {
> public:
>     vector<vector<int>> levelOrder(Node* root) {
>         // 设置队列que； 设置结果集result; 
>         queue<Node*> que;
>         vector<vector<int>> result;
> 
>         // 如果root 为空，直接返回空集
>         if(root == nullptr) return result;
> 
>         // 将第1层的root节点入队列que
>         que.push(root);
> 
>         // 设置层数标志floor
>         int floor = 0; 
> 
>         // 将que中存储的单层节点值放入vector<int>,然后将所有子节点全部存入que队尾
>         while(!que.empty()) { 
>             // 更新层数标志
>             floor++;
>             // 暂存当前层的节点数量
>             int floor_size = que.size();
>             // 将当前层的节点取出，节点值存入vector<int>，找到所有子节点，将下一层的子节点入队que
>             vector<int> vec; 
>             for(int i=0; i < floor_size; i++) {
>                 Node* node = que.front();
>                 que.pop();
>                 vec.push_back(node->val);
>                 // 对于每一个节点，遍历其children数组，将每一个子节点都放入
>                 for(int k=0; k < node->children.size(); k++) {
>                     if(node->children[k] != nullptr) que.push(node->children[k]);
>                 }
>             }
>                 
>             // 将当前层的节点值存储result
>             result.push_back(vec);
> 
>         }
> 
>         return result;        
>     }
> };
> ```
> 
> 


##### 589. N 叉树的前序遍历

>
> `Leetcode`链接: https://leetcode.cn/problems/n-ary-tree-preorder-traversal/
>
>
> **589. N 叉树的前序遍历**
>
> 
> 给定一个 `n` 叉树的根节点  `root` ，返回 其节点值的 **前序遍历** 。
> 
> `n` 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 `null` 分隔（请参见示例）。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_26.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,3,2,4,null,5,6]
> 输出：[1,3,5,6,2,4]
> ```
>
> **示例2：**
> > 
> > <div align=center>
> > <img src="./images/tree_27.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
> 输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
> ```
> 
>
> **提示：**
> * 节点总数在范围 `[0, 10^4]` 内
> * `0 <= Node.val <= 10^4`
> * `n` 叉树的高度小于或等于 `1000`
>
>
> ```c++
> /*
> // Definition for a Node.
> class Node {
> public:
>     int val;
>     vector<Node*> children;
> 
>     Node() {}
> 
>     Node(int _val) {
>         val = _val;
>     }
> 
>     Node(int _val, vector<Node*> _children) {
>         val = _val;
>         children = _children;
>     }
> };
> */
> 
> class Solution {
> public:
>     vector<int> preorder(Node* root) {
>         
>     }
> };
> ```
> 
> <font color="yellow">递归法的思路如下：</font>
>
> <font color="gree">
>
> 主要是写递归函数，然后主函数进行调用
>
> 1. **确定递归函数的参数和返回值**：因为需要处理节点值，参数包括传入节点和结果集, 不需要返回值
>
> ```c++ {.line-numbers}
> void recursion(Node* node, vector<int>& vec) {}// 注意传指针或传引用，不要传值
> ```
> 
> 2. **确定终止条件**：当前遍历的节点是空了，那么本层递归就要结束了，所以如果当前遍历的这个节点是空，就直接`return`，代码如下：
>
> ```c++ {.line-numbers}
> if (node == nullptr) return;
> ```
>
> 3. **确定单层递归的逻辑**：前序遍历是：中-从左到右的有所子节点，所以在单层递归的逻辑，是要先处理中节点代码如下：
>
> ```c++ {.line-numbers}
> // 中
> vec.push_back(node->val);    
> // 对于每一个节点，遍历其children数组
> for(int k=0; k < node->children.size(); k++) {
>     if(node->children[k] != nullptr) recursion(node->children[k], vec);
> }
> ```
> 
> 单层递归的逻辑就是按照中左右的顺序来处理的，这样二叉树的前序遍历，基本就写完了，再看一下完整代码：
>
> </font>
> 
> <font color="yellow">递归法的代码如下：</font>
>
> ```c++
> class Solution {
> public:
>     // 递归函数
>     // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意：传指针或传引用，不要传值
>     // 2. 确定终止条件：只要节点不为空，就往下探索
>     // 3. 确定单层递归的逻辑：先中，再子节点    
>     void recursion(Node* node, vector<int>& vec){
>         // 终止条件: 空节点
>         if (node == nullptr) return;
>         // 中
>         vec.push_back(node->val);    
>         // 对于每一个节点，遍历其children数组
>         for(int k=0; k < node->children.size(); k++) {
>             if(node->children[k] != nullptr) recursion(node->children[k], vec);
>         }
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> preorder(Node* root) {
>         vector<int> result;
>         recursion(root, result);
>         return result;        
>     }
> };
> ```
> 
> 
> 
> <font color="yellow">迭代法的思路如下：</font>
> 
> <font color="gree">
>
> 递归法 隐式 使用栈存储参数和返回值
> 迭代法 明式 使用栈存储？？？
>
> * 使用栈stack存储待处理节点
>
> * 设置结果集`result`
>
> * 若`root`为空，则直接返回空集
>
> * 根节点`root`入栈
>
> * while循环
>
> 开始`while(!sta.empty())`循环，将`sta`中存储的单层节点值放入vector<int>, 然后将所有子节点全部存入`sta`
> > 
> > `while`循环体如下：
> > 
> > * 暂存当前节点`Node* node = sta.top(); sta.pop();`
> > 
> > * 存储节点值`result.push_back(node->val);`
> > 
> > * 内嵌`for(int i = node->children.size() - 1; i >= 0; i--)`循环(反顺序从右到左入栈，这样出栈才能保证从左到右)
> > 
> 
> * 返回`result`
> 
> </font>
> 
> <font color="yellow">迭代法的代码如下：</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> preorder(Node* root) {
>         // 使用栈stack存储待处理节点
>         stack<Node*> sta;
>         // 设置结果集
>         vector<int> result;
>         // 若root为空，则直接返回空集
>         if(root == nullptr) return result;
>         // 根节点入栈
>         sta.push(root);
>         // while循环
>         while(!sta.empty()) {
>             // 先中
>             Node* node = sta.top();
>             sta.pop();
>             result.push_back(node->val);
>             // 遍历子节点数组, 但是需要反顺序从右到左入栈，这样出栈才能保证从左到右
>             for(int i = node->children.size() - 1; i >= 0; i--) {
>                 if(node->children[i] != nullptr) sta.push(node->children[i]);
>             }
>         }
> 
>         // 返回结果集
>         return result;
>     }
> };
> ```
> 
> 







##### 590. N 叉树的后序遍历

>
> `Leetcode`链接: https://leetcode.cn/problems/n-ary-tree-postorder-traversal/
>
>
> **590. N 叉树的后序遍历**
>
> 
> 给定一个 `n` 叉树的根节点  `root` ，返回 其节点值的 **后序遍历** 。
> 
> `n` 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 `null` 分隔（请参见示例）。
>
>
> **示例1：**
> > 
> > <div align=center>
> > <img src="./images/tree_26.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,3,2,4,null,5,6]
> 输出：[5,6,3,2,4,1]
> ```
>
> **示例2：**
> > 
> > <div align=center>
> > <img src="./images/tree_27.png" style="zoom:100%;"/>
> > </div>
> >  
> ```html
> 输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
> 输出：[2,6,14,11,7,3,12,8,4,13,9,10,5,1]
> ```
> 
>
> **提示：**
> * 节点总数在范围 `[0, 10^4]` 内
> * `0 <= Node.val <= 10^4`
> * `n` 叉树的高度小于或等于 `1000`
>
>
> ```c++
> /*
> // Definition for a Node.
> class Node {
> public:
>     int val;
>     vector<Node*> children;
> 
>     Node() {}
> 
>     Node(int _val) {
>         val = _val;
>     }
> 
>     Node(int _val, vector<Node*> _children) {
>         val = _val;
>         children = _children;
>     }
> };
> */
> 
> class Solution {
> public:
>     vector<int> postorder(Node* root) {
>         
>     }
> };
> ```
> 
> <font color="yellow">递归法的思路如下：</font>
>
> <font color="gree">
>
> 主要是写递归函数，然后主函数进行调用
>
> 1. **确定递归函数的参数和返回值**：因为需要处理节点值，参数包括传入节点和结果集, 不需要返回值
>
> ```c++ {.line-numbers}
> void recursion(Node* node, vector<int>& vec) {}// 注意传指针或传引用，不要传值
> ```
> 
> 2. **确定终止条件**：当前遍历的节点是空了，那么本层递归就要结束了，所以如果当前遍历的这个节点是空，就直接`return`，代码如下：
>
> ```c++ {.line-numbers}
> if (node == nullptr) return;
> ```
>
> 3. **确定单层递归的逻辑**：后序遍历是：从左到右的有所子节点-中，所以在单层递归的逻辑，是要先处理中节点代码如下：
>
> ```c++ {.line-numbers}
> // 对于每一个节点，遍历其children数组
> for(int k=0; k < node->children.size(); k++) {
>     if(node->children[k] != nullptr) recursion(node->children[k], vec);
> }
> // 中
> vec.push_back(node->val);    
> ```
> 
> 单层递归的逻辑就是按照中左右的顺序来处理的，这样二叉树的前序遍历，基本就写完了，再看一下完整代码：
>
> </font>
> 
> <font color="yellow">递归法的代码如下：</font>
> 
> ```c++
> class Solution {
> public:
>     // 递归函数
>     // 1. 确认递归函数的参数和返回值: 要处理的是节点和vector数组。注意：传指针或传引用，不要传值
>     // 2. 确定终止条件：只要节点不为空，就往下探索
>     // 3. 确定单层递归的逻辑：先中，再子节点    
>     void recursion(Node* node, vector<int>& vec){
>         // 终止条件: 空节点
>         if (node == nullptr) return;
>         // 对于每一个节点，遍历其children数组
>         for(int k=0; k < node->children.size(); k++) {
>             if(node->children[k] != nullptr) recursion(node->children[k], vec);
>         }
>         // 中
>         vec.push_back(node->val);    
>     }
>     // 调用递归函数即可，不能在函数内定义函数，要在函数外定义递归函数
>     vector<int> postorder(Node* root) {
>         vector<int> result;
>         recursion(root, result);
>         return result;        
>     }
> };
> ```
> 
> 
> 
> <font color="yellow">迭代法的思路如下：（在先序遍历的基础上修改，待处理节点的入栈顺序翻转， 最后再将`vector`反转顺序即可）</font>
> 
> <font color="gree">
>
> 递归法 隐式 使用栈存储参数和返回值
> 迭代法 明式 使用栈存储？？？
>
> * 使用栈stack存储待处理节点
>
> * 设置结果集`result`
>
> * 若`root`为空，则直接返回空集
>
> * 根节点`root`入栈
>
> * while循环
>
> 开始`while(!sta.empty())`循环，将`sta`中存储的单层节点值放入vector<int>, 然后将所有子节点全部存入`sta`
> > 
> > `while`循环体如下：
> > 
> > * 暂存当前节点`Node* node = sta.top(); sta.pop();`
> > 
> > * 存储节点值`result.push_back(node->val);`
> > 
> > * 内嵌`for(int i = 0; i < node->children.size(); i++)`循环(从左到右入栈，这样出栈才能保证从右到左)
> > 
>
> 
> * 翻转顺序`reverse(result.begin(), result.end())`
> > 反转前顺序是中， 子节点3，子节点2，子节点1
> > 反转后顺序是子节点1，子节点2， 子节点3，中
> 
> * 返回`result`
> 
> </font>
> 
> <font color="yellow">迭代法的代码如下：</font>
> 
> ```c++
> class Solution {
> public:
>     vector<int> postorder(Node* root) {
>         // 使用栈stack存储待处理节点
>         stack<Node*> sta;
>         // 设置结果集
>         vector<int> result;
>         // 若root为空，则直接返回空集
>         if(root == nullptr) return result;
>         // 根节点入栈
>         sta.push(root);
>         // while循环
>         while(!sta.empty()) {
>             // 先中
>             Node* node = sta.top();
>             sta.pop();
>             result.push_back(node->val);
>             // 遍历子节点数组, 从左到右入栈，这样出栈才能保证从右到左
>             for(int i = 0; i < node->children.size(); i++) {
>                 if(node->children[i] != nullptr) sta.push(node->children[i]);
>             }
>         }
> 
>         // 反转前顺序是中， 子节点3，子节点2，子节点1
>         // 反转后顺序是子节点1，子节点2， 子节点3，中
>         reverse(result.begin(), result.end());
> 
>         // 返回结果集
>         return result;
>     }
> };
> ```
> 
> 



#### 周三

>
> https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html
>
> 我们开始用栈来实现递归的写法，也就是所谓的迭代法。
>
> 细心的同学发现文中前后序遍历空节点是否入栈写法是不同的
> 
> 其实空节点入不入栈都差不多，但感觉空节点不入栈确实清晰一些，符合文中动画的演示。
> 
> 拿前序遍历来举例，空节点入栈：
>
> ```c++
> class Solution {
> public:
>     vector<int> preorderTraversal(TreeNode* root) {
>         stack<TreeNode*> st;
>         vector<int> result;
>         st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();                      // 中
>             st.pop();
>             if (node != NULL) result.push_back(node->val);
>             else continue;
>             st.push(node->right);                           // 右
>             st.push(node->left);                            // 左
>         }
>         return result;
>     }
> };
> ```
> 
> 前序遍历空节点不入栈的代码：（注意注释部分和上文的区别）
> 
> ```c++
> class Solution {
> public:
>     vector<int> preorderTraversal(TreeNode* root) {
>         stack<TreeNode*> st;
>         vector<int> result;
>         if (root == NULL) return result;
>         st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();                       // 中
>             st.pop();
>             result.push_back(node->val);
>             if (node->right) st.push(node->right);           // 右（空节点不入栈）
>             if (node->left) st.push(node->left);             // 左（空节点不入栈）
>         }
>         return result;
>     }
> };
> ```
> 
> 在实现迭代法的过程中，有同学问了：递归与迭代究竟谁优谁劣呢？
> 
> 从时间复杂度上其实迭代法和递归法差不多（在不考虑函数调用开销和函数调用产生的堆栈开销），但是空间复杂度上，递归开销会大一些，因为递归需要系统堆栈存参数返回值等等。
> 
> 递归更容易让程序员理解，但收敛不好，容易栈溢出。
> 
> 这么说吧，递归是方便了程序员，难为了机器（各种保存参数，各种进栈出栈）。
> 
> **在实际项目开发的过程中我们是要尽量避免递归！因为项目代码参数、调用关系都比较复杂，不容易控制递归深度，甚至会栈溢出。**
> 
> 


#### 周四

>
> https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.html
>
> 我们使用空节点作为标记，给出了统一的前中后序迭代法。
>
> 此时又多了一种前中后序的迭代写法，那么有同学问了：前中后序迭代法是不是一定要统一来写，这样才算是规范。
>
> 其实没必要，还是自己感觉哪一种更好记就用哪种。
>
> **但是一定要掌握前中后序一种迭代的写法，并不因为某种场景的题目一定要用迭代，而是现场面试的时候，面试官看你顺畅的写出了递归，一般会进一步考察能不能写出相应的迭代。**
>
> 


#### 周五

>
> https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html
>
> 我们介绍了二叉树的另一种遍历方式（图论中广度优先搜索在二叉树上的应用）即：层序遍历。
>
> 看完这篇文章，去leetcode上怒刷五题，文章中 编号107题目的样例图放错了（原谅我匆忙之间总是手抖），但不影响大家理解。
>
> 只有同学发现leetcode上“515. 在每个树行中找最大值”，也是层序遍历的应用，依然可以分分钟解决，所以就是一鼓作气解决六道了，哈哈。
>
> **层序遍历遍历相对容易一些，只要掌握基本写法（也就是框架模板），剩下的就是在二叉树每一行遍历的时候做做逻辑修改。**
>
> 
> 


#### 周六

>
> https://programmercarl.com/0226.%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91.html
>
> 我们把翻转二叉树这么一道简单又经典的问题，充分的剖析了一波，相信就算做过这道题目的同学，看完本篇之后依然有所收获！
>
> **文中我指的是递归的中序遍历是不行的，因为使用递归的中序遍历，某些节点的左右孩子会翻转两次。**
>
> 如果非要使用递归中序的方式写，也可以，如下代码就可以避免节点左右孩子翻转两次的情况：
>
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         if (root == NULL) return root;
>         invertTree(root->left);         // 左
>         swap(root->left, root->right);  // 中
>         invertTree(root->left);         // 注意 这里依然要遍历左孩子，因为中间节点已经翻转了
>         return root;
>     }
> };
> ```
> 
> 代码虽然可以，但这毕竟不是真正的递归中序遍历了。
> 
> 但使用迭代方式统一写法的中序是可以的。
> 
> 代码如下：
> 
> ```c++
> class Solution {
> public:
>     TreeNode* invertTree(TreeNode* root) {
>         stack<TreeNode*> st;
>         if (root != NULL) st.push(root);
>         while (!st.empty()) {
>             TreeNode* node = st.top();
>             if (node != NULL) {
>                 st.pop();
>                 if (node->right) st.push(node->right);  // 右
>                 st.push(node);                          // 中
>                 st.push(NULL);
>                 if (node->left) st.push(node->left);    // 左
> 
>             } else {
>                 st.pop();
>                 node = st.top();
>                 st.pop();
>                 swap(node->left, node->right);          // 节点处理逻辑
>             }
>         }
>         return root;
>     }
> };
> ```
> 
> 为什么这个中序就是可以的呢，因为这是用栈来遍历，而不是靠指针来遍历，避免了递归法中翻转了两次的情况，大家可以画图理解一下，这里有点意思的。
>
> 



#### 总结

>
> **本周我们都是讲解了二叉树，从理论基础到遍历方式，从递归到迭代，从深度遍历到广度遍历，最后再用了一个翻转二叉树的题目把我们之前讲过的遍历方式都串了起来。**
> 















