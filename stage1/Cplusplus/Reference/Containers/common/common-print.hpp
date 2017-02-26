// file : common-print.hpp

#ifndef COMMON_PRINT_HPP
#define COMMON_PRINT_HPP

#include <iostream>
#include <string>

#include <vector>
#include <list>
#include <forward_list>

using namespace std;

template <class T>
void printInfo(string who, const vector<T>& myvector )
{
	cout<<who<<" contains:";

	for(auto & x : myvector)
		cout<<"\t"<<x;
	cout<<"\n";
}

template <class T>
void printInfo(string who, const list<T>& mylist)
{
	cout<<who<<" contains:";

	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<"\n";
}

template <class T>
void printInfo(string who, const forward_list<T>& mylist)
{
	cout<<who<<" contains:";

	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<"\n";

}



#endif /*COMMON_PRINT_HPP*/
