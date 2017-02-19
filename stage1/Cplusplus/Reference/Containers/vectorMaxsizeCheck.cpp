// file: vectorMaxsizeCheck.cpp
// size_type max_size() const noexcept;
//  comparing size, capacity and max_size

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myVector;

	for(int i = 0; i < 100; ++i) 
		myVector.push_back(i);
	
	std::cout<<"size: "<<myVector.size()<<std::endl;
	std::cout<<"capacity: "<<myVector.capacity()<<std::endl;
	std::cout<<"max_size: "<<myVector.max_size()<<std::endl;
	return 0;
}
