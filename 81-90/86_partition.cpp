#include <iostream>

//
// Created by polarnight on 23-8-19.
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
    ListNode* partition(ListNode* head, int x) {
       ListNode *cur = head;
       ListNode *dummy01 = new ListNode(-1);
       ListNode *lessArea = dummy01;
        ListNode *dummy02 = new ListNode(-1);
       ListNode *moreArea = dummy02;

       while (cur) {
           if (cur->val < x) {
               lessArea->next = new ListNode(cur->val);
               lessArea = lessArea->next;
           } else {
               moreArea->next = new ListNode(cur->val);
               moreArea = moreArea->next;
           }
           cur = cur->next;
       }

       lessArea->next = dummy02->next;
       return dummy01->next;
    }
};

int main86() {
    int x = 3;
    ListNode *head = nullptr;
    /*ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
     head->next->next->next = new ListNode(2);
     head->next->next->next->next = new ListNode(5);
     head->next->next->next->next->next = new ListNode(2);
     // head->next->next->next->next->next->next = new ListNode(5);*/

    Solution sol;
    ListNode *res = sol.partition(head, x);

    while (res != nullptr) {
        std::cout << res->val;
        res = res->next;
    }

    return 0;
}