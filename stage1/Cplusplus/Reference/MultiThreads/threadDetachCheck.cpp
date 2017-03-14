// file : threadDetachCheck.cpp
// void detach();
// Detach thread
// Detaches the thread represented by the object from the calling thread, allowing them to execute independently from
// each other.
// Both threads continue without blocking nor synchronizing in any way. Note that when either one ends execution, its
// resources aree released.
// After a call to this function, the thread object becomes non-object and can be destroyed safely.

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void pause_thread(int n)
{
	this_thread::sleep_for(chrono::seconds(n));
	cout<<"pause of "<< n << " seconds ended\n";
}

int main()
{
	cout<<"Spawning and detaching 3 threads...\n";
	thread (pause_thread,1).detach();
	thread (pause_thread,2).detach();
	thread (pause_thread,3).detach();
	cout<<"Done spawning threads.\n";

	cout<<"(the main thread will now pause for 5 seconds)\n";
	pause_thread(5);
	return 0;
}