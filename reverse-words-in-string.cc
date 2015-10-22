/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/




#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) 
    {
    	string temp;
    	string result;

     	for (unsigned i = 0; i < s.length(); ++i){
     	   	if (s[i] != ' ')
     	   		temp += s[i];
     	   	else if (!temp.empty()){
     	   		result = result.empty() 
     	   					? temp 
     	   					: temp + ' ' + result;
     	   		temp.clear();
     	   	}
     	}

     	if (!temp.empty())
     		result = result.empty() 
     	   					? temp 
     	   					: temp + ' ' + result;

     	s = result;   
    }
};


int main(int argc, char const *argv[])
{
	string s;
	cout << "input a string :" << endl;
	cin >> s;
	cout << "length is :" << s.length() << endl;

	Solution hehe;
	hehe.reverseWords(s);

	cout << s << endl;
	system("PAUSE");
	return 0;
}




/*class Solution_1{
public:
    void reverseWords(string &s) 
    {
    	string temp;
    	string result;
    	s += ' ';

     	for (string::iterator i = s.begin(); 
     		i != s.end(); ++i){
     	   	if (*i != ' ')
     	   		temp += *i;
     	   	else if (!temp.empty()){
     	   		result = result.empty() 
     	   					? temp 
     	   					: temp + ' ' + result;
     	   		temp.clear();
     	   	}
     	}

     	s = result;   
    }
};*/