#include <iostream>
#include <stack>

using namespace std;
//
// Created by polarnight on 23-6-22.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> stack;

        if (head == nullptr && head->next == nullptr) return head;

        int len = 0;
        ListNode * cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            len++;
        }

        int realLean = len - len % k;
        ListNode *curr = head;
        ListNode *res = new ListNode(-1);
        head = res;
        while (realLean > 0) {
            int cnt = k;
            while (cnt > 0) {
                stack.push(curr);
                curr = curr->next;
                cnt--;
            }

            realLean -= k;
            while (!stack.empty()) {
                res->next = stack.top();
                res = res->next;
                stack.pop();
            }
        }

        res->next = curr;
        return head->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    ListNode *res = sol.reverseKGroup(head, 4);

    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }

    return 0;
}