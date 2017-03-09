// file : unordered_setMaxLoadFactorCheck.cpp
// get(1)       float max_load_factor() const noexcept;
// set(2)       void max_load_factor(float z);
// By default, unordered_set containers have a max_load_factor of 1.0

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
        unordered_set<string> mycity =
        {"New York", "Paris", "London", "Hong Kong", "Bangalore", "Tel Aviv"};

        cout<<"current max_load_factor: "<<mycity.max_load_factor()<<"\n";
        cout<<"current size: "<<mycity.size()<<"\n";
        cout<<"current bucket_count: "<<mycity.bucket_count()<<"\n";
        cout<<"current load_factor: "<<mycity.load_factor()<<"\n";

        float z = mycity.max_load_factor();
        mycity.max_load_factor(z / 2.0);
        cout<<"[max_load_factor halved]"<<"\n";

        cout<<"new max_load_factor: "<<mycity.max_load_factor()<<"\n";
        cout<<"new size: "<<mycity.size()<<"\n";
        cout<<"new bucket_count: "<<mycity.bucket_count()<<"\n";
        cout<<"new load_factor: "<<mycity.load_factor()<<"\n";
        
        return 0;
}
