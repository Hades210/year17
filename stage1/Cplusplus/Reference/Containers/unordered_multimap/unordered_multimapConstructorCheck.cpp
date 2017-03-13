// file : unordered_multimapConstructorCheck.cpp
/*********************************************************************************************************
*	template <class Key,											// unordered_multimap::key_type
*			  class T,												// unordered_multimap::mapped_type
*			  class Hash = hash<Key>,								// unorddered_multimap::hasher
*			  class Pred = equal_to<Key>,							// unordered_multimap::key_equal
*			  class Alloc = allocator<pair<Const Key,T> >			// unorder_multimap::allocator_type
*			  > class unordered_multimap;
**********************************************************************************************************/
// Unordered multimaps are associattive containers that store elements formed by the combination of a key value and a 
// mapped value, much like unordered_map containers, but allowing different elements to have equivalent keys.
// In an unordered_multimap, the key value is generally used to uniquely identify the element, while the mapped value is
// an object with the content associated to its key. Types of key and mapped value may differ.
// Internally, the elements in the unordered_multimap are not sorted in any particular order with respect to either their
// key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual
// elements directly by their key values (with a constant average time complexity on average).
// Elements with equivalent keys are grouped together in the same bucket and in such a way that an iterator can iterator
// through all of them.
/**********************************************************************************************************************
*	empty(1)		explicit unordered_multimap (size_type n,const hasher& hf = hasher,
*											const key_equal& eql = key_equal(),
*											const allocator_type& alloc = allocator() );
*					explicit unordered_multimap (const allocator_type& alloc );
*	range (2)		template <class InputIterator>
*						unordered_multimap(InputIterator first, InputIterator last,
*									  size_type n, const hasher& hf = hasher(),
*									  const key_equal& eql = key_equal(),
*									  const allocator_type& alloc = allocator_type() );
*	copy(3)			unordered_multimap (const unordered_multimap & umm);
*					unordered_multimap (const unordered_multimap & umm, const allocator_type& alloc);
*	move(4)			unordered_multimap (unordered_multimap && umm);
*					unordered_multimap (unordered_multimap && umm, const allocator_type& alloc);
*	il(5)			unordered_multimap (initializer_list<value_type> il, size_type n,
*								   const hasher& hf = hasher(),
*								   const key_equal& eql = key_equal(),
*								   const allocator_type& alloc = allocator_type());
***********************************************************************************************************************/
// n Minimum number of initial buckets. This is not the number of elements in the container, but the minimum unuber of slots 
// desired for the internal hash table on construction.
// If this argument is not specified, the constructor determines this automatically.

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

typedef unordered_multimap<string,string> UMMSTR ;

UMMSTR merge(UMMSTR a, UMMSTR b)
{
	UMMSTR t(a);
	t.insert(b.begin(),b.end());
	return t;
}

int main()
{
	UMMSTR first; // empty
	UMMSTR second ({{"apple","red"},{"lemon","yellow"}}); // init list
	UMMSTR third ({{"apple","green"},{"strawberry","red"}}); // init list

	UMMSTR fourth(second); // copy
	UMMSTR fifth(merge(third,fourth)); // move
	UMMSTR sixth(fifth.begin(),fifth.end()); // range

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	printInfo("fifth",fifth);
	printInfo("sixth",sixth);
	
	return 0;
}

