
六、编译
1.程序编译过程
2.预编译时，如何避免重复展开头文件
3.说一下对define的认识
2.动态库和静态库区别
3.程序编译过程


### 3.动态库和静态库区别
#### 静态库：（.a或.lib），所有相关的文件和库被链接到一个可执行文件。
#### 动态库：（.so或.dll），在程序编译时并不会被连接到目标代码中，而是在程序运行是才被载入。

### 4.程序编译过程
####  预编译：处理#include，#define等预编译指令
####  编译：进行词法分析、预防分析等过程
####  汇编：将汇编指令翻译成机器指令，生成目标文件
####  链接：将目标文件链接在一起生成可执行文件

软件调试 

编译过程

编译器和调试器你用哪些？
静态链接库与动态链接库的区别
程序生成的过程


### 1.C/C++编译器：
#### （1）MSVC：
MSVC是微软Windows平台Visual Studio自带的C/C++编译器。
优点：对Windows平台支持好，编译快。

#### （2）GCC：
GCC原名GNU C Compiler，后来逐渐支持更多的语言编译（C++、Fortran、Pascal、Objective-C、Java、Ada、Go等），所以变成了GNU Compiler Collection（GNU编译器套装），是一套由GNU工程开发的支持多种编程语言的编译器。是大多数类Unix（如Linux、BSD、Mac OS X等）的标准编译器，
g++则是GCC的c++编译器https://www.zhihu.com/question/20940822

#### （3）MingW：
MingW（Minimalist GNU on Windows）是一个Linux/Windows下的可以把软件源码中Unix-like OS API调用通过头文件翻译替换成相应的Windows API调用的编译环境。从而把Linux上的软件在不修改源码的情况下编译为可直接在Win下执行的exe。
和GCC的关系：MingW是编译环境，不是编译器，GCC是MingW中的核心组成。
优点：在Win下可以和Linux一样的方式编译C/C++源码，可以说是Win版的GCC。

### 2.调试器
#### （1）WinDbg： 
Windows 下的调试器，它还有一个命令行版本（cdb.exe）

#### （2）GDB ：
全称“GNU symbolic debugger”，从名称上不难看出，它诞生于 GNU 计划（同时诞生的还有 GCC、Emacs 等），是 Linux 下常用的程序调试器。

| Platform      | Compiler | Native Debugger |
| ----------- | ----------- | ----------- |
| Linux      | GCC/ICC       | GDB, LLDB (experimental)       |
| Unix   | GCC/ICC        | GDB       |
| macOS      | GCC/Clang       | LLDB,FSF GDB(experimental)       |
| Windows/MinGW   | GCC        | GDB       |
| Windows/MSVC      | Microsoft Visual C++ Compiler       | Debugging Tools for Windows/CDB       |