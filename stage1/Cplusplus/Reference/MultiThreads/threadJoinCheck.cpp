// file : threadJoinCheck.cpp
// void join()
// Join thread
// The function returns when the thread execution has completed.
// This synchronizes the moment this function returns with the completion of all the operations in the thread. This blocks
// the execution of the thread that calls this function until the function called on construction returns (if it hasn't yet)
// After a call to this function, the thread object becomes non-joinable and can be destroyed safely.

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
	cout<<"Spawing 3 threads...\n";

	thread t1(pause_thread,1);
	thread t2(pause_thread,2);
	thread t3(pause_thread,3);

	cout<<"Done spawing threads. Now waiting for them to join:\n";

	t1.join();
	t2.join();
	t3.join();

	cout<<"All threads joined\n";
	
	return 0;
}
