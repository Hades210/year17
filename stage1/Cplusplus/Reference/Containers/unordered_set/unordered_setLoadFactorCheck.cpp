// file : unordered_setLoadFactorCheck.cpp
// float load_factor() const noexcept;
// Returns the current load factor in the unordered_set container.
// The load factor is the ratio between the number of elements in the container(its size) and the number of buckets (bucket_count)
// load_factor = size / bucket_count
// The load factor influences the probability of collision in the hash table
// The load factor influences the probability of collision in the hash table(the probability of two elements being located in the same bucket)
// The container automatically increases the number of buckets to keep the load factor below a specific threshold (its max_load_factor),
// causing a rehash each time an expansion is needed.
// To retrieve or change this threshold,use member function max_load_factor.

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> myset;

	cout<<"size = "<<myset.size()<<"\n";
	cout<<"bucket_count = "<<myset.bucket_count()<<"\n";
	cout<<"load_factor = "<<myset.load_factor()<<"\n";
	cout<<"max_load_factor = "<<myset.max_load_factor()<<"\n";

	return 0;
}
