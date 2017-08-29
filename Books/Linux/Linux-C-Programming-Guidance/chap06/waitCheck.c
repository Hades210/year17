/*************************************************************************
*  File Name: waitCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Tue 29 Aug 2017 11:48:09 PM CST
*************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

void h_exit(int status);

int main()
{
	pid_t pid;
	int status;
	if((pid=fork()) < 0)
	{
		printf("fork error!\n");
		exit(0);
	}
	else if(pid == 0)
		exit(7);
	if(wait(&status) != pid)
	{
		printf("wait error!\n");
		exit(0);
	}
	h_exit(status);

	if((pid =fork()) < 0)
	{
		printf("fork error!\n");
		exit(0);
	}
	else if (pid == 0)
		exit(1);
	if(wait(&status) != pid)
	{
		printf("wait error!\n");
		exit(0);
	}
	h_exit(status);

	if((pid = fork()) < 0) 
	{
		printf("fork error!\n");
		exit(0);
	}
	else if (pid == 0)
		;	
	if(wait(&status) != pid)
	{
		printf("wait error!\n");
		exit(0);
	}
	h_exit(status);
	exit(0);
}

void h_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit status=%d. \n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, exit status=%d.\n", WTERMSIG(status));
}
