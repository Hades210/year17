# chap06

```
进程的创建

1.派生进程
#include <unistd.h>
pid_t fork(void);
pid_t vfork(void);

调用fork时，系统将创建一个与当前进程相同的新的进程，称为子进程。子进程是父进程的一个拷贝，但是同父进程使用不同的数据段和堆栈段。
父进程和子进程的运行无关。父进程先返回或子进程先返回的情况都有可能发生。
fork调用将执行两次返回，它将从父进程和子进程中分别返回。从父进程返回时的返回值是子进程的PID,从子进程返回时返回值为0,并且返回之后，都将执行fork以后的语句，调用出错时，返回值为-1,并将errno设置为相应值.

调用vfork，不完全复制父进程的数据段，而是和父进程共享数据段。调用vfork后，父进程被挂起，子进程运行完exec函数族的函数或调用exit时解除父进程的挂起状态。

2.创建执行其他程序的进程
exec族函数：
#include <unistd.h>
int execl(const char* pathname, const char* arg, ...);
int execlp(const char* filename, const char* arg, ...);
int execle(const char* pathname, const char* arg, ..., char* const envp[]);
int execv(const char* pathname, char* const argv[]);
int execvp(const char* filename, char* const argv[]);
int execve(const char* pathname, char* const argv[], char* const envp[]);

函数族名字中含有字母l的函数，其参数个数不定。其参数有所调用程序的命令行参数列表组成，最后一个NULL表示结束
函数名字中含有字母v的函数，使用一个字符串数组指针argv指向参数列表，这一字符串数组也以NULL结束
函数名中含有字母p的函数可以自动在环境变量PATH指定的路径中搜索要执行的程序。它的第一个参数filename表示可执行函数的文件名，而其他函数pathname为路径名，建议使用绝对路径而避免使用相对路径
函数名中含有e的函数，多了一个envp参数，用于制定环境变量。其他函数则是接收当前环境变量.

3.Linux系统特有的调用
#include <sched.h>
int __clone(int(*fn)(void* arg), void* child_stack, int flags, void* arg);
fn:函数指针，指向要执行的函数
child_stack：子进程堆栈段的指针
flags:不同继承内容的标识
arg:指向存放要传递给所调用程序的参数的缓冲区.

flags标志
CLONE_VM        继承父进程的虚拟存储器属性
CLONE_FS        继承父进程根目录，当前目录和umask
CLONE_FILES     继承父进程的文件描述符
CLONE_PID       继承父进程的文件锁，进程号及时间片
CLONE_SIGHAND   继承父进程的信号处理程序
```

```
进程等待
当一个进程结束时，Linux系统将产生一个SIGCHLD信号通知父进程，父进程未查询到子进程结束原因时，子进程虽然停止了，但并未完全结束。此时这一进程被称为僵尸进程(zombie process),这时处理方法之一是使用进程等待的系统调用wait和waitpid.

#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int* status);
pid_t waitpid(pid_t pid, int* status, int options);

wait调用专用于等待子进程，当子进程结束时，将子进程结束状态字存放在status中，当调用wait时，父进程被挂起，直至该进程的一个子进程结束时，该调用返回。调用成功，返回值为被置于等待状态的进程的PID,调用失败，返回-1.

waitpid 用来等待指定的进程。pid用用指定所等待的进程，参数option用于指定进程所做的操作。

option 取值
0               进程挂起等待其结束
WNOHANG         不使进程挂起而立刻返回
WUNTRACED       如果进程已结束，则返回

pid取值
pid> 0          等待进程ID为pid所指定值的子进程
pid= 0          等待进程组ID等于发出调用进程的进程组ID的子进程
pid= -1         等待所有子进程，等价于wait调用
pid< -1         等待进程组ID为pid的绝对值的子进程


#define _USE_BSD
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>

pid_t wait3(int* status, int options, struct rusage* rusage);
pid_t wait4(pid_t pid, int* status, int options, struct rusage* rusage);
rusage是一个结构指针，调用这两个函数时，如果rusage不为NULL，则关于子进程执行时的相关信息将被写入该指针指向的缓冲区内.

```
```
进程的终止
#include <stdlib.h>
void exit(int status);
int atexit(void(*function)(void));
int on_exit(void(*function)(int,void*),void *arg);
void abort(void);

#include <unistd.h>
void _exit(int status);

#include <assert.h>
void assert(int expression);

exit函数是标准C中提供的函数，它将关闭所有被该进程打开的文件描述符
atexit函数用于注册一个不带参数也没有返回值的函数以供程序正常退出时被调用.成功返回0，失败返回-1，并设置errno为相应值
on_exit函数作用与atexit函数十分相似。它注册的函数有参数。成功返回0,失败返回-1,并设置errno为相应值
abort产生Linux信号，SIGABRT
_exit 是为了关闭一些Linux下特有的退出句柄.
assert 宏，计算参数表达式的值，为0，则调用abort.
```

