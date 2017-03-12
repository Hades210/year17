// file : unordered_mapElementAccessCheck.cpp
/*****************************************************************************
*	mapped_type& operator[] (const key_type& k);
*	mapped_type& operator[] (key_type&& k);
*	mapped_type& at(const key_type& k);
*	const mapped_type& at(const key_type& k) const;
******************************************************************************/
// [] access element If k matches the key of an element in the container, the function returns a reference to its mapped value.
// If k does not match the key of any element in the container, the function inserts a new element with that key and returns a 
// reference to its mapped value.
// A similar member function,unordered_map::at,has the same behavior when an element with the key exists, but throws an exception when it does not.

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_map<string,string> mymap;

	mymap["Bakery"] = "Barbara";
	mymap["Seafood"] = "Lisa";
	mymap["Produce"] = "John";

	string name = mymap["Bakery"];
	mymap["Seafood"] = name;
	mymap["Bakery"] = mymap["Produce"];
	name = mymap["Deli"];
	mymap["Produce"] = mymap["Gifts"];

	printInfo("mymap",mymap);

	unordered_map<string,int> mymap2 = {{"Mars",3000},
										{"Saturn",60000},
										{"Jupiter",70000}};

	mymap2.at("Mars") = 3396;
	mymap2.at("Saturn") += 272;
	mymap2.at("Jupiter") = mymap2.at("Saturn") + 9638;

	printInfo("mymap2",mymap2);
	return 0;
}
