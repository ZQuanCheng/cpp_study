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

## 设计链表 design linked list

## _2_design_linked_list.md
--------------------------------------------------------------------------------

### 707.设计链表

> Leetcode链接: https://leetcode.cn/problems/design-linked-list/

> 你可以选择使用单链表或者双链表，设计并实现自己的链表。
> 
> 单链表中的节点应该具备两个属性：`val` 和 `next` 。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。
> 
> 如果是双向链表，则还需要属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点下标从 `0` 开始。
> 
> 实现 `MyLinkedList` 类：
> 
> * `MyLinkedList()` 初始化 `MyLinkedList` 对象。
> * `int get(int index)` 获取链表中下标为 `index` 的节点的值。如果下标无效，则返回 `-1` 。
> * `void addAtHead(int val)` 将一个值为 `val` 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
> * `void addAtTail(int val)` 将一个值为 `val` 的节点追加到链表中作为链表的最后一个元素。
> * `void addAtIndex(int index, int val)` 将一个值为 `val` 的节点插入到链表中下标为 `index` 的节点之前。如果 `index` 等于链表的长度，那么该节点会被追加到链表的末尾。如果 `index` 比长度更大，该节点将 **不会插入** 到链表中。
> * `void deleteAtIndex(int index)` 如果下标有效，则删除链表中下标为 `index` 的节点。
>  
> **示例：**
> ```html
> 输入
> ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
> [[], [1], [3], [1, 2], [1], [1], [1]]
> 
> 输出
> [null, null, null, null, 2, null, 3]
> 
> 解释
> MyLinkedList myLinkedList = new MyLinkedList();
> myLinkedList.addAtHead(1);
> myLinkedList.addAtTail(3);
> myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
> myLinkedList.get(1);              // 返回 2
> myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
> myLinkedList.get(1);              // 返回 3
> ```
>
> **提示:**
> * `0 <= index, val <= 1000`
> * 请不要使用内置的 `LinkedList` 库。
> * 调用 `get`、`addAtHead`、`addAtTail`、`addAtIndex` 和 `deleteAtIndex` 的次数不超过 `2000` 。
>
> ```c++
> class MyLinkedList {
> public:
>     MyLinkedList() {
> 
>     }
>     
>     int get(int index) {
> 
>     }
>     
>     void addAtHead(int val) {
> 
>     }
>     
>     void addAtTail(int val) {
> 
>     }
>     
>     void addAtIndex(int index, int val) {
> 
>     }
>     
>     void deleteAtIndex(int index) {
> 
>     }
> };
> 
> /**
>  * Your MyLinkedList object will be instantiated and called as such:
>  * MyLinkedList* obj = new MyLinkedList();
>  * int param_1 = obj->get(index);
>  * obj->addAtHead(val);
>  * obj->addAtTail(val);
>  * obj->addAtIndex(index,val);
>  * obj->deleteAtIndex(index);
>  */
> ```




#### 我的解法  49/64 个通过---51/64个通过---53/64个通过---全部通过
```c++
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode():val(0), next(nullptr) {}
        ListNode(int x):val(x), next(nullptr) {}
        ListNode(int x, ListNode* nextnode):val(x), next(nextnode) {}
    };
    ListNode* head = nullptr;
    ListNode* ptr = nullptr;

    MyLinkedList() { // 初始化为空
        // head = new ListNode();     
    }
    
    int get(int index) {
        if(head == nullptr) {  // 空链表
            return -1; 
        }
        else {  // 非空链表        
            ptr = head;    
            int index_val = -1;
            int xiaobiao = 0;
            while (ptr != nullptr) {
                if (xiaobiao == index) {
                    index_val = ptr->val;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }
            return index_val;
        }
    }
    
    void addAtHead(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表
            ListNode* newHead = new ListNode(val);
            newHead->next = head;
            // 更新head
            head = newHead;
        }

    }
    
    void addAtTail(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表        
            ListNode* newTail = new ListNode(val);
            ptr = head;
            // ptr指向最后一个node
            while(ptr->next != nullptr) {
                ptr = ptr->next;
            } 
            // 最后一个节点的next指向newTail
            ptr->next = newTail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(head != nullptr) {  // 非空链表        
            ListNode* newNode = new ListNode(val);
            ptr = head;    
            int xiaobiao = 0;
            while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                   // 插入
                   newNode->next = ptr->next;
                   ptr->next = newNode;
                   break;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }
            // 若while中，未进行插入，说明index >= n-1.
            // 且 ptr指向第n-1个节点(末尾节点)，xiaobiao = n-1
            if (xiaobiao = index - 1) { // index = n
               ptr->next = newNode; // newNode成为新的末尾
            }
        }        
    }
    
    void deleteAtIndex(int index) {
        if(head != nullptr) {  // 非空链表        
            ptr = head;    
            int xiaobiao = 0;
            ListNode* tmp = nullptr;

            while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                   // 删除
                   tmp = ptr->next;
                   ptr->next = ptr->next->next;
                   delete tmp;
                   break;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }
        }  
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

<font color="yellow"> 错误的例子为第50个 </font>

```html

