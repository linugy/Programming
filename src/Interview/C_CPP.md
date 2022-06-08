## 目录（1.基础语法；2.面向对象；3.智能指针，内存泄露；4.内存分类与管理；5.STL容器）

### C基础语法
#### sizeof运算符
#### 一维数组
#### 指针和多维数组
#### 预处理指令：3种预处理指令类型
#### #和##
#### 条件编译
#### #pragma
#### 字符串变量
#### 源文件
#### 头文件
#### 为什么源文件要包含同名头文件
#### 把程序划分为多个文件
#### 结构体
#### 动态分配字符串
#### 动态分配数组
#### 指向函数的指针
#### 声明
#### 存储类型
#### 类型限定符
#### 声明符
#### char *a[N] 和char (*a)[N]有什么区别？
#### 初始化式
#### static
#### 原码、反码、补码
#### 大端模式、小端模式

### C++基础语法
#### 指针和引用
#### 指针和数组
#### 左值引用与右值引用
#### static，const与extern
#### static 在 C 和 C++ 的用法
#### new和malloc
#### class前项申明和include
#### 浅拷贝和深拷贝
#### extern "C"{}
#### C和C++中struct
#### 其他
##### C和C++类型转换，dynamic_cast怎么保证安全的？
##### 结构体内存大小
##### define和防止头文件重复包含
##### C++中struct和class
##### this
##### inline
##### assert()
##### sizeof()
##### explicit
##### friend
##### ::
##### using
##### enum
##### 变量的声明和定义有什么区别
##### char str[] 和 char *str的相等比较和内存对齐大小
##### strstr函数
##### int占多少个字节，long long，long，这几个一定是占这么多空间吗?
##### 什么情况下，delete需要加一个中括号[]
##### 函数未定义时会怎么样？
##### 区别 const 指针与 const 变量
##### 引用的用法（左值引用与右值引用、引用不能改变绑定对象）
##### 局部 变量与全局变量
##### strcpy 和 memcpy 的区别
##### std::move 是什么
##### 左值引用与右值引用有什么区别，左值引用和右值引用的目的是什么
##### 引用，常引用，左值右值
##### 函数指针、指针函数区别
##### 成员初始化列表

### C++面向对象
#### 封装，继承，多态
#### 虚函数指针、虚函数表、虚表指针
#### 重写、重载、覆盖
#### 构造函数与析构函数
#### 成员初始化列表
#### C++ 有几种构造函数
#### OOP 三大特性、继承中三个修饰符的用法
#### 多继承
##### 其他
##### 父子对象构造函数生成顺序
##### 构造析构顺序
##### 构造函数和析构函数可以成为虚函数吗？为什么？
##### 虚析构函数（析构函数可以成为虚函数吗？为什么要用virtual关键修饰析构函数？）
##### 纯虚函数
##### 虚函数和纯虚函数的区别和联系
##### 抽象类、接口类
##### 虚继承的作用
##### 纯虚函数和普通的虚函数有什么区别
##### 构造函数能否为 virtual，能否调用虚函数？
##### 钻石继承为何不能出现
##### 多态还有一种叫编译时多态，有没有了解？
##### 多态的分类
##### 静态多态包含什么类型
##### 类能否嵌套
##### 在哪里用到过多态
##### 类里面的函数占用内存吗？

### C++智能指针与内存泄露
#### shared_ptr
#### weak_ptr
#### unique_ptr
#### auto_ptr
##### 其他
##### C++的垃圾回收机制
##### 空指针、悬垂指针
##### 智能指针内部原理
##### shared_ptr内部的引用计数，怎么实现的?
##### unique_ptr 与 shared_ptr 的区别
##### 智能指针，weak_ptr 能够破坏环型引用的原理（引用计数的原理）
##### 内存泄漏、智能指针
##### 堆栈溢出原因
##### 如何排查出代码里已经存在的内存泄漏问题
##### 写一个多态，展示内存泄漏

