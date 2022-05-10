
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

#### 7.Lambda表达式
答：lambda表达式主要分五部分:[函数对象参数]、(操作符重载函数参数)、mutable或 声明、->返回值类型、{函数体} [捕获列表] (参数列表) 函数选项 -> 返回值类型 {函数体}
[&]:以引用的方式捕获外部的所有变量，如果在函数体内改变外部变量值，外部变量值就会随之改变；
　　[=]:以值的方式捕获外部的所有变量，如果在函数体内改变“外部变量值”，外部变量值不会改变；

#### 4.什么是智能指针？有几种?分别是什么？
答:一般是指把指针封装到一个类中,这个类中还封装了一个计数器,
对指针的复制等操作将导致该计数器加1,对指针delete会减1,直到为0,
指针为NULL。
智能指针有:
shared_ptr、weak_ptr、unique_ptr和auto_ptr(c++11摒弃);
分别有：
1.auto_ptr定一对象可以将new到的地址赋给这一对象,当智能指针过期时
析构函数会调用delete函数,对象被销毁,由此内存可以自动被释放;
2.shared_ptr允许多个指针指向同一个对象,每多一个指针指向，
计数就会加1,释放的时候,当值减为0即最后一个指针过期才会delete函数11
3.unique_ptr唯一的，只能一个指针指向一个对象。
4.weak_ptr为配合shared_ptr而引入的用于协助shared_ptr工作.


//==================================================

什么是多态？

多态除了用指针还可以用什么？引用。
纯虚函数和虚函数有什么区别？
多态还有一种叫编译时多态，有没有了解？
构造函数和析构函数可不可以是虚函数？
析构函数标记为虚函数，有什么意义？

构造析构顺序
虚表以及和构造的关系
虚函数实现，成员函数指针调整(那几个cast)
new和delete与内存管理
重载和lambda实现
引用，常引用，左值右值
模版和特化

左值引用与右值引用有什么区别，左值引用和右值引用的目的是什么
虚函数问了好多
什么是多态
虚函数和纯虚函数
构造函数和析构函数能不能是虚函数
std::move 是什么

面向对象三大思想

引用和指针的区别

假如定义了一个指针，后面接着一个循环并 return，会造成什么后果？（内存泄漏）

说下 C++ 新特性 auto变量的使用注意事项

怎么实现 map<key,value> 的（key 是自定义类型）

C 和 C++ 的区别

栈和堆的区别

4.面向对象三大特性：封装、继承、多态，继承的作用是什么


C++ 和 java 的区别

描述 STL；vector 和 list 的区别

OOP 三大特性、继承中三个修饰符的用法

C++ 的 static 关键字

智能指针，weak_ptr 能够破坏环型引用的原理（引用计数的原理）
auto关键字 （不能定义数组）

深拷贝与浅拷贝区别

C++ 智能指针

static 在 C 和 C++ 的用法
virtual 与析构函数

写一个多态，展示内存泄漏

strcpy 和 memcpy 的区别

局部 变量与全局变量
内存的分类

C++ 有几种构造函数


虚函数表原理，虚表编译的过程

new 和 malloc 的区别
智能指针内部原理

内存泄漏

静态多态包含什么类型
纯虚函数
虚析构函数
重载与重写的区别
extern "C"{}
const 的作用
指针和引用的区别
C++11 新特性
右值引用
强制类型转换

空指针、悬垂指针

类能否嵌套

unique_ptr 智能指针

new 和 malloc 的区别
内存的分类

auto 的类型判断发生在什么阶段（编译期） 如果是在运行期的话会发生什么问题
多态的分类
类型转换
智能指针

内存的分类
一个栈多大？

内存泄漏、智能指针

unique_ptr 与 shared_ptr 的区别

C++ 怎么申请连续的内存
vector 怎么用
C++ 的垃圾回收机制

GDB 怎么调试

区别 const 指针与 const 变量
引用的用法（左值引用与右值引用、引用不能改变绑定对象）
多态的用法

虚函数表原理
构造函数调用虚函数可以吗？会发生什么？

继承、多态的定义
听过多用组合，少用继承吗

C++11 新特性；解释右值引用是为了解决什么问题？（移动语义）

浅拷贝和深拷贝的区别
OOP 设计原则

钻石继承为何不能出现

虚表是怎么使用的？虚表指针存放在哪里？
构造函数能否为 virtual，能否调用虚函数？

OOP 三大特点
STL 常用容器
栈与堆的区别
new 和 malloc 的区别
指针和引用的区别

vector 如何处理数据

new 和 malloc 的区别

函数未定义时会怎么样？
