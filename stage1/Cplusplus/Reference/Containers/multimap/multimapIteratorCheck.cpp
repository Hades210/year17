// file : multimapIteratorCheck.cpp
/********************************************************************************************
*	iterator begin() noexcept;
*	const_iterator begin() const noexcept;
*	iterator end() noexcept;
*	const_iterator end() const noexcept;
*	reverse_iterator rbegin() nothrow;
*	const_reverse_iterator rbegin() const nothrow;
*	reverse_iterator rend() nothrow;
*	const_reverse_iterator rend() const nothrow;
*	const_iterator cbegin() const noexcept;
*	const_iterator cend() const noexcept;
*	const_reverse_iterator crbegin() const noexcept;
*	const_reverse_iterator crend() const noexcept;
********************************************************************************************/

#include <iostream>
#include <map>

using namespace std;


int main()
{
	multimap<char,int> mymap1 = {{'x',10},{'x',20},{'y',30}};
	
	multimap<char,int> mymap2;
	mymap2.insert(pair<char,int>('a',35));
	mymap2.insert(pair<char,int>('a',39));
	mymap2.insert(pair<char,int>('b',50));

	multimap<char,int> mymap3;
	mymap3.insert(make_pair('u',39));
	mymap3.insert(make_pair('u',40));
	mymap3.insert(make_pair('v',45));

	multimap<char,int>::iterator it;
	multimap<char,int>::reverse_iterator rit;
	multimap<char,int>::const_iterator cit;
	multimap<char,int>::const_reverse_iterator crt;

	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++\n";
	for(it = mymap1.begin(); it != mymap1.end(); ++ it)
		cout<<it->first<<" : "<<it->second<<"\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++\n";
	for(rit = mymap2.rbegin(); rit != mymap2.rend(); ++ rit)
		cout<<rit->first<<" : "<<rit->second<<"\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++\n";
	for(cit = mymap3.cbegin(); cit != mymap3.cend(); ++ cit)
		cout<<cit->first<<" : "<<cit->second<<"\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++\n";
	for(crt = mymap3.crbegin(); crt != mymap3.crend(); ++ crt)
		cout<<crt->first<<" : "<<crt->second<<"\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++\n";

	return 0;
}
