#include <iostream>

//
// Created by polarnight on 23-10-6, 下午3:48.
//


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return nullptr;

        if (root == q || root == p) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (!left) return right;
        if (!right) return left;

        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;
    TreeNode *q = root->right;

    Solution sol;
    TreeNode *node = sol.lowestCommonAncestor(root, p, q);

    std::cout << node->val;

    return 0;
}