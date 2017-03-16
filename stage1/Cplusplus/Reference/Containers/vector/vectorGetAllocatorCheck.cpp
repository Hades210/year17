// file : vectorGetAllocatorCheck.cpp
// allocator_type get_allocator() const noexcept;
// The example shows an elaborate way to allocate memory for an array of ints using the same allocator used by the vector

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;
	int* p ;
	unsigned int i;

	//allocate an array with space for 5 elements using vector's allocator:
	p = myVector.get_allocator().allocate(5);

	//construct values in-place on the array:
	for(int i = 0; i < 5; i ++)
		myVector.get_allocator().construct(&p[i],i);

	cout<<"The allocated array contains:";
	for(i = 0; i < 5; i ++)
		cout<<" "<<p[i];
	cout<<"\n";

	//destroy and deallocate:
	for(i = 0; i < 5; i ++)
		myVector.get_allocator().destroy(&p[i]);
	myVector.get_allocator().deallocate(p,5);
	
	return 0;
}
