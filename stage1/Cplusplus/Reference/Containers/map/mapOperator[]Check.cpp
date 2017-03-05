// file : mapOperator[]Check.cpp
// mapped_type& operator[] (const key_type& k);
// mapped_type& operator[] (key_type& k);
// Access element
// If k matches the key of an element in the container, the function returns a reference to its mapped value.
// If k does not match the key of any element in the container, the function inserts a new element with that key and 
// returns a reference to its mapped value.
// A similar member functioin map::at,has the same behavior when an element with the key exists, but throws an exception
// when it does not.
// A call to this function is equivalent to:
// 											(*((this->insert(make_pair(k,mapped_type()))).first)).second

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<char,string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	cout<<"mymap[a] "<<mymap['a']<<endl;
	cout<<"mymap[b] "<<mymap['b']<<endl;
	cout<<"mymap[c] "<<mymap['c']<<endl;
	cout<<"mymap[d] "<<mymap['d']<<endl;

	cout<<"mymap now contains "<<mymap.size()<<" element\n";
	
	return 0;
}
