// file : setIteratorCheck.cpp
/**********************************************************************
*	iterator begin() noexcept;
*	const_iterator begin() const noexcept;
*	iterator end() noexcept;
*	const_iterator end() const noexcept;
*	reverse_iterator rbegin() noexcept;
*	const_reverse_iterator rbegin() noexcept;
*	reverse_iterator rend() noexcept;
*	const_reverse_iterator rend() noexcept;
*	const_iterator cbegin() const noexcept;
*	const_iterator cend() const noexcept;
*	const_reverse_iterator crbegin() const noexcept;
*	const_reverse_iterator crend() const noexcept;
**********************************************************************/

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int myints[] = {87,35,109,23,93};
	set<int> myset(myints,myints + 5);

	set<int>::iterator it ;
	set<int>::reverse_iterator rit;
	set<int>::const_iterator cit;
	set<int>::const_reverse_iterator crt;

	cout<<"begin--end iterator: ";
	for(it = myset.begin(); it != myset.end(); ++it)
		cout<<*it<<"\t";
	cout<<"\n";

	cout<<"rbegin--rend iterator: ";
	for(rit = myset.rbegin(); rit != myset.rend(); ++rit)
		cout<<*rit<<"\t";
	cout<<"\n";

	cout<<"cbegin--cend iterator: ";
	for(cit = myset.cbegin(); cit != myset.cend(); ++cit)
		cout<<*cit<<"\t";
	cout<<"\n";

	cout<<"crbegin--crend iterator: ";
	for(crt = myset.crbegin(); crt != myset.crend(); ++crt)
		cout<<*crt<<"\t";
	cout<<"\n";
	
	return 0;
}
