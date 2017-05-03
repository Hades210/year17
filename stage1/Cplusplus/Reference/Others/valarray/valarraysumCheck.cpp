// file : valarraysumCheck.cpp
//Return sum of elements
//Returns the sum of all the elements in the valarray, as if calculated by applying operator+= to a copy of one element and all the other elements, in an unspecified order.
//If the valarray has a size of zero, it causes undefined behavior.
//T shall support the calls to operator+=.

#include <iostream>
#include <valarray>

using namespace std;

int main()
{
    int init[] {10,20,30,40};
    valarray<int> myarr (init,4);
    cout<<"myarr sums up: "<<myarr.sum()<<endl;
    return 0;
}