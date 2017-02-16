// file : assertCheck.cpp
// show how to use <cassert>

#include <stdio.h>

// #define NDEBUG if define this macro before including <cassert>, then <cassert will not be included

#include <assert.h>

void print_num(int* myInt) 
{
	assert (myInt != NULL);
	printf("%d\n",*myInt);
}

int main()
{
	int a = 10;
	int* b = NULL;
	int* c = NULL;

	b = &a;

	print_num(b);
	print_num(c);

	return 0;
}
