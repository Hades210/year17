// file : unordered_mapClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_map<string,string> mymap = {{"house","maison"},{"car","voiture"},{"grapefruit","pamplemousse"}};

        printInfo("mymap",mymap);

        mymap.clear();
        mymap["hello"] = "bonjour";
        mymap["sun"] = "soleil";

        printInfo("mymap",mymap);
        return 0;
}
