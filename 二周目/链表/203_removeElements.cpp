#include <iostream>

//
// Created by polarnight on 23-9-7.
//

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head;
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;

        while (cur) {
            if (cur->val == val) pre->next = cur->next;
            else {
                pre->next = cur;
                pre = pre->next;
            }
            cur = cur->next;
        }

        return dummy->next;
    }
};

int main() {
    int val = 6;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution sol;
    ListNode *res = sol.removeElements(head, val);

    ListNode *cur = res;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
}