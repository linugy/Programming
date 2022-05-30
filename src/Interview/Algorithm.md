## Ŀ¼
### ����
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
#### ɢ�б���ϣ������
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
    for (int i = 0; i < length; i++) {
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
* ������ÿ��ѡһ��������ǰ������������壬��Ϊ��һ�����Ѿ�������ģ�������Ҫ����length-1�����������ⲿѭ����length-1,�ƶ�λ�ò���whileѭ��������˼�����
�ж�������е����һ���Ƿ��뵱ǰ���ݵĴ�С�������ǰ���ݸ��󣬾�������һλ������j����СҲҪ��0���Ͼ�j��ʾ������±ꡣ�����õ�ǰ����ʱ��j��Ҫ��1
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/
void insertionSort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int curValue = arr[i+1];
        int j = i;
        while (arr[j] > curValue && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = curValue;
    }
}
```

#### 4.ϣ������
```
/**
* \brief
* ��������������һ������ֵ����ʼ����Ϊlength/2,��������/2��ֱ��Ϊ1Ϊֹ�����ѭ����step��ʼ��Ҳ����˵�������м俪ʼ��ֱ��lengthΪֹ�������ж�j-step��j�����j-step���󣬾ͺ��ơ�
* �Ƿ��ȶ�������
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/
void  shellSort(int arr[], int length) {
    for (int step = length / 2; step > 0; step /= 2) {
        for (int i = step; i < length; i++) {
            int j = i;
            int curValue = arr[j];
            while (arr[j-step] > curValue && (j-step >= 0)) {
                arr[j] = arr[j-step];
                j = j - step;
            }
            arr[j] = curValue;
        }
    }
}
```

#### 5.�鲢����
https://zhuanlan.zhihu.com/p/124356219
```
/**
* \brief
* ������
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/
// �ݹ��
void MainWindow::sort(int arr[], int length)
{
    int arr2[length];
    mergeSort(arr, arr2, 0, length - 1);
}

void MainWindow::mergeSort(int arr[], int arr2[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;

    mergeSort(arr, arr2, start, mid);
    mergeSort(arr, arr2, mid+1, end);

    int k = start;
    int i = start;
    int j = mid+1;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            arr2[k] = arr[i];
            k++;
            i++;
        } else {
            arr2[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        arr2[k] = arr[i];
        k++;
        i++;
    }

    while (j <= end) {
        arr2[k] = arr[j];
        k++;
        j++;
    }

    for (int m = start; m <= end; m++) {
        arr[m] = arr2[m];
    }
}

```

#### 6.��������
https://blog.csdn.net/qq_40941722/article/details/94396010
```
/**
* \brief
* ��������һ��������m�����������һ������Ŀ�����ҵ�m����ȷλ�ã�Ҳ�͵�m��ߵ���С��m��m�ұߵ�������m����ôm��λ�þ�ȷ���ˣ��Ͳ����ٶ��ˡ�
����һ��i��j��i������ߣ�j�����ұߣ�j��ʼ�ƶ����������С��m��������ôjͣ�£�Ȼ��i��ʼ�ƶ��������������m��������ôiͣ�£���ʱ����i��j������
��û�꣬�����ƶ�i��j��ֱ��i��j��������ߵ��м��ˣ���ô�ͽ���m��i��j��ֵ����ʱm�ͷŵ���ȷλ���ˡ�
* �Ƿ��ȶ�������
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/
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
```

#### 7.������
```
/**
* \brief
* ������
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/



```

#### 8.��������
```
/**
* \brief
* ������
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/



```

#### 9.Ͱ����
```
/**
* \brief
* ������
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/



```

#### 10.��������
```
/**
* \brief
* ������
* �Ƿ��ȶ�����
* ʵ�ʸ��Ӷȣ�
* �ռ临�Ӷȣ�
*/


```


//============================================����==================================================

#### 1.���ֲ���
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
#### 2.ɢ�б���ϣ������
https://zhuanlan.zhihu.com/p/141539102


#### 3.���ṹ����
https://blog.csdn.net/weixin_45002147/article/details/102537222


//============================================����==================================================

#### 1.�������������DFS��


#### 2.�����������
https://blog.csdn.net/North_City_/article/details/118554484


//============================================�ַ���ƥ��==================================================

#### ����ƥ��
#### BM
#### KMP
#### Trie

https://blog.csdn.net/weixin_43528729/article/details/104989060

//============================================�㷨˼��==================================================

#### ��̬�滮
https://blog.csdn.net/Yangchenju/article/details/107870073

#### ̰���㷨
https://www.cnblogs.com/hust-chen/p/8646009.html

#### �����㷨
https://blog.csdn.net/zy450271923/article/details/105745637

#### �����㷨
https://blog.csdn.net/c15158032319/article/details/117828162

#### ö���㷨
https://blog.csdn.net/qq_52870580/article/details/122440176


//============================================����==================================================


#### �ҳ������д�������ǰ k ���� 
https://blog.csdn.net/fuyufjh/article/details/48037127

#### ����ʮ����������1�ĸ�����16������-4�ֽ�-32λ��
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

#### �������Ʒ�ת��16������-4�ֽ�-32λ��
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

#### �ҳ���������������һ���Ԫ��
https://blog.csdn.net/qiana_/article/details/79176936

#### �ҳ���������С��K����
https://blog.csdn.net/ThinPikachu/article/details/105870777
https://blog.csdn.net/gao__xue/article/details/80018869

#### ���������
https://blog.csdn.net/weixin_42205987/article/details/82011724

#### ʮ�����ַ���תʮ�������ַ���



### ʵ��strcpy����
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

### ʵ��strcmp����
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

### ʵ��memcpy����
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