// // file : operatorCheck.cpp
// /* member functions: */
// duration& operator= (const duration& rhs) = default;
// constexpr duration operator+() const;
// constexpr duration operator-() const;
// duration& operator++();
// duration  operator++(int);
// duration& operator--();
// duration  operator--(int);
// duration& operator+= (const duration& rhs);
// duration& operator-= (const duration& rhs);
// duration& operator*= (const rep& r);
// duration& operator/= (const rep& r);
// duration& operator%= (const rep& r);
// duration& operator%= (const duration& rhs);
// /* non-member functions: */
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr typename common_type<duration<Rep1,Period1>,duration<Rep2,Period2>>::type
//   operator+ (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr typename common_type<duration<Rep1,Period1>,duration<Rep2,Period2>>::type
//   operator- (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);
// template <class Rep1, class Period, class Rep2>
// constexpr duration<typename common_type<Rep1,Rep2>::type, Period>
//   operator* (const duration<Rep1,Period>& lhs, const Rep2& r);
// template <class Rep1, class Rep2, class Period>
// constexpr duration<typename common_type<Rep1,Rep2>::type, Period>
//   operator* (const Rep1& s, const duration<Rep2,Period>& rhs);
// template <class Rep1, class Period, class Rep2>
// constexpr duration<typename common_type<Rep1,Rep2>::type, Period>
//   operator/ (const duration<Rep1,Period>& lhs, const Rep2& r);
// template <class Rep1, class Rep2, class Period>
// constexpr duration<typename common_type<Rep1,Rep2>::type, Period>
//   operator/ (const Rep1& s, const duration<Rep2,Period>& rhs);
// template <class Rep1, class Period, class Rep2>
// constexpr duration<typename common_type<Rep1,Rep2>::type, Period>
//   operator% (const duration<Rep1,Period>& lhs, const Rep2& r);
// template <class Rep1, class Rep2, class Period>
// constexpr duration<typename common_type<Rep1,Rep2>::type, Period>
//   operator% (const Rep1& s, const duration<Rep2,Period>& rhs);
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr bool operator== (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr bool operator!= (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr bool operator< (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr bool operator> (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr bool operator>= (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);
// template <class Rep1, class Period1, class Rep2, class Period2>
// constexpr bool operator<= (const duration<Rep1,Period1>& lhs, const duration<Rep2,Period2>& rhs);*/

// Performs the appropriate operation on the duration objects involved as if it was applied directly on its
// iternal count object.
// When two duration objects of different types are involved, the one with the longest period (as determined by common_type)
// is converted before the operation.

#include <iostream>
#include <ratio>
#include <chrono>

using namespace std;

int main()
{
	using namespace std::chrono;

	duration<int> foo;
	duration<int> bar (10);

	foo = bar;
	foo = foo + bar;
	++foo;
	--bar;
	foo *= 2;
	foo /= 3;
	bar += (foo % bar);

	cout<<std::boolalpha;
	cout<<"foo == bar: "<<(foo == bar) <<endl;
	cout<<"foo: "<<foo.count()<<endl;
	cout<<"bar: "<<bar.count()<<endl;
	
	return 0;
}