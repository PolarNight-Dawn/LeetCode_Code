#include <iostream>
#include <vector>

//
// Created by polarnight on 23-8-31.
//

// Definition of a singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
    TreeNode *build_tree(std::vector<int> &tmp, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(tmp[mid]);

        root->left = build_tree(tmp, left, mid - 1);
        root->right = build_tree(tmp, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST02(ListNode* head) {
        std::vector<int> tmp;
        while (head != nullptr) {
            tmp.push_back(head->val);
            head = head->next;
        }

        TreeNode *root = build_tree(tmp, 0, tmp.size() - 1);

        return root;
    }
};

int main109() {
    //! \写个生成链表的工具类
    //! \写个生成二叉树的工具类
}

