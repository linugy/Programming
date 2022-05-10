#### 第一阶段：学习

#### 第二阶段：面试题
1.排序算法:冒泡,插入,选择,快排
3.实现二分查找
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
动态规划与贪心算法的区别（背包问题分析）
算法问题： 网格中有 2 个点，怎么找到从 A 到 B 的最短路径？（用广度优先搜索）
快排的思路
IPC 算法

找出数组中次数最多的前 k 个数 
计算十六进制数中1的个数
用两个线程实现循环加数
长二进制反转
写代码：找出数组中数量超过一半的元素
找出数组中最小的K个数
长整数相加
代码题：十进制字符串转十六进制字符串
找出出现频率最高的前 K 个数，或者从海量数据中找出最大的前 K 个数

#### 第三阶段：精学
