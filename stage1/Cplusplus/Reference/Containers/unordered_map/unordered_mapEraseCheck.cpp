// file : unordered_mapEraseCheck.cpp
/*************************************************************************************
*       by position (1)         iterator erase(const_iterator position);
*       by key(2)                       size_type erase(const key_type& k);
*       range (3)                       iterator erase(const_iterator first, const_iterator last);
**************************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_map<string,string> mymap;

        mymap["US"] = "Washington";
        mymap["UK"] = "London";
        mymap["France"] = "Paris";
        mymap["Russia"] = "Moscow";
        mymap["China"] = "Beijing";
        mymap["Germany"] = "Berlin";
        mymap["Japan"] = "Tokyo";

        printInfo("mymap",mymap);

        mymap.erase(mymap.begin());
        mymap.erase("France");
        mymap.erase(mymap.find("Germany"),mymap.end());

        printInfo("mymap",mymap);

        return 0;
}