### C++内存管理
#### 内存分配和管理
##### 其他
##### 栈与堆的区别
##### 内存对齐
##### new和delete与内存管理
##### C++ 怎么申请连续的内存
##### 一个栈多大
##### 静态扫描和动态检测

### STL
#### STL常用容器
#### vector如何处理数据
#### vector和list 的区别

### 其他
#### C和C++的区别
#### C++和java的区别
#### map的内部机制
#### C++11新特性
#### 看过哪些C++书

//===================================C基础语法======================================================

#### sizeof运算符
求数组的长度：
```
int a[] = {1,4,5};
int length = sizeof(a) / sizeof(int);
```

#### 一维数组
（1）对于一维数组
a[i] = 0，表示计算出偏移地址（i * 每个元素大小），然后加上a的首地址，即p = a + 4*i，最后给地址p赋值

#### 指针和多维数组
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

#### 预处理指令：3种预处理指令类型
（1）文件包含：#include
（2）宏定义：#define, #undef
（3）条件编译：#if, #ifdef, #ifndef, #elif, #else, #endif

#### #和##
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

注意：Qt中的Q_D宏用到了##，假如传入Widget，那么就会生成WidgetPrivate
```
#define Q_D(Class) Class##Private * const d = d_func()
```

#### 条件编译
#if、
#ifdef、#ifndef（等价于#if defined）、
#elif、#else、
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

#### #pragma
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

#### 字符串变量
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

#### 源文件
源文件包含函数的定义和外部变量。

共享变量的两种方式：
（1）头文件放声明，源文件放定义，需要用的地方包含头文件
```
// test.h
extern int a;
int b;// 默认是extern

// test.c
a = 0;
b = 1;

// other.c
#include "test.h"
a = 2;
b = 3;
```

（2）一个源文件声明变量，其他源文件extern变量
https://www.cnblogs.com/xiaosanxian/p/11141260.html

```
// test1.c
int a;
int b = 0;
extern int c;// c没有定义，所以其他地方不能使用
extern int d = 0;

// test2.c
extern int a;
extern int b;
extern int c;
extern int d;

b = 2;
// c = 3;// c会报错，因为c没有找到定义
d = 4;

qDebug() << a << b << d;
// 0 2 4
```

（3）总结：其实两种方式是一样的，变量首先需要定义，然后用的地方使用extern 声明，只是第一种方式将extern声明放在头文件，用到的地方include；第二种方式在源文件(也可以在头文件)中手动extern声明变量。


#### 头文件
#include <> 在系统目录中找头文件
#include "" 先在用户目录（当前目录）找，再到系统目录找

头文件作用：
（1）共享宏和数据类型
```
// a.h
#define MAN 1
#define WOMAN 0
typedef struct Stu {
	int age;
    int sex;
}S;

// b.c
#include "a.h"

S s;
s.age = 10;
s.sex = MAN;
```

（2）共享函数原型（声明）
```
// a.h
int getAge();

// a.c
int getAge()
{
	return 20;
}

// b.c
#include "a.h"
int age = getAge();
```

（3）共享变量声明
```
// a.h
extern S s;

// a.c
#include "a.h"
S s;

// b.c
#include "a.h"
s.age = 1;
```


#### 为什么源文件要包含同名头文件
https://blog.csdn.net/khwkhwkhw/article/details/49798985
按照之前的理解：对于c文件中定义的一个变量，其他c文件需要用extern 变量来声明。现在只是将extern变量放到h文件，其他c文件需要包含h文件，但是该c文件应该是不需要包含的h文件的。确实也是这样的，
举例：
```
// a.c
// 此时没有include a.h
int a = 1;

// a.h
extern int a;

// b.c
#include "a.h"
qDebug() << a;
// 结果：1
```

