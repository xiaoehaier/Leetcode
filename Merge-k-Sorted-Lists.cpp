/*Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.*/

#include <vector>
#include <cstddef>
#include <cstring>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int indexArray[lists.size()];
        memset(indexArray, 0, lists.size());

    }
};