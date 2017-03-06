// file : multimapCapacityCheck.cpp
// bool empty() const noexcept;
// size_type size() const noexcept;
// size_type max_size() const noexcept;

#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<char,int> mymap;
	mymap.insert(make_pair('a',10));
	mymap.insert(make_pair('a',15));
	mymap.insert(make_pair('b',20));
	mymap.insert(make_pair('c',30));

	cout<<"mymap size "<<mymap.size()<<"\n";
	cout<<"mymap max_size "<<mymap.max_size()<<"\n";
	cout<<"mymap contains:\n";
	while(!mymap.empty())
	{
		cout<<mymap.begin()->first<<" : "<<mymap.begin()->second<<"\n";
		mymap.erase(mymap.begin());
	}

	return 0;
} 