但是考虑这样一种情况：
```
// a.c
// 此时没有include a.h
int a = 1;

// a.h
extern double a; // 这里使用double，因为a的声明和定义不在一个文件中，所以不会检查一致性。
// 导致程序可以跑，比如下面a的结果是“5.41109e-312”，不正确，很难找出问题在哪。
// 使用include让a的声明和定义在一个文件，从而让编译器进行一致性检查。如果不一致，就会重定义变量

// b.c
#include "a.h"
qDebug() << a;
// 结果：1
```
所以根本原因还是：定义和声明不在同一个文件，编译器不会进行一致性检查。
这应该是语言这么设计的吧（暂时没有找到答案），比如像上面，其他地方定义了int a;但我extern double a;程序不会报错，但是结果是错的。

最好的做法：
c文件包含同名的h文件，这样可以对变量a进行一致性检查；
其他用到变量a的地方，直接包含h文件就行，因为有extern语句。
```
// a.c
#include a.h
int a = 1;

// a.h
extern int a;

// b.c
#include "a.h"
qDebug() << a;
// 结果：1
```


#### 把程序划分为多个文件
foo.c文件包含foo.h文件，是为了编译器可以检查foo.h文件的函数原型是否与foo.c文件中的函数定义相一致。

#### 结构体
1.结构体声明：
```
struct Stu{
	int age;
    char name[10];
};
struct Stu a;

typedef struct Stu{
	int age;
    char name[10];
} S;
Stu a;

struct Stu {
	int age;
    char name[10];
};
typedef struct Stu S;
S a;
```

2.结构体变量初始化：
```
Stu a = {1, "abc"};
```

3.结构体变量复制：
```
Stu b;
b = a;
```

#### 动态分配字符串
因sizeof(char)为1，所以假如要分配n个字符的字符串，可以使用
```
char *p = (char *)malloc(n + 1);// +1用来存放空字符

// 采用strcpy初始化
strcpy(p, "abc");
```

实例：合并两个字符串，并返回一个新串
```
char *concat(const char *s1, const char *s2)
{
	char *p = (char *)malloc(sizeof(s1) + sizeof(s2) + 1);
    if (p == NULL) {
        exit(0);
    }
    strcpy(p, s1);
    strcat(p, s2);
    return p;
}
```


#### 动态分配数组
1.malloc分配：
```
int *p = (int *)malloc(n * sizeof(int);// 分配n个整数空间
                       
for (int i = 0; i < n; i++) {
    p[i] = 0;// 进行初始化
}
```

2.calloc分配：
```
int *p = (char *)calloc(n, sizeof(int));// 分配n个整数空间，默认初始化为0
```


#### 指向函数的指针
1.声明：
void (*p)(int);
p是一个指针，指向一个函数，函数原型为：接收一个int参数，返回void

2.调用：
p(1);
(*p)(1);


#### 声明
存储类型：
auto，static，extern，register
放在最前面，只能出现一种

类型限定符：
const，volatile
可以出现多个

类型说明符：
void
char
short
int
long
float
double
signed
unsigned
可以组合使用。
还包含：struct，enum，union，typedef创建的类型

说明符：
变量名称
[]
*
()

综合例子：
```
extern const unsigned long int a[10];
extern:存储类型
const：类型限定符
unsigned, long, int:类型说明符
a[10]:声明符
```

综合理解：
（1）常规：int a;
（2）组合类型说明符：unsigned int a;
（3）组合声明符：unsigned int *a[2];
（4）组合类型限定符： const unsigned int *a[2];
（5）组合存储类型：static const unsigned int *a[2];
（6）组合初始化式：static const unsigned int *a[2] = {1, 2};


#### 存储类型
1.变量的3个性质
（1）存储期限：
自动存储期限：变量在所属的块被执行时获得内存单元，块结束后释放内存单元；
静态存储期限：变量在程序运行期间始终占有同一个内存单元；
（2）作用域：
块作用域：变量从声明的地方一直到所在块的末尾都是可见的；
文件作用域：变量从声明的地方一直到所在文件的末尾都是可见的；
（3）链接：
无链接：变量属于单独一个函数，不能被共享；
内部链接：变量属于单独一个文件，此文件中的函数共享该变量；
外部链接：变量可以被多个文件共享；

