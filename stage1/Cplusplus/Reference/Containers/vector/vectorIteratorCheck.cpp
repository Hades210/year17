// file : vectorIteratorCheck.cpp
// iterator, const_iterator, begin, end
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myvector;
	for(int i = 1; i <= 5; i ++)
		myvector.push_back(i);
	std::cout<<"myvector contains: "<<std::endl;
	for(std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout<<' '<<*it;
	std::cout<<std::endl;
	return 0;
}
