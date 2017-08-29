/*************************************************************************
*  File Name: forkCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Tue 29 Aug 2017 10:35:55 PM CST
*************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	if((pid=fork()) < 0)
	{
		printf("fork error!\n");
		exit(1);
	}
	else if (pid == 0)
	{
		printf("Child process is printing.\n");
	}
	else
	{
		printf("Parent process is printing.\n");
	}
	return 0;
}