2.auto存储类型
（1）块内部的变量默认是auto存储类型；
（2）变量具有自动存储期限；块作用域；无链接；

3.static存储类型
（1）用在块外部变量时，表示变量具有内部链接；当用在块内部时，static把变量的存储期限从自动的变成静态
举例：
```
static int i;

void f(void)
{
    static int j;
}

i:静态存储期限；文件作用域；内部链接
j:静态存储期限；块作用域；无链接
```
（2）static变量只进行一次初始化

4.extern存储类型
（1）使多个源文件共享同一个变量
（2）对变量进行初始化的extern声明是变量的定义。
extern int i = 0;等效于int i = 0;
举例：
```
extern int i;

void f(void)
{
    extern int j;
}

i:静态存储期限；文件作用域；外部链接
j:静态存储期限；块作用域；外部链接
```

5.register存储类型
（1）要求编译器将变量存储在寄存器中。适用于频繁访问或更新的变量

6.函数的存储类型
（1）extern
默认类型，表示函数具有外部链接
（2）static
表示函数具有内部链接。好处：减少名字空间污染

7.小结
```
int a;
extern int b;
static int c;

void f(int d, register int e)
{
    auto int g;
    int h;
    static int i;
    extern int j;
    register int k;
}

存储期限；作用域；链接
a:静态；文件；外部
b:静态；文件；外部
c:静态；文件；内部

d,e,g,h:自动；块；无链接

i:静态；块；无
j:静态；块；外部

k:自动；块；无
```


#### 类型限定符
1.const
（1）用const修饰的变量，只能访问，不能修改

3.volatile（在二进制章节已详细说明）


#### 声明符
1.声明符包含：
（1）变量名
（2）*
（3）[ ]
（4）( )

2.复杂声明：
（1）从内往外读
（2）[ ] 和 ( )的优先级大于 *
举例：
```
int *(*x[10])(void)

1.x是一个数组
2.数组里存放的是指针
3.每一个指针都是一个函数
4.函数原型：返回int *，参数为void
```

3.利用typedef简化复杂声明：
举例：
```
int *(*x[10])(void)

// 可以改写为如下

typedef int *Fun(void);
typedef Fun *Fun_ptr;
typedef Fun_ptr Fun_ptr_array[10];

Fun_ptr_array x;
```

#### char *a[N] 和char (*a)[N]有什么区别？
char *a[N]：定义了一个指针数组，即数组中每个元素都是char *；
char (*a)[N]：定义了一个指针，指向一位数组（该数组有N个值）


#### 初始化式
数组、结构、联合使用花括号：
int a[5] = {1, 2, 3, 4, 5};

特殊规则：
（1）静态变量的初始化式必须是常量
（2）如果变量具有自动存储期限，那么初始化式不需要是常量
举例：
```
int f(int n)
{
	int last = n - 1;
}
```

#### static
https://blog.csdn.net/leikun153/article/details/80563903
C语言中：
（1）修饰全局变量：不能在文件外访问
（2）修饰函数：不能在文件外访问
（3）修饰局部变量：生命周期是全局的，函数执行完也不会被释放

#### 原码、反码、补码
https://blog.csdn.net/zl10086111/article/details/80907428
1.机器数：
数的二进制形式，带符号，最高位为0表示正数，最高位为1表示负数。
举例：
```
33
0010 0001

-12
1000 1100
```

2.真值：
将带符号（包括正负数）的机器数对应的真正数值称为机器数的真值
例如：00000001的真值为+1，10000001的真值为-1

3.原码
就是机器数

4.反码
正数的反码就是本身
负数的反码：符号位不变，其它位按位取反

5.补码
正数的补码就是本身
负数的反码：符号位不变，其它位按位取反，然后+1

6.为什么需要原码、反码、补码？
原码：方便人类识别
反码和补码：方便计算机计算，加减法当成加法来计算，例如：2-1 = 1等同于2+（-1） = 1；
反码关于127同余，补码关于128同余。
因为0的存在，所以采用补码计算，范围为-128到127

