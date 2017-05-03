// file : sliceCheck.cpp
/**************************************************************************************
*	std::slice
*	class slice;
*	valarray slice selector
*
*	This class represents a valarray slice selector. It does not contain nor refers to 
*	any element-it only describes a selection of elements to be used as an index in
*	valarray::operator[].
*	A valarray slice is defined by a starting index, a size, and a stride.
*	The starting index(start) is the index of the first element in the selection.
*	The size(size) is the number of elements in the selection.
*	The stride(stride) is the span that separates the elements selected.
*	
*	Therefore a slice with a stride higher than 1 does not select contiguous elements
*	in the valarray; For example, slice(3,4,5) selects the elements 3,8,13 and 18.
***************************************************************************************/

/***************************************************************************************
*	constructor
*
*	default(1)	slice();
*	init(2)		slice(size_t start, size_t length, size_t stride);
*	copy(3)		slice(const slice& x);
***************************************************************************************/

#include <iostream>
#include <cstddef>
#include <valarray>

using namespace std;

int main()
{
	valarray<int> myarr (12);
	for(size_t i = 0; i < myarr.size(); ++ i)
		myarr[i] = i;

	valarray<int> myarr2 = myarr[std::slice(2,3,4)];

	cout<<"myarr contains: ";
	for(auto it = begin(myarr); it != end(myarr); ++ it)
		cout<<*it<<" ";
	cout<<endl;


	cout<<"slice(2,3,4) ";
	for(auto it = begin(myarr2); it != end(myarr2); ++ it)
		cout<<*it<<" ";
	cout<<endl;

	std::slice first;
	std::slice second(2,3,4);
	std::slice third(second);

	valarray<int> myarr3 = myarr[third];

	cout<<"std::slice third: ";
	for(auto it = begin(myarr3); it != end(myarr3); ++ it)
		cout<<*it<<" ";
	cout<<endl;

	return 0;
}