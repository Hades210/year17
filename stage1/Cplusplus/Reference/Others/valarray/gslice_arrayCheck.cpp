// file : gslice_arrayCheck.cpp
//template <class T> gslice_array;
//Valarray gslice selection
//This class is used as an intermediate type returned by valarray's subscript operator (operator[]) when used with generalized gslices.
//It references the elements in the valarray object that are selected by the gslice, and overloads the assignment and compound assignment operators, allowing direct access to the elements in the selection.
//The type is convertible to a valarray (see valarray constructor), producing a new object with copies of the referred elements.


/*********************************************************************************

template <class T> class gslice_array {
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

  gslice_array() = delete;
  gslice_array(const gslice_array&);
  const gslice_array& operator= (const gslice_array&) const;
  ~gslice_array();
};

*********************************************************************************/	
#include <iostream>
#include <cstddef>
#include <valarray>

using namespace std;

int main()
{
	valarray<int> foo (14);
	for(int i = 0; i < 14; ++ i)
		foo[i] = i;

	cout<<"foo contains: ";
	for(size_t n = 0; n < foo.size(); ++n)
		cout<<foo[n]<<" ";
	cout<<endl;

	size_t start = 1;
	size_t sizes[] = {2,3};
	size_t strides[] = {7,2};

	foo[gslice(start,
			   valarray<size_t>(sizes,2),
			   valarray<size_t>(strides,2)
			   )
	] = 0;

	cout<<"foo contains: ";
	for(size_t n = 0; n < foo.size(); ++n)
		cout<<foo[n]<<" ";
	cout<<endl;
	
	return 0;
}