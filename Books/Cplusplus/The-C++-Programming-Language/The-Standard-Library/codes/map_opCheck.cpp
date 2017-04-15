// file : map_opCheck.cpp

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

typedef string Coordinate;

int main()
{
	map<string,pair<Coordinate,Coordinate> > locations {
			{"Copenhagen",{"50:40N","12:34E"}},
			{"Rome",{"41:54N","12:30E"}},
			{"New York",{"40:40N","73:56W"}}
	};


	for(auto& location : locations )
		cout<<location.first<<" is located at: ["<<location.second.first<<","<<location.second.second<<"]"<<endl;

	multimap<string,int> mm {
			{"apple",2},
			{"pear",2},
			{"apple",7},
			{"apple",9},
			{"orange",2}
	};

	const string k{"apple"};

	auto pp = mm.equal_range(k);

	if(pp.first == pp.second)
		cout<<"no element with value "<<k<<"\n";
	else
	{
		cout<<"elements with value "<<k<<":\n";

		for(auto p = pp.first; p != pp.second; ++p)
			cout<<p->second<<" ";
	}
	cout<<endl;

	unordered_map<string,int> score1 {
			{"andy",7},
			{"al",9},
			{"bill",-3},
			{"barbara",12}
	};

	map<string,int> score2 {
			{"andy",7},
			{"al",9},
			{"bill",-3},
			{"barbara",12}
	};

	cout<<"unordered:";
	for(const auto& x : score1)
		cout<<"{"<<x.first<<","<<x.second<<"}";
	cout<<"\nordered:";
	for(const auto& x : score2)
		cout<<"{"<<x.first<<","<<x.second<<"}";
	cout<<endl;
	return 0;	
}