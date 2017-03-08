// file : unordered_setInsertCheck.cpp
/***********************************************************************************************
*	pair<iterator,bool> insert(const value_type& val);
*	pair<iterator,bool> insert(value_type&& val);
*	iterator insert(const_iterator hint, const value_type& val);
*	iterator insert(const_iterator hint, value_type&& val);
*	template <class InputIterator>
*		void insert(InputIterator first, InputIterator last);
*	void insert(initializer_list<value_type> il);
************************************************************************************************/
// In versions(1) and (2), the function returns a pair object whose first element is an iterator pointing either to the newly
// inserted element in the container or to the element whose key is equivalent and a bool value indicating whether the element  
// was successfully inserted or not.
// In versions(3) and (4), the function returns an iterator pointing either to the newly inserted element in the container or to
// the element whose key is equivalent.
// Version(5) (6) return no value.

#include <iostream>
#include <string>
#include <array>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_set<string> myset = {"yellow","green","blue"};
	array<string,2> myarray = {"black","white"};
	string mystr = "red";

	myset.insert(mystr);	// copy insertion
	myset.insert(mystr + "dish");   // move insertion
	myset.insert(myarray.begin(),myarray.end()); // range insertion
	myset.insert({"purple","orange"});	// initializer_list insertion		 

	printInfo("myset",myset);
	
	return 0;
} 
