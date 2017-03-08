// file : unordered_setSwapCheck.cpp
// void swap(unordered_set& ust);

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_set<string> first = {"apple","banana","orange","watermelon"};
	unordered_set<string> second = {"laptop","tv","cellphone","ipad"};
	
	first.swap(second);
	printInfo("first",first);
	printInfo("second",second);
	
	swap(first,second);
	printInfo("first",first);
	printInfo("second",second);
	
	return 0;
}
