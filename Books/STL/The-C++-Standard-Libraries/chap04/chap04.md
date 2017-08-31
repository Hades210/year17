# chap04

```
大部分通用工具在C++中，定义于标准头文件<utility>内，某些通用辅助函数被定义于<algorithm>头文件中，但按照STL的定义，他们称不上算法.
```
```
class auto_ptr
一种智能型指针(smart pointer)，帮助程序员防止"被异常抛出时发生资源泄漏".

void f()
{
    ClassA* ptr = new ClassA;

    try {
        ...
    }
    catch(...) {
        delete ptr;
        throw;
    }
    delete ptr;
}
为了在异常发生时处理对象的删除工作，程序代码变得复杂和累赘

如果使用智能型指针，情形就大不相同，智能指针应该保证，无论在何种情形下，只要自己被摧毁，就一定连带释放其所指资源。

#include <memory>
void f()
{
    std::auto_ptr<ClassA> ptr(new ClassA);
    ...
}
不再需要delete和catch.
auto_ptr<>不允许你使用一般指针惯用的赋值(assign)初始化方式，必须直接使用数值来完成初始化。
std::auto_ptr<ClassA> ptr1(new ClassA); // OK
std::auto_ptr<classA> ptr2 = new ClassA; //ERROR

拥有权的转移：
auto_ptr的copy构造函数和assignment操作符，都将对象的拥有权交出去。
拥有权的转移，意味着先前的拥有者失去拥有权,变成null指针，无法在使用。 使用正确的拥有拥有权的指针，这是程序员的责任。

auto_ptr语义本身就包含了拥有权，如果你无法转交你的拥有权，就不要在参数列中使用auto_ptr，也不要以它作为返回值。

const auto_ptr使得无法转移拥有权，减小了"不经意转移拥有权"所带来的危险.

auto_ptr的错误运用
auto_ptr确实解决了一个特定问题，那就是在异常处理过程中的资源遗失问题。

auto_ptr之间不能共享拥有权
一个auto_ptr千万不能指向另一个auto_ptr(或其他对象)所拥有的对象，否则，当第一个指针删除该对象后，另一个指针突然指向了一个已被销毁的对象。

不存在针对array而设计的auto_ptr.
因为auto_ptr是透过delete而非delete[]来释放其所拥有的对象.

auto_ptr绝非一个四海通用的智能型指针
并非任何适用智能型指针的地方，都适用auto_ptr.特别注意的是，它不是引用计数(reference counting)型指针——这种指针保证，如果有一组智能型指针指向同一个对象，那么当且仅当最后一个智能型指针被销毁时，该对象才会被销毁。

auto_ptr不满足STL容器对其元素的要求
因为在拷贝(copy)和赋值(assign)动作之后，原本的auto_ptr会交出拥有权。
请却对不要将auto_ptr作为标准容器的元素。
```

```
数值极限(Numeric Limits)
一般来说，数值型别(Numeric types)的极值是一个与平台相关的特性。C++标准程序是通过template numeric_limits提供这些极值。
传统的C语言所采用的预处理器常数(preprocessor constants).其中整数常数定义于<climits>和<limits.h>, 浮点常数定义于<cfloat>和<float.h>。

使用template,通常是为了对所有型别一次性地撰写出一个通用解决方案。除此之外，你还可以在必要时候以template为每个型别提供共同接口。方法是：不但提供通用性的template,还提供其特化(specialization)版本。numeric_limits就是这项技术的一个典型例子。

通用性的numeric_limits template及其特化版本都被放在<limits>头文件中。

通用性的template,为所有型别提供缺省极值：
template <class T>
class numeric_limits {
    public:
    static const bool is_specialized = false;
    ...
};

各具体型别的极值，由特化版本(specialization)提供
template <> class numeric_limits<int> {
    public:
    static const bool is_specialized = true;

    static T min() throw() {
        return -2147483648;
    }
    static T max() throw() {
        return 2147483647;
    }
    ...
}
```

```
辅助函数
定义于头文件<algorithm>

template <class T>
inline const T& min (const T& a, const T& b) {
    return b < a ? b : a;
}

template <class T>
inline const T& max(const T& a, const T& b) {
    return a < b ? b : a;
}

接收函数或仿函数版本：
template <class T, class Compare>
inline const T& min(const T& a, const T& b, Compare comp) {
    return comp(b,a) ? b : a;
}

template <class T, class Compare>
inline const T& max(const T& a, const T& b, Compare comp) {
    return comp(a,b) ?b: a; 
}
该仿函数，接收两个参数并进行比较：在某个指定规则下，判断第一参数是否小于第二参数，并返回判断结果。


两值交换
其泛型化版本
template <class T>
inline void swap(T& a, T& b) {
    T tmp(a);
    a = b;
    b = tmp;
}

swap()最大优势在于，透过template specialization(模版特化)或function overloading（函数重载),可以为更复杂的型别提供特殊的实作版本.

辅助性的"比较操作符"
有四个template functions 分别定义了 !=, >, <=, >=四个比较操作符。它们都是利用==和<来完成的。这四个函数定义于<utility>中。

namespace rel_ops {
    template <class T>
    inline operator!= (const T& x, const T& y) {
        return !(x == y);
    }

    template <class T>
    inline bool operator> (const T& x, const T& y) {
        return y < x;
    }

    template <class T>
    inline bool operator<= (const T& x, const T& y) {
        return !(y < x)
    }

    template <class T>
    inline bool operator>= (const T& x, const T& y) {
        return !(x < y);
    }
}

只需要定义<和==操作符，加上using namespace std::rel_ops 上诉四个比较操作符就自动获得了定义。

<cstddef>和<cstdlib>对应C的兼容版本，定义了一些常用的常数，宏，型别和函数。

<cstddef>中的定义项
NULL        指针值，0
size_t      一种无正负号的型别，用来表示大小（如元素个数）
ptrdiff_t   带有正负号的型别，用来表示指针之间的距离
offsetof    表示一个成员在struct或union中的偏移量

<cstdlib>中的定义项
exit(int status)        退出程序
EXIT_SUCCESS            正常结束
EXIT_FAILURE            不正常结束
abort()                 退出程序（某些系统上可能导致崩溃）
atexit(void(*function)()) 退出(exit)程序时调用某些函数

exit()和abort()都用来在任意地点终止程序运行，无需返回main().
exit()会销毁所有static对象，清空缓冲区，关闭IO通道，然后终止程序(之前会调用经由atexit()登录的函数)
abort（）会立即终止函数，不做任何清理工作。

这两个函数都不会销毁局部对象，为确保所有局部对象的析构函数获得调用，应该用异常(exception)或正常返回机制，然后由main()离开。
```