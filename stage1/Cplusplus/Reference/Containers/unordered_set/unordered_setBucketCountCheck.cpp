// file : unordered_setBucketCountCheck.cpp
// size_type bucket_count() const noexcept;
// Return number of buckets.
// A bucket is a slot in the container's internal hash table to which elements are assigned based on
// their hash value.
// The number of buckets influences directly the load factor of the container's hash table(and thus the 
// probability of collision.) The container automatically increases the number of buckets to keep the 
// load factor below a specific threshold(its max_load_factor),causing a rehash each time the number of 
// buckets needs to be increased.

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	unordered_set<string> myset = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};

	unsigned int n = myset.bucket_count();
	cout<<"myset has "<<n<<" buckets.\n";

	for(unsigned int i = 0; i < n; ++i)
	{
		cout<<"bucket #"<<i<<" contains:";
		for(auto it = myset.begin(i); it != myset.end(i); ++it)
			cout<<" "<<*it;
		cout<<"\n";
	}

	return 0;
}
