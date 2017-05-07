// file : gsliceCheck.cpp
/******************************************************************************************
*	This class represents a valarray generalized slice selector(a multidimensional slice).
*	It does not contain nor refers to any element-it only describes a selection of elements 
*	to be used as an index in valarray::operator[].
*	A valarray generalized slice is specified by a starting index, a set of sizes, and a set
*	of strides. It produces a multidimensional combination of slice selections, where:
*	The starting index(start) is the index of the first element in the selection.
*	The size(size) is the number of elements in the selection.
*	The stride(stride) is the span that separates the elements selected.
*
*	For example, a gslice with: start = 1 size = {2,3} stride = {7,2}
*	would select:
*				[0] [1]	[2]	[3] [4]	[5]	[6] [7]	[8]	[9] [10]	[11]	[12] [13]	
*	start=1		 	 *
*size=2,stride=7	 *							 *
*size=3,stride=2	 *		 *		 *			 *		 *				 *
*
*******************************************************************************************/


/*******************************************************************************************
*	constructor
*
*	default(1)		gslice();
*	init(2)			gslice(size_t start, const valarray<size_t>& lengths, const valarray<size_t>& strides);
*	copy(3)			gslice(const gslice& x);
*******************************************************************************************/

/*******************************************************************************************
*	member functions
*	size_t start() const;
*	valarray<size_t> size() const;
*	valarray<size_t> stride() const;
*******************************************************************************************/

#include <iostream>
#include <valarray>
#include <cstddef>

using namespace std;

int main()
{
	valarray<int> foo (14);

	for(int i = 0; i <14; ++ i)
		foo[i] = i;

	std::size_t start = 1;
	std::size_t sizes[] = {2,3};
	std::size_t strides[] = {7,2};

	std::gslice mygslice(start,
						 valarray<std::size_t>(sizes,2),
						 valarray<std::size_t>(strides,2));

	valarray<int> bar = foo[mygslice];

	cout<<"bar contains: ";
	for(size_t n = 0; n < bar.size(); ++ n)
		cout<<bar[n]<<" ";
	cout<<endl;

	valarray<int> myvalarr1 (14);

	for(int i = 0; i < 14; ++ i)
		myvalarr1[i] = i * 2;

	std::gslice mygslice2 (mygslice);
	valarray<int> myvalarr2 = myvalarr1[mygslice2];

	cout<<"myvalarr2 contains: ";
	for(size_t n = 0; n < myvalarr2.size(); ++ n)
		cout<<myvalarr2[n]<<" ";
	cout<<endl;

	cout<<"start: "<<mygslice.start()<<endl;
	valarray<size_t> mysizes = mygslice.size();
	cout<<"size: {";
	for(auto& x : mysizes)	cout<<x<<" ";	cout<<"}"<<endl;
	valarray<size_t> mystrides = mygslice.stride();
	cout<<"stride: {";
	for(auto& x : mystrides )	cout<<x<<" ";	cout<<"}"<<endl; 

	return 0;
}