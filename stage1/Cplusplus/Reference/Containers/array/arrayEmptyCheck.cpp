// file : arrayEmptyCheck.cpp
// constexpr bool empty() noexcept;
// Test whether array is empty
// if size == 0 return true else return false

#include <iostream>
#include <array>

using namespace std;

int main()
{
        array<int,0> a1;
        array<int,5> a2;

        cout<<"a1 is"<<(a1.empty() ? " empty." : " not empty.")<<"\n";
        cout<<"a2 is"<<(a2.empty() ? "empty." : " not empty.")<<"\n";

        return 0;
}
