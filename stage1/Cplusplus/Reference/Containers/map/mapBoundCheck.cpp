// file : mapBoundCheck.cpp

// iterator lower_bound(const key_type& k);
// const_iterator lowere_bound(const key_type& k) const;
// Return an iterator pointing to the first element in the container whose key is not considered to go before k (either it is equivalent or goes after)
// The function uses its internal comparison object(key_comp) to determine this, returning an iterator to the first element for which key_comp(element_key,k) would return false.

// iterator upper_bound(const key_type& k);
// const_iterator upper_bound(const key_type& k) const;
// Return an iterator pointing to the first element in the container whose key is considered to go after k.
// The function uses its internal comparison object(key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.

#include <iostream>
#include <map>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	map<char,int> mymap;
	map<char,int>::iterator itlow,itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	cout<<itlow->first<<" : "<<itlow->second<<"\n";
	cout<<itup->first<<" : "<<itup->second<<"\n";


	mymap.erase(itlow,itup);

	printInfo("mymap",mymap);

	map<char,int, greater<char> > mymap2;
	map<char,int, greater<char> >::iterator itlow2,itup2;

	mymap2['a'] = 20;
	mymap2['b'] = 40;
	mymap2['c'] = 60;
	mymap2['d'] = 80;
	mymap2['e'] = 100;

	printInfo("mymap2",mymap2);

	itlow2 = mymap2.lower_bound('b');
	cout<<itlow2->first<<" : "<<itlow2->second<<"\n";
	itup2 = mymap2.upper_bound('d');
	cout<<itup2->first<<" : "<<itup2->second<<"\n";

	mymap2.erase(itup2,itlow2);
	printInfo("mymap2",mymap2);

	return 0;
}