输入
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[0],[0]]

输出
[null,null,null,null,2,null,1]

预期结果
[null,null,null,null,2,null,2]
```

<font color="yellow"> 错误原因："deleteAtIndex(0)"没成功删除头节点 </font>

<font color="yellow"> 之前没考虑头结点删除的问题，这里修改deleteAtIndex()，添加虚拟头结点 </font>

```c++
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode():val(0), next(nullptr) {}
        ListNode(int x):val(x), next(nullptr) {}
        ListNode(int x, ListNode* nextnode):val(x), next(nextnode) {}
    };
    ListNode* head = nullptr;
    ListNode* ptr = nullptr;

    MyLinkedList() { // 初始化为空
        // head = new ListNode();     
    }
    
    int get(int index) {
        if(head == nullptr) {  // 空链表
            return -1; 
        }
        else {  // 非空链表        
            ptr = head;    
            int index_val = -1;
            int xiaobiao = 0;
            while (ptr != nullptr) {
                if (xiaobiao == index) {
                    index_val = ptr->val;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }
            return index_val;
        }
    }
    
    void addAtHead(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表
            ListNode* newHead = new ListNode(val);
            newHead->next = head;
            // 更新head
            head = newHead;
        }

    }
    
    void addAtTail(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表        
            ListNode* newTail = new ListNode(val);
            ptr = head;
            // ptr指向最后一个node
            while(ptr->next != nullptr) {
                ptr = ptr->next;
            } 
            // 最后一个节点的next指向newTail
            ptr->next = newTail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(head != nullptr) {  // 非空链表        
            ListNode* newNode = new ListNode(val);
            ptr = head;    
            int xiaobiao = 0;
            while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                   // 插入
                   newNode->next = ptr->next;
                   ptr->next = newNode;
                   break;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }
            // 若while中，未进行插入，说明index >= n-1.
            // 且 ptr指向第n-1个节点(末尾节点)，xiaobiao = n-1
            if (xiaobiao = index - 1) { // index = n
               ptr->next = newNode; // newNode成为新的末尾
            }
        }        
    }
    
    void deleteAtIndex(int index) {
        // 注意移除元素时，记得添加虚拟头结点dummyHead，
        // 这样不用单独处理头节点Head了
        if(head != nullptr) {  // 非空链表   
            ListNode*  dummyHead = new ListNode();
            dummyHead->next = head;
            
            int xiaobiao = -1; // 虚拟头节点的索引为-1
            ListNode* tmp = nullptr;
            
            ptr = dummyHead;    
            while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                   // 删除
                   tmp = ptr->next;
                   ptr->next = ptr->next->next;
                   delete tmp;
                   break;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }

            head = dummyHead->next;
            delete dummyHead;
        }  
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

<font color="yellow"> 再次错误的例子为第52个 </font>

```html
输入
["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
[[],[0,10],[0,20],[1,30],[0]]

输出
[null,null,null,null,-1]

预期结果
[null,null,null,null,20]
```
<font color="yellow"> "addAtIndex(0)"没成功添加头节点 </font>

