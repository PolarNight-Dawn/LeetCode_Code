#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l3 = nullptr;
        int carry = 0, val = 0;

        while (l1 || l2) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;

            int sum = num1 + num2 + carry;
            val = sum % 10;
            carry = sum / 10;

            ListNode *cur = new ListNode(val);
            cur->next = l3;
            l3 = cur;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry != 0) {
            ListNode *cur = new ListNode(carry);
            cur->next = l3;
            l3 = cur;
        }

        // 貌似是针对两个链表全部为空时的处理，首先处理并不完善，没有考虑其中一个为0的情况，其次链表的构造函数限制了链表为空
        if (l3 == nullptr) {
            ListNode *cur = new ListNode(0);
        }

        ListNode *prev = nullptr;
        ListNode *curr = l3;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main02() {
    ListNode *l1 = new ListNode(0);
    ListNode *cur = l1;
    for (int i = 0; i < 5; i++) {
        cur->next = new ListNode(0);
        cur = cur->next;
    }
    cur->next = new ListNode(1);

    ListNode *l2 = new ListNode(0);
    /*l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);*/

    Solution sol;
    ListNode *l3 = sol.addTwoNumbers(l1, l2);

    while (l3 != nullptr) {
        std::cout << l3->val << " ";
        l3 = l3->next;
    }
    std::cout << std::endl;

    return 0;
}
