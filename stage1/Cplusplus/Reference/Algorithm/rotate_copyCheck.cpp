// file : rotate_copyCheck.cpp
// template <class ForwardIterator, class OutputIterator>
//	OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle,
//							   ForwardIterator last, OutputIterator result);
// copies the elements in the range[first,last) to the range beginning at result, but rotating the order of the elements
// in such a way that the element pointed by middle becomes the first element in the resulting range.
// template <class ForwardIterator, class OutputIterator>
// OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result)
// {
// 	result = copy(middle,last,result);
// 	return copy(first,middle,result);
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int myints[] = {10,20,30,40,50,60,70};
	vector<int> myvec(7);

	rotate_copy(myints,myints+3,myints+7,myvec.begin());

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
}