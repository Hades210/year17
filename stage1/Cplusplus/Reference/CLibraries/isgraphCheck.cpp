// file: isgraphCheck.cpp
// isgraph(int c) to check if c is a character with graphical representation.
// if c == ' '  return false;


#include <cstdio>
#include <cctype>

int main()
{
	char str[] = "Example for isgraph test";
	int i = 0;

	while(str[i])
	{
		if(isgraph(str[i]))
			putchar(str[i]);
		i ++;
	}

	return 0;
}
