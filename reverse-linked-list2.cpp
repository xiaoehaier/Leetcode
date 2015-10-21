/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
	ListNode *reverseList(ListNode *head)
    {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        reverseList(head->next)->next = head;
        head->next = NULL;
        return head;
    }


    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        ListNode head0(0);
        head0.next = head;

    	ListNode *pmp = &head0;
        while (--m){
        	pmp = pmp->next;
        }

        ListNode *np = head;
        while (--n){
        	np = np->next;
        }

        ListNode *nnp = np->next;
        np->next = NULL;
        reverseList(pmp->next)->next = nnp;

        if (pmp == &head0)
            return np;

        pmp->next = np;
        return head;
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

    test1.next = &test2;
    test2.next = &test3;
    test3.next = &test4;
    test4.next = &test5;

    printList(&test1);

    Solution a;

    //printList(a.reverseBetween(&test1, 2, 4));

    //printList(a.reverseBetween(&test1, 1, 4));

    //printList(a.reverseBetween(&test1, 2, 5));

    printList(a.reverseBetween(&test1, 1, 5));

    system("PAUSE");

    return 0;
}