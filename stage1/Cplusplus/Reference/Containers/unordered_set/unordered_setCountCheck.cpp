// file : unordered_setCountCheck.cpp
// size_type count(const key_type& k) const;
// return 1 if an element with a value equivalent to k is found, or zero otherwise.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<string> myset = {"hat","umbrella","suit"};

	for(auto& x : {"hat","sunglasses","suit","t-shirt"})
	{
		if(myset.count(x) > 0)
			cout<<"myset has "<<x<<"\n";
		else
			cout<<"myset has no "<<x<<"\n";
	}
	
	return 0;
}
