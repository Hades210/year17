// file : listRelationalOperationCheck.cpp
// (1)  template <class T, class Alloc>
//              bool operator == (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
// (2)  template <class T, class Alloc>
//              bool operator != (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
// (3)  template <class T, class Alloc>
//              bool operator < (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
// (4)  template <class T, class Alloc>
//              bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
// (5)  template <class T, class Alloc>
//              bool operator > (const list<T, Alloc>& lhs, const list<T,Alloc>& rhs);
// (6)  template <class T, class Alloc>
//              bool operator >= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
//

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> a = {10,20,30};
	list<int> b = {10,20,30};
	list<int> c = {30,10,20};

	if(a == b)
		cout<<"a == b\n";
	if(a != b)
		cout<<"a != b\n";

	if(b < c)
		cout<<"b < c\n";
	if(b > c)
		cout<<"b > c\n";

	if(a <= b)
		cout<<"a <= b\n";
	if(a >= b)
		cout<<"a >= b\n";
	
	return 0;
}
