// file : unordered_setRehashCheck.cpp
// void rehash(size_type n);
// set the number of buckets in the container to n or more
// If n is greater than the current number of buckets in the container(bucket_count), a rehash is forced. The new bucket count can either be equal or greater than n.
// If n is lower than the current number of buckets in the container(bucket_count), the function may have no effect on the bucket count and may not force a rehash.
// A rehash is the reconstruction of the hash table. All the elements in the container are rearranged according to their hash value into the new set of buckets.
// This may alter the order of iteration of elements within the container.
// rehashes are automatically performed by the contanier whenever its load factor is going to surpass its max_load_factor in an operation.

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_set<string> myset;
        myset.rehash(12);

        myset.insert("office");
        myset.insert("house");
        myset.insert("gym");
        myset.insert("parking");
        myset.insert("highway");

        cout<<"current bucket_count: "<<myset.bucket_count()<<"\n";
        printInfo("myset",myset);

        return 0;
}
