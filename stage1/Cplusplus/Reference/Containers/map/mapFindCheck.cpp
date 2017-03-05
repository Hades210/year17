// file : mapFindCheck.cpp
// iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;
// Return an iterator to the element, if an element with specified key is found, or map::end otherwise.

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mymap;
	map<char,int>::iterator it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	it = mymap.find('b');

	if(it != mymap.end())
		mymap.erase(it);

	cout<<"element in mymap: "<<"\n";

	cout<<"a : "<<mymap.find('a')->second<<"\n";
	cout<<"c : "<<mymap.find('c')->second<<"\n";
	cout<<"d : "<<mymap.find('d')->second<<"\n";
	
	return 0;
}
