// file : listMergeCheck.cpp

/***********************************************************************
*	void merge(list& x);
*	void merge(list&& x);
*	template <class Compare>
*		void merge(list& x, Compare comp);
*	tempalte <class Compare>
*		void merge(list&& x, Compare comp)
&/************************************************************************/

// Merge sorted list

// Merge x into the list by transferring all of its elements at their respective orderd positions into the container
// This effectively removes all the elements in x and inserts them into their ordered position with container.
// The template version have the same behavior, but take a specific predicate(comp) to perform the comparison operation between elements.
// The function does nothing if (&x == this)


#include <iostream>
#include <list>

using namespace std;

bool mycomp (double first, double second)
{
	return int (first) < int (second); 
}

int main()
{
	list<double> first, second;

	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	first.sort();
	second.sort();

	first.merge(second);

	second.push_back(2.1);

	first.merge(second,mycomp);

	cout<<"first contains:";
	for(list<double>::iterator it = first.begin(); it != first.end(); ++ it)
		cout<<"\t"<<*it;
	cout<<endl;
	
	return 0;
}
