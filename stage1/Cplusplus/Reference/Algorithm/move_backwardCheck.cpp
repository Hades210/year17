// file : move_backwardCheck.cpp
// template <class BidirectionalIterator1, class BidirectionalIterator2>
//	BidirectionalIterator1 move_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result);
// moves the elements in the range[first,last) starting from the end into the range terminating at result.
// The function returns an iterator to the first element in the destination range.
// The resulting range has the elements in the exact same order as [first,last). To reverse their order, see reverse.
// The function begins by moving *(last -1) into *(result -1), and then follows backward by the elements preceding these,
// until first is reached (and including it).
// The ranges shall not overlap in such a way that result (which is the past-the-end element in the destination range)
// points to an element in the range(first,last]. For such cases, see move.
// The behavior of this function template is equivalent to:
// template <class BidirectionalIterator1, class BidirectionalIterator2>
// BidirectionalIterator1 move_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result)
// {
// 	while(last != first)
// 	{
// 		*(--result)=move(*(--last));
// 	}
// 	return result;
// }

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string elem[10] = {"air","water","fire","earth"};
	move_backward(elem,elem+4,elem+5);
	elem[0]="earth";

	cout<<"elem contains: ";
	for(int i =0; i < 10; ++i)
		cout<<" ["<<elem[i]<<"]";
	cout<<endl;
	
	return 0;
}