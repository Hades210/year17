/*************************************************************************
*  File Name: execlCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Tue 29 Aug 2017 11:05:50 PM CST
*************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
	pid_t pid;
	if((pid=vfork()) < 0)
	{
		printf("vfork error!\n");
		exit(1);
	}
	else if(pid==0)
	{
		printf("Child process PID: %d.\n",getpid());
		setenv("PS1","CHILD\\$",1);
		printf("Process%4d: calling exec.\n",getpid());
		if(execl("/bin/sh","/bin/sh","execlCheck.sh",NULL)<0)
		{
			printf("Process%4d: execl error!\n",getpid());
			exit(0);
		}
		printf("Process%4d: You should never see this because the child is already gone. \n",getpid());
		printf("Process%4d: The child process is exiting.\n");
	}
	else 
	{
		printf("Parent process PID:%4d.\n",getpid());
		printf("Process%4d: The parent has fork process %d.\n",getpid(),pid);
		printf("Process%4d: The Child has called exec or has exited.\n",getpid());
	}
	return 0;
}
