�ġ������㷨
1.ð��
2.����
3.ѡ��
4.����

11.�������ı���
7.ʵ�ֶ��ֲ���


### 8.���ֲ���
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


### 11.�������ı���
#### ������������ڵ�-����-�Һ���
#### �������������-���ڵ�-�Һ���
#### ��������������-�Һ���-���ڵ�
#### ��α��������ϵ��£�������

### 18.����ʮ����������1�ĸ���



### 20.������n����i��1��n+1��λ�ò������ݣ���Ҫ�ƶ����ٴ�
n-i+1


IPC �㷨