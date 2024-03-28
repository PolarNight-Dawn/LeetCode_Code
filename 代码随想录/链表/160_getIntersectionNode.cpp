#include <iostream>

#include "/home/polarnight/Code/CLionProject/LeetCode/generate_linked_list.h"

//
// Created by polarnight on 23-9-10, 下午9:41.
//

class Solution {
public:
    gll::ListNode<int> *getIntersectionNode(gll::ListNode<int> *headA, gll::ListNode<int> *headB) {
        gll::ListNode<int> *cur_a = headA;
        gll::ListNode<int> *cur_b = headB;

        int len_a = 0;
        while (cur_a) {
            len_a++;
            cur_a = cur_a->next;
        }

        int len_b = 0;
        while (cur_b) {
            len_b++;
            cur_b = cur_b->next;
        }

        cur_a = headA;
        cur_b = headB;
        if (len_b > len_a) {
            std::swap(len_a, len_b);
            std::swap(cur_a, cur_b);
        }

        int gap = len_a - len_b;
        while (gap) {
            cur_a = cur_a->next;
            gap--;
        }

        while (cur_a) {
            if (cur_a == cur_b) return cur_a;
            cur_a = cur_a->next;
            cur_b = cur_b->next;
        }

        return nullptr;
    }
};

int main160() {
    gll::ListNodeUtils<int> my_utils_01;
    std::vector<int> nums_a = {4,1,8,4,5}; // 这里有个很有趣的现象，我没有引入头文件vector，但是我依然成功创建了nums_a
    my_utils_01.AddVal(nums_a);
    gll::ListNode<int> *list_a = my_utils_01.get_head();

    gll::ListNodeUtils<int> my_utils_02;
    std::vector<int> nums_b = {5,6,1,8,4,5};
    my_utils_02.AddVal(nums_b);
    gll::ListNode<int> *list_b = my_utils_02.get_head();

    Solution sol;
    gll::ListNode<int> *res = sol.getIntersectionNode(list_a, list_b);

    std::cout << res->val << std::endl;

    return 0;
}