```
用户标识符
获取
#include <unistd.h>
#include <sys/types.h>
uid_t getuid(void);     实际用户标识符
gid_t getgid(void);     实际组标识符
uid_t geteuid(void);    有效用户标识符
gid_t getegid(void);    有效组标识符

修改
#include <unistd.h>
#include <sys/types.h>
int setuid(uid_t uid);
int setgid(gid_t gid);
int seteuid(uid_t euid);
int setegid(gid_t egid);
int setreuid(uid_t ruid, uid_t euid);
int setregid(gid_t rgid, gid_t egid);
int setfsuid(uid_t fsuid);
int setfsgid(gid_t fsgid);
```
```
system函数
#include <stdlib.h>
int system(const char* cmdstring);
执行system函数时，它将调用fork，exec,和waitpid等函数.
```

```
进程组
#include <sys/types.h>
#include <unistd.h>
pid_t getpgrp(void); //获得进程组号
int setpgid(pid_t pid, pid_t pgid); //当pid == pgid表示创建新的进程组，当pgid是一个存在的进程组ID，表示将pid加入该进程组

在进程组中的各个进程中，有一个特别的进程leader,进程leader的进程ID和它所在的进程组ID一致。

```
```
时间片的分配

调度策略和参数
#include <sched.h>
int sched_setscheduler(pid_t pid, int policy, const struct sched_param* param);
int sched_getscheduler(pid_t pid);

policy 表示所设置的调度策略，取值如下:
SCHED_OTHER: 默认调度策略，通常方法分配时间片
SCHED_FIFO: 先进先出，可以抢占SCHE_OTHER。只能被优先级比它高的抢占
SCHED_RR: 轮换规则，实时分配时间片,可以抢占SCHE_OTHER的进程。使用SCHED_RR的进程在需要与其他进程共享时间片时可以被相同优先级的进程抢占，但errno将被设置为相应值.

优先级设定
静态优先级高的进程会抢占静态优先级低的进程。对静态优先级为0的进程将依照其动态优先级来分配运行时间。优先级的值越小，优先权越高。

#include <unistd.h>
int nice(int inc); 
#include <sys/time.h>
#include<sys/resource.h>
int setpriority(int which, int who, int prio);
int getpriority(int which, int who);
#include <sched.h>
int sched_set_priority_max(int policy);
int sched_set_priority_min(int policy);

函数nice改变进程的动态优先级。调用此函数的过程，其优先级将被加上参数inc。inc > 0 优先级降低， inc < 0 优先级升高，只有超级用户才可以设置inc < 0.

getpriority和setpriority设获取和置进程动态优先级。
which 取值
PRIO_PROECSS       设置进程动态优先级
PRIO_PGRP          设置进程组动态优先级
PRIO_USER          设置用户动态优先级

参数prio取值介于-20~20之间

调用getpriority函数时，返回值是进程的优先级，而优先级可能为-1，因此调用前将errno清除，调用完毕后，检查errno是否成功.

sched_set_priority_max和sched_set_priority_min分别用于获取由参数policy所指定的调度策略下优先级的最大值和最小值.
```
```
进程的同步
文件锁定、信号、信号量、管道(即FIFO)以及套接字.其中文件锁定和信号量是专用于进程间同步的，其他几个方法是进程间通信的，也可以用于完成进程间的同步操作.
```

