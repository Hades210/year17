/*************************************************************************
*  File Name: wait4Check.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Wed 30 Aug 2017 12:11:50 AM CST
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdarg.h>

void waitchildren(int signum);
void h_exit(int status);

int main() 
{
	pid_t pid;
	int status;
	if((pid =fork()) < 0)
	{
		printf("fork error!\n");
		exit(0);
	}
	else if(pid == 0)
	{
		printf("Hello from the child process%4d!\n",getpid());
		setenv("PS1","CHILD\\$",1);
		printf("Process%4d: I'm calling exec. \n",getpid());
		execl("/bin/sh","/bin/sh","execlCheck.sh",NULL);
		printf("Process%4d: You should never see this because the child is already gone.\n",getpid());
	}
	else if(pid!= -1)
	{
		printf("Hello from the parent process%4d!\n",getpid());
		printf("Process%4d: The parent has forked process%d. \n",getpid(),pid);
		printf("Process%4d: The parent is waiting for the child to exit.\n",getpid());
		wait4(pid,&status,0,NULL);
		h_exit(status);
	}
	return 0;
}

void h_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination,exit status=%d. \n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal termination,exit status=%d. \n",WTERMSIG(status));
}
