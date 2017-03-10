// file : unordered_multisetBucketCheck.cpp
// size_type bucket(const key_type& k) const;
// Locate element's bucket
// Returns the bucket number where the element with value k is loated.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
        unordered_multiset<string> myums = {"water","sand","ice","foam"};

        int n = myums.bucket_count();

        for(int i = 0; i < n; i ++)
        {
                cout<<"bucket #"<<i<<" contains:";

                for(auto it = myums.begin(i); it != myums.end(i); ++ it)
                        cout<<" "<<*it;
                cout<<"\nbucket #"<<i<<" has "<<myums.bucket_size(i)<<" elements.\n";
        }

        for(auto & x : myums)
                cout<<x<<" is in bucket#"<<myums.bucket(x)<<"\n";

        return 0;
}
