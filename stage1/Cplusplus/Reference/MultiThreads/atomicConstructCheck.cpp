// file : atomicConstructCheck.cpp
// Atomic types are types that encapsulate a value whose access is guaranteed to not cause data races and can be used
// to synchronize memory accesses among different threads.
// This header declares two C++ classes, atomic and atomic_flag, that implement all the features of atomic types in 
// self-contained classes. The header also declares an entire set of C-style types and functons compatible with the atomic support in C

// template <class T> struct atomic;
// Objects of atomic types contian a vaule of a particular type(T).
// The main characteristic of atomic objects is that access to this contained value from different threads cannot cause data
// races (doing that is well-defined behavior,with accesses properly sequenced).Generally, for all other objects, the possibility
// of causing a data race for accessing the same object concurrently qualifies the operation as undefined behavior.
// Additionally,atomic objects have the ability to synchronize access to other non-atomic objects in their threads by specifying
// different memory orders.
/****************************************************************************************************************************************
*	default(1)			atomic() noexcept = default;
*	initialization(2)	constexpr atomic(T val) noexcept;
*	copy[delete] (3)	atomic(const atomic&) = delete
*****************************************************************************************************************************************/
// default (1)	leaves the atomic object in an uninitialized state. An uninitialized atomic object may later be initialized by calling atomic_init.
// initialization(2)	Initializes the object with val.
// copy construction deleted (atomic objects cannot be copied/moved)

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

atomic<bool> ready(false);
atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int id)
{
	while(!ready)
		this_thread::yield();
	for(volatile int i =0; i < 1000000; ++i) {}

	if(!winner.test_and_set())
		cout<<"thread #"<<id<<" won!\n";
}

int main()
{
	vector<thread> threads;
	cout<<"Spawning 10 threads that count to 1 million...\n";
	for(int i = 1; i <= 10; i ++)
		threads.push_back(thread(count1m,i));
	ready = true;

	for(auto& x : threads)
		x.join();
	
	return 0;
}


