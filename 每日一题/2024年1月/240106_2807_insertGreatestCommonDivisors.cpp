#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
//
// Created by polarnight on 24-1-6, 下午2:46.
//


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* insertGreatestCommonDivisors(ListNode* head) {
    //     vector<int> tmp, ans;
    //
    //     //! \欧几里得算法 时间复杂度通常是对数级别
    //     //! 通过反复计算两个整数的余数和较小数之间的最大公约数，知道余数为零
    //     function<int(int, int)> GCD = [&](int a, int b) -> int {
    //         while (b != 0) {
    //             int temp = b;
    //             b = a % b;
    //             a = temp;
    //         }
    //         return a;
    //     };
    //
    //     while (head) {
    //         tmp.push_back(head->val);
    //         head = head->next;
    //     }
    //
    //     for (int i = 1; i < tmp.size(); i++) {
    //         ans.push_back(tmp[i - 1]);
    //         ans.push_back(GCD(tmp[i - 1], tmp[i]));
    //     }
    //     ans.push_back(tmp.back());
    //
    //     ListNode *result = new ListNode(-1);
    //     ListNode *res = result;
    //     for (auto &vec : ans) {
    //         res->next = new ListNode(vec);
    //         res = res->next;
    //     }
    //     return result->next;
    // }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        for (auto cur = head; cur->next; cur = cur->next->next)
            cur->next = new ListNode(gcd(cur->val, cur->next->val), cur->next);
        return head;
    }
};

int main2401062807() {
    ListNode *head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    Solution sol;
    auto result = sol.insertGreatestCommonDivisors(head);

    return 0;
}