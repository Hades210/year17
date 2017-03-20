// file : memberTypeSpec.cc

#include <iostream>

using namespace std;

template <typename T>
class Tree {
	using value_type = T; // member alias
	enum Policy{rb,splay,treeps}; // member enum
	class Node { // member class
		Node* right;
		Node* left;
		value_type value;
	public:
		void f(Tree*);
	};
	Node* top;
public:
	void g(const T& );
	// ...
};

/*
A member class (often called a nested class) can refer to types and static members of its enclosing class.
It can only refer to non-static members when it is given an object of the enclosing class to refer to.
A nested class has access to members of its enclosing class, even to private members (just as a member function has)
but has no notation of a current object of the enclosing class.
*/

template <typename T>
void Tree::Node::f(Tree* p)
{
	top = right; // error: no object of type Tree specified
	p->top = right; // OK
	value_type = left-value; // OK: value_type is not associated with an object
}

/*
A class does not have any special access rights to the members of its nested class.
Member classes are more a notational convenience than a feature of fundamental importance. On the other hand,
member aliases are important as the basis of generic programming techniques relying on associated types. Member
enums are often an alternative to enum classes when it comes to avoiding polluting an enclosing scope with the names
of enumerators.
*/

template <typename T>
void Tree::g(Tree::Node* p)
{
	value_type val = right->value; // error: no object of type Tree::Node
	value_type v = p->right->value; // error: Node::right is private
	p->f(this); // OK
}
