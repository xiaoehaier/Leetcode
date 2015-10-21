/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

//merge sort worst O(nlogn)
//quick sort worst O(n^2)

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::swap;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeList(ListNode *head1, ListNode *head2)
	{
		if (!head1) return head2;
		if (!head2) return head1;

		ListNode head(0);
	
		ListNode *cur = &head;

		while (head1 && head2) {
			if (head1->val < head2->val) {
				cur->next = head1;
				head1 = head1->next;
			} else {
				cur->next = head2;
				head2 = head2->next;
			}
			cur = cur->next;
		}

		if (!head1) cur->next = head2;
		if (!head2) cur->next = head1;

		return head.next;
		
	}


	

    ListNode *sortList(ListNode *head) {
    	if (!head || !head->next) return head;

    	ListNode *half = head;
		for (ListNode *i = head; i->next && i->next->next; 
			i = i->next->next, half = half->next) {}
		
		ListNode *tmp = half->next;
		half->next = NULL;
		return mergeList(sortList(head), sortList(tmp));
    }
};

void printList(ListNode *head)
{
	while (head) {
		cout << head->val << endl;
		head =head->next;
	}
}

int main(int argc, char const *argv[])
{
	ListNode a1(-84);
	ListNode a2(142);
	ListNode a3(41);
	ListNode a4(-17);
	ListNode a5(-71);
	ListNode a6(170);
	ListNode a7(186);
	ListNode a8(183);
	ListNode a9(-21);
	ListNode a0(-76);

	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &a6;
	a6.next = &a7;
	a7.next = &a8;
	a8.next = &a9;
	a9.next = &a0;

	printList(&a1);

	cout << endl;
	Solution a;

	printList(a.sortList(&a1));
	return 0;
}