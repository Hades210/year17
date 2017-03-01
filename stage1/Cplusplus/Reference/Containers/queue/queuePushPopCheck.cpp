// file : queuePushPopCheck.cpp
// void push(const value_type& val);
// void push(value_type&& val);
// This member function effectively calls the member function push_back of the underlying container object.
// void pop();
// This member function effectively calls the member function pop_front of the underlying container object.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
        queue<int> myqueue;
        unsigned int i ;

        do 
        {
                cin>>i;
                myqueue.push(i);
        }while(i);

        while(!myqueue.empty())
        {
                cout<<myqueue.front()<<"\t";
                myqueue.pop();
        }
        
        return 0;
}
