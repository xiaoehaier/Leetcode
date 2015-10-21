/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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

/* 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode head(0);
        ListNode *index = &head;

        while (l1 || l2){
          index->val += (l1?l1->val:0) + (l2?l2->val:0);
          index->next = new ListNode(index->val / 10);
          index->val %= 10;
          index->next->next = index;
          index = index->next;
          if (l1) l1 = l1->next;
          if (l2) l2 = l2->next;
        }

        if (!index->val){
          index->next->next = NULL;
          delete index;
        }else
          index->next = NULL;

        return &head;
    }
};
*/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *head = l1;

        while (l1->next && l2->next){
          
          l1->val += l2->val;

          if (l1->val >= 10){
            l1->next->val += 1;
            l1->val %= 10;
          }

          l1 = l1->next;
          l2 = l2->next;
        }

        l1->val += l2->val;

        if (!l1->next) l1->next = l2->next;

        while (l1->val >= 10){

          if(l1->next)
            l1->next->val += 1;
          else
            l1->next = new ListNode(1);
                                               
          l1->val %= 10;

          l1 = l1->next;

        }

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
    ListNode test1(6);
    ListNode test2(2);
    ListNode test3(5);
    ListNode test4(4);
    ListNode test5(5);
    ListNode test6(6);
    ListNode test7(9);

    test1.next = &test2;
    //test2.next = &test3;
    //test3.next = &test4;
    test4.next = &test5;
    test5.next = &test6;
    test6.next = &test7;

    printList(&test1);
    printList(&test4);

    Solution a;

    printList(a.addTwoNumbers(&test1, &test4));

    system("PAUSE");

    return 0;
}