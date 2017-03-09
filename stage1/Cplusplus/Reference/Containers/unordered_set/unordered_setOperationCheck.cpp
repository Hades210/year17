// file : unordered_setOperationCheck.cpp
/****************************************************************************************************
*       equality(1)             template <class Key, class Hash, class Pred, class Alloc>
*                                               bool operator== (const unordered_set<Key,Hash,Pred,Alloc>& lhs,
*                                                                                const unordered_set<Key,Hash,Pred,Alloc>& rhs);
*       inequality(2)   template <class Key, class Hash, class Pred, class Alloc>       
*                                               bool operator!= (const unordered_set<Key,Hash,Pred,Alloc>& lhs,
                                                                                 const unordered_set<Key,Hahs,Pred,Alloc>& rhs);
****************************************************************************************************/
// The procedure for the equality comparison is as follows(stopping at any point if the procedure finds a 
// conclusive answer):
// First,the sizes are compared.
// Then,each element in one of the containers is looked for in the other.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
        unordered_set<string>
        a = {"AAPL","MSFT","GOOD"},
        b = {"GOOD","AAPL","MSFT"},
        c = {"Microsoft","Google","Facebook","Amazon"};

        if(a == b)
                cout<<"a and b are equal\n";
        if (b != c)
                cout<<"b and c are not equal\n";

        return 0;
}
