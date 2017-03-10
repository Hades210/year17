// file : unordered_multisetHashFunctionCheck.cpp
// hasher hash_function() const;
// Returns the hash function object used by the unordered_multiset container.
// The hash function is a unary function that takes an object of type key_value as argument and returns a unique value of type size_t
// based on it. It is adopted by the container on construction. By default, it is the default hashing function for the corresponding key type: hash<key_type>

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<string> myums;

	unordered_multiset<string>::hasher fn = myums.hash_function();

	cout<<"that : "<<fn("that")<<endl;
	cout<<"than: "<<fn("than")<<endl;
	
	return 0;
}
