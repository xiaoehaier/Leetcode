#include <iostream>
using namespace std;

/*class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        while(1){

        	if(*p == '\0' && *s == '\0')
        		return true;

        	if(*s == *p || *p == '.'){
        		++s;
        		++p;
        		continue;
        	}

        	if(*p != '*' && *p != *s)
        		return false;

        	//compress "******" to "*"
        	while(*p == '*' && *(p+1) == '*')
        		++p;

        	if(*(p+1) == '\0')
        		return true;

        	while(*p == '*'){
        		while(*s != *(p+1) && *(p+1) != '.'){
        			if(*s == '\0')
        				return false;
        			++s;
        		}

        		if(isMatch(s, p+1))
        			return true;
        		else 
        			++s;
        	}
        }  
    }
};*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        while(1){

        	if(*p == '\0' && *s == '\0')
        		return true;

        	if(*s == *p || *p == '.'){
        		++s;
        		++p;
        		continue;
        	}
        	
        	if(*s != *p)
    }
};



int main(int argc, char const *argv[])
{
	char *s = "abcfedddl";
	char *p = "*.....*";
	Solution a;
	if(a.isMatch(s, p))
		cout << "all ok" << endl;
	else 
		cout << "faile" << endl;
	return 0;
}