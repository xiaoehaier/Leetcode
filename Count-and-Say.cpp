#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return NULL;
        string result = "1";
        string tmp;
        char cur;
        char seriesCnt = 1;
        
        while(--n){
            cur = result[0];

            for(int i=1; i<=result.size(); ++i){
                if(cur == result[i]){
                    ++seriesCnt;
                    continue;
                }
                tmp += seriesCnt+48;
                tmp += cur;
                cur = result[i];
                seriesCnt = 1;
            }
            cout << tmp << endl;
            result = tmp;
            tmp.clear();
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    a.countAndSay(10);
    return 0;
}