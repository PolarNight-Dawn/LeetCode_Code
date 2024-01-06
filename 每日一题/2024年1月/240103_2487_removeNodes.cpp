#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
//
// Created by polarnight on 24-1-3, 下午3:55.
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
    ListNode* removeNodes(ListNode* head) {
        stack<int> sta;
        priority_queue<int> que;

        sta.push(head->val);
        head = head->next;
        while (head) {
            while (!sta.empty() && head->val > sta.top())
                sta.pop();
            sta.push(head->val);
            head = head->next;
        }

        while (!sta.empty()) {
            que.push(sta.top());
            sta.pop();
        }

        ListNode *result = new ListNode(-1);
        ListNode *tmp = result;
        while (!que.empty()) {
            tmp->next = new ListNode(que.top());
            que.pop();
            tmp = tmp->next;
        }
        return result->next;
    }
};

int main2401032487() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    // head->next->next->next->next = new ListNode(8);

    Solution sol;
    auto *result = sol.removeNodes(head);

    return 0;
}