#### 大端模式、小端模式
大端模式：高尾模式。起始地址（低地址）（尾）放高位字节。高位字节放低地址
CPU对操作数的存放方式是高地址存放低位，低地址存放高位。

小端模式：低尾模式。起始地址（低地址）（尾）放低位字节。低位字节放低地址
CPU对操作数的存放方式是高地址存放高位，低地址存放低位。

使用场景：一般操作系统都是小端，而通讯协议是大端的

测试方式：
（1）union测试：
解析：因为CPU总是从低地址读取，当为int赋值后，看char的值，如果是0x78，表示低地址放低字节，是低尾，
即小端。当char的值是0x12时，表示低地址放高字节，是高尾，即大端。
```
union A {
	int i;
    char c;
};

int main() 
{
    A a;
    a.i = 0x12345678;
    if (a.c == 0x78) {
    	// 小端
    } else {
    	// 大端
    }    
}
```

（2）指针测试：
解析：因为CPU总是从低地址读取，当取i的指针并转换为char指针后，此时取值为char，如果char为0x78，表示低地址存放低字节，为低尾，即小端。如果char为0x12，表示低地址存放高字节，为高尾，即大端。
```
int main()
{
	int i = 0x12345678;
    char c = *(char *)(&i);
    if (c == 0x78) {
    	// 小端
    } else {
    	// 大端
    }
}
```


//===================================C++基础语法======================================================

#### 指针和引用
##### 指针和引用的用法

##### 指针和引用的区别
（1）指针是一个变量，存放的是地址；引用是变量的别名
（2）引用必须初始化，指针可以在任意时间初始化
（3）有const指针，但是没有const引用

#### 指针和数组

#### 左值引用与右值引用

#### static，const与extern
#### static
#### 修饰普通变量
使变量存储在静态区，在 main 函数运行前就分配了空间
#### 修饰普通函数
表明函数只能在定义该函数的文件内才能使用。
#### 修饰成员变量
表示所有的对象都是用同一个变量，并且可以不生产对象就使用变量
#### 修饰成员函数
不需要生成对象就可以访问该函数，但是在 static 函数内只能能访问静态成员（成员函数和成员变量）

#### const
#### 修饰变量
表示变量不可以被修改，如：const int a = 0；
#### 修饰指针
（1）const指针，表示指针本身是const，不可以修改指针的值，例如int const *p = &a;
（2）指向const的指针，表示不能通过指针来修改指向变量的值，例如const int *p = &a;
#### 修饰引用
（1）对const的引用，表示不可以修改引用的值，例如const int &m = n;
（2）没有 const 引用，因为引用本身就是 const ，引用必须进行初始化
#### 修饰成员函数
说明在该成员函数内不能修改成员变量

#### extern 变量声明/函数声明（没有static修饰）
表明变量或函数的定义在别的文件中，提示编译器遇到变量或函数时，到其他文件中寻找定义

#### const与extern
1.正常情况下共享变量：源文件定义int a = 0;头文件声明extern int a;在需要用的地方包含头文件。
2.共享const变量：源文件定义extern const int a = 0;头文件声明extern const int a;在需要用的地方包含头文件。
总结：如果要共享const，不仅声明需要extern，定义时也需要extern


#### static 在 C 和 C++ 的用法

#### new和malloc
#### malloc、free
是库函数；
malloc申请指定字节数的内存，例如：
```
char *str = (char*) malloc(100);
```
free释放内存，例如：
```
free(p);  p = nullptr;
```

#### new、delete
是C++运算符；
new先底层调用 malloc 分配了内存，然后调用构造函数
delete先调用析构函数（清理资源），然后底层调用 free 释放空间

#### class前项申明和include

#### 浅拷贝和深拷贝

#### extern "C"
https://zhuanlan.zhihu.com/p/123269132
是C++特有的指令，作用是告诉C++编译器按照C语言的方式编译和链接
举例：
```
#ifdef __cplusplus
extern "C {
#endif
    ...
#ifdef __cplusplus
}
#endif
```

