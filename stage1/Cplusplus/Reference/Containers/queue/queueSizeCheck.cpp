// file : queueSizeCheck.cpp
// size_type size() const;
// This member function effectively calls member size of the underlying container object.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
        queue<int> myqueue;
        cout<<"0. size : "<<myqueue.size()<<"\n";
        
        for(int i = 0; i < 5; i ++)
                myqueue.push(i);

        cout<<"1. size : "<<myqueue.size()<<"\n";

        myqueue.pop();
        cout<<"2. size : "<<myqueue.size()<<"\n";

        return 0;
}
