// file : list_opCheck.cpp

#include <iostream>
#include <list>

using namespace std;

void useCheck()
{
	int myints[] = {2,3,2,3,5};
	list<int> lst (myints,myints + 5);

	lst.remove(3);
	lst.sort();

	lst.unique(); // even though it is already in order, but you have to sort it before unique be called.
	cout<<lst.size()<<endl;
}

void spliceCheck()
{
	list<int> lst1({1,2,3});
	list<int> lst2({5,6,7});

	auto p = lst1.begin();
	++p;

	auto q = lst2.begin();
	++q;

	lst1.splice(p,lst2);

	for(auto& x : lst1)
		cout <<x<<" ";
	cout<<endl;

	cout<<*p<<endl;
	cout<<*q<<endl;
}

int main()
{

	useCheck();

	spliceCheck();
	return 0;
}