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

# 链表

--------------------------------------------------------------------------------

## 链表相交 intersection of two linked lists

## _6_intersection_of_two_linked_lists.md
--------------------------------------------------------------------------------

### 面试题 02.07. 链表相交

> Leetcode链接: https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

> 给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。
> 
> 图示两个链表在节点 `c1` 开始相交：
> <div align=center>
> <img src="./images/intersection_of_two_linked_lists_1.png" style="zoom:100%;"/>
> </div>
> 
> 题目数据 **保证** 整个链式结构中不存在环。
> 
> **注意**，函数返回结果后，链表必须 **保持其原始结构** 。
> 
> **示例1：**
> 
> <div align=center>
> <img src="./images/intersection_of_two_linked_lists_2.png" style="zoom:100%;"/>
> </div>
> 
> ```html
> 输入：
> intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
> 
> 输出：
> Intersected at '8'
> 
> 解释：
> 相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
> 从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
> 在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
> ```
> 
> **示例2：**
> 
> <div align=center>
> <img src="./images/intersection_of_two_linked_lists_3.png" style="zoom:100%;"/>
> </div>
> 
> ```html
> 输入：
> intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
> 
> 输出：
> Intersected at '2'
> 
> 解释：
> 相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
> 从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
> 在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
> ```
> 
> **示例3：**
> 
> <div align=center>
> <img src="./images/intersection_of_two_linked_lists_4.png" style="zoom:100%;"/>
> </div>
> 
> ```html
> 输入：
> intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
> 
> 输出：
> null
> 
> 解释：
> 从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
> 由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
> 这两个链表不相交，因此返回 null 。
> ```
> 
> **提示：**
> * `listA` 中节点数目为 `m`
> * `listB` 中节点数目为 `n`
> * `0 <= m, n <= 3 * 104`
> * `1 <= Node.val <= 105`
> * `0 <= skipA <= m`
> * `0 <= skipB <= n`
> * 如果 `listA` 和 `listB` 没有交点，`intersectVal` 为 `0`
> * 如果 `listA` 和 `listB` 有交点，`intersectVal == listA[skipA + 1] == listB[skipB + 1]`
> 
>
> **进阶**：你能否设计一个时间复杂度 `O(n)` 、仅用 `O(1)` 内存的解决方案？
> 
> 