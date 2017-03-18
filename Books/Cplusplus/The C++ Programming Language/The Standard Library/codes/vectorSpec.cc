// file : vectorSpec.cc

template <typename T, typename Allocator = allocator<T> >
class vector {
public:
	using reference = value_type&;
	using const_reference = const value_type&;
	using iterator = /* implementation-defined */;
	using const_iterator = /* implementation-defined */;
	using size_type = /* implementation-defined */;
	using difference_type = /* implementation-defined */;
	using value_type = T;
	using allocator_type = Allocator;
	using pointer = typename allocator_traits<Allocator>::pointer;
	using const_pointer = typename allocator_traits<Allocator>::const_pointer;
	using reverse_iterator = reverse_iterator<iterator>
	using const_reverse_iterator reverse_iterator<const_iterator>;

	//...
};
