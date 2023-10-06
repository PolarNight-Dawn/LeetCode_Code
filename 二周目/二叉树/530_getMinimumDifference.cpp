#include <iostream>

//
// Created by polarnight on 23-10-6, 上午10:50.
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
    int min_gap = INT32_MAX;
    int pre = -1;
    int getMinimumDifference(TreeNode* root) {
        if (!root) return min_gap;

        min_gap = getMinimumDifference(root->left);

        if (pre != -1) min_gap = min_gap >= abs(pre - root->val) ? abs(pre - root->val) : min_gap;

        pre = root->val;

        return getMinimumDifference(root->right);
    }
};

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(13);

    Solution sol;
    std::cout << sol.getMinimumDifference(root);

    return 0;
}