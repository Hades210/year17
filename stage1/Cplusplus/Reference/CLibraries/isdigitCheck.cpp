// file: isdigitCheck
// isdigit(int c) to check if c is 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// usually used before atoi() function

#include <cstdio>
#include <cstdlib>  // int atoi(const char* str)
#include <cctype>

int main()
{
	char str[]="1789ad";
	int year;

	if(isdigit(str[0]))
	{
		year = atoi(str);
		printf("the year after %d is %d\n",year,year+1);
	}

	return 0;
}
