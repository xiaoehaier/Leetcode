#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> tmp(nRows, "");
        int index = 0;
        int addUp = -1;
        for(int i=0; i<s.length(); ++i){
            tmp[index] = tmp[index]+s[i];
            if(index == 0 || index == nRows-1)
                addUp *= -1;
            index += addUp;
        }
        
        for(int i=1; i<nRows; ++i)
            tmp[0] = tmp[0]+tmp[i];
            
        return tmp[0];
    }
};

int main(int argc, char const *argv[])
{
    string a = "PAYPALISHIRING";
    Solution b;
    cout << "dd";
    return 0;
}