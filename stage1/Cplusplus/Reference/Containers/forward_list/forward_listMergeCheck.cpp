// file : forward_listMergeCheck.cpp
/*****************************************************************************************
*	void merge(forward_list& fwdlst);
*	void merge(forward_list&& fwdlst);
*	template <class Compare>
*		void merge(forward_list& fwdlst, Compafre comp);
*	template<class Compare>
*		void merge(forward_list&& fwdlst, Compare comp);
*****************************************************************************************/
// Merge sorted lists

#include <iostream>
#include <forward_list>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	forward_list<double> first = {4.2,2.9,3.1};
	forward_list<double> second = {1.4,7.7,3.1};
	forward_list<double> third = {6.2,3.7,7.1};

	first.sort();
	second.sort();
	first.merge(second);

	printInfo("first",first);

	first.sort(greater<double>());
	third.sort(greater<double>());

	first.merge(third,greater<double>());
	printInfo("first",first);

	return 0;
}
