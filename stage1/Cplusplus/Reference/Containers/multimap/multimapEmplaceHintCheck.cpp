// file : multimapEmplaceHintCheck.cpp
// template <class... Args>
//	iterator emplace_hint(const_iterator position, Args&&... args);

#include <iostream>
#include <map>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multimap<string,int> mymap;
	auto it = mymap.end();

	it = mymap.emplace_hint(it,"foo",10);
	mymap.emplace_hint(it,"bar",20);
	mymap.emplace_hint(mymap.end(),"foo",30);


	cout<<"mymap contains:";
	for(auto& x : mymap)
		cout<<"[ "<<x.first<<" : "<<x.second<<" ]";
	cout<<"\n";
	
	return 0;
}
