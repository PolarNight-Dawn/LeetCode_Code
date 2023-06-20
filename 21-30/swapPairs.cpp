#include <iostream>
#include <stack>

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

        stack<ListNode*> stack;
        ListNode *res = new ListNode(-1);
        ListNode *curr = head;
        head = res;
        /*!ListNode *res = head;
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            stack.push(curr);
            stack.push(curr->next);

            curr = curr->next->next;
            res = stack.top();
            \res并不会对原链表的结构产生影响 res= stack.top()只是赋值操作，并没有进行节点交换操作
            res = res->next;
            stack.pop();
            res = stack.top();
            res = res->next;
            stack.pop();
        }*/
        while (curr != nullptr && curr->next != nullptr) {
            stack.push(curr);
            stack.push(curr->next);

            curr = curr->next->next;
            res->next = stack.top();
            res = res->next;
            stack.pop();
            res->next = stack.top();
            res = res->next;
            stack.pop();
        }

        if (curr != nullptr) {
            res->next = curr;
        } else {
            res->next = nullptr;
        }

        return head->next;
    }
};

int main() {
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