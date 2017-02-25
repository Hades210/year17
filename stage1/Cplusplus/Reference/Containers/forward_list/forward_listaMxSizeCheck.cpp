// file : size_type max_size() const noexcept;

#include <iostream>
#include <string>
#include <sstream>
#include <forward_list>

using namespace std;

int main()
{
	int myint;
	string mystring;
	forward_list <int> mylist;

	cout<<"Enter size: ";
	getline(cin,mystring);
	stringstream(mystring) >> myint;

	if(myint <= mylist.max_size())
	{
		mylist.resize(myint);
		cout<<"resize mylist \n";
	}
	else
		cout<<"That size exceeds the maximum.\n";

	return 0;
}
