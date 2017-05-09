// file : slice_arrayCheck.cpp
// template <class T> slice_array;
// This class is used as an intermediate type returned by valarray's subscript operator (operator[]) when used with slices.
//It references the elements in the valarray object that are selected by the slice, and overloads the assignment and compound assignment operators, allowing direct access to the elements in the selection.
//The type is convertible to a valarray (see valarray constructor), producing a new object with copies of the referred elements.
/***********************************************************************************************************
*	Objects of this type are obtained as the return value of a call to valarray::operator[]. They cannot be 
*	default-constructed, but can be copied. It is declared as:
*	template <class T> class slice_array {
	public:
		typedef T value_type;
  		void operator=   (const valarray<T>&) const;
  		void operator*=  (const valarray<T>&) const;
  		void operator/=  (const valarray<T>&) const;
  		void operator%=  (const valarray<T>&) const;
  		void operator+=  (const valarray<T>&) const;
  		void operator-=  (const valarray<T>&) const;
  		void operator^=  (const valarray<T>&) const;
  		void operator&=  (const valarray<T>&) const;
  		void operator|=  (const valarray<T>&) const;
  		void operator<<= (const valarray<T>&) const;
  		void operator>>= (const valarray<T>&) const;
  		void operator=(const T&) const;

  		slice_array() = delete;
  		slice_array(const slice_array&);
  		const slice_array& operator= (const slice_array&) const;
  		~slice_array();
	};
***********************************************************************************************************/

#include <iostream>
#include <cstddef>
#include <valarray>

using namespace std;

void printInfo(valarray<int>& myarr)
{
	cout<<"myarr contains: ";
	for(auto& x : myarr)	cout<<x<<" ";	cout<<endl;
}

int main()
{
	valarray<int> foo (9);
	for(int i = 0; i < 9; i ++)
		foo [i] = i;
	printInfo(foo);
	slice myslice = slice(1,3,2);
	foo[myslice] *= valarray<int>(10,3);
	printInfo(foo);

	foo[slice(0,3,3)] = 99;
	printInfo(foo); 

	return 0;
}