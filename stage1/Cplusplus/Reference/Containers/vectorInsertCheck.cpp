// file : vectorInsertCheck.cpp
// 
//	single element(1):		iterator insert(const_iterator position, const value_type& val);
//
// 	fill(2):				iterator insert(const_iterator position, size_type n, const value_type& val);
//
//  range(3):				template <class InputIterator>
//							iterator insert(const_iterator position, InputIterator first, InputIterator last);
//
//  move(4):				iterator insert(const_iterator position, value_type& val);
//
//	initializer list(5):	iterator insert(const_iterator position, initializer_list<value_type> il);
//
//  position is the place should be inserted in

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector (3,100);
	vector<int>::iterator it;

	it = myVector.begin();
	it = myVector.insert(it,200);

	myVector.insert(it,2,300);

	it = myVector.begin();

	vector<int> anotherVector(2,400);
	myVector.insert(it + 2, anotherVector.begin(),anotherVector.end());


	int myarray[] = {501,502,503};
	myVector.insert(myVector.begin(),myarray,myarray + 3);

	myVector.insert(myVector.begin(),myarray[0]);

	cout<<"myVector contains:";

	for(auto cit = myVector.cbegin(); cit != myVector.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;
	
	return 0;
}
