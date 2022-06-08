## 目录：

### 线性表（数组，栈，队列）

### 线性表（链表）
#### 单链表
#### 双向链表
#### 循环链表
#### 双向循环链表

### 散列表（哈希表）
#### 冲突解决

### 树
#### 二叉树
#### 满二叉树
#### 完全二叉树
#### 二叉排序树
#### 平衡二叉树
#### AVL树
#### 红黑树

### 堆
#### 小顶堆
#### 大顶堆
#### 堆排序

### 图
#### 图的概念
#### 图的存储
#### 图的遍历
#### 图的应用
##### 最小生成树
##### 最短路径
##### 拓扑排序
##### 关键路径

### 其他
#### 开放性问题：大量数据无序输入，怎么有序输出？ （使用最大堆最小堆）
#### 场景题：找出前 K 个最大元素的值（最大堆、最小堆的用法）
#### 用两个栈实现一个队列
#### Map和Hash的底层实现
#### 双链表和单链表的优缺点
#### 红黑树的定义
#### 哈希表的原理以及作用、怎么查找值
#### 手撕代码：把有序链表转为平衡二叉树
#### 实现排序二叉树的插入方法
#### 怎么删除双向链表？
#### 堆是不是二叉树
#### 反转链表
#### 括号匹配
#### map的内部实现（红黑树）
#### 反转单链表
#### 链表长度n，在i（1到n+1）位置插入数据，需要移动多少次(n-i+1)
#### 实现单链表（无头节点）
#### 实现双向链表（有头节点）
#### 二叉树的遍历:先序遍历：父节点-左孩子-右孩子,中序遍历：左孩子-父节点-右孩子,后续遍历：左孩子-右孩子-父节点,层次遍历：从上到下，从左到右



参考：https://zhuanlan.zhihu.com/p/137041568




//=================================线性表（数组，栈，队列）===================================

https://blog.csdn.net/Real_Fool_/article/details/113852222

//==================================线性表（链表）==================================

https://blog.csdn.net/Real_Fool_/article/details/113463997

### 链表
#### （1）单链表（无头结点）
参考：https://blog.csdn.net/swag_wg/article/details/89673850

#### （2）单链表（有头结点）

#### （3）双向链表（无头结点）
参考：https://blog.csdn.net/ffortunateoy/article/details/91359568?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param

### 问题：
#### （1）带头结点和不带头结点链表的区别？
头结点：在单链表的第一个结点之前附加一个结点，称为头结点。（通常头结点的data域可以为空）。
带头结点的优点：
1、更快删除/插入第一个结点
2、统一空表和非空表的处理

### 链表面试题详解
面试题参考：
https://zhuanlan.zhihu.com/p/52150962
https://blog.csdn.net/ffortunateoy/article/details/92174621

#### （1）从无头单链表中删除节点
取出要删除结点的下一个结点，然后将next和data给删除节点，相当于要删除的节点和下一个节点都指向第三个节点，那么此时第二个节点就是多余的。
```
void deleteNode(Node *iNode)
{
    Node *next = iNode->pNext;
    if (next != nullptr) {
        iNode->data = next->data;
        iNode->pNext = next->pNext;
    }
    delete next;
    next = nullptr;
}
```

#### （2）反转链表
用一个cur作为指示器，因为cur会往下走，head必须在cur前面，即相差一个节点，同时pre指向上一个结点。
然后pre和head又相差一个结点，这样就可以让head的next为pre。注意：while中的条件为cur != nullptr，因为cur本身在实际head前一个结点，所以为了访问最后一个结点，要让cur为null，此时head就在最后一个结点.
```
LinkedList *reverseList(LinkedList *iLst)
{
    Node *cur = iLst->pHead;
    Node *head = iLst->pHead;
    Node *pre = nullptr;
    while (cur != nullptr) {
        head = cur;
        cur = cur->pNext;
        head->pNext = pre;
        pre = head;
    }

  // 为了打印方便，此处new了一个新链表并返回
    LinkedList *newLst = new LinkedList;
    newLst->pHead = head;
    return newLst;
}
```

#### （3）合并两个排序的链表
首先需要一个head，这就是最后的链表头结点。
其次有两个头节点cur1和cur2，一个pre，pre的next存放cur1和cur2小的那一个。
当pre的next存放数据后，pre和小的cur分别往前进一步。
```
LinkedList *mergeLst(LinkedList *iLst1, LinkedList *iLst2)
{
    // 确定头结点
    Node *resHead = nullptr;
    if (iLst1->pHead == nullptr) {
        resHead = iLst2->pHead;
    }
    if (iLst2->pHead == nullptr) {
        resHead = iLst1->pHead;
    }

    if (iLst1->pHead->data < iLst2->pHead->data) {
        resHead = iLst1->pHead;
    } else {
        resHead = iLst2->pHead;
    }

    // 比较结点
    Node *cur1 = iLst1->pHead;
    Node *cur2 = iLst2->pHead;
    Node *pre = nullptr;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->data < cur2->data) {
            if (pre == nullptr) {
                pre = cur1;
            } else {
                pre->pNext = cur1;
                pre = cur1;
            }
            cur1 = cur1->pNext;
        } else {
            if (pre == nullptr) {
                pre = cur2;
            } else {
                pre->pNext = cur2;
                pre = cur2;
            }
            cur2 = cur2->pNext;
        }
    }

    // 添加剩余结点
    if (cur1 != nullptr) {
        pre->pNext = cur1;
        pre = cur1;
        cur1 = cur1->pNext;
    }
    if (cur2 != nullptr) {
        pre->pNext = cur2;
        pre = cur2;
        cur2 = cur2->pNext;
    }

    // 返回结果
    LinkedList *resLst = new LinkedList;
    resLst->pHead = resHead;
    return resLst;
}
```

