
// file : threadConstructorCheck.cpp
/******************************************************************************************************************************
*	class thread;
*class to represent individual threads of execution.
*A thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in
*multithreading environments, while sharing a same address space.
*An initialized thread object represents an active thread of execution, such a thread object is joinable, and has a 
*unique thread id.
*A default-constructed(non-initialized) thread object is not joinable, and its thread it is common for all non-joinable
*threads.
*A joinable thread becomes not joinable if moved from, or if either join or detach are called on them.
*******************************************************************************************************************************/
/******************************************************************************************************************************
*	class thread::id;
*values of this type are returned by thread::get_id and this_thread::get_id to identify threads.
*The values of a default-constructed thread::id object identifies non-joinable threads, and thus compares equal to the 
*value returned by member thread::get_id of any such threads.
*For joinable threads,thread::get_id returns a unique value of this type that does not compare equal the one returned 
*for any other joinable or non-joinable thread.
*Note that certain library implementations may reutilize the thread::id value of a terminated thread that can no longer
*be joined.
*Two thread::id object compare equal if they represent the same joinable thread, or if they both represent non-joinable threads
*******************************************************************************************************************************/
/*******************************************************************************************************************************
*	typedef native_handle_type;
*This member type is only present in class thread if the library implementation supports it.
*It is the type returned by thread::native_handle with implementation-specific information about a thread.
*******************************************************************************************************************************/
/*******************************************************************************************************************************
*	default(1)					thread() noexcept;
*	initialization(2)			template <class Fn, class... Args>
*								explicit thread (Fn&& fn, Args&&... args);
*	copy[delete](3)				thread (const thread& ) = delete;
*	move(4)						thread(thread&& x) noexcept;
*******************************************************************************************************************************/
// (1) construct a thread object that does not represent any thread of execution
// (2) Construct a thread object that represents a new joinable thread of execution. The new thread of execution calls fn passing 
// args as arguments (using decay copies of its lvalue or rvalue references)
// The completion of this construction synchronizes with the beginning of the invocation of this copy of fn.
// (3) deleted constructor form(thread objects cannot be copied)
// (4) construct a thread object that acquires the thread of execution represented by x (if any). This operation does not affect the
// execution of the moved thread in any way, it simply transfers its handler.
// The x object no longer represents any thread of execution.
// thread objects that are joinable shall either be joined or detached before they are destroyed.

// fn A pointer to function, pointer to member, or any kind of move-constructible function object(an object whose class defines operator(),
// including closures and function objects). The return value(if any) is ignored.
// args... Arguments passed to the call to fn (if any). Their types shall be move-constructible. If fn is a member pointer the first argument
// shall be an objecgt for which that member is defined(or a reference, or a pointer to it).
// Fn and Args... are template parameters: if implicitly deduced, these are the proper lvalue or rvalue reference thype to bind the arguments to.
// Note though, that on the call to fn in the new thread, decay copies of fn and args... are always used(see std::ref for a wapper class that makes
// references copyable).

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

atomic<int> global_counter (0);
void increase_global(int n) {for(int i = 0; i < n; i ++) ++global_counter; }
void increase_reference(atomic<int>& variable, int n)  {for (int i = 0; i < n; i ++) ++ variable;}

struct C : atomic<int> 
{
	C():atomic<int>(0) {}
	void increase_member(int n) {for  (int i = 0; i < n; i ++) fetch_add(1);}
};

int main()
{
	vector<thread> threads;

	cout<<"increase global counter with 10 threads...\n";
	for(int i = 0; i < 10; i ++)
		threads.push_back(thread(increase_global,1000));


	cout<<"increase counter (foo) with 10 threads using references...\n";
	atomic<int> foo (0);
	for(int i = 0; i < 10; i ++)
		threads.push_back(thread(increase_reference,ref(foo),1000));

	cout<<"increase counter(bar) with 10 threads using member...\n";
	C bar;
	for(int i = 0; i < 10; i ++)
		threads.push_back(thread(&C::increase_member,&bar,1000));


	cout<<"synchronizing all threads...\n";
	for(auto& th : threads )
		th.join();

	cout<<"global_counter: "<<global_counter<<"\n";
	cout<<"foo: "<<foo<<"\n";
	cout<<"bar: "<<bar<<"\n";

	return 0;
}

