// file : indirect_arrayCheck.cpp
//template <class T> indirect_array;
//Valarray indirect selection
//This class is used as an intermediate type returned by valarray's subscript operator (operator[]) when used with a valarray of indices.
//It references the elements from the valarray whose index is included in the object passed to the subscript operator.
//The type is convertible to a valarray (see valarray constructor), producing a new object with copies of the referred elements.
/**************************************************************************************
template <class T> class indirect_array {
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
  void operator=(const T&);

  indirect_array() = delete;
  indirect_array(const gslice_array&);
  const indirect_array& operator= (const indirect_array&) const;
  ~indirect_array();
};
**************************************************************************************/

#include <iostream>
#include <cstddef>
#include <valarray>

using namespace std;

void printInfo(valarray<int>& myarr)
{
	cout<<"myarr contains: ";
	for(size_t n = 0; n < myarr.size(); ++ n)
		cout<<myarr[n]<<" ";
	cout<<endl;
}

int main()
{
	valarray<int> foo (8);
	for(int i = 0; i < 8; ++ i)
		foo[i] = i;

	size_t sel[] = {3,5,6};
	valarray<size_t> selection(sel,3);

	foo[selection] *= valarray<int>(10,3);
	printInfo(foo);

	foo[selection] = 0;
	printInfo(foo);
	return 0;
}
