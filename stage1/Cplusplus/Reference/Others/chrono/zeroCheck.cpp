// file : zeroCheck.cpp
//  static constexpr duration zero();
// The function calls duration_value::zero to obtain the zero value for its internal count object.
// static constexpr duration zero() {
//	return duration_values<rep>::zero();
//}

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void fn()
{
	this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
	using std::chrono::steady_clock;

	steady_clock::time_point t1 = steady_clock::now();
	cout<<"Printing out something..."<<endl;

	thread t(fn);
	t.join();

	steady_clock::time_point t2 = steady_clock::now();

	steady_clock::duration d = t2 - t1;

	if(d == steady_clock::duration::zero())
		cout<<"The internal clock did not tick."<<endl;
	else
		cout<<"The internal clock advanced "<<d.count()<<" periods."<<endl;

	return 0;
}