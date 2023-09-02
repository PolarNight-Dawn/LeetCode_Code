#include <iostream>

//
// Created by polarnight on 23-9-2.
//

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr) return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(11);
    root->right->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(2);
    root->left = new TreeNode(8);
    root->left->right = new TreeNode(13);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int targetSum = 22;

    Solution sol;
    std::cout << sol.hasPathSum(root, targetSum);

    return 0;
}