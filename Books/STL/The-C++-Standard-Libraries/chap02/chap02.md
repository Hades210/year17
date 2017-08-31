# chap02 

目前template必须定义于头文件中<br>
template 缺省参数可根据前一个（或前一些）参数而定义.
```
关键字typename 被用来做为型别之前的标志符号。

template <class T>
class MyClass {
    typename T::SubType * ptr;
    ...
};
typename指出SubType是class T中定义的一个型别，而不是一个static成员。
SubType成为一个型别的条件是，任何一个用来取代T的型别， 其内部必须提供一个内部型别(inner type)SubType的定义。

MyClass<Q> x;
class Q {
    typedef int SubType;
    ...
};
此时，MyClass<Q>的ptr成员是一个指向int型别的指针.

如果要把一个template中的某个标志符号指定为一种型别，就算是意图明显，typename也不可或缺。

typename还可以在template声明中替代关键字class
```

```
如果采用不含参数的，明确的constructor调用语法，基本型别会被初始化为零。
template <class T>
void f() 
{
    T x = T();
    ...
}
```

```
异常规格(exception specification)来指明某个函数可能抛出哪些异常。
void f() throw (bad_alloc); //f()只可能丢出bad_alloc异常
void f() throw (); f()不抛出任何异常
```
explicit可以禁止"单参数构造函数"被用于自动型别转换。也同样能阻止，以赋值语法进行带有转型操作的初始化<br>

```
新的型别转换操作符
static_cast: 将一个值以符合逻辑的方式转型。利用原值重建一个临时对象，并在设立初始值时使用型别转换。 型别转换，可以是语言内建规则，也可以是程序员自定的转换动作.

dynamic_cast: 将多态型别向下转型为其实际静态型别。 从设计的角度讲，应该在运用多态技术的程序中，避免这种“程序行为取决于具体型别”的写法

class Car; //abstract base class
class Cabriolet : public Car 
{

};
class Limousine : public Car {

};

void f(Car* cp)
{
    Carbriolet* p = dynamic_cast<Cabriolet*>(cp);
    if(p==NULL)
    {
        // did not refer to an object of type Cabriolet.
    }
}

const_cast:
设定或去除型别的常数性，亦可去除volatile修饰词.

reinterpret_cast 重新解释bits含义，由编译器定义

注意: 这些操作符都只接受一个参数
```



