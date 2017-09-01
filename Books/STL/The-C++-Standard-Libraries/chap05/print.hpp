#ifndef __PRINT_HPP_
#define __PRINT_HPP_

#include <iostream>

template <class T>
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr="")
{
	typename T::const_iterator cit;

	std::cout<<optcstr;
	for(cit = coll.begin(); cit != coll.end(); ++ cit)
		std::cout<<*cit<<" ";
	std::cout<<std::endl;
}

#endif /*__PRINT_HPP_*/
