// file : unordered_setEraseCheck.cpp
/*********************************************************************************************
*	by position(1)		iterator erase(const_iterator position);
*	by key(2)			size_type erase(const key_type& k);
*	range(3)			iterator erase(const_iterator first, const_iterator last);
**********************************************************************************************/
// Versions (1) and (3) return an iterator pointing to the position immediately following the last of the elements erased.
// Version (2) returns the number of elements erased, which in unordered_set containers (that have unique values),
// this is 1 if an element with a value of k existed (and thus was subsequently erased), and zero otherwise.

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_set<string> myset = {"USA","FRANCE","ITALY","JAPAN","CANADA","UK","GERMANY"};

	printInfo("myset",myset);
	myset.erase(myset.begin()); // by position
 	myset.erase("FRANCE");  // by key
	myset.erase(myset.find("JAPAN"),myset.end()); // range

	for(auto& x : myset)
		cout<<x<<"\n";

	return 0;
}

