// file : multimapBoundCheck.cpp
/********************************************************************************************
*	iterator lower_bound(const key_type& k);
*	const_iterator lower_bound(const key_type& k) const;
*	iterator upper_bound(const key_type& k);
*	const_iterator upper_bound(const key_type& k) const;
*	pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
*	pair<iterator,iterator> equal_range(const key_type& k);
*********************************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<char,int> mymap;
	multimap<char,int>::iterator it,itlow,itup;

	mymap.insert(pair<char,int>('a',10));
	mymap.insert(pair<char,int>('b',121));
	mymap.insert(pair<char,int>('c',1001));
	mymap.insert(pair<char,int>('c',2002));
	mymap.insert(pair<char,int>('d',11011));
	mymap.insert(pair<char,int>('e',44));

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	for(it = itlow; it != itup; ++it)
		cout<<it->first<<" : "<<it->second<<"\n";

	multimap<char,int> mymap2;
	mymap2.insert(make_pair('a',10));
	mymap2.insert(make_pair('b',20));
	mymap2.insert(make_pair('b',30));
	mymap2.insert(make_pair('b',40));
	mymap2.insert(make_pair('c',50));
	mymap2.insert(make_pair('c',60));
	mymap2.insert(make_pair('d',60));

	cout<<"mymap2 contains:\n";

	for(char c = 'a'; c <= 'd'; c++)
	{
		cout<<c<<" : ";
		pair<multimap<char,int>::iterator,multimap<char,int>::iterator> ret;
		ret = mymap2.equal_range(c);

		for(multimap<char,int>::iterator it = ret.first; it != ret.second; ++ it)
			cout<<it->second<<" ";
		cout<<"\n";
	}

	return 0;
}
