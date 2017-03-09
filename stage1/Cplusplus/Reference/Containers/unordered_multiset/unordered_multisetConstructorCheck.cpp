// file : unordered_multisetConstructorCheck.cpp
/*****************************************************************************************************
*	template <class key,										// unordered_multiset::key_type/vaule_type
*			  class Hash = hash<Key>,							// unordered_multiset::hasher
*			  class Pred = equal_to<Key>,						// unordered_multiset::key_equal
*			  class Alloc = allocator<Key>						// unordered_multiset::allocator_type
*			  > class unordered_multiset;
******************************************************************************************************/
// Unordered multisets are containers that store elements in no particular order, and which allow for fast retrieval of individual elements based on their value.
// much like unordered_set containers, but allowing different elements to have equivalent values.
// In an unordered_multiset, the value of an element is at the same time its key, that identifies it uniquely. Keys are immutable, therefore, the elements in an
// unordered_multiset cannot be modified once in the container. they can be inserted and removed though.
// Internally, the elements in the unordered_multiset are not stored in any particular order, but organized into buckets depending on their hash values to allow for fast
// access to individual elements directly by their values(with a constant average time complexity on average).
// Elements with equivalent values are grouped together in the same bucket and in such a way that an iterator can iterate through all of them.
/******************************************************************************************************************
*	Hash: A unary function object type that takes an object of the same type as the elements as argument and returns
*	a unique value of type size_t based on it. This can either be a class implementing a function call operator or a
*	pointer to a function. This defaults to hash<Key>, which returns a hash value with a probability of collision 
*	approaching 1.0/std::numeric_limits<size_t>::max()
*	The unordered_multiset object uses the hash values returned by this function to organize its elements internally,
*	speeding up the process of locating individual elements.
*	Aliased as member type unordered_multiset::hasher
*
*	Pred: A binary predict that takes two arguments of the same type as the elements and returns a bool. The expression 
*	pred(a,b),where pred is an object of this type and a and b are key values, shall return true if a is to be considered
*	equivalent to b. This can either be a class implementing a function call operator or a pointer to a function.
*	This defaults to equal_to<Key>, which returns the same as applyiing the equal-to operator (a == b)
*	The unordered_multiset object uses this expression to determine whether two element keys are equivalent. This container
*	supports multiple elements with equivalent keys.
*	Aliased as member type unordered_multiset::key_equal.
*******************************************************************************************************************/
/*****************************************************************************************************************************
*	empty(1)	explicit unordered_multiset(size_type n, const hasher& hf = hasher(), const key_equal& eql = key_equal(),
*										const allocator_type& alloc = allocator_type());
*				explicit unordered_multiset(const allocator_type& alloc);
*	range(2)	template <class InputIterator>
*					unordered_multiset(InputIterator first, InputIterator last, size_type n, const hasher& hf = hasher(),
*								const key_equal& eql = key_equal(),const allocator_type& alloc = allocator_type());
*	copy(3)		unordered_multiset(const unordered_multiset& ums);
*				unordered_multiset(const unordered_multiset& ums, const allocator_type& alloc);
*	move(4)		unordered_multiset(unordered_multiset&& ums);
*				unordered_multiset(unordered_multiset&& ums, const allocator_type& alloc);
*	il(5)		unordered_multiset(initializer_list<value_type> il, size_type n , const hasher& hf = hasher(),
*							const key_equal& key_equal(), const allocator_type& alloc = allocator_type());
******************************************************************************************************************************/
// n Minimum number of initial buckets. This is not the number of elements in the container, but the minimum number of slots desired for
// for the internal hash table on construction. If this argument is not specified, the constructor determines this automatically (in a way 
// that depends on the particuolar library implementation).

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

template <class T>
T cmerge(T a, T b) {T t(a); t.insert(b.begin(),b.end()); return t;}

int main()
{
	unordered_multiset<string> first; // empty
	unordered_multiset<string> second({"red","green","blue"}); // init list
	unordered_multiset<string> third ({"red","yellow","blue"}); // init list
	unordered_multiset<string> fourth(second); // copy
	unordered_multiset<string> fifth(cmerge(third,fourth)); // move
	unordered_multiset<string> sixth (fifth.begin(),fifth.end()); // range

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	printInfo("fifth",fifth);
	printInfo("sixth",sixth);
	
	return 0;
}
