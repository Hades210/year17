// file : listCrbeginCheck.cpp
// const_reverse_iterator crbegin() const noexcept;
// const_reverse_iterator crend() const noexcept;
// c++ 11 only


#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist = {1,2,4,8,16};

	cout<<"mylist backwards:";

	for(auto cit = mylist.crbegin(); cit != mylist.crend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;

	return 0;
}
