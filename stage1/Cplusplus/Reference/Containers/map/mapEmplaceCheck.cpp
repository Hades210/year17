// file : mapEmplaceCheck.cpp
// template <class... Args>
//	pair<iterator,bool> emplace(Args&&... args);
// If the function successfully inserts the element (because no equivalent element existed already in the map),
// The function returns a pari of an iterator to the newly inserted element and a value of true.
// Otherwise, it returns an iterator to the equivalent element within the container and a value of false.

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	map<char,int> mymap;
	mymap.emplace('x',100);
	mymap.emplace('y',200);
	mymap.emplace('z',100);

	printInfo("mymap",mymap);

	auto ret = mymap.emplace('x',300);
	if(ret.second == false)
	{
		cout<<"element x already existed";
		cout<<" with a value of "<<ret.first->second<<"\n";
	}

	return 0;
}
