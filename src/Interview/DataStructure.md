1.ʵ�ֵ�������ͷ�ڵ㣩
2.ʵ��˫��������ͷ�ڵ㣩
3.�����������ʣ�
4.Map��Hash�ĵײ�ʵ��
3.������n����i��1��n+1��λ�ò������ݣ���Ҫ�ƶ����ٴ�(n-i+1)
5.�������ı���:������������ڵ�-����-�Һ���,�������������-���ڵ�-�Һ���,��������������-�Һ���-���ڵ�,��α��������ϵ��£�������
˫����͵��������ȱ��
������ջʵ��һ������
���������⣺���������������룬��ô��������� ��ʹ��������С�ѣ�
�����⣺�ҳ�ǰ K �����Ԫ�ص�ֵ�����ѡ���С�ѵ��÷���
��ô�����ϣ��ͻ
��ϣ���ԭ���Լ����á���ô����ֵ
��ת������
������Ķ���
��˺���룺����������תΪƽ�������
5.ʵ������������Ĳ��뷽��
��ôɾ��˫������
���ǲ��Ƕ�����
1. ��ת����
2. ����ƥ��


### ����
#### ��1����������ͷ��㣩
�ο���https://blog.csdn.net/swag_wg/article/details/89673850

#### ��2����������ͷ��㣩

#### ��3��˫��������ͷ��㣩
�ο���https://blog.csdn.net/ffortunateoy/article/details/91359568?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param

### ���⣺
#### ��1����ͷ���Ͳ���ͷ������������
ͷ��㣺�ڵ�����ĵ�һ�����֮ǰ����һ����㣬��Ϊͷ��㡣��ͨ��ͷ����data�����Ϊ�գ���
��ͷ�����ŵ㣺
1������ɾ��/�����һ�����
2��ͳһ�ձ�ͷǿձ�Ĵ���

### �������������
������ο���
https://zhuanlan.zhihu.com/p/52150962
https://blog.csdn.net/ffortunateoy/article/details/92174621

#### ��1������ͷ��������ɾ���ڵ�
ȡ��Ҫɾ��������һ����㣬Ȼ��next��data��ɾ���ڵ㣬�൱��Ҫɾ���Ľڵ����һ���ڵ㶼ָ��������ڵ㣬��ô��ʱ�ڶ����ڵ���Ƕ���ġ�
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

#### ��2����ת����
��һ��cur��Ϊָʾ������Ϊcur�������ߣ�head������curǰ�棬�����һ���ڵ㣬ͬʱpreָ����һ����㡣
Ȼ��pre��head�����һ����㣬�����Ϳ�����head��nextΪpre��ע�⣺while�е�����Ϊcur != nullptr����Ϊcur������ʵ��headǰһ����㣬����Ϊ�˷������һ����㣬Ҫ��curΪnull����ʱhead�������һ�����.
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

  // Ϊ�˴�ӡ���㣬�˴�new��һ������������
    LinkedList *newLst = new LinkedList;
    newLst->pHead = head;
    return newLst;
}
```

#### ��3���ϲ��������������
������Ҫһ��head���������������ͷ��㡣
���������ͷ�ڵ�cur1��cur2��һ��pre��pre��next���cur1��cur2С����һ����
��pre��next������ݺ�pre��С��cur�ֱ���ǰ��һ����
```
LinkedList *mergeLst(LinkedList *iLst1, LinkedList *iLst2)
{
    // ȷ��ͷ���
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

    // �ȽϽ��
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

    // ���ʣ����
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

    // ���ؽ��
    LinkedList *resLst = new LinkedList;
    resLst->pHead = resHead;
    return resLst;
}
```

#### ��4����������ĵ�һ�������ڵ�
��������������Ȳ�n��Ȼ���ó�����������n����Ȼ����һ���ߣ��жϽ���ֵ�Ƿ�һ��
#### ��5���ж����������Ƿ��ཻ
����������ཻ����ô���һ�����϶���ͬ������ͨ���ж����һ������Ƿ���ͬ
#### ��6�����ҵ�����K�����
���������������n����һ��ָ����n-k����Ȼ��ڶ���ָ��ָ��ͷ��㣬����ָ��ͬʱ�ߣ�����һ��ָ�뵽��ĩβʱ���ڶ���ָ�뵽��k���.
#### ��7�������м���
������
��1������1���ҵ�����n����n/2����
��2������2������ָ�룬һ�������������һ��������1��������Ĵﵽĩβʱ�����ĸպ����м�
#### ��8��֤�������л�

### ����������ͷ�ڵ㣩���Դ���
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

// ͷ��
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

// ͷɾ
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

// β��
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

// βɾ
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

// ����λ�ò�
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

// ����λ��ɾ
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

### ˫����������ͷ�ڵ㣩���Դ���
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

// ͷ��
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

// ͷɾ
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

// β��
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

// βɾ
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

// ����λ�ò�
void insertNode(DoubleLinkedList *iLst, int iData, int n)
{
    Node *node =createNode(iData);
    if (iLst != NULL) {
        if (iLst->pHead == NULL) {
            pushFront(iLst, iData);
        } else {
            Node *tmp = iLst->pHead;
            int i = 0;
            // �ҵ�����λ�õ�ǰһ����
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

// ����λ��ɾ
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
                // �ҵ�ɾ���Ľ��
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

### ��ϣ��
#### ���췽��
��1��ֱ�Ӷ�ַ��
��2������������
��3�����ַ�����
��4���۵���
��5��ƽ��ȡ�з�

#### ��ͻ������
��1������ַ����key ��ͬ���õ���������
��2�����Ŷ�ַ����
  ����̽�ⷨ��key ��ͬ -> �ŵ� key ����һ��λ�ã�Hi = (H(key) + i) % m ��
  ����̽�ⷨ��key ��ͬ -> �ŵ� Di = 1^2, -1^2, ..., ����k)^2,(k<=m/2����
  ���̽�ⷨ��H = (H(key) + α�����) % m��

### ������
#### ����
��1���ǿն������� i ����� 2^(i-1) ����� ��i >= 1����
��2�����Ϊ k �Ķ�������� 2^k - 1 ����� ��k >= 1����
��3����Ϊ 0 �Ľ����Ϊ n0����Ϊ 2 �Ľ����Ϊ n2���� n0 = n2 + 1��
��4���� n ��������ȫ��������� k = ? log2(n) ? + 1;