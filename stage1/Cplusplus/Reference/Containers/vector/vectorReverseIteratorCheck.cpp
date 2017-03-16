// file : vectorReverseIteratorChecker.cpp
// reverse_iterator, const_reverse_iterator, rbegin, rend

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector(5);
	int i = 0;

	for(vector<int>::reverse_iterator rit = myVector.rbegin(); rit != myVector.rend(); ++rit)
		*rit = ++ i;

	cout<<"myVector contains: ";
	for(vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
		cout<<' '<<*it;
	cout<<endl;

	return 0;
}
