// file : forward_listConstructorCheck.cpp
// c++ 11 only
/***************************************************************************************************************
*	default (1) explicit forward_list (const allocator_type& alloc = allocator_type());
*				explicit forward_list (size_type n);
*	fill(2)		forward_list (size_type n, const value_type& val,)
*						const allocator_type& alloc = allocator_type() );
*	range(3)	template <class InputIterator>
*					forward_list <InputIterator first, InputIterator last,
*						const allocator_type& alloc = allocator_type() );
*	copy(4)		forward_list (const forward_list& x);
*				forward_list (const forward_list& x, const allocator_type& alloc);
*	move(5)		forward_list (forward_list&& x);
*				forward_list(forward_list&& x, const allocator_type& alloc);
*	il(6)		forward_list(initializer_list<value_type> il,
*					const allocator_type& alloc = allocator_type());
**************************************************************************************************************/

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> first;
	forward_list<int> second(3,77);
	forward_list<int> third (second.begin(),second.end());
	forward_list<int> fourth (third);

	forward_list<int> fifth (move(fourth)); // move fourth wasted
	forward_list<int> sixth = {1,2,43,5};

	cout<<"first: "; for(auto& x : first ) cout<<x<<"\t"; cout<<"\n";
	cout<<"second: "; for(auto& x : second ) cout<<x<<"\t"; cout<<"\n";
	cout<<"third: "; for(auto& x : third ) cout<<x<<"\t"; cout<<"\n";

	cout<<"fourth: "; for(auto& x : fourth ) cout<<x<<"\t"; cout<<"\n";

	cout<<"fifth: "; for(auto& x : fifth ) cout<<x<<"\t"; cout<<"\n";
	cout<<"sixth: "; for(auto& x : sixth ) cout<<x<<"\t"; cout<<"\n";


	return 0;
}
