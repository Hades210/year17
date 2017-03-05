// file : mapIteratorCheck.cpp
/***********************************************************
*	iterator begin() noexcept;
*	const_iterator begin() const noexcept;
*	iterator end() noexcept;
*	const_iterator end() const noexcept;
*	reverse_iterator rbegin() noexcept;
*	const_reverse_iterator rbegin() const noexcept;
*	reverse_iterator rend() noexcept;
*	const_reverse_iterator rend() const noexcept;
*	const_iterator cbegin() const noexcept;
*	const_iterator cend() const noexcept;
*	const_reverse_iterator crbegin() const noexcept;
*	const_reverse_iterator crend() const noexcept;
************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mymap;
	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	map<char,int>::iterator it;
	map<char,int>::reverse_iterator rit;
	map<char,int>::const_iterator cit;
	map<char,int>::const_reverse_iterator crt;

	for(it = mymap.begin(); it != mymap.end(); ++ it)
		cout<<"[ "<<it->first<<" : "<<it->second<<" ]\t";
	cout<<endl;

	for(rit = mymap.rbegin(); rit != mymap.rend(); ++ rit)
		cout<<"[ "<<rit->first<<" : "<<rit->second<<" ]\t";
	cout<<endl;
	

	for(cit = mymap.cbegin(); cit != mymap.cend(); ++ cit)
		cout<<"[ "<<cit->first<<" : "<<cit->second<<" ]\t";
	cout<<endl;

	for(crt = mymap.crbegin(); crt != mymap.crend(); ++ crt)
		cout<<"[ "<<crt->first<<" : "<<crt->second<<" ]\t";
	cout<<endl;
	
	return 0;
}