#### （4）两个链表的第一个公共节点
方法：先求出长度差n，然后让长的链表先走n步，然后再一起走，判断结点的值是否一样
#### （5）判断两个链表是否相交
方法：如果相交，那么最后一个结点肯定相同，可以通过判断最后一个结点是否相同
#### （6）查找倒数第K个结点
方法：求出链表长度n，第一个指针走n-k步，然后第二个指针指向头结点，两个指针同时走，当第一个指针到达末尾时，第二个指针到达k结点.
#### （7）查找中间结点
方法：
（1）方法1，找到长度n，走n/2步；
（2）方法2，两个指针，一个快的走两步，一个慢的走1步，当快的达到末尾时，慢的刚好再中间
#### （8）证明链表有环

### 单链表（不带头节点）面试代码
```
struct Node
{
    int data;
    Node *pNext;
};

struct LinkedList
{
    Node *pHead;
};

Node *createNode(int iData) 
{
    Node *node = new Node;
    node->data = iData;
    node->pNext = NULL;
    return
}

void initList(LinkedList *iLst) 
{   
    if (iLst != NULL) {
        iLst->pHead = NULL;
    }
}

// 头插
void pushFront(LinkedList *iLst, int iData);
{
    Node *node = createNode(iData);
    if (iLst->pHead == NULL) {
        iLst->pHead = node;
    } else {
        node->pNext = iLst->pHead;
        iLst->pHead = node;
    }
}

// 头删
void popFront(LinkedList *iLst)
{
    if (iLst->pHead != NULL) {
        if (iLst->pHead->pNext == NULL) {
            Node *tmp = iLst->pHead;
            iLst->pHead = NULL;
            delete tmp;
            tmp = NULL;
        } else {
            Node *tmp = iLst->pHead;
            iLst->pHead = iLst->pHead->pNext
            delete tmp;
            tmp = NULL;
        }
    }
}

// 尾插
void pushBack(LinkedList *iLst, int iData)
{
    Node *node = createNode(node);
    if (iLst->pHead == NULL) {
        iLst->pHead = node;
    } else {
        Node *tmp = iLst->pHead;
        while (tmp->pNext != NULL) {
            tmp = tmp->pNext;
        }
        tmp->pNext = node;
    }
}

// 尾删
void popBack(LinkedList *iLst)
{
    if (iLst->head == NULL) {
        Node *node = iLst->head;
        iLst->head = NULL;
        delete node;
        node = NULL;
    } else {
        Node *pre;
        Node *tmp = iLst->pHead;
        while (tmp->pNext != NULL) {
            pre = tmp;
            tmp = tmp->pNext;
        }
        pre->pNext = NULL;
        delete tmp;
        tmp = NULL;
    }
}

// 任意位置插
void insertNode(LinkedList *iLst, int iData, int n)
{
    Node *node = createNode(iData);
    if (iLst != NULL) {
        if (iLst->pHead == NULL) {
             pushFront(iLst, iData);
        } else {
            Node *pre;
            Node *tmp = iLst->pHead;
            while (n > 0) {
                pre = tmp;
                tmp = tmp->pNext;
                n--;
            }   
            node->pNext = tmp;
            pre->pNext = node;
        }
    }
}

// 任意位置删
void deleteNode(LinkedList *iLst, int n)
{
    if (iLst != NULL) {
        if (iLst->pHead != NULL) {
            if (iLst->pHead->pNext == NULL) {
                popFront(iLst);
            } else {
                Node *pre;
                Node *tmp = iLst->pHead;
                while (n > 0) {
                    pre = tmp;
                    tmp = tmp->pNext;
                    n--;
                }
                pre->pNext = tmp->pNext;
                delete tmp;
                tmp = NULL;
            }
        }
    }
}
```

