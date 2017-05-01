// file : valarrayCheck.cpp
/**********************************************************************************************************************************************
*	template <class T> class valarray;
*	A valarray object is designed to hold an array of values, and easily perform mathematical operations on them. It also
*	allows special mechanisms to refer to subsets of elements in the arrays (see its operator[] overload).
*	Most mathematical operations can be applied directly to valarray objects, including arithmetical and comparison
*	operators, affecting all its elements.
*	
*	value_type		the first template parameter (T)	the type of the elements in the valarray
***********************************************************************************************************************************************/

/***********************************************************************************************************************************************
*	constructor
*	default(1)		valarray();
*	size(2)			explicit valarray(size_t n);
*	fill(3)			valarray(const T& val, size_t n);
*	array(4)		valarray(const T* p, size_t n);
*	copy/move(5)	valarray(const valarray& x);
*					valarray(valarray&& x) noexcept;
*	sub-array(6)	valarray(const slice_array<T>& sub);
*					valarray(const gslice_array<T>&sub);
*					valarray(const mask_array<T>& sub);
*					valarray(const indirect_array<T>& sub);
*	il(7)			valarray(initializer_list<T> il);
***********************************************************************************************************************************************/

#include <iostream>
#include <valarray>

using namespace std;

int main()
{
	int init[] = {10,20,30,40};

	valarray<int> first; // empty;
	valarray<int> second(5); // 0 0 0 0 0
	valarray<int> third (10,3); // 10 10 10
	valarray<int> fourth(init,4); // 10 20 30 40
	valarray<int> fifth(fourth); //  10 20 30 40
	valarray<int> sixth(fifth[std::slice(1,2,1)]); // 20 30
	cout<<" first contains: ";	for(auto& x : first)	cout<<x<<" ";	cout<<endl;
	cout<<" second contains: ";	for(auto& x : second)	cout<<x<<" ";	cout<<endl;
	cout<<" third contains: ";	for(auto& x : third)	cout<<x<<" ";	cout<<endl;
	cout<<" fourth contains: ";	for(auto& x : fourth)	cout<<x<<" ";	cout<<endl;
	cout<<" fifth contains: ";	for(auto& x : fifth)	cout<<x<<" ";	cout<<endl;
	cout<<" sixth contains: ";	for(auto& x : sixth)	cout<<x<<" ";	cout<<endl;
	cout<<"sixth sums "<<sixth.sum()<<"\n";

	return 0;
}
