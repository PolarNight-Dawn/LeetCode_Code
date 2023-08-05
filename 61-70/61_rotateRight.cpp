#include <iostream>

//
// Created by polarnight on 23-8-4.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !k) return head;
        int len = 0;
        ListNode *tail;
        ListNode *curr = head;

        for (ListNode *cur = head; cur; cur = cur->next) {
            tail = cur;
            len++;
        }

        int cnt = k % len;
        if (cnt == 0) return head;
        for (int i = 0; i < len - cnt - 1; i++) curr = curr->next;
        tail->next = head;
        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};

int main61() {
    int k = 1;
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for (int i = 1; i < 2; i++) {
        cur->next = new ListNode;
        cur = cur->next;
        cur->val = i + 1;
    }

    Solution sol;
    ListNode *res = sol.rotateRight(head, k);

    ListNode *curr = res;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    return 0;
}