// file : unordered_setBucketSizeCheck.cpp
// size_type bucket_size( size_type n) const noexcept;
// Returns the number of elements in bucket n.
// A bucket is a slot in the container's internal hash table to which elements are assigned based on their hash value.
// The number of elements in a bucket influences the time it takes to access a particular element in the bucket. 
//The container automatically increases the number of buckets to keep the load factor (which is the average bucket size) below its max_load_factor.

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	unordered_set<string> myset = {"red","green","blue","yellow","purple","pink"};
	
	unsigned int nbuckets = myset.bucket_count();
	cout<<"myset has "<<nbuckets<<" buckets\n";
	
	for(int i = 0; i < nbuckets; i ++)
	{
		cout<<"bucket #"<<i<<" has "<<myset.bucket_size(i)<<" elements\n";
	}
	
	return 0;
}
