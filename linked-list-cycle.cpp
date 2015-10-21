
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (1){
        	if (!fast || (!fast->next))
        		return false;
        	fast = fast->next->next;
        	slow = slow->next;

        	if (fast == slow)
        		return true;
        }
    }
};

int main(int argc, char const *argv[])
{
	ListNode test1(1);
    ListNode test2(2);
    ListNode test3(3);
    ListNode test4(4);
    ListNode test5(5);

    test1.next = &test2;
    test2.next = &test3;
    test3.next = &test4;
    test4.next = &test5;
    test5.next = &test5;


    Solution a;
    cout << a.hasCycle(&test1) << endl;
	return 0;
}