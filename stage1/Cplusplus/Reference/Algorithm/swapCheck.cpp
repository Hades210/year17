// file : swapCheck.cpp
// moved from <algorithm> to <utility> in c++11
// non-array : template <class T> void swap(T& a, T& b)
//				noexcept (is_nothrow_move_constructible<T>::value && is_nothrow_move_assignable<T>::value);
// array:	   template <class T, size_t N> void swap(T (&a)[N], T(&b)[N])
//				noexcept(noexcept(swap(*a,*b)));
//The behavior of these function templates is equivalent to:
// template <class T> 
// void swap(T& a, T& b)
// {
// 	T c(move(a));
// 	a = move(b);
// 	b = move(c);
// }

// template <class T, size_t N>
// void swap(T(&a)[N],T(&b)[N])
// {
// 	for(size_t i = 0; i < N; ++i)
// 		swap(a[i],b[i]);
// }

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int x = 10, y = 20;

	swap(x,y);

	vector<int> foo(4,x), bar(6,y);
	swap(foo,bar);

	cout<<"foo contains: ";
	for(auto& x : foo)
		cout<<x<<" ";
	cout<<endl;

	cout<<"bar contains: ";
	for(auto& x : bar)
		cout<<x<<" ";
	cout<<endl;
	
	return 0;
}