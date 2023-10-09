#include <iostream>

//
// Created by polarnight on 23-10-9, 下午2:39.
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);

        root->right = trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);

        return root;
    }
};

int main669() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);

    int low = 1;
    int high = 2;

    Solution sol;
    TreeNode *node = sol.trimBST(root, low, high);

    return 0;
}