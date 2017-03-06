// file : unordered_setFindCheck.cpp
// iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;
// Return an iterator to the element, if the specified value is found, or unordered_set::end if it is not found in the container.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<string> myset = {"red","green","blue"};

	string input;
	cout<<"color?";

	while(true)
	{
		getline(cin,input);
		if(input == "exit")
			break;

		unordered_set<string>::const_iterator got = myset.find(input);

		if(got == myset.end())
			cout<<"not found in myset";
		else
			cout<<*got<<" is in myset";

		cout<<endl;
	}

	return 0;
}
