// file : setCountCheck.cpp
// size_type count(const value_type& val) const;
// Return 1 if the container contains an element equivalent to val, or zero otherwise

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> myset;

	for(int i = 1; i < 5; i ++)
		myset.insert(i * 3);
	for(int i = 0; i < 10; i ++)
	{
		cout<<i;
		if(myset.count(i))
			cout<<" is an element of myset.\n";
		else
			cout<<" is not an element of myset.\n";
	}

	return 0;
}
