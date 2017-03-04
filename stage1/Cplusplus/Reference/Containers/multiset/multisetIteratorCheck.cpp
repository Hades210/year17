// file : multisetIteratorCheck.cpp
/*************************************************************************
*	iterator begin() noexcept;
*	const_iterator begin() const noexcept;
*	iterator end() noexcept;
*	const_iterator end() const noexcept;
*	reverse_iterator rbegin() noexcept;
*	const_reverse_iterator rbegin() const noexcept;
*	reverse_iterator rend() nothrow;
*	const_reverse_iterator rend() const nothrow;
*	const_iterator cbegin() const noexcept;
*	const_iterator cend() const noexcept;
*	const_reverse_iterator crbegin() const noexcept;
*	const_reverse_iterator crend() const noexcept;
*************************************************************************/

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int myints[] = {42,71,71,71,12};
	multiset<int>myset(myints,myints + 5);

	multiset<int>::iterator it;
	multiset<int>::reverse_iterator rit;
	multiset<int>::const_iterator cit;
	multiset<int>::const_reverse_iterator crt;

	for(it = myset.begin(); it != myset.end(); ++it)
		cout<<*it<<"\t";
	cout<<"\n";

	for(rit = myset.rbegin(); rit != myset.rend(); ++ rit)
		cout<<*rit<<"\t";
	cout<<"\n";

	for(cit = myset.cbegin(); cit != myset.cend(); ++cit)
		cout<<*cit<<"\t";
	cout<<"\n";

	for(crt = myset.crbegin(); crt != myset.crend(); ++crt)
		cout<<*crt<<"\t";
	cout<<"\n";

	return 0;
}
