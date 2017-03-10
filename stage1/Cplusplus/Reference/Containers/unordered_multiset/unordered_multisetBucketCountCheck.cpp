// file : unordered_multisetBucketCountCheck.cpp
// size_type bucket_count() const noexcept;
// Return number of buckets
// size_type bucket_size(size_type n) const;
// Return the number of elements in bucket n.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
        unordered_multiset<string>  myums = {"Klingon","Vulcan","Klingon","Cardassian","Vulcan","Human"};

        unsigned n = myums.bucket_count();

        cout<<"myums has "<<n<<" buckets\n";

        for(unsigned i = 0; i < n; i ++)
        {
                cout<<"bucket #"<<i<<" contains:";
                for(auto it = myums.begin(i); it != myums.end(i); ++it)
                        cout<<" "<<*it;
                cout<<" bucket #"<<i<<" has "<<myums.bucket_size(i)<<" elements.";
                cout<<endl;
        }
        return 0;
}
