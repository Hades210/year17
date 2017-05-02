// file : valarrayOperator2Check.cpp
/**************************************************************************************************************
*	element(1)	const T& operator[] (size_t n) const;
*					  T& operator[] (size_t n);
*	subscript(2) valarray<T> operator[] (slice slc) const;
*				 slice_array<T> operator[] (slice slc);
*				 valarray<T> operator[] (const gslice& gslc) const;
*				 gslice_array<T> operator[] (const gslice& gslc);
*				 valarray<T> operator[](const valarray<bool>& msk) const;
*				 mask_array<T> operator[] (const valarray<bool>& msk);
*				 valarray<T> operator[] (const valarray<size_t>& ind) const;
*				 indirect_array<T> operator[] (const valarray<size_T>& ind);
***************************************************************************************************************/

/***************************************************************************************************************
*	Access element or subscript
*	The element access versions(1) return the n-th element in the valarray object.
*	The subscript access versions(2) return a sub-array object that selects the elements specified by its argument
*	-If the valarray is const-qualified, the function returns a new valarray object with a copy of this selection.
*	-Otherwise, the function returns a sub-array object, which has reference semantics to the original array, ready
*	to be used as an l-value.
***************************************************************************************************************/

#include <iostream>
#include <valarray>

using namespace std;

void printInfo(valarray<int>& myvalarray)
{
	cout<<"myarray contains: ";
	for(auto& x : myvalarray)
		cout<<x<<" ";
	cout<<endl;
}

int main()
{
	valarray<int> myarray(10); 
	printInfo(myarray);
	//slice
	myarray[std::slice(2,3,3)] = 10;
	printInfo(myarray);
	// gslice
	size_t lengths[] = {2,2};
	size_t strides[] = {6,2};
	myarray[std::gslice(1,std::valarray<size_t>(lengths,2),std::valarray<size_t>(strides,2))] = 20;
	printInfo(myarray);

	// mask
	valarray<bool> mymask(10);
	for(int i = 0; i < 10; ++i)
		mymask[i] = (i % 2) == 0;
	myarray[mymask] += valarray<int>(3,5);
	printInfo(myarray);

	// indirect
	size_t sel[] = {2,5,7};
	valarray<size_t> myselection(sel,3);
	myarray[myselection]=99;
	printInfo(myarray);

	return 0;
}