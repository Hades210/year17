// file : mapOperatorCheck.cpp
/**************************************************************************
*	copy(1)		map& operator= (const map& x);
*	move(2)		map& operator=(map&& x);
*	il(3)		map& operator=(initializer_list<value_type> il);
**************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> first;
	map<char,int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;
	first = map<char,int>();

	cout<<"size of first: "<<first.size()<<"\n";
	cout<<"size of second: "<<second.size()<<"\n";
	
	return 0;
}
