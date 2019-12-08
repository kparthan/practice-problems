/*

https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *n1 = l1, *n2 = l2;
        ListNode *output = NULL, *n;
        int carry = 0;
        while (!(n1 == NULL && n2 == NULL)) {
            int sum = carry;
            if (n1 != NULL) sum += n1->val;
            if (n2 != NULL) sum += n2->val;
            carry = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            if (output == NULL) {
                output = node;
                n = output;
            } else {
                n->next = node;
                n = n->next;
            }
            if (n1 != NULL) n1 = n1->next;
            if (n2 != NULL) n2 = n2->next;
        }
        
        if (carry == 1) {
            ListNode *node = new ListNode(1);
            n->next = node;
        }
        return (output);
    }  
};

