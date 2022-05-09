

����C++
1.const
2.static
3.�ڴ����
4.�ṹ���ڴ��С
5.C��C++����ת��
6.C��C++��struct
7.define�ͷ�ֹͷ�ļ��ظ�����
8.C++��struct��class
9.this
10.inline
11.assert()
12.sizeof()
13.extern
14.explicit
15.friend
16.using
17.enum
18.�ڴ����͹���
19.��Ա��ʼ���б�
------------�ָ�-----------
1.������󣨷�װ���̳У���̬��
2.��װ
3.�̳�
4.��̬
5.��д�����ء�����
6.���Ӷ����캯������˳��
7.���캯���������������Գ�Ϊ�麯����Ϊʲô��
8.�麯��ָ�롢�麯�������ָ��
9.�����������������������Գ�Ϊ�麯����ΪʲôҪ��virtual�ؼ�����������������
10.���麯��
11.�麯���ʹ��麯�����������ϵ
12.������
13.��̳�
14.�����ࡢ�ӿ���



һ��C++
1.C++����
2.�麯������⣬���ʵ�ֵĶ�̬
3.��̳�
4.�����������Գ�Ϊ�麯����ΪʲôҪ��virtual�ؼ�������������������������
5.static����
6.const����
7.��д�����ء�����˵һ��
8.�ڴ��������Щ����ʲô����



4.ʵ��strcpy
5.ʵ��strcmp
6.ʵ��memcpy
8.��ջ���ԭ��
13.C++����ָ��
10.ָ������õ�����
12.�����������Ͷ�����ʲô����



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



### 8.��ջ���ԭ��
��1���ݹ����
��2�������ڴ��û���ͷ�


### 10.ָ������õ�����
��1��ָ����һ����������ŵ��ǵ�ַ�������Ǳ����ı���
��2�����ñ����ʼ����ָ�����������ʱ���ʼ��
��3����constָ�룬����û��const����


### 12.�����������Ͷ�����ʲô����
#### �������������ڴ�ռ䣻���Զ��������
#### ���壺�����ڴ�ռ䣻ֻ�ܶ���һ�Σ�

### 13.C++����ָ��
#### shared_ptr��������ָ��ָ��ͬһ���������ü�����
#### unique_ptr
#### weak_ptr



### 15.char str[] �� char *str����ȱȽϺ��ڴ�����С

### 16.strstr����


### 19.�������õ�����̬
�ۺ�����ʹ��sender������һ��QObject