// file : fillCheck.cpp
// template <class ForwardIterator, class T>
// void fill(ForwardIterator first, ForwardIterator last, const T& val);
// assgins val to all the elements in the range [first,last).
// The behavior of this function template is equivalent to:
// template <class ForwardIterator, class T>
// void fill(ForwardIterator first, FOrwardIterator last, const T& val)
// {
// 	while(first != last)
// 	{
// 		*first = val;
// 		++first;
// 	}
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvec(8);
	fill(myvec.begin(),myvec.begin() + 4, 5);
	fill(myvec.begin() + 3, myvec.end() - 2, 8);

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}