// file : arrayFillCheck.cpp
// void fill(const value_type& val);

#include <iostream>
#include <array>

using namespace std;

int main()
{
        array<int,6> myarray;
        myarray.fill(5);

        for(auto & i : myarray)
                cout<<i<<"\t";
        cout<<"\n";
        
        return 0;
}
