## 目录
### 排序：时间复杂度，空间复杂度
#### 冒泡排序
#### 选择排序
#### 插入排序
#### 希尔排序
#### 归并排序
#### 快速排序
#### 堆排序
#### 计数排序
#### 桶排序
#### 基数排序
### 查找
#### 二分查找
#### 散列表查找
#### 树结构查找
### 搜索
#### 深度优先搜索
#### 广度优先搜索
### 字符串匹配
#### 暴力匹配
#### BM
#### KMP
#### Trie
### 算法思想
#### 动态规划
#### 贪心算法
#### 回溯算法
#### 分治算法
#### 枚举算法
### 其他
#### 找出数组中次数最多的前 k 个数 
#### 计算十六进制数中1的个数（16进制数-4字节-32位）
#### 长二进制反转（16进制数-4字节-32位）
#### 找出数组中数量超过一半的元素
#### 找出数组中最小的K个数
#### 长整数相加
#### 十进制字符串转十六进制字符串
#### 实现strcpy函数
#### 实现strcmp函数
#### 实现memcpy函数

#### https://zhuanlan.zhihu.com/p/137041568

//============================================排序==================================================

#### 1.冒泡排序
```
/**
* 描述：两两比较，大的往后放。需要确定length-1个数的位置，所以外部循环为length-1。内部需要两两交换，第一次是length-1，第二次是length-1-1，以此类推。
* 是否稳定：是
* 实际复杂度：
* 空间复杂度：
*/
void bubbleSort(int arr[], int length)
{
   for (int i = 0; i < length - 1; i++) {
	for (int j = 0; j < length - 1 - i; j++) {
	    if (arr[j] > arr[j+1]) {
		int tmp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = tmp;
	    }
	}
    }
}
```

#### 2.选择排序
```
/**
* 描述：选择一个最小的，和第一位交换位置，继续选择最小的，和第二位交换位置。需要选length-1次最小值，所以外部循环次数为length-1,内部从第一位+1开始
寻找最小值，所以循环从i+1开始，直到数组末尾。每次假设当前i为最小值。
* 是否稳定：否
* 实际复杂度：
* 空间复杂度：
*/
void selectionSort(int arr[], int length) {
    for (int i = 0; i < lenght; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}
```

#### 3.插入排序
```
/**
* \brief
* 描述：每次选一个数，往前面的有序队列里插，因为第一个数已经是有序的，所以需要插入length-1个数，所以外部循环是length-1,移动位置采用while循环，基本思想就是
判断有序队列的最后一个是否与当前数据的大小，如果当前数据更大，就往后移一位，关于j，最小也要是0，毕竟j表示数组的下标。最后放置当前数的时候，j需要加1
* 是否稳定：是
* 实际复杂度：
* 空间复杂度：
*/
void insertionSort() {
    for (int i = 0; i < length - 1; i++) {
        int curValue = arr[i+1];
        int j = i;
        while (arr[j] > arr[j+1] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = curValue;
    }
}
```

##### 4.快速排序
```
void quickSort(int array[], int low, int high)
{
    int i = low;
    int j = high;
    int key = array[i];

    while (i < j) {
        while (i < j && array[j] >= key) {
            // 这里的 i < j，是为了防止j跑到i的位置了，还继续往前走
            // （如果是原始数组是从小到大，就可能出现这种情况）
            j--;
        }
        if (i < j) {
            array[i] = array[j];
        }

        while (i < j &&  array[i] <= key) {
            // 此处i < j，和上面一样，防止i跑到j的位置了，还继续往后走
            // （如果是原始数组是从小到大，就可能出现这种情况）
            i++;
        }
        if (i < j) {
            array[j] = array[i];
        }
    }
    // 跳槽循环时，表示i等于j，也就是一次排序完成，需要将key放到i的位置

    // 这里保证每次递归时需要low小于high，如果大于或等于了，表示不需要递归了
    if (low < high) {
        array[i] = key;
        quickSort(array, low, i - 1);
        quickSort(array, i + 1, high);
    }
}

void sort()
{
    int array[10] = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(int);
    for (int i = 0; i < length; i++) {
        qDebug() << array[i];
    }
    qDebug() << "------" << length;
    quickSort(array, 0, length - 1);
    for (int i = 0; i < length; i++) {
        qDebug() << array[i];
    }
}

结果：
10
9
8
7
6
1
2
3
4
5
------ 10
1
2
3
4
5
6
7
8
9
10
```

```
// 快排
void quickSort(int arr[], int low, int high)
{   
    int i = low;
    int j = high;
    int key = arr[i];
    
    while (i < j) {
        while (i < j && arr[j] > key) {
            j--;
        }
        if (i < j) {
            arr[i] = arr[j];
        }

        while (i < j && arr[i] < key) {
            i++;
        }
        if (i < j) {
            arr[j] = arr[i];
        }
    }

    if (low < high) {
        arr[i] = key;
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}
```
//============================================查找==================================================

#### 2.二分查找
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


//============================================搜索==================================================


//============================================字符串匹配==================================================


//============================================算法思想==================================================

#### 动态规划
#### 贪心算法
#### 回溯算法
#### 分治算法
#### 枚举算法


//============================================其他==================================================


#### 3.找出数组中次数最多的前 k 个数 
https://blog.csdn.net/fuyufjh/article/details/48037127

#### 4.计算十六进制数中1的个数（16进制数-4字节-32位）
```
int NumberOf1(int n) 
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((n >> i) & 1) == 1)
        {
            count++;
        }
    }
    return count;   
}
```

#### 5.长二进制反转（16进制数-4字节-32位）
```
unsigned int reverse(int num)
{
    
    int value = 0;
    for (int i = 0; i < 32; i++) {
	value = value << 1;
	value = value | ((num >> i) & 1)
    }
    return value;
}
```

#### 6.找出数组中数量超过一半的元素
https://blog.csdn.net/qiana_/article/details/79176936

#### 7.找出数组中最小的K个数
https://blog.csdn.net/ThinPikachu/article/details/105870777
https://blog.csdn.net/gao__xue/article/details/80018869

#### 8.长整数相加
https://blog.csdn.net/weixin_42205987/article/details/82011724

#### 9.十进制字符串转十六进制字符串



### 5.实现strcpy函数
https://blog.csdn.net/hhhuang1991/article/details/79955057
```
char *strcpy(char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    str1 = '\0';
    return str1;
}
```

### 6.实现strcmp函数
https://blog.csdn.net/wgenek/article/details/7257435
https://www.cnblogs.com/litifeng/p/7465173.html
```
int strcmp(const char *str1, const char *str2)
{
    while ((*str1) && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 > *str2) {
        return 1;
    } else if (*str1 < *str2) {
        return -1;
    } else {
        return 0;
    }
}
```

### 7.实现memcpy函数
https://www.cnblogs.com/chuanfengzhang/p/8447251.html
https://blog.csdn.net/goodwillyang/article/details/45559925
https://www.cnblogs.com/liangyc/p/11628723.html

```
void *memcpy(void *dest, const void *src, int n)
{
    if (dest == NULL || src == NULL || n <= 0) {
        return NULL;
    }

    char *pDest = (char *)dest;
    char *pSrc = (char *)src;

    if (pDest > pSrc && pDest < pSrc + n) {
        pDest = pDest + n - 1;
        pSrc = pSrc + n - 1;
        while (n--) {
            *pDest-- = *pSrc--;
        }
    } else {
        while (n--) {
            *pDest++ = *pSrc++;
        }
    }
    return dest;
}
```