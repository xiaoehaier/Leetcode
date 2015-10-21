/*All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, 
it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].*/

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> result;
    	char existTable[1024*1024];
        unsigned code10 = 0;
        map<char, unsigned> codeACGT;
        codeACGT['A'] = 0;
        codeACGT['C'] = 1;
        codeACGT['G'] = 2;
        codeACGT['T'] = 3;


        memset(existTable, 0, 1024*1024);
        for (int i = 0; i < 9; ++i){
        	code10 <<= 2;
        	code10 |= codeACGT[s[i]];
        }

        for (int i = 9; i < s.length(); ++i){
        	code10 <<= 2;
        	code10 |= codeACGT[s[i]];
        	code10 &= 0xfffff;

        	if(existTable[code10] == 1)
        		result.push_back(s.substr(i-9, 10));

        	++existTable[code10];
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution a;
	vector<string> b;
	b = a.findRepeatedDnaSequences(s);
	for (int i = 0; i < b.size(); ++i)
	{
		cout << b[i] << endl;
	}
	return 0;
}






