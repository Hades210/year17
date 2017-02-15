// file : ansiCheck.cpp

/**
 *使用template 和 bool 等特性，用于检验 C++ compiler 是否
 *支持 ANSI 标准
 **/
 
#include <iostream>
using namespace std;



template <class T>
bool ansisupported (T x) {return true;}

int main()
{
	if(ansisupported (0)) 
		cout<<"ANSI OK"<<endl;
	return 0;
}
