//
// Created on 2022/3/5.
//

/***********************
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
************************/

#include "cstdio"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = l1;
    int carry = 0;
    int temp;
    while (true) {
        temp = l1->val;
        l1->val = (l1->val + l2->val + carry) % 10;
        carry = (temp + l2->val + carry) / 10;
        if (l1->next == NULL && l2->next != NULL) {
            l1->next = new ListNode();
        } else if (l1->next != NULL && l2->next == NULL) {
            l2->next = new ListNode();
        }

        if (l1->next == NULL && l2->next == NULL) {
            break;
        } else {
            l1 = l1->next;
            l2 = l2->next;
        }

    }
    if (carry != 0) {
        l1 = new ListNode(1);
    }
    return head;
}