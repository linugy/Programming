

二、C++
1.const
2.static
3.内存分区
4.结构体内存大小
5.C和C++类型转换
6.C和C++中struct
7.define和防止头文件重复包含
8.C++中struct和class
9.this
10.inline
11.assert()
12.sizeof()
13.extern
14.explicit
15.friend
16.using
17.enum
18.内存分配和管理
19.成员初始化列表
------------分隔-----------
1.面向对象（封装，继承，多态）
2.封装
3.继承
4.多态
5.重写、重载、覆盖
6.父子对象构造函数生成顺序
7.构造函数和析构函数可以成为虚函数吗？为什么？
8.虚函数指针、虚函数表、虚表指针
9.虚析构函数（析构函数可以成为虚函数吗？为什么要用virtual关键修饰析构函数？）
10.纯虚函数
11.虚函数和纯虚函数的区别和联系
12.抽象类
13.虚继承
14.抽象类、接口类



一、C++
1.C++特性
2.虚函数的理解，如何实现的多态
3.虚继承
4.析构函数可以成为虚函数吗？为什么要用virtual关键修饰析构函数？不修饰行吗？
5.static作用
6.const作用
7.重写、重载、覆盖说一下
8.内存分配有那些，有什么区别



4.实现strcpy
5.实现strcmp
6.实现memcpy
8.堆栈溢出原因
13.C++智能指针
10.指针和引用的区别
12.变量的声明和定义有什么区别



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



### 8.堆栈溢出原因
（1）递归调用
（2）申请内存后没有释放


### 10.指针和引用的区别
（1）指针是一个变量，存放的是地址；引用是变量的别名
（2）引用必须初始化，指针可以在任意时间初始化
（3）有const指针，但是没有const引用


### 12.变量的声明和定义有什么区别
#### 声明：不分配内存空间；可以多次声明；
#### 定义：分配内存空间；只能定义一次；

### 13.C++智能指针
#### shared_ptr：允许多个指针指向同一个对象。引用计数。
#### unique_ptr
#### weak_ptr



### 15.char str[] 和 char *str的相等比较和内存对齐大小

### 16.strstr函数


### 19.在哪里用到过多态
槽函数里使用sender，返回一个QObject