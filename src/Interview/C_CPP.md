## 目录（1.基础语法；2.面向对象；3.智能指针，内存泄露；4.内存分类与管理；5.STL容器）

### C和C++基础语法
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

//===================================C和C++基础语法======================================================

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
