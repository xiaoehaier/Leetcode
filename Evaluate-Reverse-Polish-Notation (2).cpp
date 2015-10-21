/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::atoi;


class Solution {
public:
	bool isOperator(string testStr)
	{
		if (testStr.size() != 1) return false;
		if (testStr[0] < '0') return true;
	}

    int evalRPN(vector<string> &tokens) 
    {
    	vector<int> stack;
    	for (int i = 0; i < tokens.size(); ++i) {
    		if (isOperator(tokens[i])) {
    			int tmp = stack.back();
    			stack.pop_back();

    			switch (tokens[i][0]) {
    				case '+': stack.back() += tmp; break;
    				case '-': stack.back() -= tmp; break;
    				case '*': stack.back() *= tmp; break;
    				case '/': stack.back() /= tmp; break;
    			}
    		} else 
    			stack.push_back(atoi(tokens[i].c_str()));	
    	}

    	return stack[0];

    }
};

int main(int argc, char const *argv[])
{
	string tmp[] = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
	vector<string> test;
	for (int i = 0; i < 105; ++i)
	{
		test.push_back(tmp[i]);
	}
	

	Solution a;
	cout << a.evalRPN(test) << endl;
	/*string nice = "143";
	char tmp = atoi(nice.c_str());
	cout << sizeof(int) << endl;*/
	
	return 0;
}