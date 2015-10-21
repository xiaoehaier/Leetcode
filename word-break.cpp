/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
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


class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    	if (dict.size() == 0) return false;
        int lenth = s.length();
        if (!lenth) return true;
        bool trueS[lenth];
        memset(trueS,false,sizeof(trueS));
        trueS[0] = true;

        for (int i = 0; i < lenth; ++i) {
        	if (!trueS[i]) continue;
        	for(string word:dict){
        		if (word.length() > lenth - i)
        			continue;
        		if(s.substr(i).find(word) == 0){
        			if (i + word.length() == lenth)
        				return true;
        			trueS[i + word.length()] = true;
        		}
        	}
        }

        return false;
    }
};


int main(int argc, char const *argv[])
{
	string s = "dcacbcadcad";
	unordered_set<string> dict;
	//dict = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
	dict = {"cbd","dca","bcdc","dcac","ad"};
	Solution a;
	if (a.wordBreak(s, dict))
		cout << "ok" << endl;
	else 
		cout << "nope" << endl;

	return 0;
}