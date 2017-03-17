// file : initializer_listTest.cpp
// A {}-list is converted into an object of type std::initializer_list<X>.
// In <initializer_list>, we find initializer_list:

template <typename T>
class initializer_list { // iso.18.9
public:
	using value_type = T;
	using reference = const T&; // note const:iteralizer_list elements are immutable
	using const_reference = const T&;
	using size_type = size_t;
	using iterator = const T*;
	using const_iterator = const T*;

	initializer_list() noexcept;

	size_t size() const noexcept; // number of elements
	const T* begin() const noexcept; //  first element
	const T* end() const noexcept; // one-past-last element

};

template <typename T>
const T* begin(initializer_list<T> lst) noexcept {return lst.begin();}

template <typename T>
const T* end(initializer_list<T> lst) noexcept {return lst.end();}

// Unfortunately, initializer_list does not offer a subscript operator. If you want to use [] rather than *, subscript a pointer:

void f(initializer_list<int> lst)
{
	for(int i = 0; i < lst.size(); ++i)
		cout<<lst[i]<<"\n";  // error

	const int* p = lst.begin();
	for(int i = 0; i < lst.size(); ++i)
		cout<<p[i]<<'\n'; // OK
}

// Naturally, an initializer_list can also be used by a range-for. 

void f2(initializer-list<int> lst)
{
	for(auto x : lst)
		cout<<x<<'\n';
}