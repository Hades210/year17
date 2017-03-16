// file : listInsertCheck.cpp

/******************************************************************************************************************
*	single element (1)	iterator insert(const_iterator position, const value_type& val);
*	fill (2)			iterator insert(const_iterator position, size_type n, const value_type& val);
*	range(3)			template <class InputIterator>
*							iterator insert(const_iterator position, InputIterator first, InputIterator last );
*	move(4)				iterator insert(const_iterator position, value_type&& val);
*	il (5)				iterator insert(const_iterator postion, initializer_list<value_type> il);
*******************************************************************************************************************/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	list<int> mylist;
	list<int>::iterator it;

	for(int i = 1; i <= 5; ++ i)
		mylist.push_back(i);

	it = mylist.begin();
	++ it;

	mylist.insert(it,10);
	mylist.insert(it,2,20);

	-- it;

	vector<int> myVector (2,30);
	mylist.insert(it,myVector.begin(),myVector.end());

	cout<<"mylist contains:";
	for(auto& x : mylist)
		cout<<"\t"<<x;
	cout<<endl;

	return 0;
}
