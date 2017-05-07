// file : mask_arrayCheck.cpp
/******************************************************************************
template <class T> mask_array;

Valarray mask selection
This class is used as an intermediate type returned by valarray's subscript operator (operator[]) when used with masks.

It references the elements in the valarray object that are selected by a mask (a valarray<bool>), and overloads the assignment and compound assignment operators, allowing direct access to the elements in the selection.

The type is convertible to a valarray (see valarray constructor), producing a new object with copies of the referred elements.
******************************************************************************/
/******************************************************************************
template <class T> class mask_array {
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

  mask_array() = delete;
  mask_array(const mask_array&);
  const mask_array& operator= (const mask_array&) const;
  ~mask_array();
};
******************************************************************************/

#include <iostream>
#include <cstddef>
#include <valarray>

using namespace std;

int main()
{
	valarray<int> foo (10);
	for(int i = 0; i < 10; ++ i)
		foo[i] = i;

	valarray<bool> mask(10);
	for(int i = 0; i < 10; i ++)
		mask[i] = (i % 2);

	foo[mask] *= valarray<int>(10,5);
	foo[!mask] = 0;

	cout<<"foo contains: ";
	for(size_t n = 0; n < foo.size(); ++ n)
		cout<<foo[n]<<" ";
	cout<<endl;

	return 0;
}