#include <iostream>

//
// Created by polarnight on 23-8-16.
//

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);

        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);;
    head->next->next = new ListNode(2);;
    /* head->next->next->next = new ListNode(3);;
     head->next->next->next->next = new ListNode(4);;
     head->next->next->next->next->next = new ListNode(4);;
     head->next->next->next->next->next->next = new ListNode(5);;*/

    Solution sol;
    ListNode *res = sol.deleteDuplicates(head);

    while (res != nullptr) {
        std::cout << res->val;
        res = res->next;
    }

    return 0;
}