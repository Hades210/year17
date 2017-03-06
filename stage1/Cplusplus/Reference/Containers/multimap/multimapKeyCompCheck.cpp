// file : multimapKeyCompCheck.cpp
// key_compare key_comp() const;
// Return value the comparison object. Member type key_compare is the type of the comparison object associated to the container, defined in multimap as an alias of its third template parameter(Compare).

#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<char,int> mymap;
	multimap<char,int>::key_compare mycomp = mymap.key_comp();

	mymap.insert(make_pair('a',100));
	mymap.insert(make_pair('b',200));
	mymap.insert(make_pair('b',211));
	mymap.insert(make_pair('c',300));

	char highest = mymap.rbegin()->first;

	cout<<"mymap contains:\n";
	multimap<char,int>::iterator it = mymap.begin();
	do
	{
		cout<<it->first<<" : "<<it->second<<"\n";
	}while(mycomp((*it++).first, highest));

	return 0;
}
