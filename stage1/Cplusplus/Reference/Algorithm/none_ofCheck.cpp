// file : nono_ofCheck.cpp
// template <class InputIterator, class UnaryPredicate.
//	bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred);
// Returns true if pred returns false for all the elements in the range[first,last) or if the range is empty, and false otherwise.
// C++ 11 only
// The behavior of this function template is equivalent to:
// template <class InputIterator, class UnaryPredicate>
// bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		if(pred(*first)) return false;
// 		++ first;
// 	}
// 	return true;
// }

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	array<int,8> foo {1,2,4,8,16,32,64,128};

	if(none_of(foo.begin(),foo.end(),[](int i) {return i < 0;}))
		cout<<"There are no negative elements in the range.\n";
	return 0;
}