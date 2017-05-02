// file : valarraycshiftCheck.cpp
// valarray cshift(int n) const;
// circularly shift elements
// Returns a copy of the valarray object with its elements rotated left n spaces (or right if n is negative).
// The valarray returned has the same length as *this.

#include <iostream>
#include <cstddef> // std::size_t
#include <valarray>

using namespace std;

void printInfo(valarray<int>& myvalarray)
{	
	cout<<"myvalarray contains: ";
	for(auto& x : myvalarray)
		cout<<x<<" ";
	cout<<endl;
}

int main()
{
	int init[] {10,20,30,40,50};
	valarray<int> myvalarray (init,5);
	printInfo(myvalarray);
	myvalarray = myvalarray.cshift(2);
	printInfo(myvalarray);
	myvalarray = myvalarray.cshift(-1);
	printInfo(myvalarray);

	return 0;
}