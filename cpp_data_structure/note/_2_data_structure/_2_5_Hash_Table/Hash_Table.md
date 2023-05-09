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

## 哈希表理论基础

## Hash_Table.md

--------------------------------------------------------------------------------

#### 哈希表(`hash table`)

> 首先什么是 哈希表，哈希表（英文名字为`Hash table`，国内也有一些算法书籍翻译为**散列表**，大家看到这两个名称知道都是指`hash table`就可以了）。
> 
> **哈希表是根据关键码的值而直接进行访问的数据结构**。
> 
> 这么这官方的解释可能有点懵，<font color="yellow">其实直白来讲其实数组就是一张哈希表</font>。
> 
> 哈希表中<font color="yellow">关键码就是数组的索引下标</font>，然后通过下标直接访问数组中的元素，如下图所示：
> 
> 
> <div align=center>
> <img src="./images/hash_table_1.jpg" style="zoom:100%;"/>
> </div>
> 
> 
> 那么哈希表能解决什么问题呢，<font color="yellow">一般哈希表都是用来快速判断一个元素是否出现集合里。</font>
> 
> <font color="yellow">例如, 要查询一个名字是否在这所学校里</font>
> 
> 要枚举的话时间复杂度是`O(n)`，但如果使用哈希表的话， 只需要`O(1)`就可以做到。
> 
> 我们只需要初始化把这所学校里学生的名字都存在哈希表里，在查询的时候通过索引直接就可以知道这位同学在不在这所学校里了。
> 
> 将学生姓名**映射**到哈希表上就涉及到了`hash function` ，也就是**哈希函数**。
>
> ```c++
> // index          索引
> // name           姓名
> // hashFunction   哈希函数
> // hashCode       哈希码, 是一种算法, 看具体情况
> 
> // 已知
> * index = hashFunction(name)
> * hashFuncion() = hashCode() % tableSize
> 
> // 得到
> * index = hashCode(name) % tableSize
> 
> ```


#### 哈希函数
> 
> <font color="yellow"> 哈希函数，把学生的姓名直接映射为哈希表上的索引，然后就可以通过查询索引下标快速知道这位同学是否在这所学校里了。</font>
> 
> 哈希函数如下图所示，通过`hashCode`把名字转化为数值，<font color="yellow">一般`hashcode`是通过特定编码方式，可以将其他数据格式转化为不同的数值</font>，这样就把学生名字映射为哈希表上的索引数字了。
> 
> 
> <div align=center>
> <img src="./images/hash_table_2.jpg" style="zoom:100%;"/>
> </div>
> 

#### 现在有两个问题：
> 
> * **问题1**：如果`index = hashcode(name) > tableSize`怎么办， `index`无法落在哈希表中？
> 
> * **问题2**：如果两个不同`name`得到了相同的`index`怎么办？ 


#### **问题1的解答： 取模**

> 
> 如果`hashCode`得到的数值大于 哈希表的大小了，也就是大于tableSize了，怎么办呢？
> （<font color="red">若是`index=hashCode(name)`,可能会出现`index > tableSize`的情况，无法放入哈希表</font>）
> 
> 此时为了保证映射出来的索引数值都落在哈希表上，我们会在再次对数值做一个**取模**的操作，就要我们就保证了学生姓名一定可以映射到哈希表上了。
> （即`index=hashCode(name) % tableSize`）
>



#### 问题2的现象：哈希碰撞

> **问题2的讨论**
> 
> 此时问题又来了，哈希表我们刚刚说过，就是一个数组。
> 
> 如果学生的数量大于哈希表的大小怎么办，此时就算哈希函数计算的再均匀，也避免不了会有几位学生的名字同时映射到哈希表 同一个索引下标的位置。
> （<font color="red">当`name`的数量`dataSize`大于哈希表大小`tableSize`时，不同的`name`可能有相同的`index`，无法做到独一无二的`index`</font>）
>
> 这种现场，我们称之为**哈希碰撞**（`hash collision`， 或者叫**哈希冲突**）
> 
> 
> 
> <font color="yellow">如图所示，小李和小王都映射到了索引下标 `1` 的位置，这一现象叫做 **哈希碰撞**（`hash collision`， 或者叫 **哈希冲突**）。</font>
> 
> <div align=center>
> <img src="./images/hash_table_3.jpg" style="zoom:100%;"/>
> </div>
> 
> 
> <font color="yellow">一般哈希碰撞有两种解决方法， **拉链法**和**线性探测法**。</font>
> 

##### 问题2的方法1： 哈希碰撞---拉链法

>
> 刚刚小李和小王在索引`1`的位置发生了冲突，<font color="yellow">发生冲突的元素都被存储在链表中</font>。 这样我们就可以通过索引找到小李和小王了
> 
> <div align=center>
> <img src="./images/hash_table_4.jpg" style="zoom:100%;"/>
> </div>
> 
> （数据规模是`dataSize`， 哈希表的大小为`tableSize`）
> 
> <font color="yellow">其实拉链法就是要选择适当的哈希表的大小，这样既不会因为数组空值而浪费大量内存，也不会因为链表太长而在查找上浪费太多时间。</font>
>

##### 问题2的方法2：哈希碰撞---线性探测法
> <font color="yellow">使用线性探测法，一定要保证`tableSize`大于`dataSize`。 我们需要依靠哈希表中的空位来解决碰撞问题。</font>
> 
> 例如冲突的位置，放了小李，那么就向下找一个空位放置小王的信息。所以要求`tableSize`一定要大于`dataSize` ，要不然哈希表上就没有空置的位置来存放 冲突的数据了。如图所示：
> 
> <div align=center>
> <img src="./images/hash_table_5.jpg"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
> 
>
> 其实关于哈希碰撞还有非常多的细节，感兴趣的同学可以再好好研究一下，这里就不再赘述了。
>
> <font color="yellow">这样感觉，**线性探测法**不好，还是**拉链法**好，而且拉链法不用限定条件`tableSize > dataSize`</font>
> 


