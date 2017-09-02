# chap05

关联容器依赖特定的排序准则，自动为其元素排序。排序准则以函数形式呈现，用来比较元素值(value)或元素键(key).缺省情况下以operator< 进行比较，不过你也可以提供自己的比较函数，定义出不同的排序规则<br>

通常关联容器由二叉树(binary tree)实作出来。<br>

每一种容器型别都必须提供自己的迭代器，实际上，每一种容器都将其迭代器以嵌套(nested)方式定义于内部。<br>

```
迭代器的种类：

双向迭代器(Bidirectional iterator)
双向迭代器可以双向行进：以递增(increment)运算前进或以递减(decrement)运算后退。


随机存取迭代器(Random access iterator)
随机存取迭代器不但具有双向迭代器的所有属性，还具备随机访问能力。更明确的说，他们提供了“迭代器算术运算”必要的操作符（和一般指针的算术运算，完全对应）。你可以对迭代器增加或减少一个偏移量，处理迭代器之间的距离，或是使用<和>之类的关系运算符来比较。vector,deque,和strings所提供的迭代器都是此类

为了撰写尽可能与容器型别无关的泛型程序代码，最好不要使用随机存取迭代器的特有操作。
```

```
算法
STL算法，并非面向对象思维模式(OOP paradigm)，而是泛型函数式编程思维模式(generic functional programming paradigm). 在面向对象编程(OOP)概念里，数据与操作合为一体。在这里被明确划分开来，再透过特定的接口彼此互动.
```
```
迭代器配接器
Insert Iterators(安插型迭代器)
Stream Iterators (流迭代器)
Reverse Iterators (逆向迭代器)

Inserters可以使算法以安插(insert)方式而非覆写(overwrite)方式运作。包含如下三种:

back_inserter(container)    使用push_back()在容器尾端安插元素，元素排列次序和安插次序相同. 含有push_back()的容器有vector,deque和list.

front_inserter(container)   使用push_front()在容器前端安插元素，元素排列次序和安插次序相反.含有push_front()的容器有deque和list.

inserter(container, pos)    使用insert()在pos位置上安插元素，元素排列次序和安插次序相同。对于关联容器，给出的位置只是一个提示，帮助它确定从什么地方开始搜寻正确的安插位置。

Stream Iterator 是一种用来读写stream的迭代器。他们提供了必要的抽象性，使得来自键盘的输入像是个群集(collection). 你能够从中读取内容，同样道理，你也可以把一个算法的输出结果导向到某个文件或屏幕上。

EOF windows键盘输入ctrl+z Unix (Mac OS)的键盘输入ctrl + d

输入流迭代器(Input stream Iterators)

istream_iterator<string>(cin)
产生一个从标准输入流cin读取数据的stream iterator. 

istream_iterator<string>()
调用istream iterators的default构造函数，产生一个代表"流结束符号"的迭代器，它代表的意义是:你不能再从中读取任何东西.

ostream_iterator<string>(cout,"\n") 会产生一个output stream iterator，第二个参数(可有可无)被用来作为元素之间的分隔符。

Reverse Iterators（逆向迭代器）
所有容器都可以透过成员函数rbegin()和rend()产生出reverse iterators
```
```
更易型算法(指那些会移除remove,重排resort，修改modify元素的算法)用于关联容器上会出现问题。如果更易型算法用于关联式容器身上，会改变某位置上的值，进而破坏其已序(sorted)特性。为了保证这个原则，关联容器的所有迭代器均被声明为指向常量(不变量)。如果更易关联容器中的元素，会导致编译错误.

每一种关联容器都提供用以移除元素的成员函数

list针对所有更易型算法，提供了一些对应的成员函数，用于发挥修改链接的效果
```

```
自定义泛型函数
为了声明有效的迭代器，必须使用容器提供的型别，因为每一种容器都有自己的迭代器。为了写出真正的泛型函数，每一种容器都提供了一些内部的型别定义。除了iterator 和const_iterator，容器还提供了其他（内部定义的）型别，比如元素型别(valuetype)
```
```
判断式(Predicates)
算法有一种特殊的辅助函数叫做predicates(判断式).所谓predicates,就是返回bool值的函数。
包括一元判断式(Unary Predicates)
二元判断式(Binary Predicates)
```
```
仿函数
如果你定义了一个对象，行为像函数，它就可以被当作函数来用.
即重载operator()运算符

仿函数的优点：
仿函数是smart functions
每个仿函数都有自己的型别
仿函数比一般函数速度快
```
```
配接器：bind2nd()的作用，通常是在“只需要单参数”的位置，引入一个二元表达式，并将其运算的结果，作为该单参数的值。

仿函数通常都声明为inline。 某些仿函数可以用来调用集群内的每个元素的成员函数。
mem_fun_ref(&Person::save)

for_each(coll.begin(),coll.end(),mem_fun_ref(&Person::save));
仿函数mem_fun_ref用来调用它所作用的元素的某个成员函数。因此上例就是针对coll内的每一个元素调用Person::save().
```

```
容器元素的条件：

1. 必须可透过copy构造函数进行复制，副本与原本必须相等。
2. 必须可以透过assignment操作符完成赋值动作。
3. 必须可以透过析构函数完成销毁动作。析构函数绝不能被设计为private，也绝不能抛出异常。

* 对序列式容器，元素的default构造函数必须可用
* 对某些动作，必须定义operator== 以执行相等测试。
* 在关联式容器中，元素必须定义出排序准则。缺省情况下是operator <,透过less<>被调用
```

```
Value语意 vs. Reference 语意
所有容器都会建立元素副本，并返回该副本。这意味容器内的元素与你放进去的对象"相等(equal)" 但非"同一(identical)". 如果修改容器中的元素，实际上改变的是副本而不是原先对象。这意味STL容器所提供的是value语意。
```