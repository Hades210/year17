// file : threadJoinableCheck.cpp
// bool joinable() const noexcept;
// check if joinable.
// Returns whether the thread object is joinable.
// A thread object is joinable if it represents a thread of execution.
// A thread object is not joinable in any of these cases:
// 		If it was default-constructed.
//		If it has been moved from(either constructing another thread object, or assigning to it).
//		If either of its members join or detach has been called.

#include <iostream>
#include <thread>

using namespace std;

void mythread()
{
	// do stuff...
}

int main()
{
	thread foo;
	thread bar(mythread);

	cout<<"Joinable after construction:\n"<<std::boolalpha;

	cout<<"foo: "<<foo.joinable()<<"\n";
	cout<<"bar: "<<bar.joinable()<<"\n";

	if(foo.joinable()) foo.join();
	if(bar.joinable()) bar.join();

	cout<<"Joinable after joining:\n"<<std::boolalpha;
	cout<<"foo: "<<foo.joinable()<<"\n";
	cout<<"bar: "<<bar.joinable()<<"\n";

	return 0;
}