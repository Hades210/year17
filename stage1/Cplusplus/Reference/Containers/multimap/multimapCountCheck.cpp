// file : multimapCountCheck.cpp
// size_type count(const key_type& k) const;

#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<char,int> mymap;

	mymap.insert(make_pair('x',50));
	mymap.insert(make_pair('y',100));
	mymap.insert(make_pair('y',150));
	mymap.insert(make_pair('y',200));
	mymap.insert(make_pair('z',250));
	mymap.insert(make_pair('z',300));

	for(char c = 'x' ; c <= 'z'; c++)
	{
		cout<<"There are "<<mymap.count(c)<<" elements with key "<<c<<": ";
		multimap<char,int>::iterator it;

		for(it = mymap.equal_range(c).first; it != mymap.equal_range(c).second; ++it)
			cout<<" "<<(*it).second;
		// for(it = mymap.lower_bound(c); it != mymap.upper_bound(c); ++ it)
		// 	cout<<" "<<(*it).second;
		cout<<"\n";
	} 
	return 0;
}
