// file : mapValueCheck.cpp
// value_compare value_comp() const;
// Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
// The arguments taken by this function object are of member type value_type (defined in map as an alias of pair<const key_type,mapped_type>)
// but the mapped_type part of the value is not taken into consideration in this comparison.
// The comparison object returned is an object of the member type map::value_compare,which is a nested class that uses the internal 
// comparison object to generate the appropriate comparison functional class. It is defined with the same behavior as:
/*********************************************************************************************************************************************
*	template<class Key, class T, class Compare, class Alloc>
*	class map<Key,T,Compare,Alloc>::value_compare
*	{
*		friend class map;
*	protected:
*		Compare comp;
*		value_compare(Compare c) : comp(c) {}
*	public:
*		typedef bool result_type;
*		typedef value_type first_argument_type;
*		typedef value_type second_argument_type;
*		bool operator() (const value_type& x, const value_type& y) const
*		{ return comp(x.fist,y.first); }		
*	};
**********************************************************************************************************************************************/

// The public member of this comparison class returns true if the key of the first argument is considered to go before that of the second,and false otherwise.
// Notice that value_compare has no public constructor, therefore no objects can be directly crfeated from this nested class outside map members.

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	cout<<"mymap contains: \n";
	pair<char,int> highest = *mymap.rbegin();

	map<char,int>::iterator it = mymap.begin();

	do
	{
		cout<<it->first<<" : "<<it->second<<"\n";
	}while(mymap.value_comp()(*it++,highest));
	
	return 0;
}
