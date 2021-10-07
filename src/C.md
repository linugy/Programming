#### 1.sizeof运算符
求数组的长度：
```
int a[] = {1,4,5};
int length = sizeof(a) / sizeof(int);
```

#### 2.为什么数组可以不用指出第一维大小
前置知识点：
把数组传递给函数时，是传递的数组第一个元素的指针。

（1）对于一维数组
a[i] = 0，表示计算出偏移地址（i * 每个元素大小），然后加上a的首地址，即p = a + 4*i，最后给地址p赋值

（2）对于二维数组
a[i][j] = 0，首先i * 数组a每行的大小，然后加到a的首地址上，接着用j * 数组a中每个元素的大小，然后把加上前面的地址，即p = a*j + j*4；最后给地址p赋值。

#### 3.指针和多维数组
用指针访问二维数组元素：
（1）方法1：
```
char a[2][3] = {{1,2,3},{4,5,6}}

char *p = &a[0][0];

for (int i = 0; i < 2; i++) {
	for (int j = 0; j < 3; j++) {
    	qDebug() << p[i * 4 + j];
    }
}
```

（2）方法2：
```
char a[2][3] = {{1,2,3},{4,5,6}}

char (*p)[3] = a;
for (int i = 0; i < 2; i++) {
	for (int j = 0; j < 3; j++) {
    	qDebug() << p[i][j];
    }
}
```

#### 4.预处理指令：3种预处理指令类型
（1）文件包含：#include
（2）宏定义：#define, #undef
（3）条件编译：#if, #ifdef, #ifndef, #elif, #else, #endif

#### 5.#和##
#：将宏的一个参数转换为字符串字面量。
举例：
```
#define PRINT_INT(n) qDebug() << #n" = " << n;

PRINT_INT(3/4);

// 结果：3/4 =  0
// 可以连接#n就是字符串
```

##：将两个标识符“连接”在一起，成为一个标识符
举例：
```
#define MK_ID(n) i##n

int MK_ID(1) = 1;
int MK_ID(2) = 2;

qDebug() << i1 << i2;
// 结果：1 2
```

#### 6.条件编译
#if 
#ifdef、#ifndef（等价于#if defined）
#elif、#else
#endif

防止头文件重复包含：
```
#ifndef A_H
#define A_H
...
#endif
```

屏蔽代码：
```
#ifdef ABC
...
#elif
...
#else
...
#endif
```

```
#if 1
...
#else
...
#endif
```

#### 7.#pragma
（1）#pragma once 避免重复包含，编译器相关，有的编译器支持，有的编译器不支持，大部分都支持。
建议使用#ifndef，#define，#endif，因为是宏定义，在所有编译器上都支持。

（2）#pragma  pack (push,1)、#pragma pack(pop)
设定内存以n字节对齐。默认是8字节
```
#pragma pack(push, 4)
struct Stu{
	char a;
    double b;
    int c;
};
#pragma pack(pop)

// Stu大小为4 + 8 + 4 = 16
```

```
#pragma pack(push, 8)
struct Stu{
	char a;
    double b;
    int c;
};
#pragma pack(pop)

// Stu大小为8 + 8 + 8 = 24
```

#### 8.字符串变量
C语言字符串：只要保证字符串事宜空字符结尾的，任何一维的字符数组都可以用来存储字符串。

（1）字符串数组：char a[10];
初始化：

```
char a[10] = "abc";// 末尾自动加'\0'，多出来的空间也存储'\0'

char b[2] = "ab";// 刚好相等，放不下'\0'，此时b无法作为字符串来使用，只是一个字符数组

char c[] = "abc";// 自动加上'\0'，长度为4
```

（2）字符串变量：char *p;
初始化：
```
char *p = "abc";

char a[10];
char *p = a;// 指向已存在的字符数组的地址

char *p = (char *)malloc(10);
```

#### 9.源文件
