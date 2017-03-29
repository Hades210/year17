// file : includesCheck.cpp
// template <class InputIterator1, class InputIterator2>
//	bool includes(InputIterator1 first1, InputIterator1 last1,
//				  InputIterator2 first2, InputIterator2 last2);
// template <class InputIterator1, class InputIterator2, class Compare>
//	bool includes(InputIterator1 first1, InputIterator1 last1,
//				  InputIterator2 first2, InputIterator2 last2, Compare comp);

// Returns true if the sorted range [first1, last1) contains all the elements in the sorted range[first2,last2)
// template <class InputIterator1, class InputIterator2>
// bool includes(InputIterator1 first1, InputIterator1 last1,
// 			  InputIterator2 first2, InputIterator2 last2)
// {
// 	while(first2 != last2)
// 	{
// 		if((first1 == last1) || (*first2 < *first1)) return false;
// 		if(!(*first1 < *first2)) ++first2;
// 		++first1;
// 	}
// 	return true;
// }

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int container[] = {5,10,15,20,25,30,35,40,45,50};
	int continent[] = {40,30,20,10};

	sort(container,container + 10);
	sort(continent,continent + 4);

	if(includes(container,container+10,continent,continent+4))
		cout<<"container includes continent!"<<endl;
	
	return 0;
}