// file : valarrayshiftCheck.cpp
// valarray shift(int n) const;
//Shift elements
//Returns a copy of the valarray object with its elements shifted left n spaces (or right if n is negative).
//The valarray returned has the same length as *this, with the new elements value-initialized.
//By shifting a valarray, the I-th element in the resulting valarray corresponds to the I+n-th element in the original valarray (whenever I+n is less than its size) or a default-constructed element (if I+n is greater than the size).
//Unlike valarray::cshift (circular shift), the valarray returned by shift does not include the first n elements in *this (or the last -n elements if n is negative) in any position. 

#include <iostream>
#include <valarray>

using namespace std;

void printInfo(valarray<int>& myarr)
{
    cout<<"myarr contains: ";
    for(size_t i = 0; i < myarr.size(); ++ i)
        cout<<myarr[i]<<" ";
    cout<<endl;
}

int main()
{
    int init[] {10,20,30,40,50};
    valarray<int> myarr (init,5);
    printInfo(myarr);

    myarr.shift(2);
    printInfo(myarr);

    myarr.shift(-1);
    printInfo(myarr);

    return 0;
}