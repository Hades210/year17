// file : valarrayApplyCheck.cpp
// valarray apply(T func(T)) const;
// valarray apply(T func(const T&)) const;

// Returns a valarray with each of its elements initialized to the result of applying func to its corresponding element in *this.
// The valarray returned has the same length as *this.

// func: Pointer to a function taking an argument of type T(or a constant reference) and returning T.
//		 T is the template argument of valarray(the value type).

#include <iostream>
#include <cstddef>	// std::size_t
#include <valarray>

using namespace std;

int increment(int x) {return ++x;}

int main()
{
	int init[] {10,20,30,40,50};
	valarray<int> foo (init, 5);

	valarray<int> bar = foo.apply(increment);

	cout<<"foo contains: ";
	for(std::size_t n = 0; n < foo.size(); ++n)
		cout<<foo[n]<<" ";
	cout<<endl;


	cout<<"bar contains: ";
	for(std::size_t n = 0; n < bar.size(); ++n)
		cout<<bar[n]<<" ";
	cout<<endl;
	return 0;
}