#include <iostream>
#include <stack>

#include "/home/polarnight/Code/CLionProject/leedcode/generate_linked_list.h"

//
// Created by polarnight on 23-9-11, 下午2:33.
//

class Solution {
public:
    gll::ListNode<int> *reverseList(gll::ListNode<int> *head) {
        std::stack<gll::ListNode<int> *> sta;
        auto dummy = new gll::ListNode<int>(-1);
        dummy->next = head;
        gll::ListNode<int> *cur = dummy;

        while (cur->next) {
            sta.push(cur->next);
            cur = cur->next;
        }

        cur = dummy;
        while (!sta.empty()) {
            cur->next = sta.top();
            sta.pop();
            cur = cur->next;
            if (sta.empty()) cur->next = nullptr;
        }

        // 大多数情况下，结构体不需要手动释放内存，特别是当它只包含了简单的数据类型（例如int）和指向其他节点的指针
        // 因为这些数据通常是栈上分配的，它们的生命周期受限于其包含的作用域
        // 手动释放堆，自动释放栈
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main204() {
    gll::ListNodeUtils<int> my_utils;
    std::vector<int> nums = {1,2,3,4,5};
    my_utils.AddVal(nums);
    gll::ListNode<int> *head = my_utils.get_head();

    Solution sol;
    head = sol.reverseList(head);

    gll::ListNode<int> *cur = head;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }

    return 0;
}
