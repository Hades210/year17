// file : arrayDataCheck.cpp 
// value_type* data() noexcept;
// const value_type* data() const noexcept;
// Get pointer to data return a pointer to the first element in the array object

#include <iostream>
#include <cstring>
#include <array>

using namespace std;

int main()
{
        const char* str = "Hello world.";
        array<char,13> myarray;

        memcpy(myarray.data(),str,13);

        cout<<myarray.data()<<"\n";

        return 0;
}
