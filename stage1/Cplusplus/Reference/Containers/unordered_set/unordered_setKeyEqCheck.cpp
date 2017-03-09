// file : unordered_setKeyEqCheck.cpp
// key_equal key_eq() const;
//  Returns the key equivalence comparison predicate used by the unordered_set container.
// The key equivalence comparison is a predicate that takes the value of two elements as arguments and returns a bool value indicating 
// whether they ar eto be considered equivalent. It is adopted by the container on construction. By default, it is equal_to<key_type>
// which returns the same as applying the equal-to operator(==) to the arguments.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
        unordered_set<string> myset;

        bool case_insensitive = myset.key_eq()("checking","CHECKING");

        cout<<"myset.key_eq() is ";
        cout<<(case_insensitive ?"case insensitive" : "case sensitive");
        cout<<"\n ";
        
        return 0;
}
