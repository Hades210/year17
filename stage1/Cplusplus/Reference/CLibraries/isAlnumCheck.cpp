// file : isAlnumCheck.cpp
// isalnum(int c) to check if c is an alpha or a number

#include <cstdio>
#include <cctype>

int main()
{
	int i = 0;
	char str[] = "c3p0...";

	while(isalnum(str[i])) i++;
	printf("The first %d characters are alpha numeric \n",i);
	return 0;
}
