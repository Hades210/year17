// file : unordered_setBucketCheck.cpp
// size_type bucket(const key_type& k) const;
// Returns the bucket number where the element with value k is located.
// A bucket is a slot in the container's internal hash table to which elements are assigned based on their hash value.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<string> myset = {"water","sand","ice","foam"};

	int n = myset.bucket_count();

	for(int i = 0; i < n; i ++)
	{
		cout<<"bucket #"<<i;

		for(auto it = myset.begin(i); it != myset.end(i); ++it)
			cout<<" "<<*it;
		cout<<"\n";
	}

	for(const string& x : myset)
		cout<<x<<" is in bucket #"<<myset.bucket(x)<<"\n";


	return 0;
}
