/*
Given an array of words and a length L, 
format the text such that each line has exactly L characters 
and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, 
pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. 
If the number of spaces on a line do not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified 
and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        static vector<string> result;
        result.clear();
        int fir = 0;


        while(1) {
        	int len = words[fir].length();
        	int offset = 1;
        	while (fir + offset < words.size()) {
        		len += words[fir + offset].length() + 1;
        		if (len <= L) ++offset;
        		else break; 
        	}

        	if (fir + offset == words.size()) {
        		len = L - words[fir].length();
        		for (int i = 1; i < offset; ++i) {
        			words[fir] += ' ';
        			words[fir] += words[fir + i];
        			
        			len -= words[fir + i].length()+1;
        		}
        		
        		result.push_back(words[fir] + string(len, ' '));
        		return result;	
        	}

        	if (offset == 1) 
        		result.push_back(words[fir] + string(L-words[fir].length(),' '));
        	else {
        		int tmp = L - len + words[fir + offset].length() + 1;
        		string s1(tmp/(offset-1) + 2, ' ');
        		string s2(tmp/(offset-1) + 1, ' ');
        		tmp %= (offset-1);
        		for (int i = 1; i < offset; ++i, --tmp) {
        			words[fir] += ((tmp > 0) ? s1 : s2);
        			words[fir] += words[fir + i];
        		}
        		result.push_back(words[fir]);
        	}

        	fir += offset;
        }
    }
};

void print_vector_string(vector<string> a)
{
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;
}

int main(int argc, char const *argv[])
{
	vector<string> something;
	something.push_back("");
	/*something.push_back("this");
	something.push_back("is");
	something.push_back("");
	something.push_back("just");
	something.push_back("an");
	something.push_back("easy");
	something.push_back("example");
	something.push_back("of");
	something.push_back("text");
	something.push_back("justification.");*/

	Solution a;
	print_vector_string( a.fullJustify(something, 2));


	return 0;
}