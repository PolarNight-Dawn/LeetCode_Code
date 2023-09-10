#include <iostream>
#include <vector>
#include <unordered_set>

#include "/home/polarnight/Code/CLionProject/leedcode/generate_linked_list.h"

//
// Created by polarnight on 23-9-10, 下午3:56.
//

class Solution {
public:
    gll::ListNode<int> *detectCycle(gll::ListNode<int> *head) {
        std::unordered_set<gll::ListNode<int> *> tmp;

        while (head) {
            if (tmp.count(head)) return head;
            tmp.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};

int main() {
    gll::ListNodeUtils<int> my_utils;
    std::vector<int> nums = {3, 2, 0, -4};

    my_utils.AddVal(nums);
    gll::ListNode<int> *head = my_utils.get_head();

    Solution sol;
    gll::ListNode<int> *res = sol.detectCycle(head);

    while (res) {
        std::cout << res->val << " ";
        res = res->next;
    }

    return 0;
}
