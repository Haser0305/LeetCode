﻿//
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

struct list_node {
    int val;
    list_node* next;

    list_node() : val(0), next(nullptr) {
    }

    list_node(int x) : val(x), next(nullptr) {
    }

    list_node(int x, list_node* next) : val(x), next(next) {
    }
};

list_node* add_two_numbers(list_node* l1, list_node* l2) {
    list_node* head = l1;
    int carry = 0;
    int temp;
    while (true) {
        temp = l1->val;
        l1->val = (l1->val + l2->val + carry) % 10;
        carry = (temp + l2->val + carry) / 10;
        if (l1->next == nullptr && l2->next != nullptr) {
            l1->next = new list_node();
        } else if (l1->next != nullptr && l2->next == nullptr) {
            l2->next = new list_node();
        }

        if (l1->next == nullptr && l2->next == nullptr) {
            break;
        } else {
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if (carry != 0) {
        l1 = new list_node(1);
    }
    return head;
}
