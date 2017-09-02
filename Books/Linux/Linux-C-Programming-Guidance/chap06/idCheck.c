/*************************************************************************
*  File Name: idCheck.c
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Sat 02 Sep 2017 10:57:53 PM CST
*************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>

void enhancedperms(void);
void normalperms(void);
void tryopen(void);

int ruid,euid;

int main()
{
	ruid = getuid();
	euid = geteuid();
	normalperms();

	if(ruid == euid)
	{
		printf("euid%4d: Warning: this program wasn't marked setuid in the filesystem \n", euid);
		printf("euid%4d: or you running the program at root.\n",euid);
	}

	tryopen();
	enhancedperms();
	normalperms();
	printf("euid%4d: Exiting now.\n",euid);
	return 0;
}

void enhancedperms(void)
{
	if(seteuid(euid) == -1)
	{
		printf("euid%4d: Railed to switch to enhanced permissions%s.\n",euid,sys_errlist[errno]);
		exit(255);
	}
	else
	{
		printf("euid%4d: Switched to enhanced permissions.\n");
	}
}

void normalperms(void)
{
	if(seteuid(ruid) == -1)
	{
		printf("euid%4d: Failed to switch to normal permissions: %s.\n",euid,sys_errlist[errno]);
		exit(255);
	}
	else 
	{
		printf("euid%4d: Switched to normal permissions.\n");
	}
}

void tryopen(void)
{
	char* filename = "/etc/shadow";
	int result;

	if(result = open(filename, O_RDONLY) == -1)
		printf("euid%4d: Opem failed: %s. \n",euid, sys_errlist[errno]);
	else
	{
		printf("euid%4d: Open was successful. \n",euid);
		close(result);
	}
}
