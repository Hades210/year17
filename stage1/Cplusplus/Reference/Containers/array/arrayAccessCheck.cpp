// file : arrayAccessCheck.cpp
// reference operator[] (size_type n);
// const_reference operator[](size_type n) const;
// reference at(size_type n);
// const_reference at(size_type n) const;

#include <iostream>
#include <array>

using namespace std;

int main()
{
        array<int,10> myarray;

        for(int i = 0; i < 5; i ++)
                myarray[i] = i;

        for(int i = 5; i < 10; i ++)
                myarray.at(i) = i;

        for(auto & i : myarray)
                cout<<i<<"\t";
        cout<<"\n";

        return 0;
}
