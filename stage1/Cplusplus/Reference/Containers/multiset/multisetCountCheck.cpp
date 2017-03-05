// file: multisetCountCheck.cpp
// size_type count(const value_type& val) const;

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int myints[] = {10,73,12,22,73,73,12};
	multiset<int> myset(myints,myints + 7);

	cout<<"73 appears "<<myset.count(73)<<" times in myset\n";
	
	return 0;
}
