# chapo2

```
动态内存分配函数：
#include <cstdlib>
void* malloc(size_t size);
void* calloc(size_t nmemb, size_t size);

calloc的参数nmemb表示分配的内存空间占的数据项数目，参数size表示每一个数据项的大小，实际分配为nmemb * size大小的内存空间

calloc函数与malloc函数的最大区别是calloc函数将初始化所分配的内存空间，把所有位设置为0
```

```
动态内存释放
#include <cstdlib>
void free(void* ptr);
```

```
调整动态内存的大小
#include <cstdlib>
void* realloc(void*ptr, size_t size);

如果ptr为NULL，则相当于malloc,如果size为0，相当于free.
```

```
分配堆栈
#include <cstdlib>
void* alloca(size_t size);

从进程的栈中分配空间，并且调用alloca的函数返回时，所分配的内存空间自动被释放，很少用
```

```
为了更好利用系统资源，当一块内存在一段时间内未被使用时，内核会将其内容暂时置换到磁盘上。如果不希望内核如此操作，可以使用内存锁定。

#include <sys/types.h>
int mlock(const void* addr, size_t length);
int munlock(void* addr, size_t length);
int mlockall(int flag);
int munlockall(void);

函数mlockall用于一次锁定多个内存页。flag:
MCL_CURRENT: 锁定所有内存页
MCL_FUTURE: 锁定所有为进程地址空间添加的内存页

只有超级用户进程才有权限锁定内存空间或解除内存空间的锁定
```

```
内存映像IO

创建内存映像
#include <sys/types.h>
#include <sys/mman.h>
void* mmap(void* start, size_t length, int prot, int flag, int fd, off_t offset);
start: 通常为NULL
length:内存映像所占内存空间大小（字节为单位）
prot:内存映像的安全属性
flag: 内存映像的标志
fd: 文件描述符   (该文件必须先被打开)
offset: 映射的数据内容距离头文件的偏移量

PROT_EXEC   被映像内存可能含有机器码，可被执行
PROT_NONE   被映像内存不允许访问
PROT_READ   被映像内存可读
PROT_WRITE  被映像内存可写

MAP_FIXWD   若无法在start指定的地址建立内存映像，则出错返回
MAP_PRIVATE 对内存映像所做的改动不反映到外存文件中
MAP_SHARED  对内存映像所做的改动都将被保存到外存文件中

当调用成功时，返回值为指向内存映像起始地址的指针，调用失败，返回值为-1.

撤销内存映像
#include <sys/types.h>
#include <sys/mman.h>
int munmap(void* start, size_t length);
成功返回值为0，失败时，返回值为-1,并将errno设置为相应值

将内存映像写入外存
#include <sys/types.h>
#include <sys/mman.h>
int msync(const void* start, size_t length, int flag);

flag的对应选项
MS_ASYNC    调度一个写操作并返回
MS_INVALIDATE   使映像到相同文件的内存映像无效以便使他们更改为新的数据
MS_SYNC     完成写操作后函数返回

修改内存映像的保护值
#include <sys/types.h>
#include <sys/mman.h>
int protect(const void* addr, size_t length, int prot);

修改内存映像的大小
#include <sys/types.h>
#include <sys/mman.h>
void mremap(void* old_addr, size_t old_length, size_t new_length, unsigned long flag);
```

