#include <iostream>

//
// Created by polarnight on 23-9-30, 下午10:11.
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
    int get_sum(TreeNode *root, bool flag) {
        if (!root) return 0;

        int sum = 0;

        sum += get_sum(root->left, true);

        if (flag && !root->right && !root->left) sum += root->val;

        sum += get_sum(root->right, false);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode *root) {
        return get_sum(root, false);
    }
};

int main404() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    std:: cout << sol.sumOfLeftLeaves(root);

    return 0;
}