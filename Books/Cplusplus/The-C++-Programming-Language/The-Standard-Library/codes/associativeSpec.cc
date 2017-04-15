// file : associativeSpec.cc

template <typename Key,
	typename T,
	typename Compare = less<Key>,
	typename Allocator = allocator<pair<const Key,T> > >
class map {
public:
	using key_type = Key;
	using mapped_type = T;
	using value_type = pair<const Key,T>;
	using key_compare = Compare;
	using allocator_type = Allocator;
	using reference = value_type&;
	using const_reference = const value_type&;
	using iterator =/* implementation-defined*/;
	using const_iterator  =/* implementation-defined*/;
	using size_type  =/* implementation-defined*/;
	using difference_type  =/* implementation-defined*/;
	using pointer  =/* implementation-defined*/;
	using const_pointer =/* implementation-defined*/;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	class value_compare {/* operator() (k1,k2) does a key_compare()(k1,k2) */};
	// ...
};

template <typename Key,
	typename T,
	typename Hash = hash<Key>,
	typename Pred = equal_to<Key>,
	typename Allocator = allocator<pair<const Key, T> > >
class unordered_map {
public:
	using key_type = Key;
	using vaule_type = pair<const Key,T>;
	using mapped_type = T;
	using hasher = Hash;
	using key_equal = Pred;
	using allocator_type = Allocator;
	using pointer = typename allocator_traits<Allocator>::pointer;
	using const_pointer = typename allocator_traits<Allocator>::const_pointer;
	using reference = value_type&;
	using const_reference = const value_type&;
	using size_type = /*implementation-defined*/;
	using difference_type = /*implementation-defined*/;
	using iteragtor = /*implementation-defined*/;
	using const_iterator = /*implementation-defined*/;
	using local_iterator = /*implementation-defined*/;
	using const_local_iterator = /*implementation-defined*/;
	// ...
};

