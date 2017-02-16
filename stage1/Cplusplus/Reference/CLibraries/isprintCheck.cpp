// file : isprintCheck.cpp
// isprint(int c) to check if c is printable

#include <cstdio>
#include <cctype>

int main()
{
	int i = 0;
	char str[] = "first line\nsecond line\n";
	printf("%s",str);

	while(isprint(str[i]))
	{
		putchar(str[i ++]);
	}
	return 0;
}
