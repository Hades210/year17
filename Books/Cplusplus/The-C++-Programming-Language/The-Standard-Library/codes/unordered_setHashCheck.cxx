// file : unordered_setHashCheck.cpp

#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

struct Record {
	string name;
	int val;

	Record(string n, int v) : name(n),val(v) {}
};

struct Nocase_hash {
	Nocase_hash() : d (1) {}
	Nocase_hash(int dd) : d (dd) {} 
	int d = 1; // shift code d number of bits in each iteration
	size_t operator()(const Record& r) const 
	{
		size_t h = 0;
		for (auto& x : r.name)
		{
			h <<= d;
			h ^= toupper(x);
		}

		return h;

	}
};

struct Nocase_equal {
	bool operator() (const Record& r, const Record& r2) const
	{
		if(r.name.size() != r2.name.size()) return false;
		for(int i = 0; i < r.name.size(); ++i)
			if(toupper(r.name[i]) != toupper(r2.name[i]))
				return false;
		return true;
	}
};

size_t hf(const Record& r) {return hash<string>()(r.name)^hash<int>()(r.val);};
bool eq(const Record& r, const Record& r2) {return r.name == r2.name && r.val == r2.val ;};

int main()
{

	unordered_set<Record,Nocase_hash,Nocase_equal> m {
		{{"andy",7},{"al",9},{"bill",-3},{"barbara",12}},
		Nocase_hash(),
		Nocase_equal()
	};

	for(auto r : m )
		cout<<"{"<<r.name<<","<<r.val<<"}\n";

	// unordered_set<Record,decltype(&hf),decltype(&eq)> m2 {
	// 	{{"andy",7},{"al",9},{"bill",-3},{"barbara",12}},
	// 	hf,
	// 	eq
	// };

	// for (auto r : m2)
	// 	cout<<"{"<<r.name<<","<<r.val<<"}\n";

	return 0;
}