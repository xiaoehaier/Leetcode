/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should bheadserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x)
    {
    	if (head == NULL) return NULL;
   	
        ListNode head0(0);
        head0.next = head;

        ListNode *bhead = head, *stail = &head0;

        while (bhead){
            if (bhead->val >= x) break;
            stail = bhead;
            bhead =stail->next;

        } 

        if (!bhead) return head;

        ListNode *pre = bhead, *cur = bhead->next;

        while (cur){
            if (cur->val < x){
                pre->next = cur->next;
                cur->next = bhead;
                stail->next = cur;
                stail = cur;
            }else 
                pre = cur;

            cur = pre->next;
        }

        return head0.next;
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
    ListNode test2(4);
    ListNode test3(3);
    ListNode test4(2);
    ListNode test5(5);
    ListNode test6(2);

    test1.next = &test2;
    test2.next = &test3;
    test3.next = &test4;
    test4.next = &test5;
    test5.next = &test6;

    printList(&test1);

    Solution a;

    printList(a.partition(&test1, 0));

    system("PAUSE");

    return 0;
}