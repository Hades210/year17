// file arrayBeginCheck.cpp
// template <class T, size_t N> class array;
// Arrays are fixed-size sequence container: they hold a specific number of elements ordered in a strict linear sequence.
// Array containers can be treated as tuple objects. The <array> header overloads the get function to access the elements of the array as if it was a tuple, as well as specialized tuple_size and tuple_element types.
// c++ 11 only

// iterator begin() noexcept;
// const_iterator begin() const noexcept;
// iterator end() noexcept;
// const_iterator end() const noexcept;

// reverse_iterator rbegin() noexcept;
// const_reverse_iterator rbegin() const noexcept;
// reverse_iterator rend() noexcept;
// const_reverse_iterator rend() const noexcept;

// const_iterator cbegin() const noexcept;
// const_iterator cend() const noexcept;
// const_reverse_iterator crbegin() const noexcept;
// const_reverse_iterator crend() const noexcept;

#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int,5> myints = {10,20,30,40,50};

	for(array<int,5>::iterator it = myints.begin(); it != myints.end(); ++ it)
		cout<<*it<<"\t";
	cout<<endl;

	for(array<int,5>::reverse_iterator rit = myints.rbegin(); rit != myints.rend(); ++ rit)
		cout<<*rit<<"\t";
	cout<<endl;

	for(array<int,5>::const_iterator cit = myints.cbegin(); cit != myints.cend(); ++ cit)
		cout<<*cit<<"\t";
	cout<<endl;

	for(array<int,5>::const_reverse_iterator it = myints.crbegin(); it != myints.crend(); ++ it)
		cout<<*it<<"\t";
	cout<<endl;
	
	return 0;
}
