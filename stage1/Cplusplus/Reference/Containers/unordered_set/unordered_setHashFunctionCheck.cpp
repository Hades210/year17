// file : unordered_setHashFunctionCheck.cpp
// hasher hash_function() const;
// Get hash function
// Returns the hash function object used by the unordered_set container.
// The hash function is a unary function that takes an object of type key_type as argument and returns a unique value of type size_t based on it.
// It is adopted by the container on construction. By default, it is the default hashing function for the corresponding key type: hash<key_type>

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
        unordered_set<string> myset;
        unordered_set<string>::hasher fn = myset.hash_function();

        cout<<"that: "<<fn("that")<<"\n";
        cout<<"than: "<<fn("than")<<"\n";

        return 0;
}
