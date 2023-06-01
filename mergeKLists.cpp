#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vec;
        int len = lists.size();

        for (int i = 0; i < len; i++) {
            ListNode *a = lists[i];

            while (a != nullptr) {
                vec.push_back(a->val);
                a = a->next;
            }
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

// 创建链表函数，用于简化测试代码
ListNode* createLinkedList(std::vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    for (int val : values) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }

    return dummy->next;
}

// 打印链表函数，用于简化测试代码
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main23() {
    Solution solution;

    // 创建链表数组
    std::vector<ListNode*> lists;

    // 创建链表1: 1 -> 4 -> 5
    std::vector<int> values1 = {1, 4, 5};
    ListNode* list1 = createLinkedList(values1);
    lists.push_back(list1);

    // 创建链表2: 1 -> 3 -> 4
    std::vector<int> values2 = {1, 3, 4};
    ListNode* list2 = createLinkedList(values2);
    lists.push_back(list2);

    // 创建链表3: 2 -> 6
    std::vector<int> values3 = {2, 6};
    ListNode* list3 = createLinkedList(values3);
    lists.push_back(list3);

    // 合并链表数组
    ListNode* mergedList = solution.mergeKLists(lists);

    // 打印合并后的链表
    printLinkedList(mergedList);

    return 0;
}