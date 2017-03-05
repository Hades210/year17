// file : mapCountCheck.cpp
//  size_type count(const key_type& k) const;

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mymap;
	char c;

	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 303;

	for(c = 'a'; c < 'h'; c++)
	{
		cout<<c;
		if(mymap.count(c))
			cout<<" is an element of mymap.\n";
		else
			cout<<" is not an element of mymap.\n";
	}

	return 0;
}
