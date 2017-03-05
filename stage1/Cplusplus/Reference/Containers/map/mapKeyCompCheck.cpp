// file : mapKeyCompCheck.cpp
// key_compare key_comp() const;

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mymap;
	map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	cout<<"mymap contains: \n";

	char highest = mymap.rbegin()->first;

	map<char,int>::iterator it = mymap.begin();

	do
	{
		cout<<it->first<<" : "<<it->second<<"\n"; 
	}while(mycomp((*it++).first,highest));
	cout<<"\n";

	return 0;
}
