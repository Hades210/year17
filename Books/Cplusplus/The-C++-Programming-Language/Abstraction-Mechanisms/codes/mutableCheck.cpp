// file : mutableCheck.cpp

#include <iostream>
#include <string>

using namespace std;

class Test {
public:
	Test (bool v = false, string c = "hello world") : valid(v),cache(c) {}
	string string_rep() const;
private:
	mutable bool valid {false};
	mutable string cache{"hello world"};
	void compute_cache_value() const;
};

string Test::string_rep() const 
{
	if(!valid)
	{
		compute_cache_value();
		valid = true;
	}
	return cache;
}

void Test::compute_cache_value() const 
{
	cache = "compute_cache_value";
}

struct Cache {
	Cache(bool v, string c) : valid(v),cache(c) {}
	bool valid;
	string cache;
};

class Test2 {
public:
	Test2 () { c = new Cache (false,"hello world");}
	string string_rep() const;

	~Test2() { delete c;}
private:
	Cache* c;
	void compute_cache_value() const;
};

string Test2::string_rep() const 
{
	if(!c->valid)
	{
		compute_cache_value();
		c->valid = true;
	}

	return c->cache;
}

void Test2::compute_cache_value() const
{
	c->cache = "compute_cache_value";
}

int main()
{
	Test t;
	cout<<t.string_rep()<<endl;

	Test2 tt;
	cout<<tt.string_rep()<<endl;

	return 0;
}