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

