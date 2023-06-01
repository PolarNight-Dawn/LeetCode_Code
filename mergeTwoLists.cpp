#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
// Created by polarnight on 23-5-15.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        vector<int> vec;
        ListNode *a = list1;
        ListNode *b = list2;

        while (a != nullptr) {
            vec.push_back(a->val);
            a = a->next;
        }

        while (b != nullptr) {
            vec.push_back(b->val);
            b = b->next;
        }

        sort(vec.begin(), vec.end());

        ListNode *res = nullptr;
        ListNode* c = nullptr;

        for (int n : vec) {
            if (res == nullptr) {
                res = new ListNode(n);
                c = res;
            } else {
                c->next = new ListNode(n);
                c = c->next;
            }
        }

        return res;
    }
};

int main21() {
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);;
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode *res = sol.mergeTwoLists(list1, list2);

    ListNode *current = res;
    while (current != nullptr) {
        cout << current->val;
        current = current->next;
    }

    return 0;
}