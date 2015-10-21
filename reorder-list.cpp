/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



/*

************ runtime error *******************

class Solution {
public:
    void reorderList(ListNode *head) 
    {
        if (head == NULL) return;
        if (head->next == NULL) return;
        if (head->next->next == NULL) return;

        ListNode *mirror[2048];      
        int cnt;

        for (cnt = 0; head; ++cnt){
            mirror[cnt] = head;
            head = head->next;
        }

        --cnt;

        for (int i = 0; i <= cnt / 2; ++i){  
            mirror[i]->next = mirror[cnt - i];
            if ((cnt - i == i) || (cnt - i == i + 1))
                mirror[cnt - i]->next = NULL;
            else     
                mirror[cnt - i]->next = mirror[i + 1];             
        }
    }
        
};*/


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

    /*ListNode *reverse(ListNode *head)
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
*/
    void reorderList(ListNode *head) 
    {
    	if (head == NULL) return;
    	if (head->next == NULL) return;
    	if (head->next->next == NULL) return;

    	ListNode *fast = head, *slow = head, *tail = head;

        while ((fast->next) && fast){
            fast = fast->next->next;
            slow = slow->next;
        }

        while (tail->next) tail = tail->next;
		
        reverseList(slow);

        while (head->next){
            ListNode *temp = head->next;
            head->next = tail;
            tail = tail->next;
            head->next->next = temp;
            head = temp;
        }

        if (head != tail){
            head->next = tail;
            tail->next = NULL;
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

    test1.next = &test2;
    test2.next = &test3;
    test3.next = &test4;
    test4.next = &test5;

    printList(&test1);

    Solution a;

    a.reorderList(&test1);

    printList(&test1);

    system("PAUSE");

    return 0;
}