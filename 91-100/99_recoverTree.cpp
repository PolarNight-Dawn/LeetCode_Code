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
    TreeNode *pre = new TreeNode(INT32_MIN);
    TreeNode *error_node_1 = nullptr;
    TreeNode *error_node_2 = nullptr;
    void find_error(TreeNode *root) {
        if (root == nullptr) return;
        find_error(root->left);

        if (root->val <= pre->val && error_node_1 == nullptr) error_node_1 = pre;
        if (root->val <= pre->val && error_node_2 == nullptr) error_node_2 = pre;

        pre = root;
        find_error(root->right);
    }

    void recoverTree(TreeNode *root) {
        find_error(root);

        if (!error_node_1 && !error_node_2) {
            int tmp = error_node_1->val;
            error_node_1->val = error_node_2->val;
            error_node_2->val = tmp;
        }
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    Solution sol;
    sol.recoverTree(root);


    return 0;
}