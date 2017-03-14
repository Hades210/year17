// file : threadOperatorCheck.cpp
// ~thread();
// Destroys the thread object.
// If the thread is joinable when destroy,terminate() is called.
/*******************************************************************
*	move(1)				thread& operator= (thread&& rhs) noexcept;
*	copy[delete](2)  	thread& operator= (const thread&)  = delete
********************************************************************/
// Move-assign thread
// If the object is currently not joinable, it acquires the thread of execution represented by rhs(if any).
// If it is joinable, terminate() is called.
// After the call, rhs no longer represents any thread of execution(as if default-constructed).
// thread objects cannot be copied.

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void pause_thread(int n)
{
	this_thread::sleep_for(chrono::seconds(n));
	cout<<"pause of "<<n<<" seconds ended\n";
}

int main()
{
	thread threads[5];  // default-constructed threads

	cout<<"Spawing 5 threads...\n";
	for(int i = 0; i < 5; i ++)
		threads[i] = thread(pause_thread,i +1); // move-assign threads

	cout<<"Done spawing threads. Now waiting for them to join:\n";

	for(int i = 0; i < 5; i ++)
		threads[i].join();

	cout<<"All threads joined!\n";
	return 0;
}
