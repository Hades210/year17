// file : errnoCheck.cpp
// <cerrno> contains a macro called errno which can be modified by any c library function
// void perror(const char * s) to show the message about errno
// EDOM/ERANGE/EILSEQ

#include <cstdio>
#include <cerrno>
#include <cmath>

int main()
{
	sqrt(-25.0);
	if(errno == EDOM)
		perror("domain error");
	else if (errno == ERANGE)
		perror("range error");
	else if (errno == EILSEQ)
		perror("illegal sequence error");
	else
		perror("other error");
	errno = 0;

	return 0;
}
