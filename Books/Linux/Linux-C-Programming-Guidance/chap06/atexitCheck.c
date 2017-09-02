/*************************************************************************
*  File Name: atexitCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Sat 02 Sep 2017 10:22:47 PM CST
*************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

void forkerror(void);
void execerror(void);


int main()
{
	pid_t pid;
	if((pid = vfork())< 0)
		atexit(forkerror);
	else if (pid == 0)
	{
		printf("Child process PID: %d. \n",getpid());
		setenv("PS1","CHILE\\$",1);
		printf("Process%4d: calling exec. \n",getpid());

		if(execl("/bin/sh","/bin/sh","execlChecki.sh",NULL) < 0) {
			printf("error!!!!!!!!!!!!!!!!!!!!!\n");
			atexit(execerror);
		}
		printf("Process%4d: You should never see this because the child is already gone. \n",getpid());
		printf("Process%4d: The child process is exiting...\n",getpid());
	}
	else
	{
		printf("Parent process PID:%4d. \n",getpid());
		printf("Process%4d: The parent has fork process %d.\n",getpid(),pid);
		printf("Process%4d: The child has called exec or has exited.\n",getpid());
	}
	return 0;
}

void forkerror(void)
{
	printf("fork error!\n");
	exit(1);
}

void execerror(void)
{
	printf("exec error!\n");
	exit(1);
}
