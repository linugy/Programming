#### 1.排序算法:冒泡,插入,选择,快排。（参考排序算法）
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


