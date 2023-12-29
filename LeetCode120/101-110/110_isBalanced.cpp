#include <iostream>
#include <algorithm>

//
// Created by polarnight on 23-9-1.
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
    int get_height(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = get_height(root->left);
        if (left == -1) return -1;
        int right = get_height(root->right);
        if (right == -1 || abs(left - right) > 1) return -1;
        return std::max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
};

int main110() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    std::cout << sol.isBalanced(root);

    return 0;
}