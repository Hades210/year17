// file : valarraymaxminCheck.cpp
// T max() const;
// T min() const;
// Returns the maximum/minimum value contained in the valarray, as if the elemnts were compared with operator<.
// If the valarray has a size of zero, the value returned is unspecified (depends on the particular library implementation).
// T shall support being compared with operator<

#include <iostream>
#include <valarray>

using namespace std;

int main()
{
	int init[] {30,40,10,20};
	valarray<int> myvalarray(init,4);
	cout<<"The max is "<<myvalarray.max()<<"\n";
	cout<<"The min is "<<myvalarray.min()<<"\n";

	return 0;
}
