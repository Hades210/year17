// file : stackPushCheck.cpp
// void push(const value_type& val);
// void push(value_type&& val);
// This member function effectively calls the member function push_back of the underlying container object.
// void pop();
// This member function effectively calls the member function pop_back of the underlying container object.

#include <iostream>
#include <stack>

using namespace std;

int main()
{
        stack<int> mystack;

        for(int i = 1; i <=5; i ++)
                mystack.push(i);

        cout<<"popping out elements:";

        while(!mystack.empty())
        {
                cout<<mystack.top()<<"\t";
                mystack.pop();
        }
        cout<<"\n";
        
        return 0;
}
