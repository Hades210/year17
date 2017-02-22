// file : listBeginCheck.cpp
// iterator begin() noexcept;
// const_iterator begin() const noexcept;
// iterator end() noexcept;
// const_iterator end() const noexcept;


#include <iostream>
#include <list>

using namespace std;

int main()
{
	int myints[] = {75,23,65,42,13};

	list<int> myList (myints, myints + 5 );

	cout<<"myList contains:";
	for(list<int>::iterator it = myList.begin(); it != myList.end(); ++ it) 
	{
		cout<<" "<<*it;
	}

	cout<<"\n";
	return 0;
}
