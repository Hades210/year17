// file : valarraybeginendCheck.cpp
//(1) template <class T> /*unspecified1*/ begin (valarray<T>& x);
//(2) template <class T> /*unspecified2*/ begin (const valarray<T>& x);
//(3) template <class T> /*unspecified1*/ end (valarray<T>& x);
//(4) template <class T> /*unspecified2*/ end (const valarray<T>& x);

#include <iostream>
#include <valarray>

using namespace std;

int main()
{
    valarray<int> myarr {10,20,30,40,50};

    cout<<"myarr contains: ";
    for(auto it = begin(myarr); it != end(myarr); ++ it)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
