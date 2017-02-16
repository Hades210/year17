// file : islowerCheck.cpp
// islower(int c) to check if c is a lowercase
// char toupper(int c) convert c to corresponding uppercase

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
		if(islower(c)) c = toupper(c);
		putchar(c);
		i ++;
	}
	return 0;
}
