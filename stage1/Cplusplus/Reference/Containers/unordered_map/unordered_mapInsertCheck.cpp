// file : unordered_mapInsertCheck.cpp
/**************************************************************************
*       (1)     pair<iterator,bool> insert(const value_type& val);
*       (2) template <class P>
*                       pair<iterator,bool> insert(P&& val);
*       (3)     iterator insert(const_iterator hint, const value_type& val);
*       (4)     template <class P>
*                       iterator insert(const_iterator hint, P&& val);
*       (5)     template <class InputIterator>
*                       void insert(InputIterator first, InputIterator last);
*       (6)     void insert(initializer_list<value_type> il);
***************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_map<string,double> myrecipe,mypantry = {{"milk",2.0},{"flour",1.5}};

        pair<string,double> myshopping ("baking powder",0.3);

        myrecipe.insert(myshopping); //copy
        myrecipe.insert(make_pair<string,double>("eggs",6.0)); // move
        myrecipe.insert(mypantry.begin(),mypantry.end()); // range 
        myrecipe.insert({{"sugar",0.8},{"salt",0.1}}); // initializer list

        printInfo("myrecippe",myrecipe);

        return 0;
}
