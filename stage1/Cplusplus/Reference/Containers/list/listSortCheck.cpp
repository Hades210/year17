// file : listSortCheck.cpp
// void sort();
// template <class Compare>
//  void sort(Compare comp);

#include <iostream>
#include <list>
#include <string>
#include <cctype>

using namespace std;

bool compare_nocase(const string& first, const string& second)
{
	unsigned int i = 0;

	while(i < first.length() && i < second.length())
	{
		if(tolower(first.at(i) ) < tolower(second.at(i)))
			return true;
		else if (tolower(first.at(i)) > tolower(second.at(i)))
			return false;
		++ i;
	}

	return (first.length() < second.length());
}

int main()
{
	list<string> mylist;

	mylist.push_back("Three");
	mylist.push_back("one");
	mylist.push_back("two");

	mylist.sort();

	cout<<"After default sort, mylist :";
	for(auto & x : mylist)
		cout<<"\t"<<x;

	cout<<endl;

	mylist.sort(compare_nocase);
	cout<<"After compare_nocase sort, mylist :";
	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<endl;

	return 0;
}
