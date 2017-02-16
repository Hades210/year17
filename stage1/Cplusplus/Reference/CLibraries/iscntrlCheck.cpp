// file: iscntrlCheck.cpp
// iscntrl(int c) to check if c is a control 

#include <cstdio>
#include <cctype>

int main()
{
	int i = 0;
	char str[] = "first line \nsecond line \n";
	printf("%s",str);

	while(!iscntrl(str[i]))
	{
		putchar(str[i]);
		i ++;
	}
	return 0;
}
