// file : stackTopCheck.cpp
// reference& top();
// const_reference& top() const;
// This member function effectively calls member back of the underlying container object.

#include <iostream>
#include <stack>

using namespace std;

int main()
{
        stack<int> mystack;
        mystack.push(100);
        mystack.push(200);

        mystack.top() -= 50;

        cout<<"mystack.top() is "<<mystack.top()<<"\n";

        return 0;
}
