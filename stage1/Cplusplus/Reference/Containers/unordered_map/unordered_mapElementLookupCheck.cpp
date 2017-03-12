// file : unordered_mapElementLookupCheck.cpp
/************************************************************
*	iterator find(const key_type& k);
*	const_iterator find(const key_type& k) const;
*	size_type count(const key_type& k) const;
*	pair<iterator,iterator>
*		equal_range(const key_type& k);
*	pair<const_iterator,const_iterator>
*		equal_range(const key_type& k) const;
************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string,double> first = {{"mom",5.4},{"dad",6.1},{"sister",5.9}};

	string input;
	cout<<"who?";
	getline(cin,input);

	unordered_map<string,double>::iterator got = first.find(input);

	if(got == first.end())
		cout<<"not found"<<endl;
	else
		cout<<got->first<<" is "<<got->second<<endl;

	unordered_map<string,double> second = {{"Burger",2.99},{"Fries",1.99},{"Soda",1.50}};

	for(auto& x : {"Burger","Soda","Pizza","Salad"})
	{
		if(second.count(x) > 0)
			cout<<"second has "<<x<<endl;
		else
			cout<<"second has no "<<x<<endl;
	}
	
	return 0;
}
