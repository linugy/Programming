#### 1.sizeof运算符
求数组的长度：
```
int a[] = {1,4,5};
int length = sizeof(a) / sizeof(int);
```

#### 2.一维数组
（1）对于一维数组
a[i] = 0，表示计算出偏移地址（i * 每个元素大小），然后加上a的首地址，即p = a + 4*i，最后给地址p赋值

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

注意：Qt中的Q_D宏用到了##，假如传入Widget，那么就会生成WidgetPrivate
```
#define Q_D(Class) Class##Private * const d = d_func()
```

#### 6.条件编译
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

#### 10.头文件
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

#### 11.为什么源文件要包含同名头文件
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

#### 12.把程序划分为多个文件
foo.c文件包含foo.h文件，是为了编译器可以检查foo.h文件的函数原型是否与foo.c文件中的函数定义相一致。

#### 13.结构体
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

#### 14.动态分配字符串
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

#### 15.动态分配数组
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

#### 16.指向函数的指针
1.声明：
void (*p)(int);
p是一个指针，指向一个函数，函数原型为：接收一个int参数，返回void

2.调用：
p(1);
(*p)(1);

#### 17.声明
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

#### 18.存储类型
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

#### 19.类型限定符
1.const
（1）用const修饰的变量，只能访问，不能修改

3.volatile（在二进制章节已详细说明）

#### 20.声明符
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

#### 21.char *a[N] 和char (*a)[N]有什么区别？
char *a[N]：定义了一个指针数组，即数组中每个元素都是char *；
char (*a)[N]：定义了一个指针，指向一位数组（该数组有N个值）

#### 22.初始化式
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

#### 23.static
https://blog.csdn.net/leikun153/article/details/80563903
C语言中：
（1）修饰全局变量：不能在文件外访问
（2）修饰函数：不能在文件外访问
（3）修饰局部变量：生命周期是全局的，函数执行完也不会被释放

C++语言中：（新增）
（1）修饰成员变量：表示所有对象共享变量
（2）修饰成员函数：表示所有对象共享函数

#### 24.原码、反码、补码
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

#### 25.大端模式、小端模式
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
