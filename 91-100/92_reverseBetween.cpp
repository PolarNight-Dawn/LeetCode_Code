#include <iostream>
#include <stack>

//
// Created by polarnight on 23-8-22.
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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        std::stack<ListNode *> st;
        ListNode *curr = head;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *res = dummy;

        int cnt = 0;
        while (cnt < right) {
            cnt++;
            if (cnt < left) res = curr;
            if (cnt >= left && cnt <= right) st.push(curr);
            curr = curr->next;
        }

        while (!st.empty()) {
            res->next = st.top();
            st.pop();
            res = res->next;
        }

        if (st.empty()) res->next = curr;
        return dummy->next;
    }
};

int main92() {
    int left = 1, right = 2;
    ListNode *head = new ListNode(3);
    ListNode *cur = head;
    for (int i = 5; i <= 5; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    Solution sol;
    ListNode *res = sol.reverseBetween(head, left, right);

    ListNode *node = res;
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }

    return 0;
}