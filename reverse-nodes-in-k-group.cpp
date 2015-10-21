/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

#include <iostream>
#include <stdlib.h>

using namespace std;



 //Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
    	if (!head) return NULL;
    	if (k == 1) return head;

        ListNode head0(0);
        head0.next = head;
        ListNode *prehead = &head0, *tail = prehead;
		ListNode *tmp = tail->next;

        while (1){
        	if (!prehead->next) return head0.next;
        	int i;
        	for (i = 0; i < k; ++i){
        		if (!tail->next) break;
        		tail = tail->next;
        	}

        	if (i < k) return head0.next;

        	tmp = tail->next;
        	tail->next = NULL;
        	tail = prehead->next;

        	prehead->next = reverse(tail);
        	tail->next = tmp;

        	prehead = tail;
        }
    }
};


void printList(ListNode *head)
{
    while (head){
        cout << head->val << "  ";
        head = head->next;
    }

    cout << endl;
}


int main(int argc, char const *argv[])
{
    ListNode test1(1);
    ListNode test2(2);
    ListNode test3(3);
    ListNode test4(4);
    ListNode test5(5);
    ListNode test6(6);


    test1.next = &test2;
    test2.next = &test3;
    test3.next = &test4;
    test4.next = &test5;
    test5.next = &test6;

    printList(&test1);

    Solution a;

    printList(a.reverseKGroup(&test1, 3));

    system("PAUSE");

    return 0;
}