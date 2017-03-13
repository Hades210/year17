// file : unordered_multimapObserversCheck.cpp
/***************************************************************
*	hasher hash_function() const;
*	key_equal key_eq() const;
*	allocator_type get_allocator() const noexcept;
****************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_multimap<string,string> umm;

	unordered_multimap<string,string>::hasher hf = umm.hash_function();

	cout<<"this: "<<hf("this")<<endl;
	cout<<"thin: "<<hf("thin")<<endl;

	bool case_insensitive = umm.key_eq()("test","TEST");

	cout<<"umm.key_eq() is ";
	cout<<(case_insensitive ? "case insensitive" : "case sensitive");
	cout<<endl;
	
	return 0;
}
