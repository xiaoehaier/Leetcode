/*
Sort a linked list using insertion sort.
*/


/*
Definition for singly-linked list.
*/

#include <iostream>

using std::cout;
using std::endl;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
    	if (!head) return head; 

		ListNode *cur = head;
    	while (1) {	
    		if (!cur->next) break; 

    		if (cur->next->val < head->val) {
    			ListNode *tmp = cur->next;
    			cur->next = tmp->next;
    			tmp->next = head;
    			head = tmp;
    			continue;
    		}
    		ListNode *index;
        	for (index = head; index != cur; index = index->next) {
        		if ((index->val <= cur->next->val) 
        			&& (index->next->val > cur->next->val)) {
        			ListNode *tmp = cur->next;
        			cur->next = tmp->next;
        			tmp->next = index->next;
        			index->next = tmp;
        			break;
        		}
        	}
        	if (index == cur) cur = cur->next;

    	} 

    	return head;
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
	ListNode a1(1);
	ListNode a2(1);
	/*ListNode a3(14);
	ListNode a4(51);
	ListNode a5(6);
*/
	a1.next = &a2;
	/*a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;*/

	printList(&a1);

	Solution a;

	printList(a.insertionSortList(&a1));
	return 0;
}