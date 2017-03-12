// file : unordered_mapOperatorCheck.cpp
/********************************************************************************
*       copy(1)         unordered_map& operator= (const unordered_map& ump);
*       move(2)         unordered_map& operator= (unordered_map&& ump);
*       il(3)           unordered_map& operator= (initializer_list<value_type> il);
********************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

typedef unordered_map<string,string> STRMAP;

STRMAP merge(STRMAP a, STRMAP b)
{
        STRMAP t (a);
        t.insert(b.begin(),b.end());
        return t;
}

using namespace std;

int main()
{
        STRMAP first,second,third;

        first = {{"AAPL","Apple"},{"MSFT","Microsoft"}};        // init list
        second = {{"GOOG","Google"},{"ORCL","Oracle"}};         // init list
        third = merge(first, second);  // move
        first = third;          // copy

        printInfo("first",first);
        printInfo("second",second);
        printInfo("third",third);

        return 0;
}
