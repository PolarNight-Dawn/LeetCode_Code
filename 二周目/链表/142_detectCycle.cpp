#include <iostream>
#include <vector>
#include <unordered_set>

#include "/home/polarnight/Code/CLionProject/leedcode/generate_linked_list.h"

//
// Created by polarnight on 23-9-10, 下午3:56.
//

class Solution {
public:
    // 哈希表 时间复杂度为0(n) 空间复杂度为0(n)
    // gll::ListNode<int> *detectCycle(gll::ListNode<int> *head) {
    //     std::unordered_set<gll::ListNode<int> *> tmp;
    //
    //     while (head) {
    //         if (tmp.count(head)) return head;
    //         tmp.insert(head);
    //         head = head->next;
    //     }
    //
    //     return nullptr;
    // }

    // 二周目刷题 双指针法 快慢指针 时间复杂度为0(n) 空间复杂度为0(1)
    // 快慢指针的解法涉及数学分析、计算，具体解析可以看下面这一篇题解
    // 作者：代码随想录
    // 链接：https://leetcode.cn/problems/linked-list-cycle-ii/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    gll::ListNode<int> *detectCycle(gll::ListNode<int> *head) {
        gll::ListNode<int> *fast = head;
        gll::ListNode<int> *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                gll::ListNode<int> *index_1 = head;
                gll::ListNode<int> *index_2 = fast;
                while (index_1 != index_2) {
                    index_1 = index_1->next;
                    index_2 = index_2->next;
                }
                return index_2;
            }
        }

        return nullptr;
    }
};

int main142() {
    gll::ListNodeUtils<int> my_utils;
    std::vector<int> nums = {3, 2, 0, -4};

    my_utils.AddVal(nums);
    gll::ListNode<int> *head = my_utils.get_head();

    // 这一段代码会引发 double free
    // 原因大概是程序结束时会释放 cur 和 head 指针，但是这两个指针指向同一个内存块
    //! 使用智能指针 \std::shared_ptr 或 \std::unique_ptr 来管理内存， 减少手动内存管理错误的可能性
    // 可能可以解决问题，
    gll::ListNode<int> *cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head->next;

    Solution sol;
    gll::ListNode<int> *res = sol.detectCycle(head);

    std::cout << res->val << std::endl;

    return 0;
}
