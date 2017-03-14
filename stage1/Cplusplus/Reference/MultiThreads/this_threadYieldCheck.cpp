// file : this_threadYieldCheck.cpp
// void yield() noexcept;
// yield to other threads.
// The calling thread yields, offering the implementation the opportunity to reschedule.
// This function shall be called when a thread waits for other threads to advance without blocking.

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<bool> ready (false);

void count1m(int id)
{
	while(!ready)  // wait until main() sets ready...
		this_thread::yield();
	for(volatile int i = 0; i < 1000000; i ++)
		;
	cout<<id;
}

int main()
{
	thread threads[10];
	cout<<"race of 10 threads that count to 1 million...\n";

	for(int i = 0; i < 10; i ++)
		threads[i] = thread(count1m,i);
	ready = true; // go!
	for(auto& th : threads)
		th.join();

	cout<<endl;
	return 0;
}