<font color="yellow"> 之前没考虑头结点添加的问题，这里修改addAtIndex() </font>

```c++
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode():val(0), next(nullptr) {}
        ListNode(int x):val(x), next(nullptr) {}
        ListNode(int x, ListNode* nextnode):val(x), next(nextnode) {}
    };
    ListNode* head = nullptr;
    ListNode* ptr = nullptr;

    MyLinkedList() { // 初始化为空
        // head = new ListNode();     
    }
    
    int get(int index) {
        if(head == nullptr) {  // 空链表
            return -1; 
        }
        else {  // 非空链表        
            ptr = head;    
            int index_val = -1;
            int xiaobiao = 0;
            while (ptr != nullptr) {
                if (xiaobiao == index) {
                    index_val = ptr->val;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }
            return index_val;
        }
    }
    
    void addAtHead(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表
            ListNode* newHead = new ListNode(val);
            newHead->next = head;
            // 更新head
            head = newHead;
        }

    }
    
    void addAtTail(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表        
            ListNode* newTail = new ListNode(val);
            ptr = head;
            // ptr指向最后一个node
            while(ptr->next != nullptr) {
                ptr = ptr->next;
            } 
            // 最后一个节点的next指向newTail
            ptr->next = newTail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) { // index为0时，就是addAtHead
           addAtHead(val);
        }
        else {   // index 不为0
            if (head == nullptr) {  // index不为0，且空链表，不处理

            }
            else{  // index不为0，非空链表       
                ListNode* newNode = new ListNode(val);
                ptr = head;    
                int xiaobiao = 0;
                while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                    if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                       // 插入
                       newNode->next = ptr->next;
                       ptr->next = newNode;
                       break;
                    } 
                    ptr = ptr->next;
                    ++xiaobiao;
                }
                // 若while中，未进行插入，说明index >= n-1.
                // 且 ptr指向第n-1个节点(末尾节点)，xiaobiao = n-1
                if (xiaobiao = index - 1) { // index = n
                   ptr->next = newNode; // newNode成为新的末尾
                }
            } 

        }
       
    }
    
    void deleteAtIndex(int index) {
        // 注意移除元素时，记得添加虚拟头结点dummyHead，
        // 这样不用单独处理头节点Head了
        if(head != nullptr) {  // 非空链表   
            ListNode*  dummyHead = new ListNode();
            dummyHead->next = head;
            
            int xiaobiao = -1; // 虚拟头节点的索引为-1
            ListNode* tmp = nullptr;
            
            ptr = dummyHead;    
            while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                   // 删除
                   tmp = ptr->next;
                   ptr->next = ptr->next->next;
                   delete tmp;
                   break;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }

            head = dummyHead->next;
            delete dummyHead;
        }  
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

<font color="yellow"> 再次错误的例子为第54个 </font>

```html
输入
["MyLinkedList","addAtHead","addAtIndex","get","addAtHead","addAtTail","get","addAtTail","get","addAtHead","get","addAtHead"]
[[],[5],[1,2],[1],[6],[2],[3],[1],[5],[2],[2],[6]]

输出
[null,null,null,-1,null,null,-1,null,-1,null,5,null]

