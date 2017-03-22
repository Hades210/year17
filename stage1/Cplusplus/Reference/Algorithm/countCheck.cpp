// file : countCheck.cpp
// template <class InputIterator, class T>
// 	typename iterator_traits<InputIterator>::difference_type
//	count (InputIterator first, InputIterator last, const T& val);
// Returns the number of elements in the range [first,last) that compare equal to val.
// The function uses operator== to compare the individual elements to val.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class T>
// typename iterator_traits<InputIterator>::difference_type
// count(InputIterator first, InputIterator last, const T& val)
// {
// 	typename iterator_traits<InputIterator>::difference_type ret = 0;
// 	while(first != last)
// 	{
// 		if(*first == val)
// 			++ret;
// 		++first;
// 	}
// 	return ret;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};
	int mycount = count(myints,myints + 8,10);
	cout<<"10 appears "<<mycount<<" times\n";

	vector<int> myvec (myints, myints + 8);
	mycount = count(myvec.begin(),myvec.end(),20);
	cout<<"20 appears "<<mycount<<" times\n";
	
	return 0;
}