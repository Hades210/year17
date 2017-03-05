// file : mapEmptyCheck.cpp
// bool empty() const noexcept;
// size_type size() const noexcept;
// size_type max_size() const noexcept;

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	cout<<"mymap size "<<mymap.size()<<endl;
	cout<<"mymap max_size "<<mymap.max_size()<<endl;

	while(!mymap.empty())
	{
		cout<<mymap.begin()->first<<" = "<<mymap.begin()->second<<"\n"; 
		mymap.erase(mymap.begin());
	}



	return 0;
}
