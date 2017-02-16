// file : isxdigitCheck.cpp
// isxdigit(int c) to check if c is 0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f,A,B,C,D,E,F
// long int strtol(const char *nptr, char **endptr, int base)
// isxdigit is used to check if the first character in str is a valid hexadecimal digit 
// and therefore a valid candidate to be converted by strtol into an integral value.

#include <cstdio>
#include <cctype>
#include <cstdlib>

int main()
{
	char str[] = "ffff";
	long int num ;
	if(isxdigit(str[0]))
		num = strtol(str,NULL,16);
	printf("%lx:%ld",num,num);
	return 0;
}
