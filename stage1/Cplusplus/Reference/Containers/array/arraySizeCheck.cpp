// file :arraySizeCheck.cpp
//constexpr size_type size() noexcept;

#include <iostream>
#include <array>

using namespace std;

int main()
{
        array<int,5> myints;

        cout<<"myints.size():"<<myints.size()<<"\n";
        cout<<"sizeof(myints):"<<sizeof(myints)<<"\n";
        
        return 0;
}
