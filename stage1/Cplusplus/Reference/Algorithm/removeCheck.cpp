// file : removeCheck.cpp
// template <class ForwardIterator, class T>
//	ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& val);
// The function cannot alter the properties of the object containing the range of elements(it cannot alter the size of
// an array or a container): The removal is done by replacing the elements that compare equal to val vy the next element
// that does not, and signaling the new size of the shorted range by returning an iterator to the element that should be
// considered its new past-the-end element.
// The relative order of the elements not removed is preserved, while the elements between the returned iterator and last 
// are left in a valid but unspecified state.
// template <class ForwardIterator, class T>
// ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& val)
// {
// 	ForwardIterator result = first;
// 	while(first != last)
// 	{
// 		if(!(*first == val))
// 		{
// 			*result = move(*first);
// 			++result;
// 		}
// 		++first;
// 	}
// 	return result;
// }

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};

	int* pbegin = myints;
	int* pend = myints + sizeof(myints) / sizeof(int);

	pend = remove(pbegin,pend,20);

	cout<<"myints contains: ";
	while(pbegin != pend)
		cout<<*(pbegin++ )<<" ";
	cout<<endl;
	return 0;
}