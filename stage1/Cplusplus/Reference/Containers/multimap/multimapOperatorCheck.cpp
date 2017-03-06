// file : multimapOperatorCheck.cpp
/*******************************************************************************************************************
*	copy(1)		multimap& operator= (const multimap& x);
*	move(2)		multimap& operator= (multimap&& x);
*	il(3)		multimap& operator= (initializer_list<value_type> il);
*******************************************************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<char,int> foo,bar;

	// foo.insert(pair<char,int> ('x',32));
	// foo.insert(pair<char,int> ('y',64));
	// foo.insert(pair<char,int> ('y',96));
	// foo.insert(pair<char,int> ('z',128));

	foo.insert(make_pair('x',32));
	foo.insert(make_pair('y',64));
	foo.insert(make_pair('y',96));
	foo.insert(make_pair('z',128));

	bar = foo;
	foo = multimap<char,int>();

	cout<<"foo size "<<foo.size()<<"\n";
	cout<<"bar size "<<bar.size()<<"\n";
	return 0;
}
