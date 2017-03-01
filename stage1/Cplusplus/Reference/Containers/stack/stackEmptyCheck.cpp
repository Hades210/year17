// file : stackEmptyCheck.cpp
// bool empty() const;
// This member function effectively calls member empty of the underlying container object.

#include <iostream>
#include <stack>

using namespace std;

int main()
{
        stack<int> mystack;
        int sum (0);

        for(int i = 1; i <= 10; ++ i)
                mystack.push(i);

        while(!mystack.empty())
        {
                sum += mystack.top();
                mystack.pop();
        }

        cout<<sum<<"\n";
        
        return 0;
}
