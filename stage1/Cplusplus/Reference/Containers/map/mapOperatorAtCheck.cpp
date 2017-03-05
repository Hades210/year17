// file : mapOperatorAtCheck.cpp
// mapped_type& at(const key_type& k);
// const mapped_type& at(const key_type& k) const;
// Access element
// Returns a reference to the mapped value of the element identified with key K.
// If k does not match the key of any element in the container, the function throws an out_of_range exception.

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string,int> mymap = {
		{"alpha",0},
		{"beta",0},
		{"gamma",0}
	};

	mymap.at("alpha") = 10;
	mymap.at("beta") = 20;
	mymap.at("gamma") = 30;

	for(auto& x : mymap)
		cout<<x.first<<" : "<<x.second<<endl;

	return 0;
}
