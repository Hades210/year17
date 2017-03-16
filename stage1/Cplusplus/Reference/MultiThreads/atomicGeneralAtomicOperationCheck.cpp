// file : atomicGeneralAtomicOperationCheck.cpp

// bool is_lock_free() const volatile noexcept;
// bool is_lock_free() const noexcept;
// Indicates whether the object is lock-free
// A lock-free object dose not cause other threads to be blocked when accessed (possibly using some sort of transactional memory for the type)
// The value returned by this function is consistent with the values returned for all other objects of the same type.

// void store(T val, memory_order sync = memory_order_seq_cst) volatile noexcept;
// void store(T val, memory_order sync = memory_order_seq_cst) noexcept;
// Replaces the contained value with val.
// The operation is atomic and follows the memory ordering specified by sync.
// sync : synchronization mode for the operation.
// This shall be one of these possible values of the enum type memory_order:
//	memory_order_relaxed			Relaxed 						No synchronization of side effects.
//	memory_order_release			Release                         Synchronizes side effects with the next cosume or acquire operation
//	memory_order_seq_cst			Sequentially consistent			Synchronizes all visible side effects with the other sequentially consistent operations, following s single total order.

// T load(memory_order sync = memory_order_seq_cst) const volatile noexcept;
// T load(memory_order sync = memory_order_seq_cst) const noexcept;
// Returns the contained value. The operation is atomic and follows the memory ording specified by sync
// sync : synchronization mode for the operation.
// This shall be one of these possible values of the enum type memory_order:
//	memory_order_relaxed			Relaxed 						No synchronization of side effects.
//	memory_order_consume			Consume                         Synchronizes the visible side effects on values carrying dependencies from the last release or sequentially consistent operation.
//  memory_order_acquire			Acquire                         Synchronizes all visible side effects from the last release or sequentially consistent operation
//	memory_order_seq_cst			Sequentially consistent			Synchronizes all visible side effects with the other sequentially consistent operations, following s single total order.


#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

atomic<int> foo (0);

void set_foo(int x)
{
	foo.store(x,memory_order_relaxed);
}

void print_foo()
{
	int x;
	do{
		x = foo.load(memory_order_relaxed);
	}while(x == 0);
	cout<<"foo: "<<x<<endl;
}

int main()
{
	thread first(print_foo);
	thread second(set_foo,10);

	first.join();
	second.join();

	return 0;
}
