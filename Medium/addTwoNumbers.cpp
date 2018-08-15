#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
**/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum, carry;
    ListNode *ret = l1;
    for (carry = 0; ; )
    {
        sum = l1->val + l2->val + carry;
        l1->val = (sum >= 10) ? sum - 10 : sum;
        carry = (sum >= 10) ? 1 : 0;
        if (l1->next == NULL && l2->next == NULL)
        {
            if (carry) l1->next = new ListNode(1);
            break;
        }
        if (l2->next == NULL)
        {
            l2 = new ListNode(0);
            l1 = l1->next;
            continue;
        }
        if (l1->next == NULL)
        {
            l1->next = new ListNode(0);
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return ret;
}
