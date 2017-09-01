/*************************************************************************
*  File Name: ioiter1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 07:12:34 PM CST
*************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> coll;

	/* read all words from the standard input
	 * source: all strings until end-of-file (or error)
	 * destination: coll(inserting)
	 */
	copy(istream_iterator<string>(cin),
		istream_iterator<string>(),
		back_inserter(coll));

	sort(coll.begin(),coll.end());

	/* print all elements without duplicates
	 * source: coll
	 * destination: standard output(with newline between elements)
	 */
	unique_copy(coll.begin(),coll.end(),
			ostream_iterator<string>(cout,"\n"));

	return 0;
}

