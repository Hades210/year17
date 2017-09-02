/*************************************************************************
*  File Name: abortCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Sat 02 Sep 2017 10:38:06 PM CST
*************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

void h_exit(int status);
static void forkerror(void);
static void waiterror(void);

int main()
{
	pid_t pid;
	int status;

	if((pid = fork())< 0)
		atexit(forkerror);
	else if(pid == 0)
		abort();

	if(wait(&status) != pid)
		atexit(waiterror);
	h_exit(status);
	exit(0);
}

void h_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit status=%d.\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal termination, exit status=%d.\n",WTERMSIG(status));
}

void forkerror(void)
{
	printf("fork error!\n");
}

void waiterror(void)
{
	printf("wait error!\n");
}
