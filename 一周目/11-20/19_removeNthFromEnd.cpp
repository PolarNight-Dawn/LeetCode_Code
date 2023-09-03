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
        ListNode* fast = head;
        ListNode* slow = head;

        while (n >= 0) {
            if (fast == nullptr) {
                return head->next;
            }
            fast = fast->next;
            n--;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};

int main19() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 5;

    Solution sol;
    ListNode* res = sol.removeNthFromEnd(head, n);

    ListNode* current = res;
    while (current != nullptr) {
        cout << current->val;
        current = current->next;
    }


    return 0;
}