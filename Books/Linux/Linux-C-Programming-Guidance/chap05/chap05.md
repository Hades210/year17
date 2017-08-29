# chap 05
`gdb filename`:调试程序<br>
gdb可以分析崩溃程序产生的core文件，为了使gdb能够正常的工作，必须使写好的程序在编译时包含调试信息，使用`gcc -g`<br>

设置断点并调试<br>
`break main`:在main函数第一个非简单赋值语句处<br>
`break 行号`<br>
`run`执行，并停在断点处
`step / s`单步执行
```
print 命令：

print表达式
$n表示第n个print命令
$$n表示从当前编号倒着数的第n+1个print命令

print 变量=表达式

print 开始表达式@要打印的连续内存空间的大小
```

`display 要显示值的表达式`<br>
`next命令`：不需要进入函数内部跟踪，逐函数执行<br>
`quit` 退出gdb<br>
`finish`退出调试<br>

```
x/format address
format指定了显示单元的个数，后面是显示内存的方式
x/2c 0x120100fa0

prinf
printf"%2.2s\n", (char*)0x120100fa0
%2.2s 第一个2表示最多输出2个字符，第二个2表示输出从0x120100fa0开始的两个字符

set 修改变量的值
```
```
设置断点的方式
break test.c: 21 在文件test.c 第21行设置

break printmessage在函数printmessage开始位置设置断点

使用continue/cont恢复程序的运行 
```

```
条件断点：
condition 1 svalues[counter]->checksum > 700
条件为真时起作用 1是断点的号码

临时断点
tbreak 行号
相当于
break 41
enable delete 1 (产生一个断点，并在断点被激活后删除)

enable 断点编号 多个时用空格键隔开
disable 断点编号

delete 断点编号或表达式 清除断点或自动表达式的命令

clear 要清除的断点在的行号

```

`watch 表达式`：使用观察窗口<br>

```
查看栈信息
backtrace/bt 打印当前函数调用栈的所有信息
backtrace n / bt n 打印栈顶n层的栈信息
backtrace -n / bt -n 打印栈底n层的栈信息

frame n / f n n从0开始，0表示栈顶 （切换当前栈）

up n 表示向栈底方向移动n层，因为栈底在高地址区域，栈顶在低地址区域
down n 表示向栈顶移动n层

查看当前栈层信息
frame / f
info frame / info f (信息更详细)
info args 当前函数的参数名及值
info locals 当前函数中所有局部变量及值
info catcg 当前函数中的异常处理信息

```

```
查看源代码
set listsize count 设置一次显示代码的行数
show listsize 查看当前listsize的设置

list + 参数
linenum : 行号
+offset 当前行正向偏移量
-offset 当前行负向偏移量
filename:linenum: 哪个文件哪一行
function: 函数名
filename:function 哪个文件的哪个函数
*address 程序运行时的语句在内存中的地址
```

```
搜索源代码
forward-search regex
search regex

reverse-search regex 
```
```
指定源文件的路径
directory 
dir 
多个路径时，使用:(UNIX)或;(windows)

清除自定义源文件搜索路径信息directory
显示定义了的源文件搜索路径 show directories
```

```
info line + 行号 ，函数名 ， 文件名:行号, 文件名:函数名 等，查看所指定的源代码在运行时的内存地址

disassemble 查看源程序当前执行的机器码。 
disassemble func 查看func的汇编代码

```

```
int* array = (int*) malloc(len*sizeof(int));

p *array@len查看数组
如果是静态数组，print 数组名就可以

x 十六进制 d 十进制 u 十进制无符号 o 八进制 t 二进制 a 十六进制 c 字符格式 f 浮点数格式


x /n,f,u addr
n:正整数，表示显示内存的长度
f：显示的格式，如果地址所指的是字符串，格式可以是s,如果是指令地址，格式可以是i
u: 从当前地址往后请求的字节数，读取指定字节，并把其当作一个值取出来
```
```
跳转执行
jump linespace
jump address
最好只在同一个函数中进行跳转，因为jump命令不会改变当前程序栈中的内容，所以，跨越函数有可能导致奇怪的错误、
```
```
产生信号量
signal 1~15

强制函数返回
return 
return exp 该表达式值会被当作函数的返回值

强制调用函数
call expr

```

```
core dump分析
程序崩溃时，Linux会创建一个core文件，程序结束后，利用这个文件中的信息，再使用gdb,就知道程序崩溃时正在做些什么。

ulimit -a 查看core file size 大小 为0（默认）不会生成core文件
ulimit -c unlimited (获取使用core dump的权限)

gdb test core加载进gdb
异常时，查看bt 然后跳转到某一层去详细查找问题 frame 

```


