/*************************************************************************
*  File Name: vforkCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Tue 29 Aug 2017 10:45:50 PM CST
*************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	if((pid = vfork()) < 0)
	{
		printf("vfork error!\n");
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
	exit(0);
}
