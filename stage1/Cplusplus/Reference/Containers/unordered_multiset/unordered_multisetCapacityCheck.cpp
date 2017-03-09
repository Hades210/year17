// file : unordered_multisetCapacityCheck.cpp
/**********************************************************************
*	bool empty() const noexcept;
*	size_type size() const noexcept;
*	size_type max_size() const noexcept;
*	size_type max_bucket_count() const noexcept;
**********************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<string> first,second;
	second = {"mom","dad","son","daughter","son"};

	cout<<"first "<<(first.empty() ? "is empty" : "is not empty")<<"\n";
	cout<<"second "<<(second.empty() ? "is empty" : "is not empty") <<"\n";


	cout<<"0. size "<<first.size()<<"\n";
	first = {"house","parking","office"};
	cout<<"1. size "<<first.size()<<"\n";
	first.insert("house");
	cout<<"2. size "<<first.size()<<"\n";
	first.erase("house");
	cout<<"3. size "<<first.size()<<"\n";

	cout<<"max size = "<<first.max_size()<<"\n";
	cout<<"max_bucket_count = "<<first.max_bucket_count()<<"\n";
	cout<<"max_load_factor = "<<first.max_load_factor()<<"\n";
	
	return 0;
}
