// file : valarrayOperatorCheck.cpp
/**********************************************************************************
*	copy/move(1)	valarray& operator= (const valarray& x);
*					valarray& operator= (valarray&& x) noexcept;
*	fill(2)			valarray& operator= (const T& val);
*	su7b-array(3)	valarray& operator= (const slice_array<T>& sub);
*					valarray& operator= (const gslice_array<T>& sub);
*					valarray& operator= (const mask_array<T>& sub);
*					valarray& operator= (const indirect_array<T>& sub);
**********************************************************************************/
// (2) fill assignment Assign val to every element. The size of the valarray is preserved, with each of its element equal to this value.

#include <iostream>
#include <valarray>

using namespace std;

void printInfo(const string& who, valarray<int>& myvalarray)
{
	cout<<who<<" contains: ";
	for(auto& x : myvalarray)
		cout<<x<<" ";
	cout<<endl;
}

int main()
{
	valarray<int> foo(4);
	valarray<int> bar(2,4);
	printInfo("foo",foo);
	printInfo("bar",bar);

	foo = bar;
	printInfo("foo",foo);
	printInfo("bar",bar);
	
	bar = 5;
	printInfo("foo",foo);
	printInfo("bar",bar);
	
	foo = bar[std::slice(0,4,1)];
	printInfo("foo",foo);
	printInfo("bar",bar);
	
	cout<<"foo sums "<<foo.sum()<<endl;

	return 0;
}
