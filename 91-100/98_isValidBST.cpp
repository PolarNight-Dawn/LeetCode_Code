#include <iostream>

//
// Created by polarnight on 23-8-25.
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
    long pre = INT64_MIN;
    bool isValidBST(TreeNode* root) {
       if (root == nullptr) return true;

        if (!isValidBST(root->left)) return false;

        if (root->val <= pre) return false;

        pre = root->val;

        return isValidBST(root->right);
    }
};

int main98() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);

    Solution sol;
    std::cout << sol.isValidBST(root);

    return 0;
}