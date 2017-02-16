// file : ispunctCheck.cpp
// ispunct(int c) to check if c is a punctuation character.

#include <cstdio>
#include <cctype>

int main()
{
	int i = 0;
	int cx = 0;

	char str[] = "Hello, welcome!";
	printf("%s\n",str);

	while(str[i])
	{
		if(ispunct(str[i])) cx ++;
		i ++;
	}
	printf("The setence contains %d punctuation characters.\n",cx);
	return 0;
}
