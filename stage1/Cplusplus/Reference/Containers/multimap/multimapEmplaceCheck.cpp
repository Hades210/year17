// file : multimapEmplaceCheck.cpp
// template <class... Args>
//	iterator emplace(Args&&... args);
// Return an iterator to the newly inserted element.

#include <iostream>
#include <map>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multimap<string,float> mymap;

	mymap.emplace("apple",1.50);
	mymap.emplace("coffee",2.10);
	mymap.emplace("apple",1.40);

	cout<<"mymap contains:";
	for(auto& x : mymap)
		cout<<"[ "<<x.first<<" : "<<x.second<<" ]";
	cout<<"\n";

	return 0;
}
