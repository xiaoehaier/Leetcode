/*
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (1){
        	if (!fast || (!fast->next))
        		return NULL;
        	fast = fast->next->next;
        	slow = slow->next;

        	if (fast == slow)
        		break;
        }

        while (slow != head){
        	slow = slow->next;
        	head = head->next;
        }

        return head;
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
    cout << a.detectCycle(&test1)->val << endl;
	return 0;
}