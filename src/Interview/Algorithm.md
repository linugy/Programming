#### 1.�����㷨:ð��,����,ѡ��,���š����ο������㷨��
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


