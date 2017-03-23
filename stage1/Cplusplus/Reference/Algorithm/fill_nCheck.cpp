// file : fill_nCheck.cpp
// template <class OutputIterator, class Size, class T>
// OutputIterator fill_n(OutputIterator first, Size n, const T& val);
// Assigns val to the first n elements of the sequence pointed by first.
// The behavior of this function template is equivalent to:
// template <class OutputIterator, class Size, class T>
// OutputIterator fill_n(OutputIterator first, Size n, const T& val)
// {
// 	while(n > 0)
// 	{
// 		*first = val;
// 		++first;
// 		--n;
// 	}
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> myvec(8,10);
	fill_n(myvec.begin(),4,20);
	fill_n(myvec.begin() + 3,3,33);

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}