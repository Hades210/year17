// file : unordered_mapSwapCheck.cpp
// void swap(unordered_map& ump);

#include <iostream>
#include <unordered_map>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_map<string,string> 
        first = {{"Star Wars","G. Lucas"},{"Alien","R. Scott"},{"Terminator","J. Cameron"}},
        second = {{"Inception","C. Nolan"},{"Donnie Darko","R. Kelly"}};

        first.swap(second);
        printInfo("first",first);
        printInfo("second",second);

        swap(first,second);
        printInfo("first",first);
        printInfo("second",second);
        
        return 0;
}
