// file : unordered_multisetRehashCheck.cpp
// void rehash(size_type n);
// sets the number of buckets in the container to n or more.
// If n is greater than the current number of buckets in the container(bucket_count), a rehash is forced. The new bucket count can either be equal or greater than n.
// If n is lower than the current number of buckets in the container(bucket_count), the function may have no effect on the bucket count and may not force a rehash.
// A rehash is the reconstruction of the hash table. All the elements in the container are rearranged according to their hash value into the new set of buckets.
// This may alter the order of iteration of elements within the container. Although the relative order of the elements with equivalent values is preserved.
// rehashes are automatically performed by the contanier whenever its load factor is going to surpass its max_load_factor in an operation.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<string> myums;

	myums.rehash(12);

	myums.insert("red");
	myums.insert("red");
	myums.insert("blue");
	myums.insert("green");
	myums.insert("yellow");

	cout<<"current bucket_count: "<<myums.bucket_count()<<endl;
	
	return 0;
}
