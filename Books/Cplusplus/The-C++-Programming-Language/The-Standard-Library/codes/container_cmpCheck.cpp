// file : container_cmpCheck.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class Nocase { // case-insensitive string compare
public:
	bool operator() (const string& , const string&) const;
};

bool Nocase::operator() (const string& x, const string& y) const
{
	auto p = x.begin();
	auto q = y.begin();

	while(p!= x.end() && q!= y.end() && toupper(*p) == toupper(*q)) {
		++ p;
		++ q;
	}

	if(p == x.end()) return q!=y.end();
	if(q == y.end()) return false;
	return toupper(*p) < toupper(*q);
}

template <class T>
void print_vector(vector<T> & v)
{
	for(auto& x : v)
		cout<<x<<'\t';
	cout<<endl;
}

int main()
{
	vector<string> fruit;

	fruit = {"apple","pear","Apple","Pear","lemon"};
	print_vector(fruit);

	sort(fruit.begin(),fruit.end(),Nocase());
	print_vector(fruit);

	sort(fruit.begin(),fruit.end());
	print_vector(fruit);

	return 0;
}