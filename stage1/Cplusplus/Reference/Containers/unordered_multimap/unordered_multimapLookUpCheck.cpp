// file : unordered_multimapLookUpCheck.cpp
/*******************************************************
*	iterator find(const key_type& k);
*	const_iterator find(const key_type& k) const;
*	size_type count(const key_type& k) const;
*	pair<iterator,iterator>
*		equal_range(const key_type& k);
*	pair<const_iterator,const_iterator>
*		equal_range(const key_type& k) const;
********************************************************/

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm> // for_each()

using namespace std;

typedef unordered_multimap<string,string> UMMSTR;

int main()
{
	UMMSTR first = {
			{"mom","church"},
			{"mom","college"},
			{"dad","office"},
			{"bro","school"}
	};

	cout<<"one of the values for 'mom' is: ";
	cout<<first.find("mom")->second;
	cout<<endl;

	UMMSTR second = {
			{"orange","FL"},
			{"strawberry","LA"},
			{"strawberry","OK"},
			{"pumpkin","NH"}
	};

	for(auto& x : {"orange","lemon","strawberry"})
		cout<<x<<": "<<second.count(x)<<" entries.\n";


	cout<<"Entries with strawberry:";
	auto range = second.equal_range("strawberry");

	for_each(range.first,range.second,[](UMMSTR::value_type& x){cout<<" "<<x.second;});
	cout<<endl;
	return 0;
}
