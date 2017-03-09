// file : unordered_setReserveCheck.cpp
// void reserve (size_type n);
// Request a capacity change
// sets the number of buckets in the container(bucket_count) to the most appropriate to contain at least n elements.
// If n is greater than the current bucket_count multiplied by the max_load_factor, the container's bucket_count is increased and a rehash is forced.
// If n is lower than that, the function may have no effect.

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_set<string> myset;
        myset.reserve(5);

        myset.insert("office");
        myset.insert("house");
        myset.insert("gym");
        myset.insert("parking");
        myset.insert("highway");

        printInfo("myset",myset);
        return 0;
}
