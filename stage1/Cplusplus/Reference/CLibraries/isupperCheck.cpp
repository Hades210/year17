// file : isupperCheck.cpp
// isupper(int c) to check if c is a uppercase
// char tolower(int c) convert c to corresponding lowercase

#include <cstdio>
#include <cctype>

int main()
{
	int i = 0;
	char c ;
	char str[] = "Test String\n";
	printf("%s",str);

	while(str[i])
	{
		c = str[i];
		if(isupper(c)) c = tolower(c);
		putchar(c);
		i ++;
	}
	return 0;
}
