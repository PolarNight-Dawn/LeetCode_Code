#include <iostream>

using namespace std;
//
// Created by polarnight on 23-5-21.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = head->next;
        ListNode* cur = head;
        ListNode* pre = nullptr;

        int i = 0;
        while (cur != nullptr && cur->next != nullptr) {
            if (i % 2 == 0) {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                temp->next = cur;

                if (pre != nullptr) {
                    pre->next = temp;
                }

                pre = cur;
                cur = cur->next;
            }
            i++;
        }

        return newHead;
    }
};

int main24() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    ListNode* res = sol.swapPairs(head);

    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }

    return 0;
}