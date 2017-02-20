// file : vectorRelationalOperationCheck.cpp
// (1)	template <class T, class Alloc>
//		bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// (2)	template <class T, class Alloc>
//		bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// (3)	template <class T, class Alloc>
//		bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// (4)	template <class T, class Alloc>
//		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// (5)	template <class T, class Alloc>
//		bool operator > (const vector<T, Alloc>& lhs, const vector<T,Alloc>& rhs);
// (6)	template <class T, class Alloc>
//		bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> foo (3,100);
	vector<int> bar (2,200);

	if(foo == bar)
		cout<<"foo and bar are equal\n";
	if (foo != bar)
		cout<<"foo and bar are not equal\n";
	if(foo < bar)
		cout<<"foo is less than bar\n";
	if (foo > bar)
		cout<<"foo is greater than bar\n";
	if(foo <= bar)
		cout<<"foo is less than or equal to bar\n";
	if (foo >= bar)
		cout<<"foo is greater than or equal to bar\n";
	
	return 0;
}
