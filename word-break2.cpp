/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/



#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <memory.h>
using std::cout;
using std::endl;
using std::unordered_set;
using std::string;
using std::vector;


/*class Solution {
    vector<string> result;
public:
    void wordBreakRecur(string s, string tmp, unordered_set<string> &dict)
    {
        if (!tmp.empty()) tmp += ' ';

        for(string word:dict){
            if (word.length() > s.length())
                continue;
            if (s.compare(0, word.length(), word)== 0) {  
                if (word.length() == s.length()) {
                    result.push_back(tmp + word);
                } else 
                    wordBreakRecur(s.substr(word.length()), tmp + word, dict);
            }
        }
    }
    

    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
    	if (dict.size() == 0) return result;
        string raw;
        wordBreakRecur(s, raw, dict);
        return result;
    }  
};*/


class Solution {
    vector<string> result;
public:
    void wordBreakRecur(string s, string tmp, unordered_set<string> &dict)
    {
        if (!tmp.empty()) tmp += ' ';

        for(string word:dict){
            if (word.length() > s.length())
                continue;
            if (s.compare(0, word.length(), word)== 0) {  
                if (word.length() == s.length()) {
                    result.push_back(tmp + word);
                } else 
                    wordBreakRecur(s.substr(word.length()), tmp + word, dict);
            }
        }
    }
    void wordBreakRecurReverse(string s, string tmp, unordered_set<string> &dict)
    {
        if (!tmp.empty()) tmp = ' ' + tmp;

        for(string word:dict){
            if (word.length() > s.length())
                continue;
            if (s.compare(s.length()-word.length(), word.length(), word) == 0) {  
                if (word.length() == s.length()) {
                    result.push_back(word + tmp);
                } else 
                    wordBreakRecurReverse(s.substr(0, s.length()-word.length()), word + tmp, dict);
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        if (dict.size() == 0) return result;

        int po = 0, ne = 0;
        for (string word:dict) {
            if (s.length() < word.length()) continue;
            if (s.compare(0, word.length(), word)== 0) ++po;
            if (s.compare(s.length()-word.length(), s.length(), word)== 0) ++ne;
        }
        cout << po <<endl<< ne << endl;
        if (po == 0 || ne == 0) return result;

        string raw;
        if (po <= ne)
            wordBreakRecur(s, raw, dict);
        else 
            wordBreakRecurReverse(s, raw, dict);

        return result;
    }  
};




void printV(vector<string> result)
{
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
	string s = "bb";
	unordered_set<string> dict;
	//dict = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
	//dict = {"cbd","dca","bcdc","dcac","ad"};
    
    dict = {"a","b","bbb","aaaa"};
	Solution a;
	printV(a.wordBreak(s, dict));

	return 0;
}