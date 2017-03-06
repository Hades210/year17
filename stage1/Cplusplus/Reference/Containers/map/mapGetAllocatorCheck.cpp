// file : mapGetAllocatorCheck.cpp
// allocator_type get_allocator() const noexcept;

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int psize;
	map<char,int> mymap;
	pair<const char,int>* p;

	p = mymap.get_allocator().allocate(5);

	psize = sizeof(map<char,int>::value_type) * 5;

	for(int i = 0; i < 5; i ++)
		mymap.get_allocator().construct(&p[i],'a' + i,i);

	cout<<"The allocated array has a size of "<<psize<<" bytes.\n";

	for(int i = 0; i < 5; i ++)
		cout<<p[i].first<<" : "<<p[i].second<<"\n";

	for(int i = 0; i < 5; i ++)
		mymap.get_allocator().destroy(&p[i]);

	mymap.get_allocator().deallocate(p,5);

	return 0;
}