#### C和C++中struct
#### struct 和 typedef struct
C和C++中使用typedef stuct是一样的，而使用struct的时候，C语言需要再次typedef，C++可以用
（1）C语言中
```
typedef struct Student {
    int age; 
} S;
```

```
struct Student { 
    int age; 
};

typedef struct Student S;
```

（2）C++语言中
```
typedef struct Student { 
    int age; 
} S;
```

```
struct Student { 
    int age; 
};

void f( Student me );       // 正确，"struct" 关键字可省略
```


#### C和C++类型转换，dynamic_cast怎么保证安全的？
#### static_cast
用于非多态类型的转换
#### dynamic_cast
用于多态类型的转换
#### const_cast
用于删除const，比如const int 转换为int
#### reinterpret_cast
不建议使用
#### 补充:
Qt使用qobject_cast，类似dynamic_cast

#### 结构体内存大小

#### define和防止头文件重复包含
```
#ifndef A_H
#define A_H
...
#endif
```

#### C++中struct和class
唯一区别：默认访问权限，struct是public，class是private。
struct 更适合看成是一个数据结构的实现，class 更适合看成是一个对象的实现。

#### this
this指针隐含于非静态成员函数中。表示当前的对象。

#### inline
（1）相当于把内联函数里面的内容写到内联函数调用处。
（2）在类声明中定义的函数，隐式地当成内联函数。

#### assert()
断言，是宏，如果返回错误，则终止程序。

#### sizeof()
是运算符，用于判断变量或类型所占内存大小。
sizeof判断数组，获取整个数组所占空间大小。
sizeof判断指针，获取指针本身所占空间大小。
举例：求数组长度
```
int arr[] = {1,2,3};
int length = sizeof(arr) / sizeof(int));//数组的内存大小除以类型的内存大小
```

#### explicit
修饰构造函数，表示不可以进行隐式转换和复制构造
举例：
```
class A
{
	explicit A(int) { }// 构造函数，接受一个int
};

void doA(A a) {}// 函数，接受哦一个A对象

int main() 
{
	doA(2);// 此时会进行隐式转换，因为有explicit关键字，所以会报错
    A a = 3;// 此时会进行复制初始化，因为有explicit关键字，所以会报错
}
```

#### friend
友元，访问类的私有成员，友元关系不能传递，也不可逆
举例：
```
class A {
	friend class B;
private:
    int width;
    int height;
};

class B {
	int add() {
    	A a;
       	return a.width + a.height; 
    }
};
```

#### ::
（1）全局作用域（::name）
（2）类作用域（class::name）
（3）命名空间作用域（namespace::name）

#### using
不要这样使用：using namespace std;原因是命名冲突，
这样使用：std::cout << "a";或者：using std::cout; cout << "a";

#### enum
枚举，举例：
```
enum color {
	red,
    blue,
    green
};
```

#### 变量的声明和定义有什么区别
声明：不分配内存空间；可以多次声明；
定义：分配内存空间；只能定义一次；

#### char str[] 和 char *str的相等比较和内存对齐大小

#### strstr函数

#### int占多少个字节，long long，long，这几个一定是占这么多空间吗?

#### 什么情况下，delete需要加一个中括号[]

#### 函数未定义时会怎么样？

#### 区别 const 指针与 const 变量

#### 引用的用法（左值引用与右值引用、引用不能改变绑定对象）

#### 局部 变量与全局变量

#### strcpy 和 memcpy 的区别

#### std::move 是什么

#### 左值引用与右值引用有什么区别，左值引用和右值引用的目的是什么

#### 引用，常引用，左值右值

#### 函数指针、指针函数区别

#### 成员初始化列表
必须使用成员初始化列表的情况：
（1）成员变量为const类型。
（2）成员变量为引用类型。
const或引用只能初始化但是不能赋值。构造函数的函数体内是赋值。所以只能使用初始化列表。

//====================================C++面向对象=====================================================

#### C++面向对象

