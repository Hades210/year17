// file : unordered_setClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <unordered_set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_set<string> myset = {"beijing","shanghai","shenzhen","guangzhou"};

	printInfo("myset",myset);

	myset.clear();

	myset.insert({"Baidu","Ali","Tecent"});
	printInfo("myset",myset);
	
	return 0;
}
