// file : random_shuffleCheck.cpp
/******************************************************************************************************************
*	generator by default(1) template <class RandomAccessIterator>
*								void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);
*	specific generator(2)	template <class RandomAccessIterator, class RandomNumberGenerator>
*								void random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
*													RandomNumberGenerator&& gen);
******************************************************************************************************************/
// Rearranges the elements in the range [first,last) randomly.
// template <class RandomAccessIterator, class RandomNumberGenerator>
// void random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
// 					RandomNumberGenerator& gen)
// {
// 	iterator_traits<RandomAccessIterator>::difference_type i , n;
// 	n = last - first;
// 	for(i = n -1; i > 0; --i)
// 		swap(first[i],first[gen[i + 1]]);
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	srand(unsigned(time(NULL)));
	vector<int> myvec;

	for(int i = 1; i < 10; ++ i)	myvec.push_back(i);
	random_shuffle(myvec.begin(),myvec.end(),[](int i) {return rand() % i;});
	
	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	
	return 0;
}