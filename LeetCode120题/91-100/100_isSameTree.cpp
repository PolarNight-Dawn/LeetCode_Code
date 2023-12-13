#include <iostream>

//
// Created by polarnight on 23-8-26.
//

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void mid_order_traversal(TreeNode *p, TreeNode *q, bool &flag) {
        if (p == nullptr && q == nullptr) return;
        if (p == nullptr || q == nullptr) {
            flag = false;
            return;
        }

        mid_order_traversal(p->left, q->left, flag);

        if (p->val != q->val) {
            flag = false;
            return;
        }

        mid_order_traversal(p->right, q->right, flag);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        mid_order_traversal(p, q,flag);

        return flag;
    }
};

int main100() {
    TreeNode *p = new TreeNode(2);
    p->left = new TreeNode(-5);
    // p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(2);
    q->left = new TreeNode(-8);
    // q->right = new TreeNode(3);

    Solution sol;
    std::cout << sol.isSameTree(p, q);

    return 0;
}