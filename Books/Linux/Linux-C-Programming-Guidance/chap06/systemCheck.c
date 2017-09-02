/*************************************************************************
*  File Name: systemCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Sat 02 Sep 2017 11:15:49 PM CST
*************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int status;
	if((status = system(NULL)) < 0)
	{
		printf("system error!\n");
		exit(0);
	}
	printf("exit status=%d\n",status);
	if((status = system("data")) < 0)
	{
		printf("system error!\n");
		exit(0);
	}

	if((status = system("invalidcommand")) < 0)
	{
		printf("system error!\n");
		exit(0);
	}

	printf("exit status=%d. \n",status);
	if((status = system("who;exit 44")) < 0)
	{
		printf("system error!\n");
		exit(0);
	}
	printf("exit status=%d.\n",status);
	exit(0);
}
