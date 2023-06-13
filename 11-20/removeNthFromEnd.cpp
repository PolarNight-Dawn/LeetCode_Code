#include <iostream>

using namespace std;
//
// Created by polarnight on 23-5-12.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* cur = head;
        int len = 0;

        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }

        if (n > len) {
            return head;
        } else if (n == len) {
            ListNode* curr = head;
            head = head->next;
            curr->next = nullptr;
            return head;
        } else {
            ListNode* curr = head;
            int i = len - n;
            while (i > 1) {
                curr = curr->next;
                i--;
            }
            curr->next = curr->next->next;
        }
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;

    Solution sol;
    ListNode* res = sol.removeNthFromEnd(head, n);

    ListNode* current = res;
    while (current != nullptr) {
        cout << current->val;
        current = current->next;
    }


    return 0;
}