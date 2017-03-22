// file : any_ofCheck.cpp
// template <class InputIterator, class UnaryPredicate.
//	bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred);
// Returns true if pred returns true for any of the elements in the range[first,last), and fase otherwise.
// If [first,last) is an empty range, the function returns false.
// C++ 11 only
// The behavior of this function template is equivalent to:
// template <class InputIterator, class UnaryPredicate>
// bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		if(pred(*first)) return true;
// 		++ first;
// 	}

// 	return false;
// }


#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	array<int,7> foo {0,1,-1,3,-3,5,-5};

	if(any_of(foo.begin(),foo.end(), [](int i){ return i < 0;}))
		cout<<"There are negative elements in the range.\n";
	return 0;
}