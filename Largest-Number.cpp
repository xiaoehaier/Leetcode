#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    static bool earlyer(string &a, string &b)
    {
        string ab=a+b;
        return ab.compare(b+a)>0;
    }
    string largestNumber(vector<int> &num) {
        vector<string> tmp;
        for(int i=0; i<num.size(); ++i){
            tmp.push_back(to_string(num[i]));
        }
        make_heap(tmp.begin(), tmp.end(), earlyer);
        sort_heap(tmp.begin(), tmp.end(), earlyer);
        string result;
        for(int i=0; i<tmp.size(); ++i){
            result += tmp[i];
        }
        return result;
    }
};