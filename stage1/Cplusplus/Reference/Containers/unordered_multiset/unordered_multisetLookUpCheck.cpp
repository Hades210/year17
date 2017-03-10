// file : unordered_multisetLookUpCheck.cpp
/****************************************************************
*	iterator find(const key_type& k);
*	const_iterator find(const key_type& k) const;
*	size_type count(const key_type& k) const;
*	pair<iterator,iterator>
*		equal_range(const key_type& k);
*	pair<const_iterator,const_iterator>
*		equal_range(const key_type& k) const;
****************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<string> myums = {"cow","cow","pig","sheep","pig"};
	unordered_multiset<string>::iterator it = myums.find("pig");

	if(it != myums.end())
		cout<<*it<<" found"<<endl;

	unordered_multiset<string> myums2 = {"cow","pig","chicken","pig","pig","cow"};

	for(auto& x : {"cow","sheep","pig"})
	{
		cout<<x<<" : "<<myums2.count(x)<<endl;
	}

	unordered_multiset<string> myums3 = {"cow","pig","pig","chicken","pig","chicken"};
	auto range = myums3.equal_range("pig");

	cout<<"These pigs were found: ";
	while(range.first != range.second)
		cout<<*range.first++<<" ";
	cout<<endl;

	return 0;
}
