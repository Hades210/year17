# chap01 Object Lessons

## 关于3D点的几种实现方式

### 1 C 结构体方式

```
typedef struct point3d
{
    float x;
    float y;
    float z;
} Point3d;

欲打印一个Point3d,就得到一个这样的函数
void Point3d_print(const Point3d* pd)
{
    printf("(%g, %g, %g )",pd->x, pd->y, pd->z);
}

或者更有效率些，就定义一个宏
#define Point3d_print(pd) \
    printf("(%g, %g, %g )", pd->x, pd->y, pd->z);

同样道理，某个点的特定坐标值可以直接存取
Point3d pt;
pt.x = 0.0;

也可以经由一个前置处理宏来完成
#define X(p, xval) (p.x) = (xval);
...
X(pt, 0.0);

```

### 2 C++ ADT来实现

```
class Point3d
{
public:
    Point3d(float x = 0.0, float y = 0.0, float z = 0.0) 
        : _x(x), _y(y), _z(z) {}
    
    float x() {return _x;}
    float y() {return _y;}
    float z() {return _z;}

    void x(float xval) { _x = xval;}
    void y(float yval) { _y = yval;}
    void z(float zval) { _z = zval;}

    // ... etc ...

private:
    float _x;
    float _y;
    float _z;
};

inline ostream& operator<< (ostream& os, const Point3d & pt)
{
    os << "( "<<pt.x()<<", "<<pt.y()<<", "<<pt.z()<<" )";
}

```

### 3 以一个双层或三层的class体系完成
```
class Point
{
public:
    Point(float x = 0.0) : _x(x) {}

    float x() {return _x;}
    void x(float xval) {_x = xval;}

    // ...etc...
protected:
    float _x;
};

class Point2d : public Point 
{
public:
    Point2d (float x = 0.0, float y = 0.0) : Point(x), _y(y) {}

    float y() {return _y;}
    void y(float yval) {_y = yval;}

    // ... etc ...
protected:
     float _y;
};

class Point3d : public Point2d
{
public:
    Point3d (float x = 0.0, float y = 0.0, float z = 0.0) : Point2d(x,y), _z(z) {}

    float z() {return _z;}
    void z(float zval) {_z = zval;}

    // ...etc...
protected:
    float _z;
}
```

### 4 使用模版类

```
template <class type>
class Point3d
{
public:
    Point3d(type x = 0.0, type y = 0.0, type z = 0.0) 
        : _x(x), _y(y), _z(z) {}

    type x() {return _x;}
    void x(type xval) {_x = xval;}
    type y() {return _y;}
    void y(type yval) {_y = yval;}
    type z() {return _z;}
    void z(type zval) {_z = zval;}

    // ... etc ...
private:
    type _x;
    type _y;
    type _z;
};
```

### 5 坐标类型与坐标数目都参数化
```
template <class type, int dim>
class Point
{
public:
    Point();
    Point(type coords[dim])
    {
        for(int index = 0; index < dim; ++ index)
            _coords[index] = coords[index];
    }

    type& operator[] (int index) 
    {
        assert( index < dim && index >= 0);
        return _coords[index];
    }

    type operator[] (int index) const 
    {
        assert( index < dim && index >= 0);
        return _coords[index];
    }

    // ... etc ...
private:
    type _coords[dim];
};

inline template <class type, int dim>
ostream& ostream << (ostream& os, const Point<type, dim>& pt)
{
    os<<"( ";
    for(int ix = 0; ix < dim -1; ++ ix)
        os<<pt[ix]<<", ";
    os<<pt[dim -1];
    os<<" )";
}

```

## 加上封装后的布局成本(Layout Costs for Adding Encapsulation)

member functions虽然含在class的声明之内，却不出现在object之中。每一个non-inline member function只会诞生一个函数实体。至于每一个“拥有零个或一个定义”的inline function则会在其每一个使用者（模块）身上产生一个函数实体。</br>

封装性质，并未带来任何空间或执行期间的不良回应，你即将看到，C++在布局以及存取时间上主要的额外负担是由virtual引起。</br>

`virtual function 机制` 用以支持一个有效率的“执行期绑定”(runtime binding)</br>
`virtual base class` 用以实现“多次出现在继承体系中的base class,有一个单一而被共享的实体”</br>

