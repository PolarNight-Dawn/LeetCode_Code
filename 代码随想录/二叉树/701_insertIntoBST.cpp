#include <iostream>

//
// Created by polarnight on 23-10-8, 下午4:24.
//

// Definition for a binary tree node.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            auto *node = new TreeNode(val);
            return node;
        }

        if (val > root->val) root->right = insertIntoBST(root->right, val);
        if (val < root->val) root->left = insertIntoBST(root->left, val);

        return root;
    }
};

int main701() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);

    int val = 5;

    Solution sol;
    TreeNode *node = sol.insertIntoBST(root, val);

    return 0;
}