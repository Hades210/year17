// file : unordered_multisetReserveCheck.cpp
// void reserve(size_type n)
// Sets the number of buckets in the container(bucket_count) to the most appropriate to contain at least n elements.
// If n is greater than the current bucket_count multiplied by the max_load_factor, the container's bucket_count is 
// increased and a rehash is forced.
// If n is lower than that, the function may have no effect.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<string> myums;
	myums.reserve(5);

	myums = {"klingon","human","vulcan","klingon","klingon"};

	cout<<"myums contains: ";
	for(auto& x : myums)
		cout<<x<<" ";
	cout<<endl;

	cout<<"bucket_count : "<<myums.bucket_count()<<endl;

	return 0;
}
