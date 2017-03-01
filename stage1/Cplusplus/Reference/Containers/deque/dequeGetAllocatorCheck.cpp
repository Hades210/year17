// file : dequeGetAllocatorCheck.cpp
// allocator_type get_allocator() const noexcept;

#include <iostream>
#include <deque>
#include <vector>

#include "../common/common-print.hpp"

using namespace std;

class Computer
{
public:
	Computer(int p) : price(p){}
	friend ostream& operator<< (ostream& o, const Computer& c);
private:
	int price;
};

ostream& operator<< (ostream& o, const Computer& c)
{
	o << "Computer price is "<<c.price<<"\t";
	return o;
}

int main()
{
	deque<Computer> mydeque;

	vector<Computer> myvector;

	Computer* p;

	p = mydeque.get_allocator().allocate(5);

	for(int i = 0; i < 5; ++ i)
	{
		mydeque.get_allocator().construct(&p[i],(i + 1) * 100);
	}

	myvector.assign(p,p + 5);

	printInfo("myvector",myvector);

	myvector.clear();

	for(int i = 0; i < 5; ++ i)
	{
		mydeque.get_allocator().destroy(&p[i]);
	}

	mydeque.get_allocator().deallocate(p,5);

	return 0;
}


