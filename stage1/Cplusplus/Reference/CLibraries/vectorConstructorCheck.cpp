// file : vectorConstructorCheck.cpp
// template <class T, class Alloc = allocator<T> > class vector ; generic template 
// default(1), fill(2), range(3), copy(4), move(5), initializer list(6)
// default(1)		explicit vector (const allocator_type& alloc = allocator_type());
// fill(2)			explicit vector (size_type n); explicit vector (size_type n, const value_type& val, const allocator_type& alloc = allocator_type());
// range(3)			template <class InputIterator>
//  				vector (InputIterator first, InputIterator last,
//          			const allocator_type& alloc = allocator_type());
// copy(4)			vector (const vector& x);
//					vector (const vector& x, const allocator_type& alloc)
// move(5)
// initializer list (6)

#include <iostream>
#include <vector>

using namespace std;

template <class T>
void print_vector(const vector<T>& v)
{
	for(vector<T>::const_iterator it = v.begin(); it != v.end(); ++ it)
		cout<<' '<<*it;
	cout<<endl;
}

int main()
{
	vector<int> first;
	print_vector(first);

	vector<int> second(4,100);
	print_vector(second);

	vector<int> third(second.begin(),second.end());
	print_vector(third);

	vector<int> forth (third);
	print_vector(forth);

	int myInts[] = {16,2,4,19};
	vector<int> fifth (myInts,myInts + sizeof(myInts) / sizeof(int));
	print_vector(fifth);

	return 0;
}
