// file : count_ifCheck.cpp
// template <class InputIterator, class UnaryPredicate>
// typename iterator_traits<InputIterator>::difference_type
//	count_if(InputIterator first, InputIterator last, UnaryPredicate pred);
// Returns the number of elements in the range[first,last) for which pred is true
// The behavior of this template function is equivalent to:
// template <class InputIterator, class UnaryPredicate>
// typename iterator_traits<InputIterator>::difference_type
// count_if(InputIterator first, InputIterator last, UnaryPredicate pred)
// {
// 	typename iterator_traits<InputIterator>::difference_type ret = 0;
// 	while(first != last)
// 	{
// 		if(pred(*first))
// 			++ ret;
// 		++ first;
// 	}
// 	return ret;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsOdd(int i) {return i % 2;}

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 10; ++i)
		myvec.push_back(i);

	int mycount = count_if(myvec.begin(),myvec.end(),IsOdd);
	cout<<"myvector contains "<<mycount<<" odd values\n";
	
	return 0;
}