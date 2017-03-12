// file : unordered_mapConstructorCheck.cpp
/*********************************************************************************************************
*	template <class Key,											// unordered_map::key_type
*			  class T,												// unordered_map::mapped_type
*			  class Hash = hash<Key>,								// unorddered_map::hasher
*			  class Pred = equal_to<Key>,							// unordered_map::key_equal
*			  class Alloc = allocator<pair<Const Key,T> >			// unorder_map::allocator_type
*			  > class unordered_map;
**********************************************************************************************************/
// Unordered maps are associattive containers that store elements formed by the combination of a key value and a 
// mapped value, and which allows for fast retrieval of individual elements based on their keys.
// In an unordered_map, the key value is generally used to uniquely identify the element, while the mapped value is
// an object with the content associated to its key. Types of key and mapped value may differ.
// Internally, the elements in the unordered_map are not sorted in any particular order with respect to either their
// key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual
// elements directly by their key values (with a constant average time complexity on average).
// Unordered_map containers are faster than map containers to access individual elements by their key, although they are 
// generally less efficient for range iteration through a subset of their elements.
// Unordered maps implement the direct access operator (operator[]) which allows for direct access of the mapped value
// using its key value as argument
// Iterators to elements of unordered_map containers access to both the key and the mapped value.
//							typedef pair<const Key, T> value_type;
//							unordered_map<Key,T>::iterator it;
//							(*it).first		(*it).second	(*it)
//							it->first		it->second
/**********************************************************************************************************************
*	empty(1)		explicit unordered_map (size_type n,const hasher& hf = hasher,
*											const key_equal& eql = key_equal(),
*											const allocator_type& alloc = allocator() );
*					explicit unordered_map (const allocator_type& alloc );
*	range (2)		template <class InputIterator>
*						unordered_map(InputIterator first, InputIterator last,
*									  size_type n, const hasher& hf = hasher(),
*									  const key_equal& eql = key_equal(),
*									  const allocator_type& alloc = allocator_type() );
*	copy(3)			unordered_map (const unordered_map & ump);
*					unordered_map (const unordered_map & ump, const allocator_type& alloc);
*	move(4)			unordered_map (unordered_map && ump);
*					unordered_map (unordered_map && ump, const allocator_type& alloc);
*	il(5)			unordered_map (initializer_list<value_type> il, size_type n,
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

typedef unordered_map<string,string> STRMAP;

STRMAP merge(STRMAP a, STRMAP b)
{
	STRMAP t(a);
	t.insert(b.begin(),b.end());
	return t;
}

using namespace std;

int main()
{
	STRMAP first; 	// empty;
	STRMAP second ({{"apple","red"},{"lemon","yellow"}});  // init list
	STRMAP third ({{"orange","orange"},{"strawberry","red"}});  // init list
	STRMAP fourth (second); // copy
	STRMAP fifth(merge(third,fourth)); // move
 	STRMAP sixth(fifth.begin(),fifth.end()); // range

 	printInfo("first",first);
 	printInfo("second",second);
 	printInfo("third",third);
 	printInfo("fourth",fourth);
 	printInfo("fifth",fifth);
 	printInfo("sixth",sixth);

	return 0;
}






