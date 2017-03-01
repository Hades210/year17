// file : arrayFrontBackCheck.cpp
// reference front();
// const_reference front() const;
//reference back();
// const_reference back() const;

#include <iostream>
#include <array>

using namespace std;

int main()
{
        array<int,3> myarray = {100,200,300};

        myarray.front() = 10;
        myarray.back() = 30;

        for(int i = 0; i < myarray.size(); i ++)
                cout<<myarray[i] <<"\t";
        cout<<"\n";
        
        return 0;
}