预期结果
[null,null,null,2,null,null,2,null,-1,null,5,null]
```
<font color="yellow"> 看不太出来，第四个命令"get"出问题了 </font>

<font color="yellow"> 没检查出来，实机跑试试 </font>

```c++
int main()
{
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(5);
    myLinkedList->addAtIndex(1, 2); 
    int val = myLinkedList->get(1);
    cout << val << endl;

    cout << endl;
    pause(); // system("pause"); 
    return 0;
}
```

<font color="yellow"> 编译报错！！！ </font>

```html
/home/ubuntu/zqc/cpp_data_structure/main.cpp: In member function ‘void MyLinkedList::addAtIndex(int, int)’:
/home/ubuntu/zqc/cpp_data_structure/main.cpp:151:30: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
                 if (xiaobiao = index - 1) { // index = n
```

<font color="yellow"> addAtIndex()最后的if (xiaobiao = index - 1) 判别，"=="中少了一个等号 </font>


<font color="yellow"> 修改后如下 </font>

```c++
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode():val(0), next(nullptr) {}
        ListNode(int x):val(x), next(nullptr) {}
        ListNode(int x, ListNode* nextnode):val(x), next(nextnode) {}
    };
    ListNode* head = nullptr;
    ListNode* ptr = nullptr;

    MyLinkedList() { // 初始化为空
        // head = new ListNode();     
    }
    
    int get(int index) {
        if(head == nullptr) {  // 空链表
            return -1; 
        }
        else {  // 非空链表        
            ptr = head;    
            int index_val = -1;
            int xiaobiao = 0;
            while (ptr != nullptr) {
                if (xiaobiao == index) {
                    index_val = ptr->val;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }
            return index_val;
        }
    }
    
    void addAtHead(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表
            ListNode* newHead = new ListNode(val);
            newHead->next = head;
            // 更新head
            head = newHead;
        }

    }
    
    void addAtTail(int val) {
        if(head == nullptr) {  // 空链表
            head = new ListNode(val);  
        }
        else {  // 非空链表        
            ListNode* newTail = new ListNode(val);
            ptr = head;
            // ptr指向最后一个node
            while(ptr->next != nullptr) {
                ptr = ptr->next;
            } 
            // 最后一个节点的next指向newTail
            ptr->next = newTail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) { // index为0时，就是addAtHead
           addAtHead(val);
        }
        else {   // index != 0
            if (head == nullptr) {  // index不为0，且空链表，
                //  不处理
            }
            else {  // index不为0，非空链表       
                ListNode* newNode = new ListNode(val);

                ptr = head;    
                int xiaobiao = 0;
                while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                    if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                       // 插入
                       newNode->next = ptr->next;
                       ptr->next = newNode;
                       break;
                    } 
                    ptr = ptr->next;
                    ++xiaobiao;
                }
                // 若while中，未进行插入，说明index >= n-1.
                // 且 ptr指向第n-1个节点(末尾节点)，xiaobiao = n-1
                if (xiaobiao == index - 1) { // index = n
                   ptr->next = newNode; // newNode成为新的末尾
                }
            } 
        }
       
    }
    
    void deleteAtIndex(int index) {
        // 注意移除元素时，记得添加虚拟头结点dummyHead，
        // 这样不用单独处理头节点Head了
        if(head != nullptr) {  // 非空链表   
            ListNode*  dummyHead = new ListNode();
            dummyHead->next = head;
            
            int xiaobiao = -1; // 虚拟头节点的索引为-1
            ListNode* tmp = nullptr;
            
            ptr = dummyHead;    
            while (ptr->next != nullptr) { // ptr移动到第n-2个节点为止
                if (xiaobiao == index-1) { // index-1 <= n-2 即 index <= n-1
                   // 删除
                   tmp = ptr->next;
                   ptr->next = ptr->next->next;
                   delete tmp;
                   break;
                } 
                ptr = ptr->next;
                ++xiaobiao;
            }

            head = dummyHead->next;
            delete dummyHead;
        }  
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

<font color="yellow"> 完成！！！ </font>

<font color="yellow"> 上面写的虽然也没问题，但是感觉不够简洁，想办法优化一下 </font>

```c++
class MyLinkedList {
//    底部的private中定义
//    ListNode* dummyHead; // 全局虚拟头结点head node，不用再在成员函数中单独定义
//    int size;            // 全局链表长度，可以不用while循环了（结束条件容易出错），for循环更加明确
//    这里，private不能在顶部的原因是，还没定义struct ListNode，无法定义dummyHead；


public:
    struct ListNode {
        int val;
        ListNode* next;
        // 用不到 ListNode():val(0), next(nullptr) {}
        ListNode(int x):val(x), next(nullptr) {}
        // 用不到 ListNode(int x, ListNode* nextnode):val(x), next(nextnode) {}  
    };

    MyLinkedList() { // 初始化为空
        dummyHead = new ListNode(0);     
        size = 0;
    }
    
    int get(int index) {
        // index <0 或 index >= size时，是无效的，返回-1
        if (index < 0 || index >= size) {
            return -1;
        } 
        // 如果是空链表，头节点为nullptr,则返回-1
        if (dummyHead->next == nullptr) { //
            return -1;
        }
        // 非空链表，且index有效时，读取对应下标的值
        ListNode* cur = dummyHead->next; // cur指的是游标Cursor
        for(int i=0; i<index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = newNode;
        cur->next = dummyHead->next;
        dummyHead->next = cur;
        ++size;
    }
    
    void addAtTail(int val) {
        ListNode* cur = dummyHead;// 不是cur = dummyHead->next的原因是，要考虑到size = 0;
                                  // 当size =0 时，空链表，
        for(int i=0; i<size; i++) {
            cur = cur->next;
        } // cur游标移动到尾节点

        ListNode* newNode = new ListNode(val);
        cur->next = newNode; // 尾节点的next域，指向新的尾节点
                             // 默认生成的新节点的next域为nullptr，不用单独处理
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) {
            return;
        }
        else if(index < size) {  
            ListNode* newNode = new ListNode(val);
            ListNode* cur = dummyHead; // 不是cur = dummyHead->next的原因是，要考虑到index = 0;
                                       // 当index =0 时，认为是插入到头结点之前，即addAtHead(val)
            for (int i=0; i<index; i++) {
                cur = cur->next;
            } // cur指向下标为index-1的节点（注，dummyHead下标为-1，也包含在内）
            newNode->next = cur->next;
            cur->next = newNode;
            ++size;
        }
        else if(index == size) { // 其实这里就是运行成员函数void addAtTail(int val)
            addAtTail(val);
        }
        else { // index > size
            return; // 不处理直接返回
        }
        // 其实，index<size和index==size是可以放在一起的，这里分开是因为题目中分开描述了，我们对应分析
    }
    
    void deleteAtIndex(int index) {
        // index <0 或 index >= size时，是无效的，返回
        if (index < 0 || index >= size) {
            return;
        } 
        // 如果是空链表，头节点为nullptr,则返回
        if (dummyHead->next == nullptr) { //
            return;
        }
        // 非空链表，且index有效时，读取对应下标的值
        ListNode* cur = dummyHead; // 不是cur = dummyHead->next的原因是，要考虑到index = 0;
                                   // 当index =0 时，删除头结点
        for (int i=0; i<index; i++) {
            cur = cur->next;
        }  // cur指向下标为index-1的节点（注，dummyHead下标为-1，也包含在内）
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        --size;
    }

private:
    ListNode* dummyHead; // 全局虚拟headnode，不用再在成员函数中单独定义
    int size;            // 全局链表长度，可以不用while循环了（边界条件容易出错），for循环更加明确

};
```


<font color="yellow"> 还可以加一个打印链表的成员函数 </font>

```c++
class MyLinkedList {
//    底部的private中定义
//    ListNode* dummyHead; // 全局虚拟头结点head node，不用再在成员函数中单独定义
//    int size;            // 全局链表长度，可以不用while循环了（结束条件容易出错），for循环更加明确
//    这里，private不能在顶部的原因是，还没定义struct ListNode，无法定义dummyHead；


public:
    struct ListNode {
        int val;
        ListNode* next;
        // 用不到 ListNode():val(0), next(nullptr) {}
        ListNode(int x):val(x), next(nullptr) {}
        // 用不到 ListNode(int x, ListNode* nextnode):val(x), next(nextnode) {}  
    };

    MyLinkedList() { // 初始化为空
        dummyHead = new ListNode(0);     
        size = 0;
    }
    
    int get(int index) {
        // index <0 或 index >= size时，是无效的，返回-1
        if (index < 0 || index >= size) {
            return -1;
        } 
        // 如果是空链表，头节点为nullptr,则返回-1
        if (dummyHead->next == nullptr) { //
            return -1;
        }
        // 非空链表，且index有效时，读取对应下标的值
        ListNode* cur = dummyHead->next; // cur指的是游标Cursor
        for(int i=0; i<index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = newNode;
        cur->next = dummyHead->next;
        dummyHead->next = cur;
        ++size;
    }
    
    void addAtTail(int val) {
        ListNode* cur = dummyHead;// 不是cur = dummyHead->next的原因是，要考虑到size = 0;
                                  // 当size =0 时，空链表，
        for(int i=0; i<size; i++) {
            cur = cur->next;
        } // cur游标移动到尾节点

        ListNode* newNode = new ListNode(val);
        cur->next = newNode; // 尾节点的next域，指向新的尾节点
                             // 默认生成的新节点的next域为nullptr，不用单独处理
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) {
            return;
        }
        else if(index < size) {  
            ListNode* newNode = new ListNode(val);
            ListNode* cur = dummyHead; // 不是cur = dummyHead->next的原因是，要考虑到index = 0;
                                       // 当index =0 时，认为是插入到头结点之前，即addAtHead(val)
            for (int i=0; i<index; i++) {
                cur = cur->next;
            } // cur指向下标为index-1的节点（注，dummyHead下标为-1，也包含在内）
            newNode->next = cur->next;
            cur->next = newNode;
            ++size;
        }
        else if(index == size) { // 其实这里就是运行成员函数void addAtTail(int val)
            addAtTail(val);
        }
        else { // index > size
            return; // 不处理直接返回
        }
        // 其实，index<size和index==size是可以放在一起的，这里分开是因为题目中分开描述了，我们对应分析
    }
    
    void deleteAtIndex(int index) {
        // index <0 或 index >= size时，是无效的，返回
        if (index < 0 || index >= size) {
            return;
        } 
        // 如果是空链表，头节点为nullptr,则返回
        if (dummyHead->next == nullptr) { //
            return;
        }
        // 非空链表，且index有效时，读取对应下标的值
        ListNode* cur = dummyHead; // 不是cur = dummyHead->next的原因是，要考虑到index = 0;
                                   // 当index =0 时，删除头结点
        for (int i=0; i<index; i++) {
            cur = cur->next;
        }  // cur指向下标为index-1的节点（注，dummyHead下标为-1，也包含在内）
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        --size;
    }

    void printLindedList() {
        ListNode* cur = dummyHead->next;
        for (int i=0; i<size; i++) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    ListNode* dummyHead; // 全局虚拟headnode，不用再在成员函数中单独定义
    int size;            // 全局链表长度，可以不用while循环了（边界条件容易出错），for循环更加明确

};
```

<font color="yellow"> 实机跑一下 </font>

> ```c++
> int main()
> {
>     MyLinkedList* myLinkedList = new MyLinkedList();
>     myLinkedList->addAtHead(5);
>     myLinkedList->addAtIndex(1, 2); 
>     myLinkedList->printLindedList();
>     int val = myLinkedList->get(1);
>     cout << val << endl;
> 
>     cout << endl;
>     pause(); // system("pause"); 
>     return 0;
> }
> ```
> 运行结果如下
> ```html
> 5 2 
> 2
> ```







#### 代码随想录的解法 

> 删除链表节点：
> <div align=center>
> <img src="./images/design_linked_list_1.png" style="zoom:80%;"/>
> </div>
> 
> 添加链表节点：
> <div align=center>
> <img src="./images/design_linked_list_2.png" style="zoom:80%;"/>
> </div>
>
> 这道题目设计链表的五个接口：
> 
> * 获取链表第index个节点的数值
> * 在链表的最前面插入一个节点
> * 在链表的最后面插入一个节点
> * 在链表第index个节点前面插入一个节点
> * 删除链表的第index个节点
> 
> 可以说这五个接口，已经覆盖了链表的常见操作，是练习链表操作非常好的一道题目
>
> **链表操作的两种方式：**
> * 直接使用原来的链表来进行操作。
> * <font color="yellow">设置一个虚拟头结点在进行操作。</font>
> 
> 下面采用的设置一个虚拟头结点（这样更方便一些，大家看代码就会感受出来）
>
```c++
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){ // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {

        if(index > _size) return;
        if(index < 0) index = 0;        
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;

};
```


















