// file : queueFrontBack.cpp
//reference& front();
//const_reference& front() const;
//This member function effectively calls member front of the underlying container object
//reference& back();
//const_reference& back() const;
//This member function effectively calls member back of the underlying container object

#include <iostream>
#include <queue>

using namespace std;

int main()
{
        queue<int> myqueue;

        myqueue.push(50);
        myqueue.push(70);

        myqueue.front() -= myqueue.back();
        myqueue.back() -= myqueue.front();

        cout<<myqueue.front()<<endl;
        cout<<myqueue.back()<<endl;

        return 0;
}
