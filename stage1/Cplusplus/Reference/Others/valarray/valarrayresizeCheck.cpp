// file : valarrayresizeCheck.cpp
// void resize(size_t sz, T c = T());
// resize valarray
// Resizes the valarray, changing its size to sz elements, and assigns the value c to each element.
// After resizing, the previous contents are lost, the valarray will contain sz elements, all of them with a value of c.
// All pointers and references to elements of the valarray are invalidated by the call.

#include <iostream>
#include <cstddef>
#include <valarray>

using namespace std;

int main()
{
	valarray<int> myarray(10,5);
	myarray.resize(3);

	cout<<"myarray contains: ";
	for(size_t n = 0; n < myarray.size(); ++n)
		cout<<myarray[n]<<" ";
	cout<<endl;

	return 0;	
}