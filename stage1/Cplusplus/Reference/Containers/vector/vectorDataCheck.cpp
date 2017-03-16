// file : vectorDataCheck.cpp
// value_type * data() noexcept;
// const value_type * data() const noexcept;
// c++ 11 only

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector (5);

	int* p = myVector.data();

	*p = 10;
	++p;
	*p = 20;
	p[2] = 100;

	cout<<"myVector contains:";

	for(auto cit = myVector.cbegin(); cit != myVector.end(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;
	
	return 0;
}
