#include <iostream>

//
// Created by polarnight on 23-8-17.
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
    ListNode* deleteDuplicates02(ListNode* head) {
        ListNode *cur = head;
        if (!head || !head->next) return head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) cur->next = cur->next->next;
            else cur = cur->next;
        }

        return head;
    }
};

int main83() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);;
    head->next->next = new ListNode(2);;
    /* head->next->next->next = new ListNode(3);;
     head->next->next->next->next = new ListNode(4);;
     head->next->next->next->next->next = new ListNode(4);;
     head->next->next->next->next->next->next = new ListNode(5);;*/

    Solution sol;
    ListNode *res = sol.deleteDuplicates02(head);

    while (res != nullptr) {
        std::cout << res->val;
        res = res->next;
    }

    return 0;
}