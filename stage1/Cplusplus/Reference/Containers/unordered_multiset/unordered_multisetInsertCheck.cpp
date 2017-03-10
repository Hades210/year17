// file : unordered_multisetInsertCheck.cpp
/*****************************************************************
*       iterator insert(const value_type& val);
*       iterator insert(value_type&& val);
*       iterator insert(const_iterator hint, const value_type& val);
*       iterator insert(const_iterator hint, value_type&& val);
*       template <class InputIterator>
*               void insert(InputIterator first, InputIterator last);
*       iterator insert(initializer_list<value_type> il);
******************************************************************/
// In the version returning a value, the function returns an iterator to the newly inserted element.

#include <iostream>
#include <unordered_set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_multiset<string> myums = {"red","green","blue"};
        array<string,2> myarray = {"red","yellow"};
        string mystr = "red";

        myums.insert(mystr); //  copy 
        myums.insert(mystr + "dish"); // move
        myums.insert(myarray.begin(),myarray.end()); // range 
        myums.insert({"purple","orange"}); // initializer list

        printInfo("myums",myums);
        return 0;
}
unordered_multisetInsertCheck.cpp (END)
