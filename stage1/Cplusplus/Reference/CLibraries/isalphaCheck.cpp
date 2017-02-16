// file : isalphaCheck.cpp
// isalpha(int c) to check if c is an alphabetic
#include <cstdio>
#include <cctype>

int main()
{
	int i = 0;
	char str[] = "C++";

	while(str[i])
	{
		if(isalpha(str[i])) 
			printf("character %c is an alphabetic\n",str[i]);
		else
			printf("character %c is not an alphabetic\n",str[i]);
		i++;
	}
	return 0;
}
