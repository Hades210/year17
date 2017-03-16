// file : listConstructorCheck.cpp
/***************************************************************************************************************
*	default (1) explicit list (const allocator_type& alloc = allocator_type());
*				explicit list (size_type n);
*	fill(2)		list (size_type n, const value_type& val,)
*						const allocator_type& alloc = allocator_type() );
*	range(3)	template <class InputIterator>
*					list <InputIterator first, InputIterator last,
*						const allocator_type& alloc = allocator_type() );
*	copy(4)		list (const list& x);
*				list (const list& x, const allocator_type& alloc);
*	move(5)		list (list&& x);
*				list(list&& x, const allocator_type& alloc);
*	il(6)		list(initializer_list<value_type> il,
*					const allocator_type& alloc = allocator_type());
**************************************************************************************************************/

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> first;
	list<int> second (4,100);
	list<int> third (second.begin(),second.end());
	list<int> fourth (third);

	int myints[] = {16,2,77,29};
	list<int> fifth (myints,myints+4);

	cout<<"The contents of fifth are: ";
	for(list<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	
	return 0;
}
