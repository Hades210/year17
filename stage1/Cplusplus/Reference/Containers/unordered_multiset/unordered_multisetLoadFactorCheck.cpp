// file : unordered_multisetLoadFactorCheck.cpp
// float load_factor() const noexcept;
// Returns the current load factor in the unordered_multiset container.
// get(1) float max_load_factor() const noexcept;
// set(2) void max_load_factor(float z);
// By default, unordered_multiset containers have a max_load_factor of 1.0

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{       
        unordered_multiset<int> myums;

        cout<<"size = "<<myums.size()<<endl;
        cout<<"bucket_count = "<<myums.bucket_count()<<endl;
        cout<<"load_factor = "<<myums.load_factor()<<endl;
        cout<<"max_load_factor = "<<myums.max_load_factor()<<endl;

        unordered_multiset<string> myums2 = {"human","Klingon","vulcan","vulcan","andorian","vulcan"};

        cout<<"current max_load_factor: "<<myums2.max_load_factor()<<endl;
        cout<<"current size: "<<myums2.size()<<endl;
        cout<<"current bucket_count: "<<myums2.bucket_count()<<endl;
        cout<<"current load_factor: "<<myums2.load_factor()<<endl;

        float z = myums2.max_load_factor();
        myums2.max_load_factor(z / 2.0);
        cout<<"[max_load_factor halved]"<<endl;

        cout<<"new max_load_factor: "<<myums2.max_load_factor()<<endl;
        cout<<"new size: "<<myums2.size()<<endl;
        cout<<"new bucket_count: "<<myums2.bucket_count()<<endl;
        cout<<"new load_factor: "<<myums2.load_factor()<<endl;

        return 0;
}
unordered_multisetLoadFactorCheck.cpp (END)
