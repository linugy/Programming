## Ŀ¼
### ����ʱ�临�Ӷȣ��ռ临�Ӷ�
#### ð������
#### ѡ������
#### ��������
#### ϣ������
#### �鲢����
#### ��������
#### ������
#### ��������
#### Ͱ����
#### ��������
### ����
#### ���ֲ���
#### ɢ�б����
#### ���ṹ����
### ����
#### �����������
#### �����������
### �ַ���ƥ��
#### ����ƥ��
#### BM
#### KMP
#### Trie
### �㷨˼��
#### ��̬�滮
#### ̰���㷨
#### �����㷨
#### �����㷨
#### ö���㷨
### ����
#### �ҳ������д�������ǰ k ���� 
#### ����ʮ����������1�ĸ�����16������-4�ֽ�-32λ��
#### �������Ʒ�ת��16������-4�ֽ�-32λ��
#### �ҳ���������������һ���Ԫ��
#### �ҳ���������С��K����
#### ���������
#### ʮ�����ַ���תʮ�������ַ���
#### ʵ��strcpy����
#### ʵ��strcmp����
#### ʵ��memcpy����

#### https://zhuanlan.zhihu.com/p/137041568

//============================================����==================================================

#### 1.ð������
```
/**
* �����������Ƚϣ��������š���Ҫȷ��length-1������λ�ã������ⲿѭ��Ϊlength-1���ڲ���Ҫ������������һ����length-1���ڶ�����length-1-1���Դ����ơ�
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
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

#### 2.ѡ������
```
/**
* ������ѡ��һ����С�ģ��͵�һλ����λ�ã�����ѡ����С�ģ��͵ڶ�λ����λ�á���Ҫѡlength-1����Сֵ�������ⲿѭ������Ϊlength-1,�ڲ��ӵ�һλ+1��ʼ
Ѱ����Сֵ������ѭ����i+1��ʼ��ֱ������ĩβ��ÿ�μ��赱ǰiΪ��Сֵ��
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
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

#### 3.��������
```
/**
* \brief
* ÿ����ǰ������������������ݣ���Ҫ�ҵ����ʵ�λ��
* ��Ҫһ���ն��У����ڱ����ź�������ݣ����Զ�ԭ������к������ﵽֻʹ��һ������,��Ҫ��while��
* ÿ����Ҫ�ҵ�����λ��index
*/
void insertionSort() {
}
```

void insertionSort()
{
    // ��Ҫ��������
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

    // ����Ҫ��������
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
// ��������
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

##### 4.��������
```
void quickSort(int array[], int low, int high)
{
    int i = low;
    int j = high;
    int key = array[i];

    while (i < j) {
        while (i < j && array[j] >= key) {
            // ����� i < j����Ϊ�˷�ֹj�ܵ�i��λ���ˣ���������ǰ��
            // �������ԭʼ�����Ǵ�С���󣬾Ϳ��ܳ������������
            j--;
        }
        if (i < j) {
            array[i] = array[j];
        }

        while (i < j &&  array[i] <= key) {
            // �˴�i < j��������һ������ֹi�ܵ�j��λ���ˣ�������������
            // �������ԭʼ�����Ǵ�С���󣬾Ϳ��ܳ������������
            i++;
        }
        if (i < j) {
            array[j] = array[i];
        }
    }
    // ����ѭ��ʱ����ʾi����j��Ҳ����һ��������ɣ���Ҫ��key�ŵ�i��λ��

    // ���ﱣ֤ÿ�εݹ�ʱ��ҪlowС��high��������ڻ�����ˣ���ʾ����Ҫ�ݹ���
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

�����
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
// ����
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
//============================================����==================================================

#### 2.���ֲ���
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


//============================================����==================================================


//============================================�ַ���ƥ��==================================================


//============================================�㷨˼��==================================================

#### ��̬�滮
#### ̰���㷨
#### �����㷨
#### �����㷨
#### ö���㷨


//============================================����==================================================


#### 3.�ҳ������д�������ǰ k ���� 
https://blog.csdn.net/fuyufjh/article/details/48037127

#### 4.����ʮ����������1�ĸ�����16������-4�ֽ�-32λ��
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

#### 5.�������Ʒ�ת��16������-4�ֽ�-32λ��
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

#### 6.�ҳ���������������һ���Ԫ��
https://blog.csdn.net/qiana_/article/details/79176936

#### 7.�ҳ���������С��K����
https://blog.csdn.net/ThinPikachu/article/details/105870777
https://blog.csdn.net/gao__xue/article/details/80018869

#### 8.���������
https://blog.csdn.net/weixin_42205987/article/details/82011724

#### 9.ʮ�����ַ���תʮ�������ַ���



### 5.ʵ��strcpy����
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

### 6.ʵ��strcmp����
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

### 7.ʵ��memcpy����
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