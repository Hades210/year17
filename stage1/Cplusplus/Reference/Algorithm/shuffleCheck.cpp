// file : shuffleCheck.cpp
// template <class RandomAccessIterator, class URNG>
// Rearranges the elements in the range[first,last) randomly, using g as uniform random number generator.
// template <class RandomAccessIterator, class URNG>
// void shuffle(RandomAccessIterator first, RandomAccessIterator last,URNG&& g)
// {
// 	for(auto i = (last - first) - 1; i > 0; --i)
// 	{
// 		uniform_int_distribution<decltype(i)> d(0,i);
// 		swap(first[i],first[d(g)]);
// 	}
// }

#include <iostream>		
#include <algorithm>
#include <array>
#include <random>	//default_random_engine
#include <chrono>	//chrono::system_clock

using namespace std;

int main()
{
	array<int,5> foo {1,2,3,4,5};
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	shuffle(foo.begin(),foo.end(),std::default_random_engine(seed));

	cout<<"shuffled elements:";
	for(int& x : foo)	cout<<' '<<x;	cout<<endl;

	return 0;
}