// file : unordered_multimapModifierCheck.cpp
/*******************************************************************************
*	template <class... Args>
*		iterator emplace(Args&& ... args);	
*	template <class... Args>
*		iterator emplace_hint(const_iterator position, Args&&... args);
*	(1) iterator insert(const value_type& val);
*	(2) template <class P>
*			iterator insert(P&& val);
*	(3)	iterator insert(const_iterator hint, const value_type& val);
*	(4)	template <class P>
*			iterator insert(const_iterator hint, P&& val);
*	(5)	template <class InputIterator>
*			void insert(InputIterator first, InputIterator last);
*	(6)	void insert(initializer_list<value_type> il);
*	by position(1)	iterator erase(const_iterator position);
*	by key(2)		size_type erase(const key_type& k);
*	range(3)		iterator erase(const_iterator first, const_iterator last);
*	void clear() noexcept;
*	void swap(unordered_multimap& umm);
*	template <class Key, class T, class Hash, class Pred, class Alloc>
*		void swap(unordered_multimap<Key,T,Hash,Pred,Alloc>& lhs,
*				  unordered_multimap<Key,T,Hash,Pred,Alloc>& rhs);
********************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_multimap<string,string>  myumm;

	myumm.emplace("NCC-1701","C. Pike");
	myumm.emplace("NCC-1701","J.T. Kick");
	myumm.emplace("NCC-1701-D","J.L. Picard");
	myumm.emplace("NCC-74656","K. Janeway");

	printInfo("myumm",myumm);

	unordered_multimap<string,int> first,
	second = {{"AAPL",200},{"GOOG",100}};

	pair<string,int> mypair("MSFT",500);
	first.insert(mypair); // copy
	first.insert(make_pair<string,int>("GOOG",50)); // move
	first.insert(second.begin(),second.end()); // range
	first.insert({{"ORCL",100},{"GOOG",100}}); // init list

	printInfo("first",first);

	unordered_multimap<string,string> umm = {
			{"strawberry","red"},
			{"banana","yellow"},
			{"orange","orange"},
			{"lemon","yellow"},
			{"apple","red"},
			{"apple","green"},
			{"pear","green"}
	};

	printInfo("umm",umm);
	umm.erase(umm.begin()); // by position
	umm.erase("apple"); // by value
	umm.erase(umm.find("orange"),umm.end()); // by range 
	printInfo("umm",umm);

	unordered_multimap<string,string> umm2 = {{"Tom","Produce"},{"Bob","Toys"},{"Bob","Garden"}};
	printInfo("umm2",umm2);
	umm2.clear();
	umm2.insert(make_pair<string,string>("Bob","Jail"));
	printInfo("umm2",umm2);

	unordered_multimap<string,string> 
	foo = {{"orange","FL"},{"apple","NY"},{"apple","WA"}},
	bar = {{"strawberry","LA"},{"strawberry","NC"},{"pear","OR"}};

	foo.swap(bar);
	printInfo("foo",foo);
	printInfo("bar",bar);

	swap(foo,bar);
	printInfo("foo",foo);
	printInfo("bar",bar);


	return 0;
}