此外，还有一些多重继承下去的额外负担，发生在“一个derived class 和其第二或后继之base class的转换”，然而，一般言之，并没有什么天生的理由说C++程序一定比其C兄弟庞大或迟缓</br>

## C++ 对象模型（The C++ Object Model）

在C++中，有两种class data members: static 和nonstatic, 以及三种class member functions: static, nonstatic 和virtual</br>

比如：
```
class Point
{
public:
    Point(float xval);
    virtual ~Point();

    float x() const;
    static int PointCount();

protected:
    virtual ostream& print(ostream& os) const;

    float _x;
    static int _point_count;
};

如何在机器中表现class Point 呢?
```

### 简单对象模型（ A Simple Object Model）
它为了尽量减低C++编译器的设计复杂度而开发出来的，陪上的则是空间和执行期的效率。在这个简单模型中，一个object是一系列的slots,每一个slot指向一个members。Members按其声明次序，各被指定一个slot.每一个data member或function member都有自己的一个slot.</br>
![Simple Object Model](https://github.com/Hades210/year17/blob/master/Images/Inside_The_C++_Object_Model/1-1.PNG)</br>
在这个简单模型中，members本身并不放在object之中。只有"指向member的指针"才放在object内，这么做可以避免"members有不同的类型，因而需要不同的存储空间"所招致的问题。</br>
这个模型并没有被应用于实际产品上，不过关于索引或slot数目的观念，倒是被应用到C++的"指向成员的指针(pointer-to-member)观念之中。</br>

### 表格驱动对象模型(A Table-driven Object Model)

为了对所有classes的所有objects都有一致的表达方式，另一种对象模型是把所有与members相关的信息抽出来，放在一个data member table和一个member function table之中，class object本身则内含指向这两个表格的指针。Member function table是一系列的slots,每一个slot指出一个member function; Data member table 则直接含有data 本身。</br>
![Table Driven Object Model](https://github.com/Hades210/year17/blob/master/Images/Inside_The_C++_Object_Model/1-2.PNG)</br>
这个模型也没有实际应用于真正的C++编译器，但member function table这个观念却成为支持virtual functions的一个有效方案</br>

### C++ 对象模型（ The C++ Object Model）

Stroustrup当初设计的C++对象模型，是从简单对象模型派生而来的，并对内存空间和存取时间做了优化。在此模型中，Nonstatic data members被配置于每一个class object之内，static data members则被存放在所有的class object之外。static和nonstatic function members也被放在所有的class object之外. Virtual functions 则以两个步骤支持之：</br>
1. 每一个class产生出一堆指向virtual functions的指针，放在表格之中。这个表格被称为virtual table (vtbl)</br>
2. 每一个class object 被添加一个指针，指向相关的virtual table.通常这个指针被称为vptr. vptr的设定（setting）和重置(resetting)都由每一个class的constructor、destructor和copy assignment运算符自动完成。每一个class所关联的type_info object(用以支持runtime type identification RTTI)也经由virtual table被指出来，通常是放在表格的第一个slot处</br>
![C++ Object Model](https://github.com/Hades210/year17/blob/master/Images/Inside_The_C++_Object_Model/1-3.PNG)</br>
这个模型的主要优点在于它的空间和存取时间的效率；主要的缺点则是，如果应用程序代码本身未曾改变，但所用到的class objects的nonstatic data members 有所修改（可能是增加、移除或更改），那么那些应用程序代码同样得重新编译。</br>

## 加上继承(Adding Inheritance)

C++支持单一继承:
```
class Library_materials{...};
class Book : public Library_materials {...};
class Rental_book : public Book {...};
```
C++也支持多重继承:
```
class iostream : public istream, public ostream {...};
```
甚至，继承关系也可以指定为虚拟(virtual,也就是共享的意思):
```
class istream : virtual public ios {...};
class ostream : virtual public ios {...};
```

在虚拟继承的情况下，base class 不管在继承串链中被派生(derived)多少次，永远只会存在一个实体(称为subobject)</br>

一个derived class 如何在本质上model其base class 的实体？</br>

C++最初采用的继承模型并不运用任何间接性：base class subobject的data members被直接放置于derived class object中。这提供了对base class members最紧凑而且最有效的存取。缺点是：base class members的任何改变，包括增加、移除或改变类型等等，都使得所有用到此base class或其derived class之object者必须重新编译</br>

自C++2.0起才新导入的virtual base class,需要一些间接的base class表现方法。virtual base class 的原始模型是在class object中为每一个有关联的virtual base class 加上一个指针，其他演化出来的模型则若不是导入一个virtual base class table,就是扩充原已存在的virtual table,以便维护每一个virtual base class的位置</br>

## 对象模型如何影响程序(How the Object Model Effects Programs)

不同的对象模型，会导致“现有的程序代码必须修改”以及“必须加入新的程序代码”两个结果</br>

比如： class X定义了一个copy constructor, 一个virtual destructor,和一个virtual function foo:
```
X foobar()
{
    X xx;
    X *px = new X;

    // foo() 是一个virtual function
    xx.foo();
    px->foo();

    delete px;
    return xx;
}
```

这个函数有可能内部被转化为:
```
// 可能的内部转换结果
// 虚拟C++码

void foobar(X &_result)
{
    // 构造_result
    // _result 用来取代 local xx ...
    _result.X::X();

    //扩展X* px = new X;
    px = _new(sizeof(X));
    if(px != 0)
        px->X::X();
    
    //扩展xx.foo() 但不使用virtual机制
    //以_result取代xx
    foo(&_result);

    //使用virtual机制扩展px->foo()
    (*px->vtbl[2])(px)

    //扩展delete px;
    if(px != 0)
    {
        (*px->vtbl[1])(px); //destructor
        _delete(px);
    }

    //不需使用named return statement
    //不需要摧毁local object xx
    return;
}
```
![code transfer](https://github.com/Hades210/year17/blob/master/Images/Inside_The_C++_Object_Model/1-4.PNG)</br>

## 关键词所带来的差异(A Keyword Distinction)
如果不是为了努力维护与C之间的兼容性，C++远可以比现在更简单些。</br>

## 对象的差异(An Object Distinction)

C++程序设计模型直接支持三种porgramming paradigms(程序设计典范)</br>
1. 程序模型(procedural model)，就像C一样，C++当然也支持它.</br>
```
字符串处理的例子
char boy[] = "Danny";
char *p_son;
...
p_son = new char[strlen(boy) + 1];
strcpy(p_son,boy);
...
if(!strcmp(p_son,boy))
    take_to_disneyland(boy);
```
2. 抽象数据类型模型(abstract data type model, ADT).</br>
```
所谓的抽象，是和一组表达式(public接口)一起提供，而其运算定义仍然隐而未明。
string girl = "Anna";
string daughter;
...
// string::operator=();
daughter = girl;
...
// string::operator==();
if(girl == daughter)
    take_to_disneyland(girl);
```
3. 面向对象模型(object-oriented model).</br>
```
在此模型中有一些彼此相关的类型，通过一个抽象的base class（用以提供共通接口）被封装起来。

void check_in(Library_materials * pmat)
{
    if(pmat->late())
        pmat->fine();
    pmat->check_in();

    if(Lender* plend = pmat->reserved())
        pmat->notify(plend);
}
```
纯粹以一种paradigm写程序，有助于整体行为的良好稳固</br>

需要多少内存才能够表现一个class object? 一般而言要有：
其 nonstatic data members的总和大小</br>
加上任何由于alignment(译注)的需求而填补(padding)上去的空间(可能存在于members之间，也可能存在于集合体边界)</br>
```
alignment就是将数值调整到某数的倍数，在32位计算机上，通常alignment为4bytes(32位)，以使bus的“运输量”达到最高效率
```
加上为了支持virtual而由内部产生的任何额外负担(overhead)</br>

## 指针的类型(The Type of a Pointer)
指向不同类型之各指针间的差异，既不再其指针表示法不同，也不再其内容（代表一个地址）不同，而是在其所寻址出来的object类型不同，“指针类型”会教导编译器如何解释某个特定地址中的内存内容及其大小</br>
转型(cast)其实是一种编译器指令，大部分情况下它并不改变一个指针所含的真正地址，它只影响“被指出之内存的大小和其内容”的解释方式</br>

在弹性(OO)和效率(OB)之间常常存在着取与舍，一个人在能够有效选择其一之前，必须先清楚了解两者的行为和应用领域的需求</br>
