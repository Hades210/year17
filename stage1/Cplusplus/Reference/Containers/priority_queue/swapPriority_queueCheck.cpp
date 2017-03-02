//file : swapPriority_queueCheck.cpp
// template <class T, class Container, class Compare>
//	void swap(queue<T,Container,Compare>& x, queue<T, Container,Compare>& y) noexcept(noexcept(x.swap(y)));

#include <iostream>
#include <queue>
#include "../common/common-print.hpp"

using namespace std;

int main()
{
	priority_queue<int> foo, bar;

	foo.push(15);foo.push(30);foo.push(10);

	bar.push(101);bar.push(202);

	swap(foo,bar);

	cout<<"size of foo: "<<foo.size()<<"\n";
	cout<<"size of bar: "<<bar.size()<<"\n";

	printInfo("foo",foo);
	printInfo("bar",bar);

	return 0;
}
