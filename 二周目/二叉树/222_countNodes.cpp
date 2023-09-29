#include <iostream>

//
// Created by polarnight on 23-9-29, 下午3:52.
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
    int countNodes(TreeNode *root) {
        if (!root) return 0;

        int num = 0;
        num += countNodes(root->left);

        num += countNodes(root->right);

        return num + 1;
    }
};

int main222() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);

    Solution sol;
    std::cout << sol.countNodes(root);

    return 0;
}