### 常见的三种哈希结构

> 
> <font color="yellow">当我们想使用哈希法来解决问题的时候，我们一般会选择如下三种数据结构。</font>
> 
> * 数组(`vector`)
> * 集合(`set`)
> * 映射(`map`)
> 
> 这里数组就没啥可说的了，我们来看一下`set`。
> 
> 在C++中，`set` 和 `map` 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：
> 
> <div align=center>
> <img src="./images/hash_table_6.jpg"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
> 
>
> `std::unordered_set` 底层实现为哈希表，`std::set` 和`std::multiset` 的底层实现是红黑树，红黑树是一种平衡二叉搜索树，所以`key`值是有序的，但`key`不可以修改，改动`key`值会导致整棵树的错乱，所以**只能删除和增加**。
> 
> 
> <div align=center>
> <img src="./images/hash_table_7.jpg"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
> 
>
> `std::unordered_map` 底层实现为哈希表，`std::map` 和`std::multimap` 的底层实现是红黑树。同理，`std::map` 和`std::multimap` 的`key`也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。
>
> <font color="yellow">
> 
> 当我们要使用集合`set`来解决哈希问题的时候，该如何选择？
> 
> * 优先使用`unordered_set`，因为它的查询和增删效率是最优的
> 
> * 如果需要集合是有序的，那么就用`set`
> 
> * 如果要求不仅有序还要有重复数据的话，那么就用`multiset`
> 
> </font>
> 
>
> 
> 那么再来看一下`map` ，在`map`中 是一个`(key，value)` 的数据结构，`map`中，对`key`是有限制，对`value`没有限制的，因为`key`的存储方式使用红黑树实现的。
>
> 其他语言例如：`java`里的`HashMap` ，`TreeMap` 都是一样的原理。可以灵活贯通。
> 
> <font color="green">虽然`std::set`、`std::multiset` 的底层实现是红黑树，不是哈希表（即`std::set`、`std::multiset` 使用红黑树来索引和存储），不过给我们的使用方式，还是哈希法的使用方式，即`key`和`value`。所以使用这些数据结构来解决映射问题的方法，我们依然称之为哈希法。 `map`也是一样的道理。</font>
>
> 
> 这里在说一下，一些`C++`的经典书籍上 例如`STL`源码剖析，说到了`hash_set`， `hash_map`，这个与`unordered_set`，`unordered_map`又有什么关系呢？
>
> 
> 实际上功能都是一样一样的， 但是`unordered_set`在`C++11`的时候被引入标准库了，而`hash_set`并没有，所以建议还是使用`unordered_set`比较好，这就好比一个是官方认证的，`hash_set`，`hash_map` 是`C++11`标准之前民间高手自发造的轮子。
>
> 
> <div align=center>
> <img src="./images/hash_table_8.jpg"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
> 

> **总结**：
>
> <font color="green">注意：以下内容中，有`std::`前缀时，才指的是具体容器，否则都是抽象概念</font>
>
> `set` 和 `map` 的<font color="yellow">相同点</font>
> 
> * 都是 `key`和`value` 对应
> 
> * 都有三种容器 `std::xxx`、`std::multixxx`、`std::unordered_xxx` (`xxx` = `set`或`map`)
> 
> * <font color="yellow">都是优先使用`std::unordered_xxx` (`xxx` = `set`或`map`)</font>
>
> * <font color="yellow">如果需要`key`是有序的，则使用`std::multixxx` (`xxx` = `set`或`map`)</font>
>
> * <font color="yellow">如果要求不仅`key`有序还要有重复`value`的话，才需要使用`std::xxx`(`xxx` = `set`或`map`)</font>
>
> * 虽然`std::xxx`、`std::multixxx`的底层实现并不是哈希表，而是红黑树，但是从使用方式的角度来说，还是哈希法的使用方式，即`key`和`value`。所以使用这些数据结构来解决映射问题的方法，我们依然称之为哈希法
>
> * 都能通过迭代器进行遍历；
>
> 
> `set` 和 `map` 的<font color="yellow">不同点</font>
>
> * `set`是值`value`的集合；`map`是`(key，value)`键值对
> 
> * `set`因为只有值`value`，不能通过`get`方法取值；`map`可以通过`get`方法获取值
>
> * `set`的值是唯一的可以做数组去重，`map`由于没有格式限制，可以做数据存储
>
> * 由于`std::map`是`key_value`的形式，所以`std::map`里的所有元素都是`std::pair`类型。`std::pair`里面的`std::pair::first`被称为`key`(键），`std::pair::second`被称为`value`(值）。它可以通过关键字`key`查找映射关联信息`value`，同时根据`key`值进行排序。
>
> 


### 总结
> 总结一下，**当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法**。
>
> 但是哈希法也是**牺牲了空间换取了时间**，因为我们要使用额外的数组，`std::unordered_set`或者是`std::unordered_map`来存放数据，才能实现快速的查找。
> 
> **如果在做面试题目的时候遇到需要判断一个元素是否出现过的场景也应该第一时间想到哈希法！**
> 

### 代码随想录的评论区
> 
> 
> <div align=center>
> <img src="./images/hash_table_9.jpg"  width="" height="" alt="no photo" title="" style="zoom:100%;"/>
> </div>
> 
>