// file : unordered_mapObserverCheck.cpp
/**********************************************************
*	hasher hash_function() const;
*	key_equal key_eq() const;
*	allocator_type get_allocator() const noexcept;
***********************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string,string> mymap;
	unordered_map<string,string>::hasher hf = mymap.hash_function();

	cout<<"this:"<<hf("this")<<endl;
	cout<<"that:"<<hf("that")<<endl;

	bool case_insentive = mymap.key_eq()("test","TEST");

	cout<<"mymap.key_eq() is ";
	cout<<(case_insentive ? "case insensitive" : "case sensitive");
	cout<<endl;

	return 0;
}
