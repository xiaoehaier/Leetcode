/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k)
    {
    	
    	if (head == NULL) return NULL;

        ListNode *tail = head;
        int len = 1;
        for (; tail->next; ++len) tail = tail->next;

        k %= len;
    	if (k == 0) return head;
    	tail->next =head;
    	len -= k;
        ListNode *pknode = head;
    	for (int i = 1; i < len; ++i)
    		pknode = pknode->next;

    	ListNode *knode = pknode->next;
    	pknode->next = NULL;
    	return knode;

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
    //printList(a.rotateRight(&test1, 1));
    //printList(a.rotateRight(&test1, 3));
    printList(a.rotateRight(&test1, 9));
    //printList(a.rotateRight(&test1, 5));
    system("PAUSE");

    return 0;
}