#### 封装
将数据和方法封装起来，通过public，protected，private来进行访问控制。
（1）public：可以被任意访问。
（2）protected：只能被子类及本类的成员函数访问。
（3）private：只能被本类，友元类和函数访问。

#### 继承
子类继承父类的方法和成员变量
（1）public继承：访问权限不变。
（2）protected继承：public变为protected访问权限。
（3）private继承：访问权限都变为private。

#### 多态

可以理解为：一个方法，多种实现。
主要分为
（1）静态多态：在编译期决定函数的调用，通过函数重装来实现
（2）动态多态：在运行期决定函数的调用，通过虚函数来决定

举例：
```
// 基类
class Shape {
	public:
    	virtual double area() {}
    	virtual ~Shape();
};

// 子类
class Circle : public Shape {
	public:
    	virtual double area() {}
    ...
};

// 子类
class Rect : public Shape {
	public:
    	virtual double area() {}
};

// main函数
int main()
{
	Shape *shape_1 = new Circle(2);
    Shape *shape_2 = new Rect(1, 2);
    
    shape_1->area();// 调用Circle的方法
    shape_2->area();// 调用Rect的方法
    
    delete shape_1;
    shape_1 = nullptr;
    
    delete shape_2;
    shape_2 = nullptr;
    
    return 0;
}
```

#### 虚函数指针、虚函数表、虚表指针
参考：https://zhuanlan.zhihu.com/p/75172640
https://blog.twofei.com/496/
每个包含了虚函数的类都包含一个虚表。虚表是属于类的，而不是属于某个具体的对象。
虚表中存放虚函数指针，每个虚函数指针指向一个虚函数。
对象内部包含一个虚表的指针，来指向自己所使用的虚表。当类的对象在创建时便拥有了这个指针，且这个指针的值会自动被设置为指向类的虚表。

#### 重写、重载、覆盖
#### 重写：
override，派生类重新实现了基类的同名函数，基类函数必须用virtual修饰
#### 重载：
overload，多个函数名相同，参数列表（参数类型，参数个数，参数顺序）不同的函数
#### 覆盖：
派生类的函数屏蔽了基类中的同名函数

#### 构造函数与析构函数

#### 成员初始化列表

#### C++有几种构造函数

#### OOP 三大特性、继承中三个修饰符的用法

#### 多继承

##### 父子对象构造函数生成顺序
先调用父类的构造函数，再调用子类成员变量的构造函数，在调用子类自己的构造函数

##### 构造析构顺序

##### 构造函数和析构函数可以成为虚函数吗？为什么？
（1）构造函数不能是虚函数，因为在调用构造函数时，虚表指针还没有在对象的内存空间种，必须在构造函数嗲用完成后才会形成虚表指针。
（2）析构函数可以是虚函数。

##### 虚析构函数（析构函数可以成为虚函数吗？为什么要用virtual关键修饰析构函数？）
为了解决基类指针指向派生类对象，并且用基类指针删除派生类对象。
举例：
```
delete shape_1;
// 因为Shape有虚析构函数，所以delete释放内存时，先调用子类析构函数，再调用基类析构函数，防止内存泄漏
shape_1 = nullptr; 
```

##### 纯虚函数
在虚函数的声明后面加上 =0；
举例：
```
virtual double area() = 0;
```

##### 虚函数和纯虚函数的区别和联系
（1）包含虚函数的类可以实例化对象；
（2）包含纯虚函数的类不能实例化对象，只能通过继承，重新实现纯虚函数后才能生成对象。

##### 抽象类、接口类
包含纯虚函数的类叫做抽象类，抽象类不能实例化对象。
抽象类：含有纯虚函数的类
接口类：仅含有纯虚函数的抽象类

##### 虚继承的作用
为了解决多继承体情况下的菱形继承问题。
```
class B : virtual public A  
```

##### 纯虚函数和普通的虚函数有什么区别

##### 构造函数能否为 virtual，能否调用虚函数？

##### 钻石继承为何不能出现

##### 多态还有一种叫编译时多态，有没有了解？

##### 多态的分类
https://blog.csdn.net/jia_gushuai/article/details/106158214