```
线程

线程的创建
#include <pthread.h>
int pthread_create(pthread_t * thread, pthread_attr_t * attr, void* (*start_routine)(void*), void* arg);
pthread_create用于创建一个新的线程并将其标识符放入参数thread指向的新线程中。参数attr是一个属性对象的指针，用于设置要执行的线程属性。此属性对象由函数pthread_attr_init()生成。参数start_routine指向该线程要调用额程序的函数指针。参数arg用于存放要传递给所调用的函数的参数.

线程属性的设置
#include <pthread.h>
int pthread_attr_init(pthread_attr_t * attr);
int pthread_attr_destroy(pthread_attr_t * attr);
int pthread_attr_setdetachstate(pthread_attr_t * attr, int detachstate);
int pthread_attr_getdetachstate(const pthread_attr_t* attr, int detachstate);
int pthread_attr_setschedpolicy(pthread_attr_t* attr, int policy);
int pthread_attr_getschedpolicy(const pthread_attr_t* attr, int* policy);
int pthread_attr_setschedparam(pthread_attr_t* attr, const struct sched_param* param);
int pthread_attr_getschedparam(const pthread_attr_t* attr, const struct sched_param * param);
int pthread_attr_setinheritsched(pthread_attr_t* attr, int inherit);
int pthread_attr_getinheritsched(const pthread_attr_t * attr, int * inherit);
int pthread_attr_setscope(pthread_attr_t* attr, int scope);
int pthread_attr_getscope(const pthread_attr_t * attr, int scope);
int pthread_setschedparam(pthread_t target_thread, int policy, const struct sched_param* param);
int pthread_getschedparam(pthread_t target_thread, int* policy, struct sched_param * param);

系统的默认设置为：
detachstate = PTHREAD_CREATE_JOINABLE
schedpolicy = SCHED_OTHER
inheritsched = PTHREAD_EXPLICIT_SCHED
scope = PTHREAD_SCOPE_SYSTEM

线程属性表
detachstate        PTHREAD_CREATE_JOINABLE      可连接状态
                   PTHREAD_CREATE_DETACHED      分离状态
schedpolicy        SCHED_OTHER                  普通，非实时
                   SCHED_RR                     实时，轮换
                   SCHED_FIFO                   实时，先进先出
schedparam         由调度策略指定
inheritsched       PTHREAD_EXPLICIT_SCHED       由schedpolicy和schedparam设置
                   PTHREAD_INHERIT_SCHED        从父进程继承
scope              PTHREAD_SCOPE_SYSTEM         每个线程占用一个系统时间片


线程结束
#include <pthread.h>
void pthread_exit(void* retval);

线程的挂起
#include <pthread.h>
int pthread_join(pthread_t th, void** thread_return);

pthread_join()的调用者将挂起并等待th线程的终止.一个线程仅允许唯一的另一个线程使用pthread_join()等待它的终止，并且被等待的线程应该处于可join状态，即非DETACHED（分离）状态。

用户可以挂起一个线程直至某种条件得到满足。
#include <pthread.h>
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int pthread_cond_init(pthread_cond_t* cond, pthread_condattr_t* cond_attr);
int pthread_cond_destroy(pthread_cond_t* cond);
int pthread_cond_signal(pthread_cond_t* cond);
int pthread_cond_broadcast(pthread_cond_t* cond);
int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex);
int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespce * abstime);

取消线程:当前线程调用这些函数来取消另一个线程
#include <pthread.h>
int pthread_cancel(pthread_t thread);
int pthread_setcancelstate(int type, int* oldtype);
int pthread_setcanceltype(int type, int* oldtype);
void pthread_testcancel(void);

互斥
#include <pthread.h>
pthread_mutex_t fastmutex = PTHREAD_MUTEX_INITEALIZER;
pthread_mutex_t recmutex = PTHREAD_RECURSIVE_MUTEX_INITEALIZER_NP;
pthread_mutex_t errchkmutex = PTHREAD_ERRORCHECK_MUTEX_INITEALIZER_NP;
int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* mutexattr); //构造
int pthread_mutex_destroy(pthread_mutex_t* mutex); //取消一个互斥
int pthread_mutex_lock(pthread_mutex_t* mutex); //上锁
int pthread_mutex_trylock(pthread_mutex_t* mutex); // 尝试上锁，如果锁已经被占据时返回EBUSY而不是挂起
int pthread_mutex_unlock(pthread_mutex_t* mutex); //互斥解锁

```
