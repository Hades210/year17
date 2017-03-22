// file : all_ofCheck.cpp
// template <class InputIterator, class UnaryPredicate>
//	bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred);
// Returns true if pred returns true for all the elements in the range [first, last) or if the range is empty
// and false otherwise.
// C++ 11 only

// The behavior of this function template is equivalent to:
/********************************************************************************************
*	template <class InputIterator, class UnaryPredicate)
*		bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred)
*		{
*			while(first != last) 	
*			{
*				if(!pred(*first)) return false;
*				++ first;
*			}
*			return true;
*		}
*********************************************************************************************/

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	array<int,8> foo {3,5,7,11,13,17,19,23};
	
	if(all_of(foo.begin(),foo.end(), [](int i) {return i % 2;}))
		cout<<"All the elements are odd numbers.\n";
	return 0;
}