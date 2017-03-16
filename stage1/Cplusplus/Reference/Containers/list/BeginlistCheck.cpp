// file : BeginlistCheck.cpp
// c++ 11 only
//std::begin();
/***************************************************************
*	container(1)	template <class Container>
*						auto begin(Container& cont) -> decltype(cont.begin());
*					template <class Container>
*						auto begin(const Container& cont) -> decltype(cont.begin());
*	array(2)		template <class T, size_t N>
*						T* begin(T(&arr)[N])
***************************************************************/

//std::end();
/***************************************************************
*	container(1)	template <class Container>
*						auto end(Container& cont) -> decltype(cont.end());
*					template <class Container>
*						auto end(const Container& cont) -> decltype(cont.end());
*	array(2)		template <class T, size_t N)
*						T* end(T(&arr)[N])
***************************************************************/

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist1 = {10,20,30,40,50};
	list<int> mylist2;

	for(list<int>::iterator it = begin(mylist1); it != end(mylist1); ++ it)
		mylist2.push_back(*it);

	for(list<int>::iterator it = begin(mylist2); it != end(mylist2); ++ it)
		cout<<*it<<"\t";
	cout<<endl;
	return 0;
}
