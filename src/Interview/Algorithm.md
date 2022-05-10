#### 1.排序算法：冒泡，插入，选择，快排。
##### 1.冒泡排序
```
/**
* \brief
* 比较相邻两个变量的值，如果一个大于另一个，就交换，每次确定一个最大值
* 因为是两两交换，所以内部用一个循环交换;
* 外部因为最后一次不用比较，所以-1
* 内部因为两两比较，也要-1；同时每次都会确定一个最大值，所以会-i
*/
void bubbleSort()
{
    QList<double> lst = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};
    for (int i = 0; i <  lst.length() - 1; i++) {
        for (int j = 0; j < lst.length() - 1 - i; j++) {
            if (lst[j] > lst[j + 1]) {
                double tmp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = tmp;
            }
        }
    }
    qDebug() << lst;
}
```

```
// 冒泡排序
void bubbleSort(int arr[])
{
    int length = arr.length;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = arr[j];
            }
        }
    }
}
```

##### 2.插入排序
```

/**
* \brief
* 每次往前面的有序队列里插入数据，需要找到合适的位置
* 需要一个空队列，用于保存排好序的数据（可以对原数组进行后移来达到只使用一个数组,需要用while）
* 每次需要找到插入位置index
*/
void insertionSort()
{
    // 需要额外数组
//    QList<double> lst = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};
//    QList<double> res;
//    for (int i = 0; i < lst.length(); i++) {
//        double curNumber = lst.at(i);
//        int index = 0;
//        for (int j = 0; j < res.length(); j++) {
//            if (curNumber > res.at(j)) {
//                index += 1;
//            }
//        }
//        res.insert(index, curNumber);
//    }
//    qDebug() << res;

    // 不需要额外数组
    QList<double> lst = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};
    for (int i = 0; i < lst.length(); i++) {
        double curNumber = lst.at(i);
        int index = i;
        while(i > 0 && curNumber < lst.at(i - 1)) {
            lst[i] = lst[i - 1];
            index = i - 1;
        }
        lst[index] = curNumber;
    }
    qDebug() << lst;
}
```

```
// 插入排序
void insertionSort(int arr[])
{
    int length = arr.length;
    for (int i = 1; i < length; i++) {
        int index = i;
        int curData = arr[index];
        while (index > 0 && arr[index] < arr[index - 1]) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = curData;
    }
}
```

##### 3.选择排序
```
/**
* \brief
* 每次选择一个最大的或者最小的，放到队列最前面
*
*/
void selectionSort()
{
    // 同时有index和number
//    QList<double> lst = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};
//    for (int i = 0; i < lst.length() - 1; i++) {
//        double minNumber = lst[i];
//        int minNumberIndex = i;
//        for (int j = i + 1; j < lst.length(); j++) {
//            if (lst.at(j) < minNumber) {
//                minNumber = lst.at(j);
//                minNumberIndex = j;
//            }
//        }
//        // 和数组第一位交换
//        double tmp = lst[i];
//        lst[i] = minNumber;
//        lst[minNumberIndex] = tmp;
//    }
//    qDebug() << lst;

    // 只有index
    QList<double> lst = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5};
    for (int i = 0; i < lst.length() - 1; i++) {
        int minNumberIndex = i;
        for (int j = i + 1; j < lst.length(); j++) {
            if (lst.at(j) < lst[minNumberIndex]) {
                minNumberIndex = j;
            }
        }
        // 和数组第一位交换
        double tmp = lst[i];
        lst[i] = lst[minNumberIndex];
        lst[minNumberIndex] = tmp;
    }
    qDebug() << lst;
}
```

```
// 选择排序
void selctionSort(int arr[]) 
{
    int length = arr.length;
    for (int i = 0; i < length; i++) {
        int min = arr[i];
        int index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < min) {
                index = j;
                min = arr[j];
            }
        }
        int tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = arr[i];
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


