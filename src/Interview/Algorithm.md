四、排序算法
1.冒泡
2.插入
3.选择
4.快排

11.二叉树的遍历
7.实现二分查找


### 8.二分查找
https://www.cnblogs.com/kyoner/p/11080078.html
https://www.cnblogs.com/luoxn28/p/5767571.html
```
int binarySearch(int arr[], int key)
{
    int low = 0;
    int high = arr.length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
```


### 11.二叉树的遍历
#### 先序遍历：父节点-左孩子-右孩子
#### 中序遍历：左孩子-父节点-右孩子
#### 后续遍历：左孩子-右孩子-父节点
#### 层次遍历：从上到下，从左到右

### 18.计算十六进制数中1的个数



### 20.链表长度n，在i（1到n+1）位置插入数据，需要移动多少次
n-i+1


IPC 算法