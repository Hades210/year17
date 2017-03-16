// file : listCbeginCheck.cpp
// const_iterator cbegin() const noexcept;
// const_iterator cend() const noexcept;
// c++ 11 only

#include <iostream>
#include <list>

using namespace std;

int main() 
{
	list<int> mylist = {5,10,15,20};

	cout<<"mylist contains:";

	for(auto cit = mylist.cbegin(); cit != mylist.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;
	
	return 0;
}