##### 静态多态包含什么类型

##### 类能否嵌套

##### 在哪里用到过多态

##### 类里面的函数占用内存吗？
https://blog.csdn.net/sangba2019/article/details/117083443


//===================================C++智能指针与内存泄露=====================================================

https://blog.csdn.net/TABE_/article/details/117391903
#### C++智能指针
#### shared_ptr
#### weak_ptr
#### unique_ptr
#### auto_ptr

#### C++的垃圾回收机制：没有垃圾回收机制

#### 空指针、悬垂指针

#### 智能指针内部原理

#### shared_ptr内部的引用计数，怎么实现的?

#### unique_ptr 与 shared_ptr 的区别

#### 智能指针，weak_ptr 能够破坏环型引用的原理（引用计数的原理）

#### 内存泄漏、智能指针

#### 堆栈溢出原因
（1）函数调用层次太深，函数递归调用
（2）动态申请空间使用之后没有释放。
（3）数组访问越界。
（4）指针非法访问。

#### 如何排查出代码里已经存在的内存泄漏问题
https://www.zhihu.com/question/63946754?sort=created

#### 写一个多态，展示内存泄漏
https://blog.csdn.net/weixin_44648216/article/details/117607223

//===================================C++内存管理=====================================================

https://blog.csdn.net/William_CW/article/details/96429114
#### C++内存管理
（1）栈区
（2）堆区
（3）全局区（静态区）
（4）常量区
（5）代码区

### 4.内存分区
#### 堆区
通过new来分配的内存，需要手动delete，由程序员手动控制
#### 栈区
存放局部变量，由编译器自动申请和释放
#### 常量区
存放常量，不能修改
#### 静态数据区
存放静态变量
#### 代码区
存放函数体的二进制代码

#### 栈与堆的区别

#### 内存对齐
参考：https://www.cnblogs.com/zrtqsk/p/4371773.html
简单理解为：每次分配4个字节，如果变量能放就放，不能放就重新分配4字节。
举例：
```
struct {
    char c='1';//1byte 
    int i;//4byte
    short s=2;//2byte
};
解析：先分配4字节，char可以放进去，但是剩下3字节int放不进去，所以又分配4字节，同理short也分配4字节。
所以结果为12字节


struck{
    int i;//4byte
    char c = '1';//1byte 
    short s = 2;//2byte
};
解析：先分配4字节，刚好可以放int，然后分配4字节，先放一个char，剩下3字节，可以放一个short。
所以结果为8字节
```


#### malloc/free和new/delete的区别是什么？
https://zhuanlan.zhihu.com/p/447104887
https://zhuanlan.zhihu.com/p/509656320

##### C++ 怎么申请连续的内存

##### 一个栈多大
https://blog.csdn.net/qq_41786318/article/details/81670878

//==========================================STL=====================================================

https://zhuanlan.zhihu.com/p/130905242

#### STL常用容器
（1）vector
（2）deque
（3）list
（4）set
（5）multiset
（6）map
（7）multimap

#### vector如何处理数据

#### vector和list的区别

//==========================================其他=====================================================

#### C 和 C++ 的区别
（1）C是面向过程的语言；C++是面向对象的语言

#### C++ 和 java 的区别
（1）Java是解释型语言，C++是编译型语言
（2）C++比Java速度快

#### map的内部机制
https://www.csdn.net/tags/Mtjacg1sMzcxNTgtYmxvZwO0O0OO0O0O.html
（1）map的实现原理就是红黑树 

#### C++11新特性：
https://zhuanlan.zhihu.com/p/139515439
（1）列表初始化
（2）右值引用和move语义
（3）lambda表达式
（4）类型推导auto和decltype
（5）基于范围的 for 循环
（6）尖括号 “>”
（7）委托构造、继承构造
（8）nullptr
（9）Override和final
（10）智能指针
（11）default、delete
（12）explicit
（13）正则表达式regex库

#### 看过哪些C++书：
《C++ Primer》《Effective C++》
