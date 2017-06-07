# chap 01 Windows 应用程序开发入门

创建的工程类型为Win32应用程序.Win32应用程序的入门是WinMain，而Win32控制台应用程序的入口为main.创建错误的应用程序类型，则会在链接时提示找不到main函数。</br>
右键项目 -> 属性 -> 链接器 -> 系统 -> 子系统 如果是窗口，则是Win32程序，如果是控制台，则是Win32控制台程序</br>

API 是一系列函数、宏、数据类型、数据结构的集合。运行于Windows系统的应用程序可以使用这些操作系统提供接口来完成应用程序需要的功能。</br>

WinMain是程序入口函数，相当于C语言的main函数，定义如下：
```
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

第一个参数hInstance,数据类型HINSTANCE, 此参数表示应用程序本次运行实例的句柄
第二个参数hPrevInstance,数据类型HINSTANCE,表示应用程序之前运行实例的句柄，在实际应用中，此参数始终为NULL
第三个参数lpCmdLine是运行时参数，如在cmd命令行中运行 “start.ext Command Arguments” 
那么lpCmdLine就指向字符串"Command Arguments"，作用与C语言中main函数的参数作用类似。
数据类型LPSTR是Windows API中常用的字符串类型
最后一个参数nCmdShow,数据类型是int,表示应用程序窗口（如果有）的显示状态.

函数返回值int类型
return 0;
```

`Windows.h`是Windows应用程序开发中常用的头文件，在Windows应用程序开发中所使用的很多的数据类型、结构、API接口函数都在Windows.h或Windows.h所包含的其他头文件中进行了声明</br>

`#pragma comment(lib,"User32.lib")`指明将源文件编译生成目标文件(.obj)后，将目标文件链接成可执行文件的过程中需要使用到User32.lib，因为User32.lib中包含了MessageBox的链接信息，如果在链接程序时，调用链接器的参数中指明了链接时需要使用到user32.lib,则该行可以省略。</br>

```
MessageBox函数的原型如下：
int MessageBox(HWND hWnd,LPCTSTR lpText, LPCTSTR lpCaption,UINT uType);

第一个参数hWnd是消息框所属的窗口的句柄，可以设置为NULL.
第二个参数lpText是字符串，表示消息框所显示的消息
第三个参数lpCaption是字符串，表示消息框的标题
第四个参数uType,是消息框的类型。 设置为"MB_OK",意思是消息框包含一个“确定”按钮
```

过去已经发行了的所有windows版本，每一个版本都有一个Platform SDK, Windows系统为应用程序提供了很多的调用接口，如果要使用这些调用接口就需要用于Platform SDK. Platform SDK提供了开发Windows应用程序所必须的头文件，库文件等。</br>

解决方案是指若干工程的集合。一般大型的应用程序，都不是一个可执行文件构成的，可能包含一个exe文件、若干个dll文件等。一个解决方案下可以有零个至多个工程，每个工程可以生成一个可执行文件。 可以为解决方案添加或删除工程</br>

使用命令行编译。可以使用nmake工具对程序进行编译和链接。nmake是一个字符界面程序，通过makefile配置，在使用nmake工具时，需要使用visual studio的命令行。</br>

将makefile文件和start.c文件放到同一目录下，在开始菜单visual studio tools目录下找到visual studio命令提示并运行，切换到start.c和makefile两个文件所在的目录，运行nmake.exe则进行编译链接。</br>

```
start.c
/*头文件*/
#include <Windows.h>
//连接时使用User32.lib
#pragma comment (lib,"User32.lib")
/* ***********************************************
* WinMain
* 功能: Windows应用程序示例
*************************************************/
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 调用API函数MessageBox
	MessageBox(NULL, TEXT("开始学习Windows编程"), TEXT("消息对话框"), MB_OK);
	return 0;
}
```
```
makefile
# Nmake macros for building Windows 32-Bit apps
!include <C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include\Win32.Mak>
OUTDIR = START_BIN
#--------------------Build Rule------------------------------------------------------------
all: $(OUTDIR) $(OUTDIR)\start.exe
#---------- If OUTDIR does not exist, then create directory
$(OUTDIR) :
	if not exist "$(OUTDIR)/$(NULL)" mkdir $(OUTDIR)
$(OUTDIR)\start.obj: start.c
	$(cc) $(cflags) $(cvars) /Gz /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" start.c
$(OUTDIR)\start.exe: $(OUTDIR)\start.obj
	$(link) $(guiflags) -out:$(OUTDIR)\start.exe $(OUTDIR)\start.obj $(conlibs)
#--------------------Clean Rule-------------------------------------------------------------
# Rules for cleaning out those old files
clean:
	$(CLEANUP)
```