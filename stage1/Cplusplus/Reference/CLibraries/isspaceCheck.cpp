// file: isspaceCheck.cpp
// isspace(int c) to check if c is a white-space 

#include <cstdio>
#include <cctype>

int main()
{
	int i = 0;
	char c;
	char str[] = "Example to test isblank\n";
	printf("%s",str);

	while(str[i])
	{
		c = str[i];
		if(isspace(c)) c = '\n';
		putchar(c);
		i ++;
	}
	return 0;
}
