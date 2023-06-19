#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    struct cmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue <ListNode *, vector<ListNode *>, cmp> min_heap;

        for (auto &vec : lists) {
            if (vec) min_heap.push(vec);
        }

        ListNode dummy(-1);
        ListNode *p = &dummy;
        while(!min_heap.empty()){
            ListNode* top = min_heap.top();
            min_heap.pop();
            p->next = top;
            p = top;
            if(top->next) min_heap.push(top->next);
        }
        //! \基于代码本身的理解 这是一种入队和出队处理 重点在出队 因为涉及了指针的替代 个人感觉比较难 但会加深对链表的掌握
        //! \基于解题思路的理解 让链表头元素入队组成小根堆 不断弹出最小元素 更新指针将弹出的元素连接起来 更新弹出元素的链表的头元素

        p->next = nullptr;
        return dummy.next;
    }
};

// 创建链表函数，用于简化测试代码
ListNode *createLinkedList(std::vector<int> &values) {
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;

    for (int val: values) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }

    return dummy->next;
}

// 打印链表函数，用于简化测试代码
void printLinkedList(ListNode *head) {
    ListNode *curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Solution solution;

    // 创建链表数组
    std::vector<ListNode *> lists;

    // 创建链表1: 1 -> 4 -> 5
    std::vector<int> values1 = {1, 4, 5};
    ListNode *list1 = createLinkedList(values1);
    lists.push_back(list1);

    // 创建链表2: 1 -> 3 -> 4
    std::vector<int> values2 = {1, 3, 4};
    ListNode *list2 = createLinkedList(values2);
    lists.push_back(list2);

    // 创建链表3: 2 -> 6
    std::vector<int> values3 = {2, 6};
    ListNode *list3 = createLinkedList(values3);
    lists.push_back(list3);

    // 合并链表数组
    ListNode *mergedList = solution.mergeKLists(lists);

    // 打印合并后的链表
    printLinkedList(mergedList);

    return 0;
}