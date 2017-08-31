# chap 03
```
异常类别的头文件
基础类别exception和bad_exception定义于<exception> bad_alloc定义于<new> bad_cast和bad_typeid定义于<typeinfo>.Ios_base::failure定义于<ios>, 其他异常类别定义于<stdexcept>

唯一通用的异常评估手段，大概只有打印一途了：
try {
    ...
}
catch (const exception& e)
{
    cerr<<e.what()<<endl;
}
```

```
配置器(Allocators)
C++标准程序库在许多地方采用特殊对象来处理内存配置和寻址，这样的对象称为配置器(allocator).配置器体现出一种特定的内存模型(memory model),成为一个抽象表征，表现出"内存需求"至"内存低阶调用"的转换.

C++标准程序库定义了一个缺省配置器(default allocator) 如下：
namespace std {
    template <class T>
    class allocator;
}
缺省配置器可在任何“配置器得以被当作参数使用”的地方担任默认值。缺省配置器会执行内存分配和回收的一般性手法，也就是呼叫new和delete操作符。
```

