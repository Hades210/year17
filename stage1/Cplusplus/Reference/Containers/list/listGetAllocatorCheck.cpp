// file : listGetAllocatorCheck.cpp
// allocator_type get_allocator() const noexcept;

// step 1: list<T>.get_allocator().allocate(const size_type& n);
// step 2: list<T>.get_allocator().construct(T*,i);
// step 3: list<T>.get_allocator().destroy(T*);
// step 4: list<T>.get_allocator().deallocator(T*,size_type n);

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	int* p = mylist.get_allocator().allocate(5);

	for(int i = 0; i < 5; i ++)
		mylist.get_allocator().construct(&p[i],i);

	for(int i = 0; i < 5; i ++)
		cout<<p[i]<<" ";
	cout<<endl;

	for(int i = 0; i < 5; i ++)
		mylist.get_allocator().destroy(&p[i]);

	mylist.get_allocator().deallocate(p,5);

	return 0;
}
