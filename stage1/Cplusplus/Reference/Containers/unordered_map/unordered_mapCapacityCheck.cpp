// file : unordered_mapCapacityCheck.cpp
/*****************************************************************
*       bool empty() const noexcept;
*       size_type size() const noexcept;
*       size_type max_size() const noexcept;
*       size_type max_bucket_count() const noexcept;
*****************************************************************/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
        unordered_map<int,int> first;
        unordered_map<int,int> second = {{1,10},{2,20},{3,30}};
        cout<<"first "<<(first.empty() ? "is empty" : "is not empty")<<endl;
        cout<<"second "<<(second.empty() ? "is empty" : "is not empty")<<endl;

        unordered_map<string,double> mymap = {{"milk",2.30},
                                                                                  {"potatoes",1.90},
                                                                                  {"eggs",0.40}};

        cout<<"mymap.size() is "<<mymap.size()<<endl;

        cout<<"max_size = "<<mymap.max_size()<<endl;
        cout<<"max_bucket_count = "<<mymap.max_bucket_count()<<endl;
        cout<<"max_load_factor = "<<mymap.max_load_factor()<<endl;

        return 0;
}
