// file: vectorResizeCheck.cpp
// void resize(size_type n);
// void resize(size_type n, const value_type& val)
// if n is greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
// the container's allocator, which may throw exceptions on faulure (bad_alloc)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myints;
	for(int i = 0; i < 10; i ++) 
		myints.push_back(i);

	myints.resize(5);
	myints.resize(8,100);
	myints.resize(12);

	cout<<"myints contains:";
	for(auto cit = myints.cbegin(); cit != myints.cend(); ++cit)
		cout<<"\t"<<*cit;
	cout<<endl;

	return 0;
}
