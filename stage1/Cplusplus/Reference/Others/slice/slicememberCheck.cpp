// file : slicememberCheck.cpp
/******************************************************************
*	size_t start() const;
*	Return start of slice
*
*	size_t size() const;
*	Return size of slice
*
*	size_t stride() const;
*	Return stride of slice
******************************************************************/

#include <iostream>
#include <cstddef>
#include <valarray>

using namespace std;

int main()
{
	valarray<int> foo (10);
	for(int i = 0; i < 10; ++i )
		foo[i] = i;

	slice slc(2,4,1);
	valarray<int> bar = foo[slc];
	cout<<"slice starting at "<<slc.start()<<endl;
	for(size_t n = 0; n < bar.size(); ++ n)
		cout<<bar[n]<<" ";
	cout<<endl;

	slice slc2(0,3,1);
	valarray<int> bar2 = foo[slc2];
	cout<<"slice with a size of "<<slc2.size()<<endl;
	for(size_t n = 0; n < bar2.size(); ++ n)
		cout<<bar2[n]<<" ";
	cout<<endl;

	slice slc3(0,5,2);
	valarray<int> bar3 = foo[slc3];
	cout<<"slice with a stride of "<<slc3.stride()<<endl;
	for(size_t n = 0; n < bar3.size(); ++ n)
		cout<<bar3[n]<<" ";
	cout<<endl;

	return 0;
}