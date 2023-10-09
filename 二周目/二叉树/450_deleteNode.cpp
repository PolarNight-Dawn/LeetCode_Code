#include <iostream>

//
// Created by polarnight on 23-10-8, 下午4:36.
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return nullptr;

        if (key > root->val) root->right = deleteNode(root->right, key);
        if (key < root->val) root->left = deleteNode(root->left, key);

        if (key == root->val) {
            if (!root->left && !root->right) return nullptr;
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode *node = root->right;
            while (node->left) node = node->left;
            node->left = root->left;
            root = root->right;
        }

        return root;
    }
};

int main450() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int key = 3;

    Solution sol;
    TreeNode *node = sol.deleteNode(root, key);

    return 0;
}