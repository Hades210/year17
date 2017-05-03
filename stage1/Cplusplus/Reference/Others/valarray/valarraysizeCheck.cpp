// file : valarraysizeCheck.cpp
//size_t size() const;
//Returns the number of elements in the valarray.

#include <iostream>
#include <valarray>

using namespace std;

int main()
{
    valarray<int> myarr;
    cout<<"After construction: "<<myarr.size()<<endl;

    myarr = valarray<int>(5);
    cout<<"After assignment: "<<myarr.size()<<endl;

    myarr.resize(3);
    cout<<"After downsizing: "<<myarr.size()<<endl;

    myarr.resize(10);
    cout<<"After resizing up: "<<myarr.size()<<endl;
    
    return 0;
}