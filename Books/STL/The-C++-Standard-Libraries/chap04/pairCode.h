/*************************************************************************
*  File Name: pairCode.h
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Thu 31 Aug 2017 03:50:31 PM CST
*************************************************************************/

template <class T1, class T2>
struct pair {
	//type names for the values
	typedef T1 first_type;
	typedef T2 second_type;

	//member
	T1 first;
	T2 second;

	/* default constructor
	 * -T1() and T2() force initialization for built-in types
	 */
	pair()
		:first(T1()),second(T2()){}

	// constructor for two values
	pair(const T1& a, const T2& b) 
		:first(a), second(b) {}

	// copy constructor with implicit conversions
	template <class U1, class U2>
		pair(const pair<U1,U2>& p) 
		: first(p.first),second(p.second) {}
};

template <class T1, class T2>
inline bool operator== (const pair<T1,T2>& x, const pair<T1, T2>& y) {
	return x.first == y.first && x.second == y.second;
}

template <class T1, class T2>
inline bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y) {
	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template <class T1, class T2>
inline pair<T1,T2> make_pair(const T1&x, const T2& y) {
	return pair<T1,T2>(x,y);
}
