// file : threadAllCheck.cpp
/**********************************************************************************************************************
*	void swap(thread& x) noexcept; //swaps the state of the object with that of x
*	void swap(thread& x, thread& y) noexcept; // exchange the state of the thread objects x and y
*	native_handle_type native_handle(); // This member function is only present in class thread if supported.
***********************************************************************************************************************/
// static unsigned hardware_concurrency() noexcept;
// Returns the number of hardware thread contexts.
// The interpretation of this value is system-and implementation-specific, and may not be exact, but just an approximation.
// Note that this does not need to match the actual number of processors or cores available in the system. A system can support
// multiple threads pre processing unit, or restrict the access to its resources to the program.
// If this value is not computable or well defined, the function returns 0.

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void pause_thread(int n)
{
	this_thread::sleep_for(chrono::seconds(n));
	cout<<"pause of "<<n<<" seconds ended\n";
}

int main()
{
	vector<thread> threads;
	unsigned core = thread::hardware_concurrency();
	cout<<"thread::hardware_concurrency = "<<core<<endl;

	for(int i = 0; i < core; i ++)
		threads.push_back(thread(pause_thread,i + 1));

	for(auto& th : threads)
		th.join();

	return 0;
}
