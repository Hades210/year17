// file : valarrayswapCheck.cpp
//void swap (valarray& x) noexcept;
//Swap valarray contents
//Exchanges the contents of *this and x.
//template <class T>
//  void swap (valarray<T>& x, valarray<T>& y) noexcept;



#include <iostream>
#include <valarray>

using namespace std;

void printInfo(const string& who, valarray<int>& myarr)
{
    cout<<who<<" contains: ";
    for(auto& x : myarr)
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
    valarray<int> foo {10,20,30,40};
    valarray<int> bar {100,200,300};

    printInfo("foo",foo);
    printInfo("bar",bar);

    cout<<"After first swap"<<endl;
    foo.swap(bar);
    printInfo("foo",foo);
    printInfo("bar",bar);

    cout<<"After second swap"<<endl;
    swap(foo,bar);
    printInfo("foo",foo);
    printInfo("bar",bar);

    return 0;
}