### 双向链表（不带头节点）面试代码
```
struct Node
{
    int data;
    Node *pNext;
    Node *pPre;

};

struct DoubleLinkedList
{
    Node *pHead;
};

void initList(DoubleLinkedList *iLst)
{
    if (iLst != NULL) {
        iLst->pHead = NULL;
    }
}

Node *createNode(int iData)
{
    Node *node = new Node;
    node->data = iData;
    node->pPre = NULL;
    node->pNext = NULLL;
    return node;
}

// 头插
void pushFront(DoubleLinkedList *iLst, int iData)
{
    Node *node = createNode(iData);
    if (iLst != NULL) {
        if (iLst->pNext == NULL) {
            iLst->pNext = node;
        } else {
            node->pNext = iLst->pHead;
            iLst->pHead->pPre = node;
            iLst->pHead = node;
        }
    }
}

// 头删
void popFront(DoubleLinkedList *iLst)
{
    if (iLst != NULL) {
        if (iLst->pHead != NULL) {
            if (iLst->pHead->pNext == NULL) {
                Node *tmp = iLst->pHead;
                delete tmp;
                tmp = NULL;
            } else {
                Node *tmp = iLst->pHead;
                tmp->pPre = NULL;
                iLst->pHead = tmp->pNext;
                delete tmp;
                tmp = NULL;
            }
        }
    }
}

// 尾插
void pushBack(DoubleLinkedList *iLst, int iData)
{
    Node *node = createNode(iData);
    if (iLst != NULL) {
        if (iLst->pHead == NULL) {
            iLst->pHead = node;
        } else {
            Node *tmp = iLst->pHead;
            while (tmp->pNext != NULL) {
                tmp = tmp->pNext;
            }
            tmp->pNext = node;
            node->pPre = tmp;
        }
    }
}

// 尾删
void popBack(DoubleLinkedList *iLst)
{
    if (iLst != NULL) {
        if (iLst->pHead != NULL) {
            if (iLst->pHead->pNext == NULL) {
                Node *tmp = iLst->pHead;
                iLst->pHead = NULL;
                delete tmp;
                tmp = NULL;
            } else {
                Node *pre;
                Node *tmp = iLst->pHead;
                while (tmp->pNext != NULL) {
                    pre = tmp;
                    tmp = tmp->pNext;
                }
                pre->pNext = NULL;
                delete tmp;
                tmp = NULL;
            }
        }
    }
}

// 任意位置插
void insertNode(DoubleLinkedList *iLst, int iData, int n)
{
    Node *node =createNode(iData);
    if (iLst != NULL) {
        if (iLst->pHead == NULL) {
            pushFront(iLst, iData);
        } else {
            Node *tmp = iLst->pHead;
            int i = 0;
            // 找到插入位置的前一个点
            while (i < n - 1) {
                tmp = tmp->pNext;
                i++;
            }
            node->pNext = tmp->pNext;
            tmp->pNext->pre = node;
            tmp->pNext = node;
            ndoe->pre = tmp;
        }
    }
}

// 任意位置删
void deleteNode(DoubleLinkedList *iLst, int n)
{
    if (iLst != NULL) {
        if (iLst->pHead != NULL) {
            if (iLst->pHead->pNext == NULL) {
                Node *tmp = iLst->pHead;
                delete tmp;
                tmp = NULL;
            } else {
                Node *tmp = iLst->pHead;
                int i = 0;
                // 找到删除的结点
                while (i < n) {
                    tmp = tmp->pNext;
                    i++;
                }
                tmp->pNext->pPre = tmp->pPre;
                tmp->pPre->pNext = tmp->pNext;

                delete tmp;
                tmp = NULL;
            }
        }
    }
}
```

//===================================散列表（哈希表）=================================

https://blog.csdn.net/weixin_47251999/article/details/113037111
### 哈希表
#### 构造方法
（1）直接定址法
（2）除留余数法
（3）数字分析法
（4）折叠法
（5）平方取中法

#### 冲突处理方法
（1）链地址法：key 相同的用单链表链接
（2）开放定址法：
  线性探测法：key 相同 -> 放到 key 的下一个位置，Hi = (H(key) + i) % m ；
  二次探测法：key 相同 -> 放到 Di = 1^2, -1^2, ..., ±（k)^2,(k<=m/2）；
  随机探测法：H = (H(key) + 伪随机数) % m；

//====================================树================================

https://blog.csdn.net/Real_Fool_/article/details/113930623
https://zhuanlan.zhihu.com/p/90255760

#### 二叉树性质
（1）非空二叉树第 i 层最多 2^(i-1) 个结点 （i >= 1）；
（2）深度为 k 的二叉树最多 2^k - 1 个结点 （k >= 1）；
（3）度为 0 的结点数为 n0，度为 2 的结点数为 n2，则 n0 = n2 + 1；
（4）有 n 个结点的完全二叉树深度 k = ? log2(n) ? + 1;

#### 二叉树
#### 满二叉树
#### 完全二叉树
#### 二叉排序树
#### 平衡二叉树
#### AVL树
#### 红黑树


//====================================堆================================

https://zhuanlan.zhihu.com/p/335322846
https://zhuanlan.zhihu.com/p/398011990

#### 小顶堆
#### 大顶堆
#### 堆排序

//=====================================图===============================

https://blog.csdn.net/Real_Fool_/article/details/114141377

#### 图的概念
#### 图的存储
#### 图的遍历
#### 图的应用
##### 最小生成树
##### 最短路径
##### 拓扑排序
##### 关键路径

//=====================================其他===============================

