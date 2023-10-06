#include <iostream>

//
// Created by polarnight on 23-10-3, 下午4:39.
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && root2) root1 = new TreeNode();
        if (root1 && !root2) root2 = new TreeNode();
        if (!root1 && !root2) return nullptr;

        if (!root1->left && root2->left) root1->left = new TreeNode();
        if (root1->left && !root2->left) root2->left = new TreeNode();
        if (!root1->right && root2->right) root1->right = new TreeNode();
        if (root1->right && !root2->right) root2->right = new TreeNode();

        root1->val = root1->val + root2->val;

        mergeTrees(root1->left, root2->left);

        mergeTrees(root1->right, root2->right);

        return root1;
    }
};

int main617() {
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(5);
    root1->right = new TreeNode(2);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(7);

    Solution sol;
    TreeNode *node = sol.mergeTrees(root1, root2);

    return 0;
}