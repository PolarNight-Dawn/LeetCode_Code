#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by polarnight on 23-12-4, 下午4:22.
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
    int sum = 0;
    TreeNode *bstToGst(TreeNode *root) {
        if (!root) return 0;

        bstToGst(root->right);

        sum += root->val;
        root->val = sum;

        bstToGst(root->left);

        return root;
    }
};

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);

    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    root->right->left = new TreeNode(5);

    Solution sol;
    TreeNode *Node = sol.bstToGst(root);

    return 0;
}