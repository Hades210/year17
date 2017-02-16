// file: isblankCheck.cpp
// isblank(int c) to check if c is a blank 
// c++ 11 only

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
		if(isblank(c)) c = '\n';
		putchar(c);
		i ++;
	}
	return 0;
}
