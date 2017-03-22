// file : minmaxCheck.cpp
/***********************************************************************************************************
*	default(1)	template<class T> const T& min(const T& a, const T& b);
*	custom(2)	template<class T, class Compare> const T& min(const T& a, const T& b, Compare comp);
*	il(3)		template<class T> T min(initializer_list<T> il);
*				template<class T, class Compare> T min(initializer_list<T> il, Compare comp); 
***********************************************************************************************************/
// Returns the smallest of a and b. If both are equivalent, a is returned.
// The versions for il(3) return the smallest of all the elements in the list. Returning the first of them if these 
// are more than one.
// The function uses operator< (or comp) to compare the values.
// The behavior of this function template is equivalent to:
// template <class T>
// const T& min(const T& a, const T& b)
// {
// 	return !(b<a)?a:b;
// }

/***********************************************************************************************************
*	default(1)	template<class T> const T& max(const T& a, const T& b);
*	custom(2)	template<class T, class Compare> const T& max(const T& a, const T& b, Compare comp);
*	il(3)		template<class T> T max(initializer_list<T> il);
*				template<class T, class Compare> T max(initializer_list<T> il, Compare comp); 
***********************************************************************************************************/
// Returns the largest of a and b. If both are equivalent, a is returned.
// The versions for il(3) return the largest of all the elements in the list. Returning the first of them if these 
// are more than one.
// The function uses operator< (or comp) to compare the values.
// The behavior of this function template is equivalent to:
// template <class T>
// const T& max(const T& a, const T& b)
// {
// 	return (a<b)?b:a;
// }

/***********************************************************************************************************
*	default(1)	template<class T>  pair<const T&,const T&> minmax(const T& a, const T& b);
*	custom(2)	template<class T, class Compare> pair<const T&,const T&> minmax(const T& a, const T& b, Compare comp);
*	il(3)		template<class T> pair<T,T> minmax(initializer_list<T> il);
*				template<class T, class Compare> pair<T,T> minmax(initializer_list<T> il, Compare comp); 
***********************************************************************************************************/
// Returns a pair with the smallest of a and b as first element, and the largest as second. If both are equivalent,the function returns
// make_pair(a,b).
// The versions for il(3) return a pair with the smallest of all the elements in the list as first element(the first of them if these 
// are more than one) and the largest as second(the last of them,if there are more than one).
// The function uses operator< (or comp) to compare the values.
// The behavior of this function template is equivalent to:
// template <class T>
// pair<const T&,const T&> minmax(const T& a, const T& b)
// {
//		return (b<a): make_pair(b,a):make_pair(a,b);
// }

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cout<<"min(1,2) == "<<min(1,2)<<endl;
	cout<<"min(2,1) == "<<min(2,1)<<endl;
	cout<<"min('a','z') == "<<min('a','z')<<endl;
	cout<<"min(3.14,2.72) == "<<min(3.14,2.72)<<endl;

	cout<<"max(1,2) == "<<max(1,2)<<endl;
	cout<<"max(2,1) == "<<max(2,1)<<endl;
	cout<<"max('a','z') == "<<max('a','z')<<endl;
	cout<<"max(3.14,2.73) == "<<max(3.14,2.73)<<endl;

	auto result = minmax({1,2,3,4,5});

	cout<<"minmax({1,2,3,4,5}): ";
	cout<<result.first<<' '<<result.second<<endl;

	return 0;
}