// file : find_ifCheck.cpp
// template <class InputIterator, class UnaryPredicate>
//	InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred);
// Returns an iterator to the first element in the range[first,last)for which pred returns true. If no such element is found, the 
// function returns last.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class UnaryPredicate>
// InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		if(pred(*first)) return first;
// 		++ first;
// 	}
// 	return last;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsOdd(int i)
{
	return i % 2;
}

int main()
{
	vector<int> myvec {10,25,40,55};

	auto it = find_if(myvec.begin(),myvec.end(),IsOdd);

	if(it != myvec.end())
		cout<<"The first odd value is "<<*it<<endl;

	return 0;
}