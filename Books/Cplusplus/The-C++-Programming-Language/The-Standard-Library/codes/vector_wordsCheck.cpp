// file : vector_wordsCheck.cpp

// be careful when using vector to store pointers , because any reallocation (implicit or explicit)
// will cause problems 

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	vector<char> chars;     // input "buffer" for characters
	constexpr int max = 20000;
	chars.reserve(max);
	cout<<"chars.capacity() "<<chars.capacity()<<endl;

	vector<char*> words;  // pointers to start of words

	bool in_word = false;

	char c;
	while(true)
	{
		cin.get(c);

		if(c == '*')
			break;

		if(isalpha(c)) {
			if(!in_word) { // found beginning of word
				in_word = true; 
				chars.push_back(0); // end of previous word
				chars.push_back(c);
				words.push_back(&chars.back());
			}
			else
				chars.push_back(c);
		}
		else
			in_word = false;
	}

	if(in_word)
		chars.push_back(0); // terminate last word

	if(max < chars.size()) { // oops: chars grew beyond capacity; the words are invalid
		//...
		cout<<"oops: chars grew beyond capacity; the words are invalid"<<endl;
		chars.shrink_to_fit(); // release any surplus capacity
	}

	for (char* word : words)
		cout<<word<<"\n";
	

	return 0;
}