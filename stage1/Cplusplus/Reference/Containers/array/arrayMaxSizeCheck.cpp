// file : arrayMaxSizeCheck.cpp
// constexpr size_type max_size() noexcept;
// In array, size() and max_size() are both equal to the second template parameter

#include <iostream>
#include <array>

using namespace std;

int main()
{
        array<int,5> myints;

        cout<<"myints.size():"<<myints.size()<<"\n";
        cout<<"myints.max_size():"<<myints.max_size()<<"\n";

        return 0;
}
